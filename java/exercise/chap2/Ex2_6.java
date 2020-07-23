package chap2;

/**
 * Write a program that counts from 0 to 999 and outputs its status each 50 steps, 
 * e.g. “...100, 150, 200, ...” 
 */
public class Ex2_6 {
    public void runWithFor() {
        for (int i = 0; i < 1000; i++) {
            if (i % 50 == 0)
                System.out.println(String.format("Status: running at %d ...", i));
        }
    }

    public void runWithWhile() {
        int i = 0;
        while (++i < 1000) {
            if (i % 50 == 0)
                System.out.println(String.format("Status: running at %d ...", i));
        }
    }

    public void runWithDoWhile() {
        int i = 0;
        do {
            if (i % 50 == 0)
                System.out.println(String.format("Status: running at %d ...", i));
        } while (i++ < 1000);
    }
}