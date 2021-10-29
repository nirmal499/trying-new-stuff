package mod2;

import java.io.*;
import java.nio.file.*;
import java.util.*;

public class loadProperties {
    public static void PrintOutProperties(Properties properties) {
        Enumeration<Object> keys = properties.keys();
        for (int i = 0; i < properties.size(); i++) {
            String key = keys.nextElement().toString();
            System.out.println(key + ": " + properties.getProperty(key));
        }
    }

    public static Properties LoadProperties(String pathString) throws IOException {
        Properties properties = new Properties();
        FileInputStream fileInputStream = null;

        try {
            fileInputStream = new FileInputStream(pathString);
            properties.load(fileInputStream);
        } catch (FileNotFoundException fnfe) {
            System.out.println("WARNING: could not find the properties file");
        } catch (IOException ioe) {
            System.out.println("WARNING: problem processing the properties file");
        } finally {
            if (fileInputStream != null) {
                fileInputStream.close();
            }
        }

        return properties;
    }

    public static void WriteProperties(String pathString, Properties properties) throws IOException {
        // create the output Stream and write to the file
        FileOutputStream fileOutputStream = null;
        try {
            fileOutputStream = new FileOutputStream(pathString);

            // write the resulting properties object back to the file
            // adds as comment the timestamp to the latest modification made
            properties.store(fileOutputStream, "# modified on: " + java.time.LocalDate.now());
        } catch (FileNotFoundException fnfe) {
            /*
             * In FileOutputStream(..) If the file exists but is a directory rather than a
             * regular file, does not exist but cannot be created, or cannot be opened for
             * any other reason then a FileNotFoundException is thrown
             */
            System.out.println("WARNING: could not find the properties file");
        } catch (IOException ioe) {
            System.out.println("WARNING: problem processing the properties file");
        } finally {
            if (fileOutputStream != null) {
                fileOutputStream.close();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        // take first argument as the file to open. By default we are going to be using
        // our temporary folder inside the user home directory, mainly for security
        // reasons
        if (args.length < 2) {
            /* Java does not consider the filename as argument */
            System.out.println("Insufficient Arguments!!! " + args.length);
        } else {
            String pathString = System.getProperty("user.home") + "/javaTemp/" + args[0];
            Path pathFile = Paths.get(pathString);

            // create the properties object
            Properties properties = new Properties();

            // System.out.println("Test: " + pathFile.toString());
            // System.out.println("Test: " + Files.exists(pathFile));

            // if the properties file exists, load the file into the properties object
            if (Files.exists(pathFile)) {
                try {
                    /* File exists */
                    properties = LoadProperties(pathString);
                } catch (IOException ioe) {
                    System.out.println("WARNING: problem closing the stream to the file");
                }
            } else {
                System.out.println("File Does not exists");
            }
            /* File Does not exists */

            // iterate through the rest of the arguments and add them to the properties
            // object
            for (int i = 1; i < args.length; i++) {
                String[] keyValue = args[i].split("=");
                properties.setProperty(keyValue[0], keyValue[1]);
            }

            try {
                WriteProperties(pathString, properties);
            } catch (IOException ioe) {
                System.out.println("WARNING: problem while closing properties file");
            }
            // print the final result to System.out
            PrintOutProperties(properties);
        }

    }
}
