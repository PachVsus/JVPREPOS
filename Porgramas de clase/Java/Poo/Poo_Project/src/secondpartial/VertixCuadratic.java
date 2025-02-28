package secondpartial;

    /*  VertexCuadratic se representa con y = a(x - h)^2 + k 
     donde a = coeficiente principal que determanina la apertura de la parabola
     h y k = coordenadas del vertice de la parabola, se calculara la interseccion con el eje x (cuando y = 0)

     Estructura

     VertixCuadratic
        - a.h.k: double
        - hasSolution: boolean
        - roots: double[]

     VertixCuadratic(double a, double h, double k)
     + set(double a, double h, double k): void
     + getHasSolution(): boolean
     + getRoots(): double[]
     - solve()
     + toString(): String
     + equal(): boolean

    */

public class VertixCuadratic {
    private double a, h, k;
    private boolean hasSolution
    private double[] roots;
}

public VertixCuadratic(double a, double h, double k) {
    this.a = a;
    this.h = h;
    this.k = k;
    solve();
}

public void set(double a, double h, double k) {
    this.a = a;
    this.h = h;
    this.k = k;
    solve();
}

public boolean getHasSolution() {
    return hasSolution;
}

public double[] getRoots() {
    return roots;
}

private void solve() {
    double d = Math.pow(h, 2) - 4 * a * k;
    if (d < 0) {
        hasSolution = false;
        roots = new double[0];
    } else if (d == 0) {
        hasSolution = true;
        roots = new double[1];
        roots[0] = -h / (2 * a);
    } else {
        hasSolution = true;
        roots = new double[2];
        roots[0] = (-h + Math.sqrt(d)) / (2 * a);
        roots[1] = (-h - Math.sqrt(d)) / (2 * a);
    }
}

@Override
public String toString() {
    return "y = " + a + "(x - " + h + ")^2 + " + k;
}
