package student; // declare the package name is student cause it is in path /student/student.java

public class student extends Person{
    // poperties of student
    String class_name; 
    int id;
    // private poperty
    private String password;
    
    // Constructor of Student
    public student() {
        super(); // call parent Constructor
        System.out.println("New student was created");
    } // defaul constructor
    public student(String name, String class_name, int age, int id) {
        super(name, age); // call parent constructor
        this.class_name = class_name;
        this.id = id;
        System.out.println("New student was created");
    }

    // @Override
    public void display() {
        System.out.println("==========Student============");
        // System.out.println("Name: " + name);
        // System.out.println("Age: " + age);
        super.display(); // call dispaly class of parent is Person.display()
        System.out.println("ID: " + id);
        System.out.println("Class: " + class_name);
    }

    // getter and setter for password poperty
    public void setPassword(String pass) {
        this.password = pass;
    }

    public String getPassword() {
        return password;
    }

    public boolean isEqual(student another) { // this fucntion use to compare 2 class
        return 
            (this.name.equals(another.name)) && 
            (this.class_name.equals(another.class_name)) &&
            (this.id == another.id) && (this.age == another.age);
    }

    public static void main(String[] args) {
        student std1 = new student();
        student std2 = new student("Long", "12CL", 20, 14472);
    
        System.out.println("============Student 1=============");
        std1.name = "bla bla";
        std1.class_name = "ble ble";
        std1.display();
        System.out.println();

        System.out.println("============Student 2=============");
        std2.name = "Phan Nguyen Long"; // cause name is public ==> easily change it
        std2.display();

        String is_equal_msg = std1.isEqual(std2) ? "Equal" : "Not Equal";
        System.out.println("\n2 student are " + is_equal_msg);
        
        System.gc(); // gc means "Garbage Collector" will clean up data which is not in the scope
    }
}