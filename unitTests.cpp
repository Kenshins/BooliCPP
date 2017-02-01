#include "searchCondition.h"
#include <gtest/gtest.h>
#include <stdexcept>
 
TEST(Bboxtest, NegativeLatLo) { 
  ASSERT_THROW(new bbox(-5, 1, 2, 2), std::invalid_argument);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
