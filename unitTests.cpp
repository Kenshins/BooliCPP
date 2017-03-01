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

TEST(MissingYearDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_mon = 10;
  testTime.tm_mday = 27;
  maxPublishedDate* maxPub;
  ASSERT_THROW(maxPub = new maxPublishedDate(&testTime), std::invalid_argument);
}

TEST(MissingMonthDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 2015;
  testTime.tm_mday = 27;
  maxPublishedDate* maxPub;
  ASSERT_THROW(maxPub = new maxPublishedDate(&testTime), std::invalid_argument);
}

TEST(MissingDayDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 2015;
  testTime.tm_mon = 10;
  maxPublishedDate* maxPub;
  ASSERT_THROW(maxPub = new maxPublishedDate(&testTime), std::invalid_argument);
}

TEST(InvalidYearDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 1066;
  testTime.tm_mon = 10;
  testTime.tm_mday = 27;
  maxPublishedDate* maxPub;
  ASSERT_THROW(maxPub = new maxPublishedDate(&testTime), std::invalid_argument);
}
  
// month in tm in ctime is from 0 to 11, so confusing
TEST(InvalidMonthDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 1997;
  testTime.tm_mon = 12;
  testTime.tm_mday = 27;
  maxPublishedDate* maxPub;
  ASSERT_THROW(maxPub = new maxPublishedDate(&testTime), std::invalid_argument);
}

TEST(InvalidDayDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 2017;
  testTime.tm_mon = 02;
  testTime.tm_mday = 29;
  maxPublishedDate* maxPub;
  ASSERT_THROW(maxPub = new maxPublishedDate(&testTime), std::invalid_argument);
}

TEST(ListingsSearchConditionSetBbox, MultipleSetCheckBbox) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  sc->SetC(new center(30,30));
  ASSERT_THROW(sc->SetBbox(new bbox(30,30,30,30)), std::invalid_argument);
}

TEST(ListingsSearchConditionSetAreaId, MultipleSetCheckAreaId) {
  listingsSearchCondition_t* mysc = new listingsSearchCondition_t();
  mysc->SetAreaId("4,5,6,6");
  ASSERT_THROW(mysc->SetBbox(new bbox(30,30,30,30)), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinListPriceTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMinListPrice(-22), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxListPriceTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMaxListPrice(-34), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinListSqmPriceTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMinListSqmPrice(-4), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxListSqmPriceTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMaxListSqmPrice(-87), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinRoomsTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMinRooms(-77), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxRoomsTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMaxRooms(-4), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxRentTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMaxRent(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinLivingAreaTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMinLivingArea(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxLivingAreaTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMaxLivingArea(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinPlotAreaTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMinPlotArea(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxPlotAreaTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMaxPlotArea(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinConstructionYearTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMinConstructionYear(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxConstructionYearTest, NegativeCheck) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetMaxConstructionYear(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetObjectTypeTest, IncorrectObjectType) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_THROW(sc->SetObjectType("BananBåt"), std::invalid_argument);
}

TEST(ListingsSearchConditionSetObjectTypeTest, CorrectObjectType) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  ASSERT_NO_THROW(sc->SetObjectType("gård"));
}

TEST(listingsSearchConditionSearchConditionResultTest, FullReturnString) {
  listingsSearchCondition_t* sc = new listingsSearchCondition_t();
  sc->SetQ("Nacka");
  sc->SetMinListPrice(200);
  sc->SetMaxListPrice(10000000);
  sc->SetMinListSqmPrice(200);
  sc->SetMaxListSqmPrice(90000);
  sc->SetMinRooms(2);
  sc->SetMaxRooms(8);
  sc->SetMinLivingArea(10);
  sc->SetMaxLivingArea(500);
  sc->SetMinConstructionYear(1900);
  sc->SetMaxConstructionYear(2016);

  tm minPubDate = {};
  minPubDate.tm_year = 2010;
  minPubDate.tm_mon = 02;
  minPubDate.tm_mday = 27;

  minPublishedDate* minPub = new minPublishedDate(&minPubDate);
  sc->SetMinPublishDate(minPub);
  
  tm maxPubDate = {};
  maxPubDate.tm_year = 2017;
  maxPubDate.tm_mon = 02;
  maxPubDate.tm_mday = 27;

  maxPublishedDate* maxPub = new maxPublishedDate(&maxPubDate);
  sc->SetMaxPublishDate(maxPub);

  sc->SetLimit(30);

  EXPECT_EQ(sc->SearchConditionResult(), "q=Nacka&minListPrice=200&maxListPrice=10000000&minListSqmPrice=200&maxListSqmPrice=90000&minRooms=1&maxRooms=8&minLivingArea=10&maxLivingArea=500&minConstructionYear=1900&maxConstructionYear=2016&minPublished=20100227&maxPublished=20170227&priceDecrease=0&isNewConstruction=0&includeUnset=1&limit=30");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
