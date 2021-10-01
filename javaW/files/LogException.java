import java.io.IOException;
import java.nio.file.NoSuchFileException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class LogException {
    /*
     * We are telling that issuePointerException() throws NullPointerException since
     * we can actually see that the code inside the indeed generates a
     * NullPointerException
     */
    public static void issuePointerException() throws NullPointerException {
        throw new NullPointerException("Exception: Null Pointer");
    }

    public static void issueFileException() throws NoSuchFileException {
        throw new NoSuchFileException("Exception: File Not Found");
    }

    public static void main(String[] args) {
        Logger logger = Logger.getAnonymousLogger();
        if (args.length == 0) {
            System.out.println("Specify arguments !!!!");
        } else {
            Integer exceptionNum = Integer.valueOf(args[0]);
            String exceptionInfo = "Exception happened";

            switch (exceptionNum) {
                case 1:
                    try {
                        issuePointerException();
                    } catch (NullPointerException e) {
                        logger.log(Level.SEVERE, exceptionInfo, e);
                    }
                    break;
                case 2:
                    try {
                        issueFileException();
                    } catch (NoSuchFileException e) {
                        logger.log(Level.WARNING, exceptionInfo, e);
                    }
                    break;
                case 3:
                    try {
                        issueFileException();
                    } catch (IOException e) {
                        logger.log(Level.INFO, exceptionInfo, e);
                    }
                    break;

                default:
                    System.out.println("No case for this " + exceptionNum + " Exception");
                    break;
            }
        }

    }
}
