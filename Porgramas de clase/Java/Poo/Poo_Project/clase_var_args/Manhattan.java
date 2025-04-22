package clase_var_args;

public class Manhattan {

    public static double distance(double ... num) {
        if (num.length < 2) {
            throw new IllegalArgumentException("At least two numbers are required to calculate Manhattan distance.");
        }

        double dif = 0;
        for (int i = 0; i < num.length - 1; i++) {
            dif += Math.abs(num[0] - num[i + 1]);
        }

        return dif / (num.length - 1);
    }

    public static void main(String[] args) {
        // Example usage
        double result = distance(1.0, 2.0, 3.0, 4.0);
        System.out.println("Manhattan distance: " + result);

        double result2 = distance(5.0, 10.0, 15.0);
        System.out.println("Manhattan distance: " + result2);
    }
}
