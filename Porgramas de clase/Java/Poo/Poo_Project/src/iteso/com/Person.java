package iteso.com;

public class Person {
    private final String name;
    private final int age;
    protected int noIMSS;

    public Person() {
        this.name = " ";
        this.age = 10;
        this.noIMSS = 00;
    }
    public Person(String name, int age, int noIMSS) {
        this.name = name;
        this.age = age;
        this.noIMSS = noIMSS;
    }

    public static void main(String[] args) {
        Person p = new Person("Juan", 20, 1234);
        System.out.println("Nombre: " + p.name);
        System.out.println("Edad: " + p.age);
        System.out.println("No. IMSS: " + p.noIMSS);
    }
}

