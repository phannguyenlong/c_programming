import java.lang.Thread;

public class SimpleThread implements Runnable {
    String name;

    public SimpleThread(String name) {
        this.name = name;
    }

    @Override
    public void run() { // Overide tis to define what to do in thread
        for (int i = 0; i < 100; i++) {
            try {
                if (Thread.interrupted()) {
                    System.out.println("break");
                }
                // break; // if threat is interupted, break and stop the threat
                System.out.print(name + "\t");
                Thread.sleep(100);
            } catch (InterruptedException e) {
                // e.printStackTrace();
                System.out.println("Thread 2 is interupted");
                break; // stop the for loop when interrupt appear
            } // wait 100ms then execute next
        } 
    }

    public static void main(final String[] args) {
        System.out.println("Threat Main Start"); // run in thread main

        // Thread 1 (1st way to declare thread)
        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 100; i++) {
                    try {
                        System.out.print("Thread 1" + "\t");
                        Thread.sleep(10);
                    } catch (InterruptedException e) { // must have try catch
                        e.printStackTrace();
                    } // wait 10ms than run to next cod
                }
            }
        });

        // Thread 2 (2nd way to declare a thread - Implement the interface Runable)
        Thread t2 = new Thread(new SimpleThread("Thread 2"));

        // Thread 3 (3rd way to declare a thread - Using lamda without creat variable)
        new Thread(() -> {
            for (int i = 0; i < 100; i++)
                try {
                    System.out.print("Thread 3" + "\t");
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } // wait 1000ms than execute
        }).start();

        // Run
        t1.start();
        t2.start();

        // Join Threat 1 (t1) to Thread main
        // ==> "End of threat main" only appear appear when t1 finnish
        try {
            System.out.println("Join t1 into main");
            t1.join();
            System.out.println("T1 finnished, then countinue run main");
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        t2.interrupt();

        System.out.println("End of thread main");
    }
}