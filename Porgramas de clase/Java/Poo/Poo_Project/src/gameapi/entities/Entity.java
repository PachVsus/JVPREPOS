package gameapi.entities;
import java.util.UUID;

public class Entity {
    private String id;

    public Entity() {
        this.id = UUID.randomUUID().toString();
    }

    public String getId() {
        return id;
    }
}
