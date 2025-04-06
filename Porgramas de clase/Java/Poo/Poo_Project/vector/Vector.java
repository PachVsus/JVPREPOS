package vector;
import vector.Matrix;
import java.util.Arrays;

public class Vector extends Matrix {
    protected boolean isRowVector;
    public int MIN_LENGTH = 2;

    @Override
    public Vector() {
        super(1, 3);
        isRowVector = true;
    }

    public Vector(int length) {
        super(1, length);
        isRowVector = true;
        if (length < MIN_LENGTH) {
            throw new IllegalArgumentException("Length must be greater than or equal to " + MIN_LENGTH);
        }
    }

    public Vector(int length, boolean dummy) {
        super(length, 1);
        isRowVector = false;
        if (length < MIN_LENGTH) {
            throw new IllegalArgumentException("Length must be greater than or equal to " + MIN_LENGTH);
        }
    }

    public int length() {
        if (isRowVector) {
            return super.cols;
        } else {
            return super.rows;
        }
    }

    // + set(index, value) method
    public void set(int index, double value) {
        if (index < MIN_LENGTH || index > length()) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        if (isRowVector == true) {
            super.set(1, index, value);
        if (index < 1 || index > length()) {
            super.set(index, 1, value);
        }
    }

    // + get(index) double method
    public double get(int index) {
        if (index < MIN_LENGTH || index > length()) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        if (isRowVector == true) {
            return super.get(1, index);
        } else {
            return super.get(index, 1);
        }
    }

    // + toString() method
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (isRowVector == true) {
            for (int i = 1; i <= length(); i++) {
                sb.append(get(i)).append(" ");
            }
        } else {
            for (int i = 1; i <= length(); i++) {
                sb.append(get(i)).append("\n");
            }
        }
        return sb.toString();
    }

}
