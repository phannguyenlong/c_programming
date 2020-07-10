package student;

public class Person {
    public String name;
    public int age;

    // constructor
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
}