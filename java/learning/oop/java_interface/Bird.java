package java_interface;

/**
 * Class that implement from interface Animal
 */
public class Bird implements Animal {
    //@Overide
    public void getName() {
        System.out.println("Bird");
    }

    //@Overide
    public void getSound() {
        System.out.println("Chip Chip");
    }
    
    //@Overide
    public void move() {
        System.out.println("Fly like a bird");
    }
}