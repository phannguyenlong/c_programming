package synchornization.notify;

import synchornization.SharedData;

/**
 * This is the demo of using notify, notifyAll, wait
 * Program has 2 thread:
 *  1st thread will generate a random number
 *  2nd thread will catch that number a square it
 */
public class Test {
    public static void main(String[] args) {
        SharedData sharedData = new SharedData();
        System.out.println("System start");

        Thread t1 = new Thread(new Thread1(sharedData));
        Thread t2 = new Thread(new Thread2(sharedData));

        t1.start();
        t2.start();
    }

}