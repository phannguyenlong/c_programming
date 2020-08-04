package chap7;

public class CheckThread implements Runnable {
    Counter counter;
    String name;

    public CheckThread(Counter counter, String name) {
        this.counter = counter;
        this.name = name;
    }

    @Override
    public void run() {
        for (int i = 0; i < 100; i++) {
            int num = counter.getNum() ;
            System.out.println(name + "> " + num);
            if (num % 2 == 0)
                counter.setNum(num -  1);
            else
                counter.setNum(num + 1);
        }
        System.out.println(name + " stop");
    }

}