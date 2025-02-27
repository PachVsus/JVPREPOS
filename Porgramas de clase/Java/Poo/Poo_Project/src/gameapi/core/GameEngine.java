package gameapi.core;

import gameapi.graphics.Renderer;
import gameapi.input.InputManager;
import gameapi.levels.Level;
import gameapi.entities.Player;

public class GameEngine {
    private boolean running;
    private Renderer renderer;
    private InputManager input;
    private Player player;
    private Level level;

    public GameEngine() {
        this.running = false;
        this.renderer = new Renderer();
        this.input = new InputManager();
        this.player = new Player("Jugador 1");
        this.level = new Level("Nivel 1");
    }

    // Método para iniciar el juego
    public void start() {
        running = true;
        System.out.println("🚀 Juego iniciado...");
        level.load();
        gameLoop();
    }

    // Bucle principal del juego
    private void gameLoop() {
        final int FPS = 60;
        final long OPTIMAL_TIME = 1000000000 / FPS; // 16ms por frame

        while (running) {
            long startTime = System.nanoTime();

            update(); // Lógica del juego
            render(); // Renderizar gráficos

            long elapsedTime = System.nanoTime() - startTime;
            long sleepTime = (OPTIMAL_TIME - elapsedTime) / 1000000; // Convertir a milisegundos
            if (sleepTime > 0) {
                try {
                    Thread.sleep(sleepTime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    // Método para actualizar la lógica del juego
    private void update() {
        System.out.println("🔄 Actualizando el juego...");
        player.update(); // Actualiza el jugador
    }

    // Método para renderizar los gráficos
    private void render() {
        renderer.render(); // Llamar al sistema de renderizado
    }

    // Método para detener el juego
    public void stop() {
        running = false;
        System.out.println("🛑 Juego detenido.");
    }
}
