package shape2d;

public class Rectangle1 {
	private double base;
	private double height;

	public Rectangle1() {
	}

	public Rectangle1(double base, double height) {
		this.base = base;
		this.height = height;
	}

	public double getBase() {
		return this.base;
	}

	public void setBase(double base) {
		this.base = base;
	}

	public double getHeight() {
		return this.height;
	}

	public void setHeight(double height) {
		this.height = height;
	}

	public static void main(String[] args) {
		Rectangle1 r1 = new Rectangle1();
		r1.setBase(5);
		r1.setHeight(12);
		System.out.println(r1.getBase());
	}
}


