import java.io.*;
import java.net.*;

public class TCPClient1 {
    public static void main(String argv[]) throws Exception{
        String sentence;
        String modifiedSentence;
        String serverIP = "127.0.0.1";
        int nPort = 6789;

        //유저 입력 객체 생성
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));

        //소켓 생성
        Socket clientSocket = new Socket(serverIP, nPort);

        //아웃풋 스트림 연결
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

        //인풋 스트림 연결하고 버퍼에 연결
        BufferedReader inFromServer = new BufferedReader(
                new InputStreamReader(clientSocket.getInputStream()));

        //유저 입력 읽기
        sentence = inFromUser.readLine();

        //아웃풋 스트림 통해 전송
        outToServer.writeBytes(sentence + '\n');

        //인풋 스트림 통해 들어와 버퍼에 저장된 데이터를 mod-에 입력
        modifiedSentence = inFromServer.readLine();
        System.out.println("FROM SERVER : " + modifiedSentence);
        clientSocket.close();
    }
}
