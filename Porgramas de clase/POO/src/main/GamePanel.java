package main;

import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JPanel;

public class GamePanel extends JPanel implements Runnable{
    
    //Ajustes de pantalla.
    final int ogTileSize = 16;    //16 x 16 Tile
    final int scale = 3;

    final int tileSize = ogTileSize*scale;  //48*48 tile
    final int maxScreenCol = 16     //Tamaño ancho pantalla.
            , maxScreenRow = 12;    //Tamaño alto pantalla.
    final int screenWidth = tileSize*maxScreenCol;  //48 * 16 = 768 pixels.
    final int screenHeight = tileSize*maxScreenRow; //48 * 12 = 576 pixels.

    Thread gameThread;  //

    //Constructor 
    public GamePanel(){

        this.setPreferredSize(new Dimension(screenWidth, screenHeight));
        this.setBackground(Color.black); 
        this.setDoubleBuffered(true);   //Improves game performance.
        
    }

    public void startGameThread(){
        gameThread = new Thread(this);
        gameThread.start();
    }
    @Override
    public void run() {
        // TODO Auto-generated method stub
        //throw new UnsupportedOperationException("Unimplemented method 'run'");
        
    }
}