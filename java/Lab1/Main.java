class Employee
{
    int employeeID;
    String employeeName;
    String employeeDept;
    String employeeDesignation;
    float employeeSalary;


    void setDetails(int eID, String eName, String eDept, String eDesig, float eSalary)
    {
        employeeID = eID;
        employeeName = eName;
        employeeDept = eDept;
        employeeDesignation = eDesig;
        employeeSalary = eSalary;
    }


    float getSalary()
    {
        return employeeSalary;
    }


    void displayDetails()
    {
        System.out.println("Employee ID: " + employeeID);
        System.out.println("Employee Name: " + employeeName);
        System.out.println("Employee Department: " + employeeDept);
        System.out.println("Employee Designation: " + employeeDesignation);
        System.out.println("Employee salary: " + employeeSalary);
    }
}


public class Main
{
    public static void main(String args[])
    {
        Employee e1 = new Employee();
        Employee e2 = new Employee();


        e1.setDetails(100,"Gojo","IT","SD2",3000000);
        e2.setDetails(101,"Geto","IT","SD1",1000000);


        e1.displayDetails();
        e2.displayDetails();


        System.out.println("Salary of Employee 1: " + e1.getSalary());
    }
}