package example;

public class Bird extends Animal implements Flyable {
    private double height = 0;

    @Override
    public void rise() {
        if (height < MAX_HEIGHT) {
            height += 10;
            System.out.println("Bird is rising. Current height: " + height);
        }
    }

    @Override
    public void descend() {
        if (height > 0) {
            height -= 10;
            System.out.println("Bird is descending. Current height: " + height);
        }
    }

    @Override
    public double getHeight() {
        return height;
    }
}
