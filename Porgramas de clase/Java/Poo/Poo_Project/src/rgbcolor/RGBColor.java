package rgbcolor;
public class RGBColor {
		// atributos
	    int rojo = 127;
	    int verde = 127;
	    int azul = 127;
	    
	    public RGBColor() {	 
	    	
	    }
	    
	    public RGBColor(int i, int j, int k) {
	    	if (0 <= i && i <= 255) {
	    		this.rojo = i;
	    	}
	    	if (0 <= j && j <= 255) {
	    		this.verde = j;
	    	}
	    	if (0 <= k && k <= 255) {
	    		this.azul = k;
	    	}
	    	
	    }

	    // metodos setters y getters
	    public void setRojo(int rojo) {
	    	if (0 <= rojo && rojo <= 255) {
	    		this.rojo = rojo;
	    	}
	    }

	    public void setVerde(int verde) {
	    	if (0 <= verde && verde <= 255) {
	    		this.verde = verde;
	    	}
	    }

	    public void setAzul(int azul) {
	    	if (0 <= azul && azul <= 255) {
	        	this.azul = azul;
	    	}
	    }

	    public int getRojo() {
	    	return rojo;
	    }

	    public int getVerde() {
	    	return verde;
	    }

	    public int getAzul() {
	    	return azul;
	    }

	    public static void main(String[] args) {
	    	
	    	RGBColor miC1 = new RGBColor();

	    	RGBColor miC2 = new RGBColor(100, 300, 80);

	    	System.out.println(miC1.getRojo());
	    	System.out.println(miC2.getRojo());
	    	System.out.println(miC2.getVerde());

	    }

	
}