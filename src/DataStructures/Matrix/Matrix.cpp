#include <Matrix/Matrix.h>

Matrix::Matrix(int rows, int columns){
    if(rows == columns){
        SquareMatrix(rows);
    }
}

Matrix::Matrix(int size){
    SquareMatrix(size);
}

void Matrix::SquareMatrix(int size){

    int SquareSize = size * size;

    for(int i = 0; i < SquareSize; i++){
        matrix.push_back(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/MAXVALUE)));
    }
}