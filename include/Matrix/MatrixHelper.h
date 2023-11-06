#include<iostream>
#include<vector>
#include <string>
#include <fstream>
#include <iterator>

#ifndef MATRIXHELPER_H
#define MATRIXHELPER_H 

class MatrixHelper
{
    public:
        MatrixHelper();

        static void writeMatrixToFile(std::vector<float> matrixToWriteA, std::vector<float> matrixToWriteB, std::vector<float> matrixToWriteC, int sizeofMatrix, std::string fileName)
        {
            std::string filePath = "../../test/TestOutput/" + fileName + ".csv";

            std::ofstream myfile;
            myfile.open (filePath);

            size_t size = matrixToWriteA.size();

            for(int i = 1; i <= size; i++){

                myfile << matrixToWriteA[i - 1] << ", ";

                if(i % sizeofMatrix == 0){
                    myfile << std::endl;
                }

            }

            myfile << std::endl;
            myfile << std::endl;
            myfile << std::endl;

            for(int i = 1; i <= size; i++){

                myfile << matrixToWriteB[i - 1] << ", ";

                if(i % sizeofMatrix == 0){
                    myfile << std::endl;
                }

            }
            
            myfile << std::endl;
            myfile << std::endl;
            myfile << std::endl;

            for(int i = 1; i <= size; i++){

                myfile << matrixToWriteC[i - 1] << ", ";

                if(i % sizeofMatrix == 0){
                    myfile << std::endl;
                }

            }

            myfile.flush();
            myfile.close();
    }

};

#endif