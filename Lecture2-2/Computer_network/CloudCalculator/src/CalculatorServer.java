import java.io.*;
import java.net.*;
import java.util.concurrent.*;
import java.util.*;

public class CalculatorServer {
    public static void main(String[] args) throws Exception {
        // 포트 번호 : 7777이고, 접속 대기, 접속 가능 클라이언트 수는 20
        try(ServerSocket listener = new ServerSocket(7777)){
            System.out.println("The Calculator server is running...");
            ExecutorService pool = Executors.newFixedThreadPool(20);
            while (true) {
                Socket sock = listener.accept();
                pool.execute(new Calculator(sock)); // 접속이 들어오면 Caculator 객체 생성 및 실행
            }
        }
    }
}

class Calculator implements Runnable {
    private Socket socket;

    // Constructor(생성자)로서 socket 설정
    Calculator(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        System.out.println("Connected: " + socket);
        try {
            Scanner in = new Scanner(socket.getInputStream());
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            while (in.hasNextLine()) {
                // input 스트림에서 명령어 가져오고, 공백을 기준으로 분리하여 elements에 저장
                String request = in.nextLine();
                String[] elements = request.split(" ");

                // 명렁어가 연산자 하나, 숫자 2개로 이루어지지 않은 경우 오류 코드 전송
                if (elements.length != 3) {
                    out.println("993"); // error : invalid number of arguments
                    continue;
                }


                String operator = elements[0];
                int num1 = Integer.parseInt(elements[1]);
                int num2 = Integer.parseInt(elements[2]);

                // 명령어에 따라 연산 처리
                switch (operator.toLowerCase()) {
                    case "add":
                        out.println(num1 + num2);
                        break;
                    case "minus":
                        out.println(num1 - num2);
                        break;
                    case "mul":
                        out.println(num1 * num2);
                        break;
                    case "div":
                        if (num2 == 0){
                            out.println("992"); // 0으로 나누는 경우 오류 코드 출력
                        } else {
                            out.println(num1 / num2);
                        }
                        break;
                    default:
                        out.println("991"); // 연산자 형식이 잘못 됐다면 오류 코드 출력 (ex. add가 아니라 edd로 받았다면)
                }
            }
        }catch (Exception e) {
            System.out.println("Error: " + socket);
        } finally {
            // 연산 및 전송 처리 완료 후 socket close 처리 (없어도 되지만 완결성을 위해)
            try {
                socket.close();
            } catch (IOException e) {
            }
            System.out.println("Closed: " + socket);
        }
    }
}
