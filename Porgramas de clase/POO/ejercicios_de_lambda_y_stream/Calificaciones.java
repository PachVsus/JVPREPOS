package ejercicios_de_lambda_y_stream;

import java.util.List;
import java.util.stream.Collectors;

public class Calificaciones {

    // aqui se puede agregar un comentario para describir la clase
    // Esta clase contiene métodos para filtrar y calcular promedios de calificaciones
public static void main(String[] args) {
    List<Integer> calificaciones = List.of(5, 7, 8, 4, 6, 9, 3); // Lista de calificaciones
    System.out.println("Calificaciones: " + calificaciones);

    System.out.println("Calificaciones aprobadas: " + calificaciones.stream().filter(calificacion -> calificacion >= 6).collect(Collectors.toList()));
    System.out.println("Calificaciones reprobadas: " + calificaciones.stream().filter(calificacion -> calificacion < 6).collect(Collectors.toList()));
    System.out.println("Calificaciones reprobadas: " + calificaciones.stream().filter(calificacion -> calificacion < 6).toList());

    System.out.println("Promedio de calificaciones: " + calificaciones.stream().mapToInt(calificacion -> calificacion).average().orElse(0));
    System.err.println("Calificacion mas alta: " + calificaciones.stream().mapToInt(calificacion -> calificacion).max().orElse(0));
    System.err.println("Calificacion mas baja: " + calificaciones.stream().mapToInt(calificacion -> calificacion).min().orElse(0));
}

    public static void printCalificaciones(List<Integer> calificaciones) {
        System.out.println("Calificaciones: " + calificaciones);
    }

    public static void printCalificacionesAprobadas(List<Integer> calificaciones) {
        System.out.println("Calificaciones aprobadas: " + calificaciones.stream().filter(calificacion -> calificacion >= 6).toList());
    }

    public static void printCalificacionesReprobadas(List<Integer> calificaciones) {
        System.out.println("Calificaciones reprobadas: " + calificaciones.stream().filter(calificacion -> calificacion < 6).toList());
    }

    public static void printPromedioCalificaciones(List<Integer> calificaciones) {
        System.out.println("Promedio de calificaciones: " + calificaciones.stream().mapToInt(calificacion -> calificacion).average().orElse(0));
    }

    public static void printCalificacionMasAlta(List<Integer> calificaciones) {
        System.out.println("Calificacion mas alta: " + calificaciones.stream().mapToInt(calificacion -> calificacion).max().orElse(0));
    }

    public static void printCalificacionMasBaja(List<Integer> calificaciones) {
        System.out.println("Calificacion mas baja: " + calificaciones.stream().mapToInt(calificacion -> calificacion).min().orElse(0));
    }

}

