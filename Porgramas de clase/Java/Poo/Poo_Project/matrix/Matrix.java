package matrix;

public class Matrix {
    private final double[][] matrix;
    protected int rows;
    protected int cols;
    public final static int MIN_COLS = 1;
    public final static int MIN_ROWS = 1;

    public Matrix(int rows, int cols) {
        this.rows = Math.max(rows, MIN_ROWS);
        this.cols = Math.max(cols, MIN_COLS);
        matrix = new double[this.rows][this.cols];
    }

    public double get(int row, int col) {
        if (row < 0 || row >= this.rows || col < 0 || col >= this.cols) {
            throw new IllegalArgumentException("Row or column index out of bounds");
        }
        return matrix[row][col];
    }

    public void set(int row, int col, double value) {
        if (row < 0 || row >= this.rows || col < 0 || col >= this.cols) {
            throw new IllegalArgumentException("Row or column index out of bounds");
        }
        matrix[row][col] = value;
    }

@Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                sb.append(matrix[i][j]);
                if (j < this.cols - 1) {
                    sb.append("\t");
                }
            }
            sb.append("\n");
        }
        return sb.toString();
    }

    public Matrix add(Matrix other) {
        if (this.rows != other.rows || this.cols != other.cols) {
            throw new IllegalArgumentException("Matrices must have the same dimensions");
        }
        Matrix result = new Matrix(this.rows, this.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                result.set(i, j, this.get(i, j) + other.get(i, j));
            }
        }
        return result;
    }

    public Matrix multiply(Matrix other) {
        if (this.cols != other.rows) {
            throw new IllegalArgumentException("Number of columns in the first matrix must be equal to the number of rows in the second matrix");
        }
        Matrix result = new Matrix(this.rows, other.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                double sum = 0;
                for (int k = 0; k < this.cols; k++) {
                    sum += this.get(i, k) * other.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }

    public Matrix transpose() {
        Matrix result = new Matrix(this.cols, this.rows);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                result.set(j, i, this.get(i, j));
            }
        }
        return result;
    }

    public Matrix scalarMultiply(double scalar) {
        Matrix result = new Matrix(this.rows, this.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                result.set(i, j, this.get(i, j) * scalar);


}

        }
        return result;
    }

    public Matrix scalarAdd(double scalar) {
        Matrix result = new Matrix(this.rows, this.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                result.set(i, j, this.get(i, j) + scalar);
            }
        }
        return result;
    }

    public Matrix scalarSubtract(double scalar) {
        return scalarAdd(-scalar);
    }

    public Matrix subtract(Matrix other) {
        return add(other.scalarMultiply(-1));
    }

    public Matrix divide(double scalar) {
        if (scalar == 0) {
            throw new IllegalArgumentException("Cannot divide by zero");
        }
        return scalarMultiply(1 / scalar);
    }

    public Matrix power(int exponent) {
        if (exponent < 0) {
            throw new IllegalArgumentException("Exponent must be non-negative");
        }
        if (this.rows != this.cols) {
            throw new IllegalArgumentException("Matrix must be square");
        }
        Matrix result = identity(this.rows);
        for (int i = 0; i < exponent; i++) {
            result = result.multiply(this);
        }
        return result;
    }

    public static Matrix identity(int size) {
        Matrix result = new Matrix(size, size);
        for (int i = 0; i < size; i++) {
            result.set(i, i, 1);
        }
        return result;
    }

    public static Matrix random(int rows, int cols) {
        Matrix result = new Matrix(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.set(i, j, Math.random());
            }
        }
        return result;
    }

    public static Matrix fromArray(double[] array) {
        Matrix result = new Matrix(array.length, 1);
        for (int i = 0; i < array.length; i++) {
            result.set(i, 0, array[i]);
        }
        return result;
    }

    public double[] toArray() {
        if (this.cols != 1) {
            throw new IllegalArgumentException("Matrix must have exactly one column");
        }
        double[] result = new double[this.rows];
        for (int i = 0; i < this.rows; i++) {
            result[i] = this.get(i, 0);
        }
        return result;
    }

    public static void main(String[] args) {
        Matrix m1 = new Matrix(2, 2);
        m1.set(0, 0, 1);
        m1.set(0, 1, 2);
        m1.set(1, 0, 3);
        m1.set(1, 1, 4);
        System.out.println(m1);
        Matrix m2 = new Matrix(2, 2);
        m2.set(0, 0, 5);
        m2.set(0, 1, 6);
        m2.set(1, 0, 7);
        m2.set(1, 1, 8);
        System.out.println(m2);
        System.out.println(m1.add(m2));
        System.out.println(m1.subtract(m2));
        System.out.println(m1.multiply(m2));
        System.out.println(m1.transpose());
        System.out.println(m1.scalarMultiply(2));
        System.out.println(m1.scalarAdd(2));
        System.out.println(m1.scalarSubtract(2));
        System.out.println(m1.divide(2));
        System.out.println(m1.power(2));
        System.out.println(Matrix.identity(3));
        System.out.println(Matrix.random(2, 2));
        System.out.println(Matrix.fromArray(new double[]{1, 2, 3}));
    }

    // Removed duplicate main method to resolve compilation error

}

