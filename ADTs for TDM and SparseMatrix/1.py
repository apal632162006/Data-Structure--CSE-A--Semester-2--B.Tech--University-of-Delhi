class TermDocumentMatrix:
    def __init__(self, num_terms, num_documents):
        self.num_terms = num_terms
        self.num_documents = num_documents
        self.matrix = [[0] * num_documents for _ in range(num_terms)]

    def updateTermFrequency(self, term_index, document_index, frequency):
        self.matrix[term_index][document_index] = frequency

    def getTermFrequency(self, term_index, document_index):
        return self.matrix[term_index][document_index]

    def getDocumentFrequency(self, term_index):
        return sum(1 for document in self.matrix[term_index] if document > 0)

    def getTotalTermsInDocument(self, document_index):
        return sum(self.matrix[term_index][document_index] for term_index in range(self.num_terms))

    def toSparseMatrix(self):
        from collections import defaultdict
        sparse_matrix = defaultdict(dict)
        for term_index in range(self.num_terms):
            for document_index in range(self.num_documents):
                frequency = self.matrix[term_index][document_index]
                if frequency > 0:
                    sparse_matrix[term_index][document_index] = frequency
        return sparse_matrix


class SparseMatrix:
    def __init__(self, rows, cols):
        self.rows = rows
        self.cols = cols
        self.matrix = {}

    def setValue(self, row, col, value):
        self.matrix[(row, col)] = value

    def getValue(self, row, col):
        return self.matrix.get((row, col), 0)

    def addValue(self, row, col, value):
        current_value = self.matrix.get((row, col), 0)
        self.matrix[(row, col)] = current_value + value

    def removeValue(self, row, col):
        if (row, col) in self.matrix:
            del self.matrix[(row, col)]

    def getNumRows(self):
        return self.rows

    def getNumCols(self):
        return self.cols

    def transpose(self):
        transposed_matrix = SparseMatrix(self.cols, self.rows)
        for (row, col), value in self.matrix.items():
            transposed_matrix.setValue(col, row, value)
        return transposed_matrix

    def multiplyScalar(self, factor):
        for key in self.matrix.keys():
            self.matrix[key] *= factor

    def add(self, other_sparse_array):
        if self.rows != other_sparse_array.rows or self.cols != other_sparse_array.cols:
            raise ValueError("Sparse matrices must have the same dimensions for addition.")
        result = SparseMatrix(self.rows, self.cols)
        for (row, col), value in self.matrix.items():
            result.setValue(row, col, value + other_sparse_array.getValue(row, col))
        return result

    def multiply(self, other_sparse_array):
        if self.cols != other_sparse_array.rows:
            raise ValueError("Number of columns in first matrix must be equal to number of rows in second matrix.")
        result = SparseMatrix(self.rows, other_sparse_array.cols)
        for i in range(self.rows):
            for j in range(other_sparse_array.cols):
                value = sum(self.getValue(i, k) * other_sparse_array.getValue(k, j) for k in range(self.cols))
                result.setValue(i, j, value)
        return result

    def toDenseArray(self):
        dense_array = [[0] * self.cols for _ in range(self.rows)]
        for (row, col), value in self.matrix.items():
            dense_array[row][col] = value
        return dense_array
