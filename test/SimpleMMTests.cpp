#include <gtest/gtest.h>
#include <SimpleMM/SimpleMM.h>

class SimppleMMTests : public testing::Test
{

protected:

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

------------------isEmpty Tests-------------------------------

*/

// Testing isEmpty

TEST(SimpleMMTests, SimpleMMTest)
{

	int size = 3;
	std::vector<float> matrixA{1.56f, 3.96f, 45.2f, 12.5f, 4.5f, 125.8f, 17.5f, 165.8f, 12.2f};
	std::vector<float> matrixB{49.5f, 61.5f, 78.3f, 19.5f, 37.5f, 91.6f, 0.59f, 4.85f, 2.6f};
	std::vector<float> matrixResult{181.108f, 463.66f, 602.404f, 780.722f, 1547.63f, 1718.03f, 4106.548f, 7352.92f, 16589.25f};

	SimpleMM *simpleMM = new SimpleMM(matrixA, matrixB, size);

	std::vector<float> resultMatrix = simpleMM->Multiply();

	for (int i = 0; i < (size * size); i++)
	{
		EXPECT_FLOAT_EQ(resultMatrix[i], matrixResult[i]);
	}
}