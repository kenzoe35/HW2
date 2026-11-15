#include <gtest/gtest.h>
#include <sstream>
#include "duration.h"

// Test constructor defaults and basic values
TEST(DurationTest, DefaultAndBasicConstructor) {
    Duration d1;
    EXPECT_EQ(d1.total_seconds(), 0);

    Duration d2(3, 5); // 3m 5s = 185 seconds
    EXPECT_EQ(d2.total_seconds(), 185);
}

// Test boundary: seconds past 59 carry into minutes
TEST(DurationTest, SecondsCarryIntoMinutes) {
    Duration d(0, 75); // 75 seconds -> 1 min 15 sec = 75 total seconds
    EXPECT_EQ(d.total_seconds(), 75);
}

// Test boundary: negative totals clamp to zero
TEST(DurationTest, NegativeClamping) {
    Duration d1(0, -5); // Negative seconds
    EXPECT_EQ(d1.total_seconds(), 0);

    Duration d2(-2, 10); // Negative minutes
    EXPECT_EQ(d2.total_seconds(), 0);
}

// Test operator+
TEST(DurationTest, AdditionOperator) {
    Duration d1(1, 30); // 90s
    Duration d2(2, 15); // 135s
    Duration sum = d1 + d2; // 3m 45s = 225s
    EXPECT_EQ(sum.total_seconds(), 225);
}

// Test operator==
TEST(DurationTest, EqualityOperator) {
    Duration d1(2, 30);
    Duration d2(1, 90); // 150s total for both
    Duration d3(2, 31);

    EXPECT_TRUE(d1 == d2);
    EXPECT_FALSE(d1 == d3);
}

// Test operator<< using std::ostringstream as required
TEST(DurationTest, StreamInsertionOperator) {
    Duration d(3, 5);
    std::ostringstream oss;
    oss << d;
    EXPECT_EQ(oss.str(), "3:05");
}
