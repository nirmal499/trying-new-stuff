package mod2;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class readFile {
    public static void main(String[] args) {
        String pathString = System.getProperty("user.home") + "/javaTemp/temp.txt";
        reFileUsingList(pathString);
        System.out.println("========================================================================");
        reFileUsingStream(pathString);

    }

    static void reFileUsingStream(String pathString) {
        Path pathFile = Paths.get(pathString);
        try {
            Files.lines(pathFile).forEach(System.out::println);
        } catch (IOException ioe) {
            System.out.println("WARNING: there was an issue with the file");
        }
    }

    static void reFileUsingList(String pathString) {
        Path pathFile = Paths.get(pathString);
        try {
            List<String> fileContent = Files.readAllLines(pathFile);

            // this will go through the buffer containing the whole file
            // and print it line by one to System.out
            for (String content : fileContent) {
                System.out.println(content);
            }
        } catch (IOException ioe) {
            System.out.println("WARNING: there was an issue with the file");
        }
    }
}
