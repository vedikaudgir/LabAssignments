class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void displayPerson() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}
class Student extends Person {
    String course;
    int rollNo;

    Student(String name, int age, String course, int rollNo) {
        super(name, age); // calling base class constructor
        this.course = course;
        this.rollNo = rollNo;
    }

    void displayStudent() {
        displayPerson();
        System.out.println("Course: " + course);
        System.out.println("Roll No: " + rollNo);
    }
}

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student("Vedika", 20, "Computer Science", 101);

        s1.displayStudent();
    }
}