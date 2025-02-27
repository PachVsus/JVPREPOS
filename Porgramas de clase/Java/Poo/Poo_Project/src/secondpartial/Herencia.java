package secondpartial;

import iteso.com.Person;

public class Herencia {
    private final String name; //atributo
    public Herencia(){    // constructor
        this.name = "by default";
    }
    public Herencia(String nameX){ // constructor
        this.name = nameX;
    }
    // metodos
    public class Student extends Person{
        private final int studentID;
        public Student(String nameX, int studentIDX){
            super(nameX, studentIDX, 0); // Assuming the Person constructor takes (String, int, int)
            this.studentID = studentIDX;
        }
        public void print(){
            System.out.println("Name: " + name + " ID: " + studentID);
        }
    }
    public class Employee extends Person{
        private final int employeeID;
        public Employee(String nameX, int employeeIDX){
            super(nameX, employeeIDX, 0); // Assuming the Person constructor takes (String, int, int)
            this.employeeID = employeeIDX;
        }
        public void print(){
            System.out.println("Name: " + name + " ID: " + employeeID);
        }
    }
    public class Teacher extends Person{
        private final int teacherID;
        public Teacher(String nameX, int teacherIDX){
            super(nameX, teacherIDX, 0); // Assuming the Person constructor takes (String, int, int)
            this.teacherID = teacherIDX;
        }
        public void print(){
            System.out.println("Name: " + name + " ID: " + teacherID);
        }
    }
    public static void main(String[] args){
        Herencia herencia = new Herencia();
        Herencia.Student student = herencia.new Student("Juan", 123);
        Herencia.Employee employee = herencia.new Employee("Pedro", 456);
        Herencia.Teacher teacher = herencia.new Teacher("Maria", 789);
        student.print();
        employee.print();
        teacher.print();
    }
    public void print(){
        System.out.println("Name: " + name);
    }

}
