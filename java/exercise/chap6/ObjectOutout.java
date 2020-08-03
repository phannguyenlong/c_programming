package chap6;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

import chap3.CardDeck;

/**
 * This is for exercise 6.3: Output an object to fiel
 */
public class ObjectOutout {
    public static void main(String[] args) throws IOException {
        String path = new String();
        try (Scanner scan = new Scanner(System.in)) {
            System.out.print("Input path to write: ");
            path = scan.nextLine();
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Write Object
        ObjectOutputStream out = null;
        CardDeck game = new CardDeck();
        try {
            out = new ObjectOutputStream(new FileOutputStream(path));
            out.writeObject(game);
        } catch (FileNotFoundException e) {
            System.out.println("Cannot found file at path: " + path);
        } finally {
            if (out != null)
                out.close();
        }

        // Read object
        ObjectInputStream in = null;
        try {
            in = new ObjectInputStream(new FileInputStream(path));
            CardDeck object = (CardDeck) in.readObject();
            object.showDeck();
        } catch (FileNotFoundException e) {
            System.out.println("Can not find file at path: " + path);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (in != null)
                in.close();
        }
    }
}