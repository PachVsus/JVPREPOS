package ejercicios_de_lambda_y_stream;

import java.util.List;
import java.util.stream.Collectors;

public class Calificaciones {

    public static void main(String[] args) {
        System.out.println("Calificaciones aprobadas: " + calificaciones.stream().filter(calificacion -> calificacion >= 6).collect(Collectors.toList()));
        System.out.println("Calificaciones reprobadas: " + calificaciones.stream().filter(calificacion -> calificacion < 6).collect(Collectors.toList()));
        System.out.println("Calificaciones reprobadas: " + calificaciones.stream().filter(calificacion -> calificacion < 6).toList());

        System.out.println("Promedio de calificaciones: " + calificaciones.stream().mapToInt(calificacion -> calificacion).average().orElse(0));
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


}
