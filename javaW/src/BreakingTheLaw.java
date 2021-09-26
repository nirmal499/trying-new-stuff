public class BreakingTheLaw {

    static class MyException extends Exception {
        /* Must have a Constructor */
        /* constructor overloading */
        MyException() {
            super();
        }

        MyException(String message) {
            super(message);
        }

        MyException(String message, Throwable cause) {
            super(message, cause);
        }

        MyException(Throwable cause) {
            super(cause);
        }

    }

    /*
     * The main function specifies that it throws MyException since it is infact
     * throwing MyException inside its body
     */
    public static void main(String[] args) throws MyException {
        String s = null;

        try {
            System.out.println(s.length());
        } catch (NullPointerException e) {
            throw new MyException("Exception: my exception happened", e);
            // throw new MyException("Exception: my exception happened");
        }
    }
}
