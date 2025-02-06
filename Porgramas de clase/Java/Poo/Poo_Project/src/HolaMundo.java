
import javax.swing.JOptionPane;
// Jesus was here

public class HolaMundo {
    public static void main(String[] args) {
        System.out.println("Hola ITESO");
        int edad = 10;
        System.out.printf("Edad: %d\n", edad);
        JOptionPane.showMessageDialog(null, "Hola");
        String name = JOptionPane.showInputDialog("Dame tu nombre: ");
        if (name != null) {
            System.out.println(name);
        } else {
            System.out.println("No name provided.");
        }
    }
}