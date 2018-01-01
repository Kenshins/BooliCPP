#include "searchCondition.h"
#include "jsonRetriverFake.h"
#include "Booli.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <ctime>
#include <memory>

TEST(Bboxtest, NegativeLatLo) { 
  ASSERT_THROW(bbox(-5, 1, 2, 2), std::invalid_argument);
}

TEST(CenterTest, NegativeLat) {
 ASSERT_THROW(center(-5, 1), std::invalid_argument);
}

TEST(CenterTest, ToHighLat) {
 ASSERT_THROW(center(91, 1), std::invalid_argument);
}

TEST(CenterTest, NegativeLong) {
 ASSERT_THROW(center(1, -5), std::invalid_argument);
}

TEST(CenterTest, ToHighLong) {
 ASSERT_THROW(center(1, 181), std::invalid_argument);
}

TEST(DimensionTest, NegativeX) {
 ASSERT_THROW(dimension(-3, 1), std::invalid_argument);
}

TEST(DimensionTest, NegativeY) {
 ASSERT_THROW(dimension(1, -4), std::invalid_argument);
}

TEST(MinPublishedDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 2016;
  testTime.tm_mon = 11;
  testTime.tm_mday = 28;
  minPublishedDate minPub = minPublishedDate(&testTime);
  EXPECT_EQ(minPub.retMinPublishedDate(), "20161128");
}

TEST(MaxPublishedDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 2015;
  testTime.tm_mon = 10;
  testTime.tm_mday = 27;
  maxPublishedDate maxPub = maxPublishedDate(&testTime);
  EXPECT_EQ(maxPub.retMaxPublishedDate(), "20151027");
}

TEST(MissingYearDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_mon = 10;
  testTime.tm_mday = 27;
  ASSERT_THROW(maxPublishedDate maxPub = maxPublishedDate(&testTime), std::invalid_argument);
}

TEST(MissingMonthDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 2015;
  testTime.tm_mday = 27;
  ASSERT_THROW(maxPublishedDate maxPub = maxPublishedDate(&testTime), std::invalid_argument);
}

TEST(MissingDayDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 2015;
  testTime.tm_mon = 10;
  ASSERT_THROW(maxPublishedDate maxPub = maxPublishedDate(&testTime), std::invalid_argument);
}

TEST(InvalidYearDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 1066;
  testTime.tm_mon = 10;
  testTime.tm_mday = 27;
  ASSERT_THROW(maxPublishedDate maxPub = maxPublishedDate(&testTime), std::invalid_argument);
}
  
// month in tm in ctime is from 0 to 11, so confusing
TEST(InvalidMonthDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 1997;
  testTime.tm_mon = 12;
  testTime.tm_mday = 27;
  ASSERT_THROW(maxPublishedDate maxPub = maxPublishedDate(&testTime), std::invalid_argument);
}

TEST(InvalidDayDateTest, DateTheSame) {
  tm testTime = {};
  testTime.tm_year = 2017;
  testTime.tm_mon = 02;
  testTime.tm_mday = 29;
  ASSERT_THROW(maxPublishedDate maxPub = maxPublishedDate(&testTime), std::invalid_argument);
}

TEST(ListingsSearchConditionSetBbox, MultipleSetCheckBbox) {
  listingsSearchCondition sc = listingsSearchCondition();
  center c = center(30,30);
  sc.SetC(&c);
  bbox b = bbox(30,30,30,30);
  ASSERT_THROW(sc.SetBbox(&b), std::invalid_argument);
}

