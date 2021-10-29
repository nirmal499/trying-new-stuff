package mod2;

import java.io.IOException;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.Arrays;
import java.util.Collections;

public class writingDirStructure {
    public static void main(String[] args) throws IOException {
        Path path = Paths.get(System.getProperty("user.home") + "/javaTemp/");

        String fileName = "temp.txt";
        Path pathFile = Paths.get(fileName);

        if (!Files.exists(pathFile)) {
            try {
                // Create the file
                Files.createFile(pathFile);
                System.out.println("New file created at: " + pathFile);
            } catch (IOException ioe) {
                System.out.println("EXCEPTION when creating file: " + ioe.getMessage());
            }
        }

        Files.walkFileTree(path, Collections.emptySet(), 10, new SimpleFileVisitor<Path>() {
            @Override
            public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) {

                String toFile = "";

                // System.out.println("path is :" + path.toString());
                String[] pathArray = path.toString().split("/");
                int depthInit = pathArray.length;
                // System.out.println("depthInit: " + depthInit);
                // System.out.println("pathArray: " + pathArray[1] + " " + pathArray[3]);

                /*
                 * pathArray consists [ "" , "home" , "nbaskey" , "javaTemp"]. The deptIit is 4
                 */

                // System.out.println("dir is :" + dir.toString());
                String[] fileArray = dir.toString().split("/");
                int depthCurrent = fileArray.length;
                // System.out.println("depthCurrent: " + depthCurrent);

                /*
                 * For dir is :/home/nbaskey/javaTemp . The depthCurrent: 4
                 * 
                 * For dir is :/home/nbaskey/javaTemp/fol1 . The depthCurrent: 5 becoz the
                 * fileArray contains ["" , "home" ,"nbaskey","javaTemp" , "fol1"]
                 * 
                 * Similarly, For dir is :/home/nbaskey/javaTemp/fol1/fol2/fol3/fol4. The
                 * depthCurrent: 8 becoz the fileArray contains ["" , "home"
                 * ,"nbaskey","javaTemp" , "fol1","fol2","fol3","fol4"]
                 */

                for (int i = depthInit; i < depthCurrent; i++) {
                    toFile += "    ";
                }
                toFile += fileArray[fileArray.length - 1];

                if (Files.exists(pathFile))
                    try {
                        // System.out.println("Arrays as list: " + Arrays.asList(toFile));
                        Files.write(pathFile, Arrays.asList(toFile), StandardOpenOption.APPEND);
                    } catch (IOException ioe) {
                        System.out.println("EXCEPTION when writing to file: " + ioe.getMessage());
                    }

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
