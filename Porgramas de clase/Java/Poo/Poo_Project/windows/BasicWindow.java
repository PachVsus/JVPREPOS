package windows;

public class BasicWindow {
    // atributos
    protected final static int MIN_WIDTH = 10;
    protected final static int MIN_HEIGHT = 15;
    protected int x, y, width, height;

    public BasicWindow() {

    }

    public BasicWindow(int x, int y, int w, int h) {
        this.x = x;
        this.y = y;
        this.width = w;
        this.height = h;
    }

    public void display() {
        System.out.println(this.x + " " + this.y + " " + this.width + " " + this.height);
    }

    public void resize(int dw, int dh) {
        this.width = dw;
        this.height = dh;
    }
}

