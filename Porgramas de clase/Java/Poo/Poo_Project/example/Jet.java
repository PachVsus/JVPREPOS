package example;

public class Jet extends Vehicle implements Flyable {
    private double height = 0; // Atributo para almacenar la altura del jet

    @Override
    public void rise() {
        if (height < MAX_HEIGHT) {
            height += 20; // Los jets ascienden más rápido
            System.out.println("Jet is rising. Current height: " + height);
        }
    }

    @Override
    public void descend() {
        if (height > 0) {
            height -= 20; // Los jets también descienden más rápido
            System.out.println("Jet is descending. Current height: " + height);
        }
    }

    @Override
    public double getHeight() {
        return height;
    }

    // Sobreescribiendo métodos de Vehicle para ajustar la velocidad
    @Override
    public void speedUp() {
        speed += 50; // Los jets aceleran más rápido
        System.out.println("Jet is speeding up. Current speed: " + speed);
    }

    @Override
    public void slowDown() {
        if (speed > 0) {
            speed -= 50;
            System.out.println("Jet is slowing down. Current speed: " + speed);
        } else {
            System.out.println("Jet is already stopped.");
        }
    }
}