TEST(ListingsSearchConditionSetAreaId, MultipleSetCheckAreaId) {
  listingsSearchCondition mysc = listingsSearchCondition();
  mysc.SetAreaId("4,5,6,6");
  bbox b = bbox(30,30,30,30);
  ASSERT_THROW(mysc.SetBbox(&b), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinListPriceTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMinListPrice(-22), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxListPriceTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMaxListPrice(-34), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinListSqmPriceTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMinListSqmPrice(-4), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxListSqmPriceTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMaxListSqmPrice(-87), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinRoomsTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMinRooms(-77), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxRoomsTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMaxRooms(-4), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxRentTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMaxRent(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinLivingAreaTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMinLivingArea(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxLivingAreaTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMaxLivingArea(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinPlotAreaTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMinPlotArea(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxPlotAreaTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMaxPlotArea(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMinConstructionYearTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMinConstructionYear(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetMaxConstructionYearTest, NegativeCheck) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetMaxConstructionYear(-1), std::invalid_argument);
}

TEST(ListingsSearchConditionSetObjectTypeTest, IncorrectObjectType) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_THROW(sc.SetObjectType("BananBåt"), std::invalid_argument);
}

TEST(ListingsSearchConditionSetObjectTypeTest, CorrectObjectType) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_NO_THROW(sc.SetObjectType("gård"));
}

TEST(ListingsSearchConditionSetObjectTypeTest, CorrectObjectTypeUpperAndLower) {
  listingsSearchCondition sc = listingsSearchCondition();
  ASSERT_NO_THROW(sc.SetObjectType("GårD"));
}

TEST(listingsSearchConditionSearchConditionResultTest, FullReturnString) {
  listingsSearchCondition sc = listingsSearchCondition();
  sc.SetQ("Nacka");
  sc.SetMinListPrice(200);
  sc.SetMaxListPrice(10000000);
  sc.SetMinListSqmPrice(200);
  sc.SetMaxListSqmPrice(90000);
  sc.SetMinRooms(2);
  sc.SetMaxRooms(8);
  sc.SetMinLivingArea(10);
  sc.SetMaxLivingArea(500);
  sc.SetMinConstructionYear(1900);
  sc.SetMaxConstructionYear(2016);

  tm minPubDate = {};
  minPubDate.tm_year = 2010;
  minPubDate.tm_mon = 02;
  minPubDate.tm_mday = 27;

  minPublishedDate minPub = minPublishedDate(&minPubDate);
  sc.SetMinPublishDate(&minPub);
  
  tm maxPubDate = {};
  maxPubDate.tm_year = 2017;
  maxPubDate.tm_mon = 02;
  maxPubDate.tm_mday = 27;

  maxPublishedDate maxPub = maxPublishedDate(&maxPubDate);
  sc.SetMaxPublishDate(&maxPub);

  sc.SetLimit(30);

  EXPECT_EQ(sc.SearchConditionResult(), "q=Nacka&minListPrice=200&maxListPrice=10000000&minListSqmPrice=200&maxListSqmPrice=90000&minRooms=2&maxRooms=8&minLivingArea=10&maxLivingArea=500&minConstructionYear=1900&maxConstructionYear=2016&minPublished=20100227&maxPublished=20170227&limit=30");
}

TEST(listingsSearchConditionSearchConditionResultTest, ObjectTypeReturnString) {
  listingsSearchCondition sc = listingsSearchCondition();
  sc.SetQ("Norrköping");
  sc.SetObjectType("lägenhet");
  EXPECT_EQ(sc.SearchConditionResult(), "q=Norrköping&objectType=lägenhet&limit=10");
}

// This uses fixed data from testdata.json
TEST(BooliResultTest, SimpleTest) {
  Booli* b = new Booli(std::make_shared<jsonRetriverFake>());
  listingsSearchCondition lSC = listingsSearchCondition();
  lSC.SetQ("Nacka");
  std::string caller = "blabla";
  std::string hash = "P8rfkeJvKORgHjvX61npRXVGG2kHPm9pXNZetHS";
  tr::models::result_t result = b->FetchListingsResult(&lSC, caller, hash);
  EXPECT_EQ(result.Count, 10);
  delete b;
}

// This uses fixed data from testdata.json
TEST(BooliResultTest, AdvancedTest) {
  Booli* b = new Booli(std::make_shared<jsonRetriverFake>());
  listingsSearchCondition lSC = listingsSearchCondition();
  lSC.SetQ("Nacka");
  std::string caller = "blabla";
  std::string hash = "P8rfkeJvKORgHjvX61npRXVGG2kHPm9pXNZetHS";
  tr::models::result_t result = b->FetchListingsResult(&lSC, caller, hash);

  for (auto listings : result.Listings) // access by reference to avoid copying
    {  
        if (listings.BooliId == 2284444)
        {
	  EXPECT_EQ(listings.LivingArea, 101);
	  EXPECT_EQ(listings.Rooms, 4);
	  EXPECT_EQ(listings.Source.Id, 1573);
	  EXPECT_EQ(listings.Source.Type, "Broker");
	  EXPECT_EQ(listings.IsNewConstruction, true);
	  EXPECT_EQ(listings.Location.Position.Longitude, 18.11234352);
        }
    }
  delete b;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
