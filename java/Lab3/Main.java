import java.util.Scanner;


class Student {
    private int rollNumber;
    private String name;
    private String course;
    private int semester;
    private double marks;


    static int studentCount = 0;


    public Student(int rollNumber, String name, String course, int semester, double marks) {
        this.rollNumber = rollNumber;
        this.name = name;
        this.course = course;
        this.semester = semester;
        this.marks = marks;


        studentCount++;
    }


    public int getRollNumber() {
        return rollNumber;
    }


    public double getMarks() {
        return marks;
    }


    public void setMarks(double marks) {
        this.marks = marks;
    }


    public void displayStudent() {
        System.out.println("Roll No: " + rollNumber);
        System.out.println("Name: " + name);
        System.out.println("Course: " + course);
        System.out.println("Semester: " + semester);
        System.out.println("Marks: " + marks);
        System.out.println("Grade: " + calculateGrade());
    }


    public void showCompleteInfo() {
        System.out.println("\nStudent Information: \n");
        displayStudent();
    }


    public String calculateGrade() {
        if (marks >= 90) return "A";
        else if (marks >= 75) return "B";
        else if (marks >= 60) return "C";
        else if (marks >= 50) return "D";
        else return "F";
    }


    static class Department {
        String deptName;
        String deptCode;


        Department(String deptName, String deptCode) {
            this.deptName = deptName;
            this.deptCode = deptCode;
        }


        void displayDepartment() {
            System.out.println("\nDepartment Name: " + deptName);
            System.out.println("Department Code: " + deptCode);
        }
    }
}


public class StudentManagement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        Student[] students = new Student[3];


        students[0] = new Student(1, "gojo", "BCA", 3, 82);
        students[1] = new Student(2, "geto", "BSc", 2, 91);
        students[2] = new Student(3, "yuji", "BTech", 5, 67);


        System.out.println("All Student Details:");
        for (Student s : students) {
            s.showCompleteInfo();
        }


        System.out.println("\nTotal Students Created: " + Student.studentCount);


        Student.Department dept = new Student.Department("Computer Science", "CS101");
        dept.displayDepartment();


        System.out.print("\nEnter roll number to search: ");
        int roll = sc.nextInt();
        boolean found = false;


        for (Student s : students) {
            if (s.getRollNumber() == roll) {
                System.out.println("Student Found:");
                s.showCompleteInfo();
                found = true;


                System.out.print("Enter new marks: ");
                double newMarks = sc.nextDouble();
                s.setMarks(newMarks);


                System.out.println("Updated Details:");
                s.showCompleteInfo();
                break;
            }
        }


        if (!found) {
            System.out.println("Student not found.");
        }


        sc.close();
    }
}

