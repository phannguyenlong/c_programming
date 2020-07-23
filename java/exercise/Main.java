import chap3.CardDeck;

// import chap2.Ex2_6;

public class Main {
    public static void main(String[] args) {
        CardDeck game = new CardDeck();
        System.out.println(game.numberOfCard());
        game.showDeck();

        System.out.println("Withdraw 1 card: ");
        game.withDrawOneCard();
        
        game.showDeck();
    }
}