package synchornization;

public class Main {
    public static void main(String[] args) {
        SharedData sharedData = new SharedData();
        System.out.println("System start");

        Thread t1 = new Thread(new CustomThread(sharedData, "Thread 1"));
        Thread t2 = new Thread(new CustomThread(sharedData, "Thread 2"));
        Thread t3 = new Thread(new CustomThread(sharedData, "Thread 3"));
        Thread t4 = new Thread(new CustomThread(sharedData, "Thread 4"));
        
        t1.start();
        t2.start();
        t3.start();
        t4.start();

        System.out.println("System end");
    }
}