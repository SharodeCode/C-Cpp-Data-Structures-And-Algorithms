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

/*

------------------SimpleMM Test-------------------------------

*/

// Testing n=3 square matrix

TEST_F(SimppleMMTests, N3SimpleMMMatrix)
{
    int squareMatrixSize = 3;

	srand((unsigned int)time(NULL));

	Matrix matrixA = Matrix(squareMatrixSize);
    Matrix matrixB = Matrix(squareMatrixSize);

	SimpleMM *simpleMM = new SimpleMM(matrixA.matrix, matrixB.matrix, squareMatrixSize);

	std::vector<float> resultMatrix = simpleMM->Multiply();

	if(writeResult){
		MatrixHelper::writeMatrixToFile(matrixA.matrix, matrixB.matrix, resultMatrix, squareMatrixSize, "MatrixA");
	}
}