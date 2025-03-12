package example;

public class Superman extends Man implements Flyable {
    private int power = 20;
    private double height = 0;

    public void runFast() {
        System.out.println("Superman is running fast...");
    }

    public int getPower() {
        return power;
    }

    public void losePower(int kryptonite) {
        if (kryptonite >= 1) {
            System.out.println("Superman has weakened!");
            power = 0;
        }
    }

    @Override
    public void rise() {
        if (height < MAX_HEIGHT) {
            height += 15;
            System.out.println("Superman is rising. Current height: " + height);
        }
    }

    @Override
    public void descend() {
        if (height > 0) {
            height -= 15;
            System.out.println("Superman is descending. Current height: " + height);
        }
    }

    @Override
    public double getHeight() {
        return height;
    }

    public static void main(String[] args) {
        Superman superman = new Superman();
        superman.losePower(1);
        System.out.println("Current power: " + superman.getPower());
        superman.rise();
    }
}
