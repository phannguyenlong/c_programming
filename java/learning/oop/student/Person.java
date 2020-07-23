package student;

public class Person {
    public String name;
    public int age;

    /**
     * This is docuemntation for constructor of class Person.
     * Person class the base class student and CsStudent.
     * @param name: paremeter indicate passing name of person
     * @param age: paremter indicate passing age of person
     */
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
        System.out.println("New Person created");
    }

    public Person() { // defaul contructor
        System.out.println("New Person created");
    }

    public void display() {
        System.out.println("==========Person============");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }

    public void sortDisplay() {
        // example of add variable to a string
        System.out.println(String.format("Student {name: %s; age: %d}", name, age));
    }
    
}