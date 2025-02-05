package Poo.src;

// Define the person class
public class person {
    // Define the attributes of the class
    private final String name;
    private final int age;

    // Define the constructor
    public person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // methods to display details
    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);

    }

    // Define the main method
    public static void main(String[] args) {
        // Create an object of the class
        person p1 = new person("Jesus", 21);
        // Call the display method
        p1.display();
    }


    
}
