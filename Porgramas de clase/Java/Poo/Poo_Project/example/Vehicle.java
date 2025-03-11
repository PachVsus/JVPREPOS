package example;

public class Vehicle {
    protected double fuel;
    protected double speed;

    public void speedUp() {
        // implementation here
    }
    
    public void slowDown() {
        // implementation here
    }
    
    public double getSpeed() {
        return speed;
    }
    
    public void loadFuel(double fuel) {
        this.fuel += fuel;
    }
}
