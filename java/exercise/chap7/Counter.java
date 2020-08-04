package chap7;

public class Counter {
    private int num;

    public Counter(int num) {
        this.num = num;
    }

    public synchronized int getNum() {
        return num;
    }

    public synchronized void setNum(int num) {
        this.num = num;
    }
    
    public synchronized void increasement() {
        setNum(getNum() + 1);
    }

    public synchronized void decreasement() {
        setNum(getNum() - 1);
    }

}