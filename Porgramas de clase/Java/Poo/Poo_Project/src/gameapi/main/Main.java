package gameapi.main;

import gameapi.core.GameEngine;

public class Main {
    public static void main(String[] args) {
        // Iniciar el motor del juego
        GameEngine engine = new GameEngine();
        engine.start();
    }
}
