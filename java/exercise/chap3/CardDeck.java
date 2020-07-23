package chap3;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * This class will create a deck of card with 52 cards inside
 */
public class CardDeck {
    private List <Card> card_deck = new ArrayList<>();
    private String[] suites = { "Spade", "Heart", "Diamond", "Club" };
    private String[] non_number_card = { "King", "Queen", "Jack", "ACE" };
    
    public CardDeck() {
        card_deck = generateCardDeck();
        System.out.println("Card deck was created");
    }

    public int numberOfCard() {
        return card_deck.size();
    }

    public void withDrawOneCard() {
        Random rd = new Random();
        Card card = card_deck.get(1 + rd.nextInt(card_deck.size()));
        card.display();
        card_deck.remove(card);
        System.out.println();
    }

    public List<Card> generateCardDeck() {
        List <Card> cards = new ArrayList<>();
        for (int i = 2; i <= 10; i++) {
            for (String index : suites) {
                cards.add(new Card(String.valueOf(i), index));
            }
        }
        for (String card : non_number_card) {
            for (String index : suites) {
                cards.add(new Card(card, index));
            }
        }
        return cards;
    }

    public void showDeck() {
        System.out.print("{\n");
        for (int i = 0; i < card_deck.size(); i++) {
            card_deck.get(i).display();
            System.out.print((i+1)%4 == 0 ? "\n" : "\t");
        }
        System.out.println("}");
    }
    
    public static void main(String[] args) {
        CardDeck game = new CardDeck();
        System.out.println(game.numberOfCard());
        game.showDeck();

        System.out.println("Withdraw 1 card: ");
        game.withDrawOneCard();
        
        game.showDeck();
    }
}