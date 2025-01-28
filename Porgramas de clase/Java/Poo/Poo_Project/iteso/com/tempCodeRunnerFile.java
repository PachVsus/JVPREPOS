import javax.swing.JOptionPane;

public class Fotomulta {
    
    public static void main(String[] args) {
        String strVelocidad = JOptionPane.showInputDialog("Introduce la velocidad del vehiculo");
        double velocidad;
        try {
            velocidad = Double.parseDouble(strVelocidad);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "La velocidad debe ser un numero");
            System.exit(1);
        }
        if (velocidad > 80) {
            JOptionPane.showMessageDialog(null, "El vehiculo fue multado");
        } else {
            JOptionPane.showMessageDialog(null, "El vehiculo no fue multado");
        }
    }
}
