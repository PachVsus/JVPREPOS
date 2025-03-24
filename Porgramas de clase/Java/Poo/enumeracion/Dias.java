package enumeracion;

public enum Dias {
    LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
}

public class TestEnum {
    public static void main(String[] args) {
        Dias hoy = Dias.JUEVES;
        System.out.println("Hoy es: " + hoy);
        switch (hoy) {
            case SABADO, DOMINGO:
                System.out.println("Es fin de semana");
                break;
            default:
                System.out.println("Es un dia de la semana");
                break;
        }
    }
}

