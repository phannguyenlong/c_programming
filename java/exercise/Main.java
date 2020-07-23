// import chap3.CardDeck;
import chap3.CeacarCipher;

// import chap2.Ex2_6;

public class Main {
    public static void main(String[] args) {
        CharSequence cs = new CeacarCipher("Test 26", 1);
        System.out.println(cs.length());
        System.out.println(cs.charAt(1));
        System.out.println(String.valueOf(cs.subSequence(0, 6)));
    }   
}