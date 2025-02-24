package shape2d;

public class Estudiante {
    private String nombre;
    private int edad;
    private double calificacion;

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public double getCalificacion() {
        return calificacion;
    }

    public void setCalificacion(double calificacion) {
        this.calificacion = calificacion;
    }

    // constructor que recibe los valores de los atributos con gettes y setters y metodo mostrardatos()
    public Estudiante(String nombre, int edad, double calificacion) {
        this.nombre = nombre;
        this.edad = edad;
        this.calificacion = calificacion;
    }

    public String getDatos() {
        return "Nombre: " + nombre + "\nEdad: " + edad + "\nCalificacion: " + calificacion;
    }

    // metodo de checar si aprobo o no aprobo
    public String checarCalificacion() {
        if (calificacion >= 6) {
            return "Aprobado";
        } else {
            return "No aprobado";
        }
    }

    public static void main(String[] args) {
        Estudiante estudiante = new Estudiante("Juan", 20, 8.5);
        System.out.println(estudiante.getDatos());
        System.out.println(estudiante.checarCalificacion());
    }
}
