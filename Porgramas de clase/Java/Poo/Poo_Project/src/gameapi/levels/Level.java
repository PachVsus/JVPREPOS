package gameapi.levels;

public class Level {
    private String name;

    public Level(String name) {
        this.name = name;
    }

    public void load() {
        System.out.println("🌍 Cargando " + name + "...");
    }
}
