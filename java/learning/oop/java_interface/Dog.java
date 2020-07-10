package java_interface;

/**
 * Class that implement from interface Animal
 */
public class Dog implements Animal{
    //@Overide
    public void getName() {
        System.out.println("Dog");
    }

    //@Overide
    public void getSound() {
        System.out.println("Woof Woof");
    }
    
    //@Overide
    public void move() {
        System.out.println("Walk like a dog");
    }
}