import java.io.*;
import java.net.*;
import java.util.*;

public class CalculatorClient2 {
    public static void main(String[] args) {
        // 파일 위치 설정
        String path = "ServerInfo.txt";

        try (BufferedReader bis = new BufferedReader(new FileReader(path))) {
            // 파일에서 읽고 ip주소와 port번호 저장
            String ip = bis.readLine();
            int port = Integer.parseInt(bis.readLine());

            // 소켓 생성
            try (Socket socket = new Socket(ip, port);
                 Scanner keyboard = new Scanner(System.in);
                 Scanner in = new Scanner(socket.getInputStream());
                 PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {

                // 명령어 입력
                System.out.println("Enter operation expression (e.g. 5 + 5) or 'exit' to quit");
                while (keyboard.hasNextLine()) {
                    String input = keyboard.nextLine();

                    if ("exit".equalsIgnoreCase(input)) {
                        System.out.println("Exiting the client.");
                        break;
                    }

                    // 공백을 기준으로 operation expression 분리
                    String[] parts = input.split(" ");

                    // 연산자, 두 개의 숫자 총 세 개의 입력을 넘어서거나 못미친다면, 양식에 맞지 않는다면 error 메시지
                    // 양식 : 숫자와 연산자 간에 띄어쓰기
                    if (parts.length != 3 || !parts[0].matches("\\d+") || !parts[2].matches("\\d+")) {
                        System.out.println("Invalid input. Please enter in the format: 5 + 5");
                        continue;
                    }

                    String operator = parts[1];

                    // operator를 ACKII코드로 변환
                    switch (operator) {
                        case "+":
                            operator = "add";
                            break;
                        case "-":
                            operator = "minus";
                            break;
                        case "*":
                            operator = "mul";
                            break;
                        case "/":
                            operator = "div";
                            break;
                    }

                    //서버에 보낼 명령어 조합 및 전송
                    String output = operator + " " + parts[0] + " " + parts[2];
                    out.println(output);

                    //서버의 답장에 대한 처리 (오류 코드에 따른 오류 메시지 출력 또는 계산 결과 출력)
                    String response = in.nextLine();
                    switch (response) {
                        case "991":
                            System.out.println("Error: Invalid operator. Only +, -, *, / are allowed.");
                            break;
                        case "992":
                            System.out.println("Error: Division by zero is not allowed.");
                            break;
                        case "993":
                            System.out.println("Error: Invalid number of arguments. Please enter in the format: 5 + 5");
                            break;
                        default:
                            System.out.println(response);
                    }
                }
            } catch (IOException e) {
                System.out.println("There was a problem with the socket connection.");
                e.printStackTrace();
            }
        } catch (IOException e) {
            System.out.println("There was a problem reading the server info file.");
            e.printStackTrace();
        }
    }
}
