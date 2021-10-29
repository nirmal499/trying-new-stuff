package mod3;

import java.io.*;
import java.net.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class server {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: Enter args[0] as port_number");
            System.exit(1);
        }

        int portNumber = Integer.parseInt(args[0]);

        /*
         * The try-with-resources statement is a try statement that declares one or more
         * resources. A resource is an object that must be closed after the program is
         * finished with it.Prior to Java SE 7, you can use a finally block to ensure
         * that a resource is closed regardless of whether the try statement completes
         * normally or abruptly. The following example uses a finally block instead of a
         * try-with-resources statement: See:
         * https://docs.oracle.com/javase/tutorial/essential/exceptions/tryResourceClose
         * .html
         */
        try (ServerSocket serverSocket = new ServerSocket(Integer.parseInt(args[0]));
                Socket clientSocket = serverSocket.accept();
                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));) {
            /*
             * Two different streams: BufferReader in for the input, and PrinterWriter out
             * for the output. As soon as a connection is established, 'in' will get the
             * data, and 'out' will send it – with adding the date with the data recieved
             * from 'in' back to the socket
             */
            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                String s = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss").format(LocalDateTime.now());
                out.println(s + " " + inputLine);
            }
        } catch (IOException e) {
            System.out.println(
                    "Exception caught when trying to listen on port " + portNumber + " or listening for a connection");
            System.out.println(e.getMessage());
        }
    }
}
