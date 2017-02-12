#include "searchCondition.h"
#include <gtest/gtest.h>
#include <stdexcept>
#include <ctime>
 
TEST(Bboxtest, NegativeLatLo) { 
  ASSERT_THROW(new bbox(-5, 1, 2, 2), std::invalid_argument);
}

TEST(CenterTest, NegativeLat) {
 ASSERT_THROW(new center(-5, 1), std::invalid_argument);
}

TEST(CenterTest, ToHighLat) {
 ASSERT_THROW(new center(91, 1), std::invalid_argument);
}

TEST(CenterTest, NegativeLong) {
 ASSERT_THROW(new center(1, -5), std::invalid_argument);
}

TEST(CenterTest, ToHighLong) {
 ASSERT_THROW(new center(1, 181), std::invalid_argument);
}

TEST(DimensionTest, NegativeX) {
 ASSERT_THROW(new dimension(-3, 1), std::invalid_argument);
}

TEST(DimensionTest, NegativeY) {
 ASSERT_THROW(new dimension(1, -4), std::invalid_argument);
}

TEST(MinPublishedDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 2016;
  testTime.tm_mon = 11;
  testTime.tm_mday = 28;
  minPublishedDate* minPub = new minPublishedDate(&testTime);
  EXPECT_EQ(minPub->retMinPublishedDate(), "20161128");
}

TEST(MaxPublishedDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 2015;
  testTime.tm_mon = 10;
  testTime.tm_mday = 27;
  maxPublishedDate* maxPub = new maxPublishedDate(&testTime);
  EXPECT_EQ(maxPub->retMaxPublishedDate(), "20151027");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
