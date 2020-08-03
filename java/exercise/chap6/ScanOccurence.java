package chap6;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 * This exercise for 6.2
 * It will scan for the ocurrence of input character in file
 */
public class ScanOccurence {
    public int scanFile(String path, char x) throws IOException {
        int count = 0;
        FileReader in = null;
        try {
            in = new FileReader(path);
            int c;
            while ((c = in.read()) != -1) {
                if ( Character.toLowerCase((char) c) == Character.toLowerCase(x))
                    count++;
            }
        } catch (FileNotFoundException e) {
            System.out.println("Can't not found at path " + path);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (in != null)
                in.close();
        }

        return count;
    }
    
    public static void main(String[] args) {
        ScanOccurence checker = new ScanOccurence();
        try (Scanner scan = new Scanner(System.in)) {
            System.out.print("Input path: ");
            String path = scan.nextLine();
            System.out.print("Input character to scan: ");
            char x = scan.next().charAt(0);
            System.out.println("Ocurrence of " + x + " is: " + checker.scanFile(path, x));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}