package mod1;

public class MultipleOccurrence {
    public static void main(String[] args) {
        String textToBeSearched = "so";
        String[] text = { "So", "many", "books", "so", "little", "time" };
        for (int i = 0; i < text.length; i++) {
            if (text[i].compareToIgnoreCase(textToBeSearched) == 0) {
                System.out.println("Found Query at: " + i);
            }
        }
    }
}
