import javax.swing.JOptionPane;

public class Fotomulta {
    
    public static void main(String[] args) {
        // Solicita al usuario que introduzca la velocidad del vehículo
        String strVelocidad = JOptionPane.showInputDialog("Introduce la velocidad del vehiculo");
        double velocidad = -1;
        
        try {
            // Intenta convertir la entrada del usuario a un número de tipo double
            velocidad = Double.parseDouble(strVelocidad);
        } catch (NumberFormatException e) {
            // Si la conversión falla, muestra un mensaje de error y termina el programa
            JOptionPane.showMessageDialog(null, "La velocidad debe ser un numero");
            System.exit(1);
        }
        
        // Verifica si la velocidad es mayor a 80
        if (velocidad > 90) {
            // Si la velocidad es mayor a 80, muestra un mensaje indicando que el vehículo fue multado
            JOptionPane.showMessageDialog(null, "El vehiculo fue multado");
        } else {
            // Si la velocidad es 80 o menor, muestra un mensaje indicando que el vehículo no fue multado
            JOptionPane.showMessageDialog(null, "El vehiculo no fue multado");
        }
    }
}