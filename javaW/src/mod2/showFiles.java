package mod2;

import java.io.*;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.*;
import java.util.stream.*;

public class showFiles {
    public static void main(String[] args) throws IOException {
        // show1();
        // show2();
        // show3();
        show4();
    }

    static void show1() {
        String pathString = System.getProperty("java.io.tmpdir");
        System.out.println("PathString: " + pathString);
        String[] fileNames = new File(pathString).list();

        for (int i = 0; i < 5; i++) {
            System.out.println(fileNames[i]);
        }
    }

    /*
     * With this the full path to the directories and files are shown. This has to
     * do with the way DirectoryStream captures information from the OS
     */
    static void show2() throws IOException {
        String pathString = System.getProperty("user.home");
        // String pathString = System.getProperty("java.io.tmpdir");
        List<String> fileNames = new ArrayList<>();
        DirectoryStream<Path> directoryStream;

        /*
         * Paths.get() Converts a path string, or a sequence of strings that when joined
         * form a path string, to a Path
         */
        System.out.println("Test 1: " + Paths.get(pathString));
        directoryStream = Files.newDirectoryStream(Paths.get(pathString));
        /*
         * directoryStream contains all entries in the directory [Paths.get(pathString)]
         */

        for (Path path : directoryStream) {
            fileNames.add(path.toString());
        }

        for (int i = 0; i < 5; i++) {
            String filePath = fileNames.get(i);
            String fileType = Files.isDirectory(Paths.get(filePath)) ? "Dir" : "File";
            System.out.println(fileType + " " + filePath);
        }

    }

    static void show3() throws IOException {
        /*
         * Files.walk() will extract the directory structure up to a certain depth, in
         * our case, one. The depth represents how many levels of subdirectories your
         * code will be digging into. filter(Files::isDirectory) is going to exclude
         * anything that is not a directory. We have not seen filters yet, but it is a
         * clear enough concept to not need any further explanation at this point. The
         * final part of the call, collect(Collectors.toList()), will be creating a list
         * of the output
         */

        String pathString = System.getProperty("user.home");
        /*
         * Level 1 is the same level as where the search is initiated. Level 2 indicates
         * that we should also represent the contents of the directories inside the main
         * directory
         */
        List<Path> subdirectories = Files.walk(Paths.get(pathString), 1).filter(Files::isDirectory)
                .collect(Collectors.toList());
        for (int i = 0; i < 5; i++) {
            Path filePath = subdirectories.get(i);
            String fileType = Files.isDirectory(filePath) ? "Dir" : "File";
            /* All fileType will be Dir since we are filtering out only directory */
            System.out.println(fileType + " " + filePath);
        }
    }

    static void show4() throws IOException {
        /*
         * walkFileTree() method, which can browse through directory structures up to a
         * certain depth – two in the following example – and offers the possibility of
         * overriding some of its methods to decide what happens when reaching a
         * directory item and trying to access it
         */

        /*
         * you can see how the preVisitDirectory() method is called at the time of
         * trying to open a directory item in a folder. A program including that line
         * will run until, for example, a permissions-related exception arrives. If
         * there is no exceptional situation, the overridden method will print out all
         * directory names up to two levels of depth
         */

        /*
         * preVisitDirectory() method will tell the walkFileTree method that it should
         * continue to work through its return. The issue here is that because of the
         * AccessDeniedException, our program will not enter preVisitDirectory(). We
         * need to override yet another method called visitFileFailed() to see how to
         * handle any kind of exception that occurs when trying to access an item in the
         * directory
         */

        // maxDepth 1 means the /home/nbaskey
        // maxDepth 2 means the Folders inside of the /home/nbaskey
        // maxDepth 3 means the Folders inside the Folders inside of the /home/nbaskey

        Path path = Paths.get(System.getProperty("user.home"));
        Files.walkFileTree(path, Collections.emptySet(), 0, new SimpleFileVisitor<Path>() {
            @Override
            public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) {
                System.out.println(dir.toString());
                return FileVisitResult.CONTINUE;
            }

            @Override
            public FileVisitResult visitFileFailed(Path file, IOException exc) throws IOException {
                System.out.println("visitFileFailed: " + file);
                return FileVisitResult.CONTINUE;
            }
        });
    }
}
