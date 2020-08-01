package synchornization;

import java.util.Random;

/**
 * This is use for example of synchornizied method
 */
public class CustomThread implements Runnable {
    SharedData data;
    String thread_name;

    public CustomThread(SharedData data, String name) {
        this.data = data;
        this.thread_name = name;
    }

    @Override
    public void run() {
        Random num = new Random();
        for (int i = 0; i < 3; i++) {
            data.add(num.nextInt(5), thread_name);
        }
    }
}