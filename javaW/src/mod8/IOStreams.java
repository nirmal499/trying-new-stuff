package mod8;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class IOStreams {
    public static void main(String[] args) {
        String pathString = System.getProperty("user.home") + File.separator + "javaTemp/authors.csv";
        // way1(pathString);
        way2(pathString);
    }

    static void way1(String pathString) {
        try (Stream<String> authors = Files.lines(Paths.get(pathString))) {
            authors.onClose(() -> {
                System.out.println("Closed1");
            }).forEach((author) -> {
                System.out.println(author);
            });
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void way2(String pathString) {
        try (Stream<String> authors = new BufferedReader(new InputStreamReader(new FileInputStream(pathString)))
                .lines()) {

            authors.onClose(() -> {
                System.out.println("Closed2");
            }).forEach((author) -> {
                System.out.println(author);
            });
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

}
