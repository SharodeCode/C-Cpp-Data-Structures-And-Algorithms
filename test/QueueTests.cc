#include <gtest/gtest.h>
#include "../src/DataStructures/Queue/Queue.h"


queue<int> q1_;

// Testing isEmpty

TEST(QueueTesting, InitialQueueIsEmpty) {

  // Expect empty queue.
  EXPECT_EQ(q1_.isEmpty(), true);
}

TEST(QueueTesting, NotEmptyAfterEnqueue) {

  q1_.enqueue(7);

  // Expect non-empty queue.
  EXPECT_EQ(q1_.isEmpty(), false);
}