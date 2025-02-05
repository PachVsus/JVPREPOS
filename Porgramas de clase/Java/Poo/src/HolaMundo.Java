package poo;

import javax.swing.JOptionPane;
// Jesus was here

public class HolaMundo {
    public static void main(String[] args) {
        System.out.println("Hola ITESO");
        int edad = 10;
        System.out.printf("Edad: %d\n", edad);
        JOptionPane.showMessageDialog(null, "Hola");
        String name = JOptionPane.showInputDialog("Dame tu nombre: ");
        System.out.println(name);
    }
}