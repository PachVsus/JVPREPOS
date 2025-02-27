package gameapi.entities;

public class Player extends Entity {
    private String name;

    public Player(String name) {
        this.name = name;
    }

    public void update() {
        System.out.println("👾 " + name + " se está moviendo...");
    }
}
