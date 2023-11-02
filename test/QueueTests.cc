#include <random>
#include <gtest/gtest.h>
#include "../src/DataStructures/Queue/Queue.h"




  class QueueTesting : public testing::Test {

  protected:

    queue<int> * q1_;
    int arr[100];

    QueueTesting() {
      std::srand(std::time(nullptr));

      for(int i = 0; i < 100; i++){
        arr[i] =  (rand() % 10);
      }

    }

    virtual ~QueueTesting() {
    }

    virtual void SetUp() {
      q1_ = new queue<int>();
    }

    virtual void TearDown() {
      delete q1_;
    }
  };

/*

------------------isEmpty Tests-------------------------------

*/

// Testing isEmpty

TEST_F(QueueTesting, InitialQueueIsEmpty) {

  // Expect empty queue.
  EXPECT_EQ(q1_->isEmpty(), true);
}

// Testing non empty after enqueue
TEST_F(QueueTesting, NotEmptyAfterEnqueue) {

  int random_variable = std::rand();

  q1_->enqueue(random_variable);

  // Expect non-empty queue.
  EXPECT_EQ(q1_->isEmpty(), false);
}

// Testing empty after dequeue
TEST_F(QueueTesting, EmptyAfterEnqueueThenDequeue) {

  q1_->enqueue(arr[0]);
  q1_->dequeue();

  // Expect non-empty queue.
  EXPECT_EQ(q1_->isEmpty(), true);
}

/*

------------------Enqueue Tests-------------------------------

*/

// Testing size when enqueue many items
TEST_F(QueueTesting, EnqueueManyItems) {
  const int initialSize = 100;

  for(int i = 1; i < initialSize; i++){
    q1_->enqueue(arr[i]);
    EXPECT_EQ(q1_->size(), i);
  }

}


/*

------------------Dequeue Tests-------------------------------

*/


// Testing size when dequeue many items
TEST_F(QueueTesting, DequeueManyItemsSize) {
    const int initialSize = 100;

    for(int i = 1; i <= initialSize; i++){
        q1_->enqueue(7);
    }

    for(int i = initialSize; i > 0; i--){
        q1_->dequeue();
        EXPECT_EQ(q1_->size(), i - 1);  // Adjust the expected size
    }
}


// Testing value order dequeue many items
TEST_F(QueueTesting, DequeueManyItemsValue) {
  const int initialSize = 10;

  for(int i = 0; i < initialSize; i++){
    q1_->enqueue(arr[i]);
  }

  for(int i = 0; i < initialSize; i++){
    EXPECT_EQ(q1_->dequeue(), arr[i]);
  }

}