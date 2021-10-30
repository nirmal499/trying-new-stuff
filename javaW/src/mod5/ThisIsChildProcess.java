package mod5;

import java.io.IOException;

public class ThisIsChildProcess {
    public static void main(String[] args) throws IOException {
        int c;
        System.out.print("Let's echo: ");
        while ((c = System.in.read()) != '\n') {
            System.out.print((char) c);
        }
    }
}
