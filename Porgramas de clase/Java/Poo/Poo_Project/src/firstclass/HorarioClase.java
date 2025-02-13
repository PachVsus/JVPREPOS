package firstclass;

public class HorarioClase {
    private String horaInicio;
    private String horaFin;
    private String materia;

    public HorarioClase(String horaInicio, String horaFin, String materia) {
        this.horaInicio = horaInicio;
        this.horaFin = horaFin;
        this.materia = materia;
    }

    public String getHoraInicio() {
        return horaInicio;
    }

    public void setHoraInicio(String horaInicio) {
        this.horaInicio = horaInicio;
    }

    public String getHoraFin() {
        return horaFin;
    }

    void setClase(String horaFin) {
        this.horaFin = horaFin;
    }

    public String getMateria() {
        return materia;
    }

    public void setMateria(String materia) {
        this.materia = materia;
    }

    @Override
    public String toString() {
        return "HorarioClase{" + "horaInicio=" + horaInicio + ", horaFin=" + horaFin + ", materia=" + materia + '}';
    }

    public static void main(String[] args) {
        HorarioClase horario = new HorarioClase("08:00", "10:00", "Matemáticas");
        System.out.println("Hora de inicio: " + horario.getHoraInicio());
        System.out.println("Clase del objeto: " + horario.getClass());
    }
}

