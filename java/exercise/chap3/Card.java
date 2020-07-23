package chap3;

/**
 * This class will take role as a card with 2 poperty is value and suite
 */
public class Card {
    private String value;
    private String suite;

    public Card(String val, String suite) {
        this.value = val;
        this.suite = suite;
    }

    public String getSuite() {
        return suite;
    }

    public String getValue() {
        return value;
    }

    public void display() {
        System.out.print(String.format("%s of %s", value, suite));
    }
}