public class CALCULADORA {
    // Attributes
    private double num1 = 0;
    private double num2 = 0;
    // Constructor
    public CALCULADORA() {
        super();
    }
    public double getNum1() {
        return num1;
    }
    public void setNum1(double num1) {
        this.num1 = num1;
    }
    public double getNum2() {
        return num2;
    }
    public void setNum2(double num2) {
        this.num2 = num2;
    }
    public CALCULADORA(double num1, double num2) {
        this.num1 = num1;
        this.num2 = num2;
    }
    // Method to display details
    public void displayInfo() {
        System.out.println("Num1: " + num1);
        System.out.println("Num2: " + num2);
    }
    // Main method to test the class
    public static void main(String[] args) {
        // Creating an object of the Person class
        CALCULADORA calc1 = new CALCULADORA();
        CALCULADORA calc2 = new CALCULADORA(5, 10);
        // Calling the method to display information
        calc1.displayInfo();
        calc2.displayInfo();
    }

    public double sum() {
        return num1 + num2;
    }

    public double subtraction() {
        return num1 - num2;
    }

    public double multiplication() {
        return num1 * num2;
    }

    public double division() {
        return num1 / num2;
    }

    public void print() {
        System.out.println("Calculator");
        System.out.println("Num1: " + num1);
        System.out.println("Num2: " + num2);
        System.out.println("Sum: " + sum());
        System.out.println("Subtraction: " + subtraction());
        System.out.println("Multiplication: " + multiplication());
        System.out.println("Division: " + division());
    }
}

// MAIN CLASS


