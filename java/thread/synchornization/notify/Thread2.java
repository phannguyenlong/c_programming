package synchornization.notify;

import synchornization.SharedData;

public class Thread2 implements Runnable {
    private SharedData data;

    public Thread2(SharedData data) {
        this.data = data;
    }

    @Override
    public void run() {
        for (int i = 0; i < 100; i++) {
            synchronized (data) { // synchornized on variable data
                // wait until being notify than continue
                try {
                    System.out.println("Thread 2 waiting");
                    data.wait();

                    System.out.println("Thread 2 awake and run [" + i + "]");
                    System.out.println("T2> " + data.getX() * data.getX()); // square X

                    data.notifyAll(); // wake other thread synchornized on variable data awake
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
        System.out.println("Thread 2 finish...");
    }

}