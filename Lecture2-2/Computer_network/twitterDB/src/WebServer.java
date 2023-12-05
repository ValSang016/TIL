import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class WebServer {
    private static final int PORT = 6789;
    private static final int MAX_CLIENT = 20;

    public static void main(String[] args) throws Exception {
        ServerSocket welcomeSocket = new ServerSocket(PORT);
        System.out.println("Server start .. (port=" + PORT + ")");

        ExecutorService pool = Executors.newFixedThreadPool(MAX_CLIENT);

        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            pool.execute(new ClientHandler(connectionSocket));
        }
    }

    private static class ClientHandler implements Runnable {
        private Socket connectionSocket;

        public ClientHandler(Socket socket) {
            this.connectionSocket = socket;
        }

        @Override
        public void run() {
            try {
                BufferedReader inFromClient = new BufferedReader(
                        new InputStreamReader(connectionSocket.getInputStream()));
                DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());

                String clientSentence = inFromClient.readLine();

                String[] credentials = clientSentence.split(",");
                String userId = credentials[0];
                String password = credentials[1];
                boolean isAuthenticated = authenticateUser(userId, password);

                String capitalizedSentence = isAuthenticated ? "인증 성공" : "인증 실패";

                outToClient.writeBytes(capitalizedSentence + ' ');
            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                try {
                    connectionSocket.close();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

        private boolean authenticateUser(String userId, String password) {
            // 동일한 인증 코드
            // ...
        }
    }
}
