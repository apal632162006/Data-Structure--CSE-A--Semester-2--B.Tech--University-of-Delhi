class SparseMatrix {
    constructor(rows, cols) {
        this.rows = rows;
        this.cols = cols;
        this.matrix = {};
    }

    getValue(row, col) {
        if (row < 0 || row >= this.rows || col < 0 || col >= this.cols) {
            throw new Error('Index out of bounds');
        }

        return this.matrix[`${row},${col}`] || 0;
    }

    setValue(row, col, value) {
        if (row < 0 || row >= this.rows || col < 0 || col >= this.cols) {
            throw new Error('Index out of bounds');
        }

        if (value !== 0) {
            this.matrix[`${row},${col}`] = value;
        } else {
            delete this.matrix[`${row},${col}`];
        }
    }

    print() {
        for (let i = 0; i < this.rows; i++) {
            let rowString = '';
            for (let j = 0; j < this.cols; j++) {
                rowString += this.getValue(i, j) + '\t';
            }
            console.log(rowString);
        }
    }
}