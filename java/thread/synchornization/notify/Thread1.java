package synchornization.notify;

import java.util.Random;

import synchornization.SharedData;

public class Thread1 implements Runnable {
    SharedData data;

    public Thread1(SharedData data) {
        this.data = data;
    }

    @Override
    public void run() {
        Random rand = new Random();
        for (int i = 0; i < 100; i++) {
            // set synchornized on variable data
            synchronized (data) {
                // this thread will set random number to x
                int random_num = rand.nextInt(10) + 1;
                data.setX(random_num);
                System.out.println("T1> " + data.getX());

                data.notifyAll(); // notify all the threat that synchornized on variabl data

                // thread pause and wait until beign notify
                try {
                    System.out.println("Thread 1 wait");
                    data.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("Thread 1 awake and run");
            }
        }
    }
    
}