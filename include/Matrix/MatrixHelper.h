#include<iostream>
#include<vector>
#include <string>
#include <fstream>
#include <iterator>

#ifndef MATRIXHELPER_H
#define MATRIXHELPER_H 


/**
 * @brief Helper class for matrix operations and file I/O.
 */
class MatrixHelper
{
    public:
        /**
         * @brief Constructor for MatrixHelper.
         */
        MatrixHelper();

        /**
         * @brief Write matrices A, B, and C to a CSV file.
         * 
         * @param matrixToWriteA Vector representing matrix A.
         * @param matrixToWriteB Vector representing matrix B.
         * @param matrixToWriteC Vector representing matrix C.
         * @param sizeofMatrix Size of the square matrices.
         * @param fileName Name of the output CSV file.
         */
        static void writeMatrixToFile(std::vector<float> matrixToWriteA, std::vector<float> matrixToWriteB, std::vector<float> matrixToWriteC, int sizeofMatrix, std::string fileName);


    private:
        /**
         * @brief Helper function to write a matrix to a file.
         * 
         * @param matrixToWrite Vector representing the matrix to write.
         * @param sizeofMatrix Size of the square matrix.
         * @param myfile Reference to the ofstream object for file writing.
         */
        static void writeSingleMatrixToFile(const std::vector<float>& matrixToWrite, int sizeofMatrix, std::ofstream& myfile);

};

void MatrixHelper::writeMatrixToFile(std::vector<float> matrixToWriteA, std::vector<float> matrixToWriteB, std::vector<float> matrixToWriteC, int sizeofMatrix, std::string fileName)
{
    // Construct the file path for the output CSV file
    std::string filePath = "../../test/TestOutput/" + fileName + ".csv";

    // Open the file for writing
    std::ofstream myfile;
    myfile.open (filePath);

    // Write matrix A to the file
    writeSingleMatrixToFile(matrixToWriteA, sizeofMatrix, myfile);

    // Write matrix B to the file
    writeSingleMatrixToFile(matrixToWriteB, sizeofMatrix, myfile);

    // Write matrix C to the file
    writeSingleMatrixToFile(matrixToWriteC, sizeofMatrix, myfile);

    // Flush and close the file
    myfile.flush();
    myfile.close();
}

void MatrixHelper::writeSingleMatrixToFile(const std::vector<float>& matrixToWrite, int sizeofMatrix, std::ofstream& myfile)
{
    size_t size = matrixToWrite.size();

    // Write the matrix to the file
    for(int i = 1; i <= size; i++){

        myfile << matrixToWrite[i - 1] << ", ";

        // Start a new line after each row
        if(i % sizeofMatrix == 0){
            myfile << std::endl;
        }
    }

    // Add spacing between matrices
    myfile << std::endl;
    myfile << std::endl;
    myfile << std::endl;
}

#endif