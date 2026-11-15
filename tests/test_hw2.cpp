#include <gtest/gtest.h>
#include <sstream>
#include "duration.h"
#include "playlist.h"

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

TEST(PlaylistTest, CapacityFloor) {
    // Tests capacity below 1 defaults to 1 (Invariants)
    Playlist p(0);
    EXPECT_EQ(p.size(), 0);

    // Should successfully add 1 track, but refuse a 2nd since capacity is 1
    Track t1{ "Song A", Duration(2, 30) };
    Track t2{ "Song B", Duration(3, 0) };

    EXPECT_TRUE(p.add_track(t1));
    EXPECT_FALSE(p.add_track(t2)); // Playlist full invariant
    EXPECT_EQ(p.size(), 1);
}

TEST(PlaylistTest, AddTrackAndSize) {
    Playlist p(3);
    EXPECT_EQ(p.size(), 0);

    Track t1{ "Midnight Drive", Duration(3, 42) };
    Track t2{ "Neon Rain", Duration(4, 5) };

    EXPECT_TRUE(p.add_track(t1));
    EXPECT_EQ(p.size(), 1);

    EXPECT_TRUE(p.add_track(t2));
    EXPECT_EQ(p.size(), 2);
}

TEST(PlaylistTest, RefuseEmptyTitle) {
    Playlist p(2);
    Track invalid_track{ "", Duration(2, 30) };

    EXPECT_FALSE(p.add_track(invalid_track)); // Empty title invariant
    EXPECT_EQ(p.size(), 0);
}

TEST(PlaylistTest, TotalLengthCalculation) {
    Playlist p(3);
    // Empty playlist totals 0:00
    EXPECT_EQ(p.total_length().total_seconds(), 0);

    p.add_track(Track{ "Midnight Drive", Duration(3, 42) });
    p.add_track(Track{ "Neon Rain", Duration(4, 5) });

    // 3:42 + 4:05 = 7:47 (467 seconds)
    Duration expected(7, 47);
    EXPECT_TRUE(p.total_length() == expected);
}

TEST(PlaylistTest, FindTrackExistingAndMissing) {
    Playlist p(2);
    Track t1{ "Static", Duration(2, 58) };
    p.add_track(t1);

    // Find existing track
    const Track* found = p.find_track("Static");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->title, "Static");
    EXPECT_EQ(found->length.total_seconds(), 178);

    // Find missing track returns nullptr
    const Track* missing = p.find_track("Missing");
    EXPECT_EQ(missing, nullptr);
}