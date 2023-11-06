#include<iostream>
#include<vector>

#ifndef MATRIX_H
#define MATRIX_H 

class Matrix
{
    const float MAXVALUE = 100.0f;
    public:
        std::vector<float> matrix;
        
        Matrix(int rows, int columns);
        Matrix(int size);
        void SquareMatrix(int size);

};

#endif