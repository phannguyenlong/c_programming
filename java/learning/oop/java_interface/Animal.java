package java_interface;

/**
 * This is example interface Animal
 */
public interface Animal {
    /**
     * Abstract function print the name of animal
     */
    public abstract void getName();

    /**
     * Abstract function print sound of animal
     */
    void getSound(); // defaul is alread public astract ==> we don't need to declare anymore
    
    /**
     * Abstract function print wave of moving of animal
     */
    void move();
    
}