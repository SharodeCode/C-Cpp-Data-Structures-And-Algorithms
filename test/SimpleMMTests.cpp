#include <gtest/gtest.h>
#include <SimpleMM/SimpleMM.h>
#include <Matrix/Matrix.h>
#include <Matrix/MatrixHelper.h>

class SimppleMMTests : public testing::Test
{

protected:
	bool writeResult = true;

	SimppleMMTests()
	{

	}

	virtual ~SimppleMMTests()
	{
	}

	virtual void SetUp()
	{
		
	}

	virtual void TearDown()
	{
		
	}
};

/**
 * @brief Testing n=3 square matrix
 */
TEST_F(SimppleMMTests, N3SimpleMMMatrix)
{
	// Set the size of the square matrix for testing
    int squareMatrixSize = 3;

	// Seed the random number generator
	srand((unsigned int)time(NULL));

	// Create square matrices A and B with random float values
	Matrix matrixA = Matrix(squareMatrixSize);
    Matrix matrixB = Matrix(squareMatrixSize);

	// Create an instance of SimpleMM with matrices A and B
	SimpleMM *simpleMM = new SimpleMM(matrixA.matrix, matrixB.matrix, squareMatrixSize);

	// Perform matrix multiplication and get the result matrix
	std::vector<float> resultMatrix = simpleMM->Multiply();

	// Optionally write matrices A, B, and the result to a file for inspection
	if(writeResult){
		MatrixHelper::writeMatrixToFile(matrixA.matrix, matrixB.matrix, resultMatrix, squareMatrixSize, "MatrixA");
	}
}