#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    // Constructor: Create an empty matrix of size rows x cols
    Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {}

    // Get the number of rows
    int numRows() const {
        return rows;
    }

    // Get the number of columns
    int numCols() const {
        return cols;
    }

    // Access element at row i, column j
    double& operator()(int i, int j) {
        return data[i][j];
    }

    // Access element at row i, column j (const version)
    const double& operator()(int i, int j) const {
        return data[i][j];
    }

    // Transpose the matrix
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(j, i) = data[i][j];
            }
        }
        return result;
    }

    // Perform matrix dot product with another matrix
    Matrix dot(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrix dimensions are incompatible for dot product.");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                double sum = 0.0;
                for (int k = 0; k < cols; ++k) {
                    sum += data[i][k] * other(k, j);
                }
                result(i, j) = sum;
            }
        }
        return result;
    }
};

int main() {
    // Example usage:
    Matrix A(2, 3);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(0, 2) = 3;
    A(1, 0) = 4;
    A(1, 1) = 5;
    A(1, 2) = 6;

    Matrix B(3, 2);
    B(0, 0) = 3;
    B(0, 1) = 4;
    B(1, 0) = 4;
    B(1, 1) = 3;
    B(2, 0) = 6;
    B(2, 1) = 5;

    Matrix C = A.dot(B);
    Matrix D = C.transpose();

    // Display the result of A * B
    std::cout << "A * B:" << std::endl;
    for (int i = 0; i < C.numRows(); ++i) {
        for (int j = 0; j < C.numCols(); ++j) {
            std::cout << C(i, j) << " ";
        }
        std::cout << std::endl;
    }

    // Display the transpose of C
    std::cout << "Transpose of A * B:" << std::endl;
    for (int i = 0; i < D.numRows(); ++i) {
        for (int j = 0; j < D.numCols(); ++j) {
            std::cout << D(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



