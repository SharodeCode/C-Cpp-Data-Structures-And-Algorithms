#include <SimpleMM/SimpleMM.h>

SimpleMM::SimpleMM(std::vector<float> &A, std::vector<float> &B, int sizeN)
{
    matrixA = A;
    matrixB = B;
    size = sizeN;

    matrixC.resize(size*size);
}

std::vector<float> SimpleMM::Multiply()
{

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){

            int c = i * size + j;
            matrixC[c] = 0;

            for(int k = 0; k < size; k++){
                int a = i * size + k;
                int b = k * size + j;

                matrixC[c] += matrixA[a] * matrixB[b];
            }
        }
    }

    return matrixC;
}