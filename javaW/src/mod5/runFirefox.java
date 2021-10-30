package mod5;

import java.io.IOException;
import java.util.concurrent.TimeUnit;

public class runFirefox {
    public static void main(String[] args) {
        // way1();
        way2();
    }

    static void way1() {
        /*
         * It is possible to get information about the Runtime class by calling the
         * getRuntime() method and assigning its outcome to a variable of the Runtime
         * class.
         */
        Runtime runtime = Runtime.getRuntime();
        Process process = null;

        try {
            /* A process is launched with exec() */
            process = runtime.exec("firefox");
        } catch (IOException ioe) {
            System.out.println("WARNING: something happened with exec");
        }

        try {
            /*
             * The waitFor(timeOut, timeUnit) method will wait for the process to end for 10
             * seconds. If it was waitFor() without parameters, it would wait for the
             * program to end by itself. Following the 10-second timeout, the process
             * variable will call the destroy() method, which will stop the process
             * immediately. This example is, therefore, opening and closing an application
             * over a short period of time
             */
            process.waitFor(10, TimeUnit.SECONDS);
        } catch (InterruptedException ie) {
            System.out.println("WARNING: interruption happened");
        }

        process.destroy();
    }

    static void way2() {
        ProcessBuilder processBuilder = new ProcessBuilder("firefox");
        Process process = null;

        try {
            process = processBuilder.start();
        } catch (IOException ioe) {
            System.out.println("WARNING: something happened with exec");
        }

        try {
            process.waitFor(10, TimeUnit.SECONDS);
        } catch (InterruptedException ie) {
            System.out.println("WARNING: interruption happened");
        }

        process.destroy();
    }
}
