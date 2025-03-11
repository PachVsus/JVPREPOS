package example;

interface Flyable {
    static int MAX_HEIGHT = 100;

    public default void rise() {

    }
    public default void descend() {

    }

    public default double getHeight(double Height) {
        return Height = MAX_HEIGHT;
    }
}
