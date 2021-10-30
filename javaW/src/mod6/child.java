package mod6;

import java.io.*;
import static java.lang.Thread.sleep;

public class child {
    /*
     * the parent process will read the inputs and compare them with a certain
     * number, for example, 37, after which the counter should restart. To ask the
     * child process to restart, the parent should send a single-byte command to the
     * child. Let's use an asterisk (*) for this activity. You should use the
     * sleep() command so that printing on the terminal doesn't happen too quickly.
     * A good configuration would be sleep(200)
     */
    public static void main(String[] args) throws IOException, InterruptedException {
        int ch;
        System.out.print("Let's echo: ");

        // echo out whatever comes from system in
        while ((ch = System.in.read()) != '\n') {
            System.out.print((char) ch);
        }
        System.out.println();

        // the Child process will be logged in a file here
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(new File("mycal2022.txt")));

        /*
         * To stop the program from running forever to reach infinity, the child process
         * should stop when a certain number is reached. Let's take 50 as a limit
         */
        int cont = 0;
        while (cont <= 50) {
            System.out.println(cont++);

            // added this to log data in local file + EOL
            bufferedWriter.write(cont + "\n");
            bufferedWriter.flush();

            sleep(1000);

            /*
             * Here, there is a call to System.in.available() to check whether there is any
             * data in the output buffer from the child program
             */
            if (System.in.available() > 0) {
                ch = System.in.read();

                // reset counter if asterisk
                if (ch == '*') {
                    cont = 0;
                }
            }
        }
        bufferedWriter.close();
    }
}
