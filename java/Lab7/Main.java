import java.util.Scanner;

class Student {
    protected String name;
    protected int rollNo;

    public void setStudentDetails(String name, int rollNo) {
        this.name = name;
        this.rollNo = rollNo;
    }

    public void displayStudentDetails() {
        System.out.println("Student Name : " + name);
        System.out.println("Roll Number  : " + rollNo);
    }
}

class Test extends Student {
    protected int theoryMarks;
    protected int practicalMarks;

    public void setTestMarks(int theoryMarks, int practicalMarks) {
        this.theoryMarks = theoryMarks;
        this.practicalMarks = practicalMarks;
    }

    public void displayTestMarks() {
        System.out.println("Theory Marks   : " + theoryMarks);
        System.out.println("Practical Marks: " + practicalMarks);
    }
}

interface Sports {
    int sportsScore = 10;

    void displaySportsScore();
}

class Result extends Test implements Sports {
    private int totalMarks;

    public void calculateTotal() {
        totalMarks = theoryMarks + practicalMarks + sportsScore;
    }

    @Override
    public void displaySportsScore() {
        System.out.println("Sports Score   : " + sportsScore);
    }

    public void displayResult() {
        displayStudentDetails();
        displayTestMarks();
        displaySportsScore();
        calculateTotal();
        System.out.println("Total Marks    : " + totalMarks);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Result result = new Result();

        System.out.print("Enter student name: ");
        String name = scanner.nextLine();

        System.out.print("Enter roll number: ");
        int rollNo = scanner.nextInt();

        System.out.print("Enter theory marks : ");
        int theory = scanner.nextInt();

        System.out.print("Enter practical marks: ");
        int practical = scanner.nextInt();

        result.setStudentDetails(name, rollNo);
        result.setTestMarks(theory, practical);

        System.out.println("\n--- Student Result ---");
        result.displayResult();

        scanner.close();
    }
}
