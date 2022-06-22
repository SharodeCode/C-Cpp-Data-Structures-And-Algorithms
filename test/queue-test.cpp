#include <gtest/gtest.h>

#include "Queue.h"

TEST(QueueTest, isEmptyTest) {
    // Arrange
    queue<int> q;

    // Result
    EXPECT_TRUE(q.isEmpty());
}
