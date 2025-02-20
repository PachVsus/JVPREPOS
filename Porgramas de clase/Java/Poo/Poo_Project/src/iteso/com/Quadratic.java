package iteso.com;

public class Quadratic {
    private int a,b,c;
    private boolean hasSolution;
    private double positiveX;
    private double negativeX;
    public Quadratic() {}

    public Quadratic(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
        solve();
    }

    public void set(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
        solve();   
    }

    private void solve() {
        double d;
        d = this.b*this.b - 4*this.a*this.c;
        if (d >= 0) {
            this.positiveX = (-this.b + Math.sqrt(d))/(2*this.a);
            this.negativeX = (-this.b - Math.sqrt(d))/(2*this.a);
            this.hasSolution = true;
        } else {
            this.hasSolution = false;
        }
    }

    @Override public String toString() {
        if (hasSolution) {
            return "X1 = " + this.positiveX + " X2 = " + this.negativeX;
        } else {
            return "No tiene solucion";
        }
    }
    public static void main(String[] args) {
        Quadratic q = new Quadratic(2, 5, 2);
        System.out.println(q);
        q.set(2, 5, 2);
        System.out.println(q);
        q.set(2, 5, 2);
        System.out.println(q);
    }
}