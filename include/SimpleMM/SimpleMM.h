#include <iostream>
#include <vector>

#ifndef SIMPLEMM_H
#define SIMPLEMM_H

class SimpleMM
{
    std::vector<float> matrixA;
    std::vector<float> matrixB;
    std::vector<float> matrixC;
    int size;


    public:
        SimpleMM(std::vector<float> &A, std::vector<float> &B, int sizeN);
        std::vector<float> Multiply();
};

#endif