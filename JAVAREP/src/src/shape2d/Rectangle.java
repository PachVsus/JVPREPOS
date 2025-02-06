package src.shape2d;

public class Rectangle {
    public double base = 1;
    public double height = 1;

    // Constructor
    public Rectangle() {
    }

    public Rectangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    public double area() {
        return base * height;
    }

    public double perimeter() {
        return 2 * (base + height);
    }

    public void print() {
        System.out.println("Rectangle");
        System.out.println("Base: " + base);
        System.out.println("Height: " + height);
        System.out.println("Area: " + area());
        System.out.println("Perimeter: " + perimeter());
    }
}
