#include <Matrix/Matrix.h>

Matrix::Matrix(int rows, int columns){
    // Check if the matrix is square (number of rows equals number of columns)
    if(rows == columns){
        SquareMatrix(rows);
    }
}

Matrix::Matrix(int size){
    SquareMatrix(size);
}

void Matrix::SquareMatrix(int size){
    
    // Calculate the total number of elements in the square matrix
    int SquareSize = size * size;

    // Populate the matrix with random float values between 0 and MAXVALUE
    for(int i = 0; i < SquareSize; i++){
        matrix.push_back(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/MAXVALUE)));
    }
}