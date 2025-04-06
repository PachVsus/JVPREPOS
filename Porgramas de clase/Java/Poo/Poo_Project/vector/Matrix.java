package vector;

public class Matrix {
    private double [][] Matrix;
    protected int rows, cols;
    public int Min_Rows = 1;
    public int Min_Cols = 1;

    public Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        Matrix = new double[rows][cols];
    }

    // + get(rows, cols) method
    public double get(int row, int col) {
        if (row < Min_Rows || row > rows || col < Min_Cols || col > cols) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        return Matrix[row - 1][col - 1];
    }
    // + set(rows, cols, value) method
    public void set(int row, int col, double value) {
        if (row < Min_Rows || row > rows || col < Min_Cols || col > cols) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        Matrix[row - 1][col - 1] = value;
    }
    // + toString() method
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sb.append(Matrix[i][j]).append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }
}
