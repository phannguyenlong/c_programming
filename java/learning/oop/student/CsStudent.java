package student;

// import student.student;

public class CsStudent extends student { // inherit from super class in student in file student.java
    private String subject;
    
    public CsStudent(String subject) {
        super("long", "12CL", 10, 14472); // Passing argument to parent constructor

        this.subject = subject;
        System.out.println("New CS Stutdent created");
    }

    public CsStudent(String name, String class_name, int age, int id, String subject) {
        super(name, class_name, age, id);

        this.subject = subject;
        System.out.println("New CS Stutdent created");
    }

    public String getSubject() {
        return subject;
    }

    // @Override
    public void display() { // overiding display function in base class
        System.out.println("==========CS Student============");
        // System.out.println("Name: " + name);
        // System.out.println("Age: " + age);
        // System.out.println("ID: " + id);
        // System.out.println("Class: " + class_name);
        super.display(); // call display class of parent student.display()
        System.out.println("Subject: " + subject);
    }

    public static void main(String[] args) {
        CsStudent student = new CsStudent("subject");
        System.out.println("\n" + student.getSubject() + "\n");
        student.display();
    }

}