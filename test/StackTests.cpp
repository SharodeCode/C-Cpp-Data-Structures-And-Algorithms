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
TEST_F(StackTests, InitialStackIsEmpty)
{
	// Expect empty stack.
	EXPECT_EQ(s1_->isEmpty(), true);
}

// Testing non empty after push
TEST_F(StackTests, NotEmptyAfterPush)
{

	int random_variable = std::rand();

	s1_->push(random_variable);

	// Expect non-empty stack.
	EXPECT_EQ(s1_->isEmpty(), false);
}

// Testing empty after stack
TEST_F(StackTests, EmptyAfterPushThenPop)
{

	s1_->push(arr[0]);
	s1_->pop();

	// Expect non-empty stack.
	EXPECT_EQ(s1_->isEmpty(), true);
}

/*

------------------Push Tests-------------------------------

*/

// Testing size when push many items
TEST_F(StackTests, PushManyItems)
{
	const int initialSize = 100;

	for (int i = 1; i < initialSize; i++)
	{
		s1_->push(arr[i]);
		EXPECT_EQ(s1_->size(), i);
	}
}

/*

------------------Pop Tests-------------------------------

*/

// Testing value order pop many items
TEST_F(StackTests, PopManyItemsValue)
{
	const int initialSize = 10;

	for (int i = 0; i < initialSize; i++)
	{
		s1_->push(arr[i]);
	}

	for (int i = (initialSize - 1); i >= 0; i--)
	{
		EXPECT_EQ(s1_->pop(), arr[i]);
	}
}

// Testing popping from an empty stack
TEST_F(StackTests, PopFromEmptyStack)
{
    // Ensure that popping from an empty stack returns a default value (0 for int in this case)
    EXPECT_EQ(s1_->pop(), 0);
}

// Testing popping from a non-empty stack
TEST_F(StackTests, PopFromNonEmptyStack)
{
    // Arrange
    const int initialSize = 100;

    for (int i = 1; i <= initialSize; i++)
    {
        s1_->push(arr[i]);
    }

    // Ensure that popping from a non-empty stack returns the top element (arr[initialSize] in this case)
    EXPECT_EQ(s1_->pop(), arr[initialSize]);
    EXPECT_EQ(s1_->size(), initialSize - 1);  // Ensure that the size of the stack is updated
}

// Testing that popping does not affect peeking
TEST_F(StackTests, PopDoesNotAffectPeek)
{
    // Arrange
    const char firstChar = 'a';
    const char secondChar = 'b';

    s1_->push(firstChar);
    s1_->push(secondChar);

    // Act
    s1_->pop();  // Pop one element

    // Ensure that peeking still returns the correct value (firstChar in this case)
    EXPECT_EQ(s1_->peek(), firstChar);
}

// Testing popping from a stack at its maximum capacity
TEST_F(StackTests, PopOnMaxCapacityStack)
{
    // Arrange
    const int maxCapacity = 3;
    Stack<std::string> stringStack(maxCapacity);

    s1_->push(1);
    s1_->push(2);
    s1_->push(3);

    // Ensure that popping from a stack at its maximum capacity returns the correct value (3 in this case)
    EXPECT_EQ(s1_->pop(), 3);
    EXPECT_EQ(s1_->size(), maxCapacity - 1);  // Ensure that the size of the stack is updated
}

// Testing popping from a stack with mixed data types
TEST_F(StackTests, PopOnMixedTypeStack)
{
	Stack<double>* s2_;

    // Arrange
    const double pi = 3.14;
    s2_->push(pi);

    // Ensure that popping from a stack with mixed data types returns the correct value (pi in this case)
    EXPECT_DOUBLE_EQ(s2_->pop(), pi);
    EXPECT_EQ(s2_->size(), 0);  // Ensure that the size of the stack is updated
}

/*

------------------Peek Tests-------------------------------

*/

// Testing peek on an empty stack
TEST_F(StackTests, PeekOnEmptyStack) {
    EXPECT_EQ(s1_->peek(), 0);  // Assuming int has a default value of 0
}

// Testing peek on a non-empty stack
TEST_F(StackTests, PeekOnNonEmptyStack) {
    s1_->push(10);
    s1_->push(20);
    s1_->push(30);

    EXPECT_EQ(s1_->peek(), 30);
}

// Testing peek doesn't modify the stack
TEST_F(StackTests, PeekDoesNotModifyStack) {
    s1_->push(1);
    s1_->push(2);

    s1_->peek();  // Peek without modifying

    EXPECT_EQ(s1_->size(), 2);
    EXPECT_EQ(s1_->pop(), 2);
}

// Testing peek on an stack at maximum capacity
TEST_F(StackTests, PeekOnMaxCapacityStack) {
    s1_->push(1);
    s1_->push(2);
    s1_->push(3);

    EXPECT_EQ(s1_->peek(), 3);
}

// Testing peek on different stack type
TEST_F(StackTests, PeekOnMixedTypeStack) {
    Stack<double>* s2_;
    s2_->push(3.14);

    EXPECT_DOUBLE_EQ(s2_->peek(), 3.14);
}