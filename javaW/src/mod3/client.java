package mod3;

import java.io.*;
import java.net.*;

public class client {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Usage: Enter args[0] as host_number and args[1] as port_number");
            System.exit(1);
        }

        String hostName = args[0];
        int portNumber = Integer.parseInt(args[1]);

        /*
         * Note that, in this case, instead of creating a SocketServer object, we create
         * a Socket object. This second program introduces the idea of using one of the
         * system streams to capture data and send it to the socket: System.in. This
         * program will run for as long as the input in System.in is not null. This is
         * something that cannot really be achieved through direct interaction with
         * System.in, because we will be just pressing keys on the keyboard. Therefore,
         * you will need to call Ctrl + C to stop the client, just as was the case with
         * the server
         */
        try (Socket echoSocket = new Socket(hostName, portNumber);
                PrintWriter out = new PrintWriter(echoSocket.getOutputStream(), true);
                BufferedReader in = new BufferedReader(new InputStreamReader(echoSocket.getInputStream()));
                BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in))) {
            String userInput;
            /*
             * This makes this reader synchronous because it waits for the user to type,
             * sends the data, and, finally, waits until getting an answer from the socket
             */
            while ((userInput = stdIn.readLine()) != null) {
                out.println(userInput);
                System.out.println("echo from server: " + in.readLine());
                /*
                 * Note how sending data to the server is done with out.println(), where out is
                 * a PrinterWriter object, a stream, that is constructed on top of the Socket.
                 * On the other hand, to read the incoming Socket, we have implemented a
                 * BufferedReader object called in. Since it is buffered, we can poll the object
                 * whenever we want. The call to out. readLine() and in.readLine() is blocking.
                 * It will not stop reading from System.in or from the socket until the end of
                 * the line has been reached
                 */
            }
        } catch (UnknownHostException e) {
            System.err.println("Don't know about host " + hostName);
            System.exit(1);
        } catch (IOException e) {
            System.err.println("Couldn't get I/O for the connection to " + hostName);
            System.exit(1);
        }
    }

}
