#include<iostream>
#include<vector>

#ifndef MATRIX_H
#define MATRIX_H 

/**
 * @brief Class representing a matrix with random float values.
 */
class Matrix
{
    const float MAXVALUE = 100.0f;
    public:
        /**
         * @brief Public vector containing the matrix elements.
         */
        std::vector<float> matrix;
        
        /**
         * @brief Constructor for a matrix with a given number of rows and columns.
         * 
         * @param rows The number of rows in the matrix.
         * @param columns The number of columns in the matrix.
         */
        Matrix(int rows, int columns);

        /**
         * @brief Constructor for a square matrix with a given size.
         * 
         * @param size The size of the square matrix (number of rows or columns).
         */
        Matrix(int size);

    private:

        /**
         * @brief Private function to initialize a square matrix with random float values.
         * 
         * @param size The size of the square matrix (number of rows or columns).
         */
        void SquareMatrix(int size);

};

#endif