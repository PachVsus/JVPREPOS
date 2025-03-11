package example;

public class Superman extends Man implements Flyable{
    private int power = 20;

    public void runfast() {
        
    }
    public int getPower() {
        return power;
    }

    public void loosepower(int krypto) {
        if (krypto >= 1) {
            System.out.println("You've become weakened.");
            power = 0;
        }
    }

}
