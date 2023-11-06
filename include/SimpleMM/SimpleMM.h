#include <iostream>
#include <vector>

#ifndef SIMPLEMM_H
#define SIMPLEMM_H

/**
 * @brief Class representing a simple matrix multiplication operation.
 */
class SimpleMM
{
    std::vector<float> matrixA;
    std::vector<float> matrixB;
    std::vector<float> matrixC;
    int size;


    public:
        /**
         * @brief Constructor for SimpleMM.
         * 
         * @param A Vector representing matrix A.
         * @param B Vector representing matrix B.
         * @param sizeN Size of the square matrices.
         */
        SimpleMM(std::vector<float> &A, std::vector<float> &B, int sizeN);

        /**
         * @brief Perform matrix multiplication and return the result.
         * 
         * @return Vector representing the result of matrix multiplication (matrixC).
         */
        std::vector<float> Multiply();
};

#endif