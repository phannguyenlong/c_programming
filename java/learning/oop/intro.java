import student.student; // import packet from the link student/student.java
import student.Person;
import student.CsStudent;
import java_interface.*; // import all packet in java_interface folder

class Intro {
    public static void staticMethoid(String name) {
        System.out.println(String.format("Your name is %s", name));
        System.out.println("Static method run without creating any object");
        System.out.println("Static only play with static");
    }

    public static void main(String[] args) {
        staticMethoid("Long"); // cause main is static ==> it can call staticMethod
        Person person = new Person("Long", 20); // create new Person

        Person student = new student("Long", "12CL", 20, 14472);// initalize object student as base class is Person

        Person cs_student = new CsStudent("Long", "12CL", 20, 14472, "JAVA"); // initalize object CsStudent as base clas Person

        Person[] arr = { person, student, cs_student }; // cause they share same base class Person ==> can be same array
        
        for (Person index : arr) { // another way to write for loop
            index.display();
            System.out.println("");
        }

        System.out.println("==============Interface session============");
        Animal[] animal_list = { new Dog(), new Cat(), new Bird() };

        for (Animal index : animal_list) {
            index.getName();
            index.getSound();
            index.move();
            System.out.println("");
        }

        staticMethoid("Long"); // cause main is static ==> it can call staticMethod
    }
}