package mod6;

import java.io.*;
import java.util.concurrent.TimeUnit;

public class parent {
    public static void main(String[] args) throws IOException {
        Runtime runtime = Runtime.getRuntime();
        Process process = null;

        try {
            /*
             * Make sure the compiled file of ThisIsChildProcess.java is present is
             * class_files
             */

            String program = "java -cp class_files mod6/child";
            process = runtime.exec(program);

        } catch (IOException ioe) {
            System.out.println("WARNING: couldn't start your app");
        }

        try {
            process.waitFor(10, TimeUnit.SECONDS);
        } catch (InterruptedException ie) {
            System.out.println("WARNING: interrupted exception fired");
        }

        System.out.println("trying to write");
        OutputStream out = process.getOutputStream();
        Writer writer = new OutputStreamWriter(out);

        /*
         * EOL to ensure the process sends back. Since the childProcess will not end
         * until a new line is appeared
         */
        writer.write("This is how we roll!\n");
        writer.flush();

        /*
         * To capture whatever is being sent by the child process to System.out, we need
         * to create a BufferedReader in the parent class that will be fed from the
         * InputStream that can be instantiated from the process. We are then going to
         * store the whatever sent by child process to a file
         */

        // prepare the data logger
        File file = new File("data.log");
        FileWriter fileWriter = new FileWriter(file);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

        System.out.println("trying to read");
        // read from System.out from the child
        InputStream in = process.getInputStream();
        Reader reader = new InputStreamReader(in);
        BufferedReader bufferedReader = new BufferedReader(reader);
        String line = bufferedReader.readLine();

        // send to screen
        System.out.println(line); /* This is how the echoed oned */

        // send to file
        bufferedWriter.write(line);
        bufferedWriter.flush();

        while (line != null) {
            // send to screen
            System.out.println(line);

            // send to file + EOL
            bufferedWriter.write(line + "\n");
            bufferedWriter.flush();

            // read next line
            line = bufferedReader.readLine();

            // this will force the reset of the counter
            // the program will therefore never end
            if (Integer.parseInt(line) == 37) {
                writer.write('*');
                writer.flush(); // needed because of the buffered output
                System.out.println("sent message");
            }
        }

        process.destroy();

        bufferedWriter.close();
    }
}
