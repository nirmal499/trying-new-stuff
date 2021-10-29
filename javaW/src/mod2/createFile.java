package mod2;

import java.io.IOException;
import java.nio.file.*;
import java.util.Arrays;
import java.util.List;

public class createFile {
    public static void main(String[] args) {
        String pathString = System.getProperty("user.home") + "/javaTemp/";
        crDirectory(pathString);
        crFile(pathString);
        appendData();
    }

    static void crDirectory(String pathString) {

        Path pathDirectory = Paths.get(pathString);

        if (Files.exists(pathDirectory)) {
            System.out.println("WARNING: directory exists already at: " + pathString);
        } else {
            try {
                // Create the directory
                Files.createDirectories(pathDirectory);
                System.out.println("New directory created at: " + pathString);
            } catch (IOException ioe) {
                System.out.println("Could not create the directory");
                System.out.println("EXCEPTION: " + ioe.getMessage());
            }
        }

    }

    static void crFile(String pathString) {
        String fileName = "temp.txt";
        Path pathFile = Paths.get(pathString + fileName);
        if (Files.exists(pathFile)) {
            System.out.println("WARNING: file exists already at: " + pathFile);
        } else {
            try {
                // Create the file
                Files.createFile(pathFile);
                System.out.println("New file created at: " + pathFile);
            } catch (IOException ioe) {
                System.out.println("Could not create the file");
                System.out.println("EXCEPTION: " + ioe.getMessage());
            }
        }
    }

    static void appendData() {
        String pathString = System.getProperty("user.home") + "/javaTemp/temp.txt";
        Path pathFile = Paths.get(pathString);
        String text = "Hola,\nme da un refresco,\npor favor?";

        if (Files.exists(pathFile))
            try {
                // System.out.println("Arrays as list: " + Arrays.asList(text));
                // System.out.println("Arrays as list SIZE: " + Arrays.asList(text).size());
                Files.write(pathFile, Arrays.asList(text), StandardOpenOption.APPEND);
                System.out.println("Text added to the file: " + pathFile);
            } catch (IOException ioe) {
                System.out.println("EXCEPTION: " + ioe.getMessage());
            }

    }
}
