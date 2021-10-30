package mod5;

import java.io.*;
import java.util.concurrent.TimeUnit;

public class sendToChildProcess {
    public static void main(String[] args) throws IOException {
        Runtime runtime = Runtime.getRuntime();
        Process process = null;

        try {
            /*
             * Make sure the compiled file of ThisIsChildProcess.java is present is
             * class_files
             */

            // String program = "java -cp ../class_files mod5/ThisIsChildProcess";
            // Above statement will cause IOException since
            // we do : ./run.sh mod5/sendToChildProcess . And we do it from src directory
            // So, we have to provide -cp as class_files instead of ../class_files

            String program = "java -cp class_files mod5/ThisIsChildProcess";
            process = runtime.exec(program);

        } catch (IOException ioe) {
            System.out.println("WARNING: couldn't start your app");
        }

        try {
            process.waitFor(5, TimeUnit.SECONDS);
        } catch (InterruptedException ie) {
            System.out.println("WARNING: interrupted exception fired");
        }

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

        // read from System.out from the child
        InputStream in = process.getInputStream();
        Reader reader = new InputStreamReader(in);
        BufferedReader bufferedReader = new BufferedReader(reader);
        String line = bufferedReader.readLine();

        // send to screen
        System.out.println(line);

        // send to file
        bufferedWriter.write(line);
        bufferedWriter.flush();

        process.destroy();

        bufferedWriter.close();

    }
}
