import java.util.HashMap;

public class SparseMatrix {
    private final int rows;
    private final int cols;
    private final HashMap<String, Integer> matrix;

    public SparseMatrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.matrix = new HashMap<>();
    }

    public void setValue(int row, int col, int value) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw new IllegalArgumentException("Index out of bounds");
        }
        String key = row + "," + col;
        if (value != 0) {
            matrix.put(key, value);
        } else {
            matrix.remove(key);
        }
    }

    public int getValue(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw new IllegalArgumentException("Index out of bounds");
        }
        String key = row + "," + col;
        return matrix.getOrDefault(key, 0);
    }

    public void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(getValue(i, j) + "\t");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        SparseMatrix sparseMatrix = new SparseMatrix(3, 3);
        sparseMatrix.setValue(0, 0, 1);
        sparseMatrix.setValue(1, 1, 2);
        sparseMatrix.setValue(2, 2, 3);
        sparseMatrix.display();
    }
}