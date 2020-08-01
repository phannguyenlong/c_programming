package synchornization;

public class SharedData {
    private int x = 0;

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public synchronized void add(int plus, String name) {
        x += plus;
        System.out.println("\nX is: " + x);
        System.out.print("============" + name + "===========");
        for (int i = 0; i < x; i++) {
            System.out.print(i + " ");
        }
    }
}