/**
 * <H1>WordTool</H1> A class to perform calculations about text. For generating
 * use : $javadoc Your_java_file.java
 * 
 * @author Joe Smith
 * @version 0.1
 * @since 20190305
 */
public class WordTool {

    /**
     * <h2>wordCount</h2> returns the amount of words in a text, takes a string as
     * parameter
     *
     * @param str
     * @return int
     */
    public int wordCount(String str) {
        int count = 0;
        /*
         * string is not null(not assgined) and not empty(It means empty string -> "")
         */
        if (!(str == null || str.isEmpty())) {
            /* separate words having whitespaces as separator */
            String[] strArray = str.split("\\s+");
            count = strArray.length; /* length is a property not a method */
        }
        return count;
    }

    /**
     * <h2>symbolCount</h2> returns the amount of symbols in a string with or
     * without counting spaces
     *
     * @param str
     * @param includeWhiteSpacesOrNot
     * @return int
     */
    public int symbolCount(String str, boolean includeWhiteSpacesOrNot) {
        int count = 0;
        /* string is not null and not empty */
        if (!(str == null || str.isEmpty())) {
            if (includeWhiteSpacesOrNot) {
                /* count characters including whitespaces */
                count = str.length(); /* length is a method */
            } else {
                /* count characters excluding whitespaces */
                count = str.replace(" ", "").length();
            }
        }
        return count;

    }

    /**
     * <h2>getFrequency</h2> returns the amount of occurrences of a symbol in a
     * string
     *
     * @param str
     * @param ch
     * @return int
     */
    public int getFrequency(String str, char ch) {
        int count = 0;
        /* string is not null and not empty */
        if (!(str == null || str.isEmpty())) {
            count = str.length() - str.replace(Character.toString(ch), "").length();
        }
        return count;
    }

    /**
     * <h2>main</h2> uses an example string to demonstrate how the class works
     *
     * @param args
     */
    public static void main(String[] args) {

        WordTool wt = new WordTool();

        String text = "The river carried the memories from her childhood";
        char search = 'e';

        System.out.println("Analyzing the text: \n" + text);
        System.out.println("Total words: " + wt.wordCount(text));
        System.out.println("Total characters(with spaces): " + wt.symbolCount(text, true));
        System.out.println("Total characters(without spaces): " + wt.symbolCount(text, false));
        System.out.println("Total amount of " + search + " is : " + wt.getFrequency(text, search));

    }
}
