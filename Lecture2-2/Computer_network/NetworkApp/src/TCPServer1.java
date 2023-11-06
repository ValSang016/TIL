import jdk.nashorn.internal.ir.WhileNode;

import java.io.*;
import java.net.*;

public class TCPServer1 {
    public static void main(String[] args) throws IOException{
        ServerSocket welcomeSocket;
        String clientSentence;
        String capitalizedSentence;
        int nPort;
        nPort = 6789;

        //서버용 소켓 생성
        welcomeSocket = new ServerSocket(nPort);

        System.out.println("Server start .. (port3=" + nPort + ")\n ");

        //wait for a new connection on nPort#
        while (true){
            Socket connectionSocket = welcomeSocket.accept();

            //인풋 스트림을 생성하고 버퍼리더에 연결
            BufferedReader inFromClient = new BufferedReader(
                    new InputStreamReader((connectionSocket.getInputStream())));

            //아웃풋 스트림 연결
            DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());

            //인풋 스트림에서 데이터 읽어오기
            clientSentence = inFromClient.readLine();

            //Processing
            System.out.println("FROM CLIENT: " + clientSentence);
            capitalizedSentence = clientSentence.toUpperCase() + '\n';

            //아웃풋 스트림으로 데이터 내보내기
            outToClient.writeBytes(capitalizedSentence);

            connectionSocket.close();
        }


    }
}