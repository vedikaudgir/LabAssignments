import java.util.*;

interface Approvable {
    void approve(PermissionRequest request);
}

abstract class Person {
    protected String name;
    protected int id;

    public Person(String name, int id) {
        this.name = name;
        this.id = id;
    }

    abstract void display();
}

class Student extends Person {
    private String course;

    public Student(String name, int id, String course) {
        super(name, id);
        this.course = course;
    }

    public void display() {
        System.out.println("Student: " + name + " | ID: " + id + " | Course: " + course);
    }
}

class PermissionRequest {
    private static int counter = 1; 
    private final int requestId;
    private Student student;
    private String reason;
    private boolean approved;

    public PermissionRequest(Student student, String reason) {
        this.requestId = counter++;
        this.student = student;
        this.reason = reason;
        this.approved = false;
    }

    public void setApproved(boolean status) {
        this.approved = status;
    }

    public boolean isApproved() {
        return approved;
    }

    public int getRequestId() {
        return requestId;
    }

    public String getReason() {
        return reason;
    }

    public Student getStudent() {
        return student;
    }
}

abstract class Authority extends Person implements Approvable {

    public Authority(String name, int id) {
        super(name, id);
    }

    public void display() {
        System.out.println("Authority: " + name);
    }
}

class Warden extends Authority {

    public Warden(String name, int id) {
        super(name, id);
    }

    public void approve(PermissionRequest request) {
        System.out.println("Warden approved request " + request.getRequestId());
    }
}

class ChiefWarden extends Authority {

    public ChiefWarden(String name, int id) {
        super(name, id);
    }

    public void approve(PermissionRequest request) {
        System.out.println("Chief Warden approved request " + request.getRequestId());
    }
}

class Security extends Authority {

    public Security(String name, int id) {
        super(name, id);
    }

    public void approve(PermissionRequest request) {
        System.out.println("Security approved request " + request.getRequestId());
        request.setApproved(true);
    }
}

public class PermissionSystem {

    public static void main(String[] args) {

        Student s1 = new Student("Vedika", 101, "IT");

        PermissionRequest req = new PermissionRequest(s1, "Going Home");

        Authority warden = new Warden("Mr. Sharma", 1);
        Authority chief = new ChiefWarden("Mrs. Rao", 2);
        Authority security = new Security("Guard Singh", 3);

        s1.display();

        warden.approve(req);
        chief.approve(req);
        security.approve(req);

        if (req.isApproved()) {
            System.out.println("Request " + req.getRequestId() + " is FULLY APPROVED ✅");
        } 
        else {
            System.out.println("Request Pending ❌");
        }
    }
}