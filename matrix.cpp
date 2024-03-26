#include <iostream>
#include <fstream>
#include <iomanip> // For std::setw

const int MAX_SIZE = 10; // Adjust based on expected maximum size
int N; // Matrix size, to be read from the file

// Function prototypes
void readMatrix(std::ifstream& file, int matrix[MAX_SIZE][MAX_SIZE], int size);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int row, int col, int newValue, int size);
int findMaxValue(int matrix[MAX_SIZE][MAX_SIZE], int size);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], resultMatrix[MAX_SIZE][MAX_SIZE];

    std::ifstream file("matrix_input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    file >> N; // Read the size of the matrices
    readMatrix(file, matrix1, N);
    readMatrix(file, matrix2, N);

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1, N);

    std::cout << "Matrix 2:" << std::endl;
    printMatrix(matrix2, N);

    std::cout << "Addition of Matrix 1 and Matrix 2:" << std::endl;
    addMatrices(matrix1, matrix2, resultMatrix, N);
    printMatrix(resultMatrix, N);

    std::cout << "Multiplication of Matrix 1 and Matrix 2:" << std::endl;
    multiplyMatrices(matrix1, matrix2, resultMatrix, N);
    printMatrix(resultMatrix, N);

    std::cout << "Subtraction of Matrix 2 from Matrix 1:" << std::endl;
    subtractMatrices(matrix1, matrix2, resultMatrix, N);
    printMatrix(resultMatrix, N);

    std::cout << "Updating element at (1, 1) of Matrix 1 to 100:" << std::endl;
    updateElement(matrix1, 1, 1, 100, N);
    printMatrix(matrix1, N);

    std::cout << "Maximum value in Matrix 1:" << std::endl;
    std::cout << findMaxValue(matrix1, N) << std::endl;

    std::cout << "Transpose of Matrix 1:" << std::endl;
    transposeMatrix(matrix1, N);
    printMatrix(matrix1, N);

    file.close();
    return 0;
}

void readMatrix(std::ifstream& file, int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0; // Initialize to 0
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int row, int col, int newValue, int size) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column index." << std::endl;
    }
}

int findMaxValue(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int max = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}
