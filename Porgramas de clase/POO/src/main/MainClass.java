package main;

import javax.swing.JFrame;

public class MainClass {

    public static void main(String[] args) {
                
        //Constructores Pantalla Inicio:
        JFrame wd1 = new JFrame();  //wd1 = window1
        wd1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Boton X cerrar Ventana.
        wd1.setResizable(false);  
        wd1.setTitle("8 Bit Legend's.");

        GamePanel gp1 = new GamePanel();
        wd1.add(gp1);

        wd1.pack();

        wd1.setLocationRelativeTo(null);    //Ventana emegente centro de pantalla.
        wd1.setVisible(true);


    }
    
}