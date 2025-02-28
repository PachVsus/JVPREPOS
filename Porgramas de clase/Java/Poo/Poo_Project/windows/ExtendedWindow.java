package windows;

public class ExtendedWindow extends BasicWindow {
    public final static int MAX_X = 1200, MAX_Y = 1080;

    protected String title;

    public ExtendedWindow(String title) {
        this.title = title;
    }
    public ExtendedWindow(int x, int y, int w, int h, String title) {
        super(x, y, w, h);
        this.title = title;
    }

    @Override
    public void display() {
        super.display();
        System.out.println(title);
        System.out.println(super.x + " " + super.y + " " + super.width + " " + super.height + " " + title);
    }

    public void move(int dx, int dy) {
        // x, y son los atributos de la clase BasicWindow
        // Son accesibles en ExtendedWidnwos por ser protegidos
        x += dx;
        y += dy;
        if (x > MAX_X) {
            x = MAX_X;
        }
        if (y > MAX_Y) {
            y = MAX_Y;
        }
    }

    public static void main(String[] args) {
        ExtendedWindow w1 = new ExtendedWindow("Window 1");
        w1.display();
        ExtendedWindow w2 = new ExtendedWindow(10, 20, 30, 40, "Window 2");
        w2.display();
        w2.resize(50, 60);
    }
    
}
