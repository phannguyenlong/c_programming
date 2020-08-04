package chap7;

public class CorrencyProb {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter(3);
        Thread t1 = new Thread(new CheckThread(counter, "Thread 1"));
        Thread t2 = new Thread(new CheckThread(counter, "Thread 2"));
        Thread t3 = new Thread(new CheckThread(counter, "Thread 3"));

        t1.start();
        t2.start();
        t3.start();

        Thread.sleep(1000);

        System.out.println("Counter is: " + counter.getNum());
    }
}