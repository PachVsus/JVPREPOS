public class PERSON {
    // Attributes
    private String name="XXX";
    private int age=10;
    // Constructor
    public PERSON() {
    super();
    }
    public String getName() {
    return name;
    }
    public void setName(String name) {
    this.name = name;
    }
    public int getAge() {
    return age;
    }
    public void setAge(int age) {
    this.age = age;
    }
    public PERSON(String nombre) {
    this.name = nombre;
    this.age = 10;
    }
    // Method to display details
    public void displayInfo() {
    System.out.println("Name: " + name);
    System.out.println("Age: " + age);
    }
    // Main method to test the class
    public static void main(String[] args) {
    // Creating an object of the Person class
    PERSON person1 = new PERSON();
    PERSON person2 = new PERSON("Diego");
    // Calling the method to display information
    person1.displayInfo();
    person2.displayInfo();
    }
}
