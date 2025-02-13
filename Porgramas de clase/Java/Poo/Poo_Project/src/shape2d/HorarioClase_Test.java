package shape2d;

import firstclass.HorarioClase;

public class HorarioClase_Test {
    public static void main(String[] args) {
        HorarioClase horario = new HorarioClase("08:00", "10:00", "Matemáticas");
        System.out.println("Hora de inicio: " + horario.getHoraInicio());
        System.out.println("Clase del objeto: " + horario.getClass());
        System.out.println("Hora de fin: " + horario.getHoraFin());
    }
}