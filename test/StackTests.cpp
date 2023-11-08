#include <random>
#include <gtest/gtest.h>
#include <Stack/Stack.h>

class StackTests : public testing::Test
{

protected:
	Stack<int> *s1_;
	int arr[100];

	StackTests()
	{
		std::srand(std::time(nullptr));

		for (int i = 0; i < 100; i++)
		{
			arr[i] = (rand() % 10);
		}
	}

	virtual ~StackTests()
	{
	}

	virtual void SetUp()
	{
		s1_ = new Stack<int>();
	}

	virtual void TearDown()
	{
		delete s1_;
	}
};


/*

------------------isEmpty Tests-------------------------------

*/

// Testing isEmpty

TEST_F(StackTests, TestSTack)
{
	s1_->push(4);

	// Expect empty queue.
	EXPECT_EQ(s1_->pop(), 4);
}
