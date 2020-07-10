package java_interface;

/**
 * Class that implement from interface Animal
 */
public class Cat implements Animal {
    //@Overide
    public void getName() {
        System.out.println("Cat");
    }

    //@Overide
    public void getSound() {
        System.out.println("Meow Meow");
    }
    
    //@Overide
    public void move() {
        System.out.println("Run like a cat");
    }
}