#include "searchCondition.h"
#include "jsonRetriverFake.h"
#include "jsonRetriverMock.h"
#include "urlGenerator.h"
#include "Booli.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <ctime>
#include <memory>
#include <string>

using ::testing::AtLeast; 

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

  EXPECT_EQ(sc.SearchConditionResult(), "listings?q=Nacka&minRooms=2&maxRooms=8&minLivingArea=10&maxLivingArea=500&minConstructionYear=1900&maxConstructionYear=2016&minPublished=20100227&maxPublished=20170227&minListPrice=200&maxListPrice=10000000&minListSqmPrice=200&maxListSqmPrice=90000&limit=30");
}

TEST(listingsSearchConditionSearchConditionResultTest, ObjectTypeReturnString) {
  listingsSearchCondition sc = listingsSearchCondition();
  sc.SetQ("Norrköping");
  sc.SetObjectType("lägenhet");
  EXPECT_EQ(sc.SearchConditionResult(), "listings?q=Norrköping&objectType=lägenhet&limit=10");
}

TEST(soldSearchConditionSearchConditionResultTest, FullReturnString) {
  soldSearchCondition sc = soldSearchCondition();
  sc.SetQ("Nacka");
  sc.SetMinSoldPrice(200);
  sc.SetMaxSoldPrice(10000000);
  sc.SetMinSoldSqmPrice(200);
  sc.SetMaxSoldSqmPrice(90000);
  sc.SetMinRooms(2);
  sc.SetMaxRooms(8);
  sc.SetMinLivingArea(10);
  sc.SetMaxLivingArea(500);
  sc.SetMinConstructionYear(1900);
  sc.SetMaxConstructionYear(2016);

  tm minSDate = {};
  minSDate.tm_year = 2010;
  minSDate.tm_mon = 02;
  minSDate.tm_mday = 27;

  minSoldDate minSold = minSoldDate(&minSDate);
  sc.SetMinSoldDate(&minSold);
  
  tm maxSDate = {};
  maxSDate.tm_year = 2017;
  maxSDate.tm_mon = 02;
  maxSDate.tm_mday = 27;

  maxSoldDate maxSold = maxSoldDate(&maxSDate);
  sc.SetMaxSoldDate(&maxSold);

  sc.SetLimit(30);

  EXPECT_EQ(sc.SearchConditionResult(), "sold?q=Nacka&minRooms=2&maxRooms=8&minLivingArea=10&maxLivingArea=500&minConstructionYear=1900&maxConstructionYear=2016&minSoldPrice=200&maxSoldPrice=10000000&minSoldSqmPrice=200&maxSoldSqmPrice=90000&minSoldDate=20100227&maxSoldDate=20170227&limit=30");
}

// This uses fixed data from listingstestdata.json
TEST(BooliListingsResultTest, SimpleTest) {
  Booli* b = new Booli(std::make_shared<jsonRetriverFake>(), std::make_shared<urlGenerator>());
  listingsSearchCondition lSC = listingsSearchCondition();
  lSC.SetQ("Nacka");
  std::string caller = "blabla";
  std::string hash = "P8rfkeJvKORgHjvX61npRXVGG2kHPm9pXNZetHS";
  tr::models::booliresult_t booliResult = b->FetchResult(&lSC, caller, hash);
  EXPECT_EQ(booliResult.Count, 10);
  delete b;
}

// This uses fixed data from listingstestdata.json
TEST(BooliListingsResultTest, AdvancedTest) {
  Booli* b = new Booli(std::make_shared<jsonRetriverFake>(), std::make_shared<urlGenerator>());
  listingsSearchCondition lSC = listingsSearchCondition();
  lSC.SetQ("Nacka");
  std::string caller = "blabla";
  std::string hash = "P8rfkeJvKORgHjvX61npRXVGG2kHPm9pXNZetHS";
  tr::models::booliresult_t booliResult = b->FetchResult(&lSC, caller, hash);

  bool found = false;
  for (auto listings : booliResult.Listings)
    {  
        if (listings.BooliId == 2284444)
        {
	  EXPECT_EQ(listings.LivingArea, 101);
	  EXPECT_EQ(listings.Rooms, 4);
	  EXPECT_EQ(listings.Source.Id, 1573);
	  EXPECT_EQ(listings.Source.Type, "Broker");
	  EXPECT_EQ(listings.IsNewConstruction, true);
	  EXPECT_EQ(listings.Location.Position.Longitude, 18.11234352);
	  found = true;
        }
    }

    if (!found)
    FAIL() << "BooliId 2284444 could not be found in the test json file!";
    
  delete b;
}

// This uses fixed data from soldtestdata.json
TEST(BooliSoldResultTest, SimpleTest) {
  Booli* b = new Booli(std::make_shared<jsonRetriverFake>(), std::make_shared<urlGenerator>());
  soldSearchCondition sSC = soldSearchCondition();
  sSC.SetQ("Nacka");
  std::string caller = "blabla";
  std::string hash = "P8rfkeJvKORgHjvX61npRXVGG2kHPm9pXNZetHS";
  tr::models::booliresult_t booliResult = b->FetchResult(&sSC, caller, hash);
  EXPECT_EQ(booliResult.Count, 30);
  delete b;
}

// This uses fixed data from soldtestdata.json
TEST(BooliSoldResultTest, AdvancedTest) {
  Booli* b = new Booli(std::make_shared<jsonRetriverFake>(), std::make_shared<urlGenerator>());
  soldSearchCondition sSC = soldSearchCondition();
  sSC.SetQ("Nacka");
  std::string caller = "blabla";
  std::string hash = "P8rfkeJvKORgHjvX61npRXVGG2kHPm9pXNZetHS";
  tr::models::booliresult_t booliResult = b->FetchResult(&sSC, caller, hash);

  bool found = false;
  for (auto sold : booliResult.Sold)
    {  
        if (sold.BooliId == 3069049)
        {
	  EXPECT_EQ(sold.LivingArea, 81);
	  EXPECT_EQ(sold.Rooms, 3);
	  EXPECT_EQ(sold.Source.Id, 58);
	  EXPECT_EQ(sold.Source.Type, "Broker");
	  EXPECT_EQ(sold.Location.Position.Longitude, 18.25889111);
	  found = true;
        }	
    }
    if (!found)
    FAIL() << "BooliId 3069049 could not be found in the test json file!";
    
  delete b;
}

// This uses fixed data from areastestdata.json
TEST(BooliAreasResultTest, SimpleTest) {
  Booli* b = new Booli(std::make_shared<jsonRetriverFake>(), std::make_shared<urlGenerator>());
  areaSearchCondition aSC = areaSearchCondition();
  aSC.SetQ("Nacka");
  std::string caller = "blabla";
  std::string hash = "P8rfkeJvKORgHjvX61npRXVGG2kHPm9pXNZetHS";
  tr::models::booliresult_t booliResult = b->FetchResult(&aSC, caller, hash);
  EXPECT_EQ(booliResult.Count, 9);
  delete b;
}

// This uses fixed data from areastestdata.json
TEST(BooliAreasResultTest, AdvancedTest) {
  Booli* b = new Booli(std::make_shared<jsonRetriverFake>(), std::make_shared<urlGenerator>());
  areaSearchCondition aSC = areaSearchCondition();
  aSC.SetQ("Nacka");
  std::string caller = "blabla";
  std::string hash = "P8rfkeJvKORgHjvX61npRXVGG2kHPm9pXNZetHS";
  tr::models::booliresult_t booliResult = b->FetchResult(&aSC, caller, hash);

  bool found = false;
  for (auto areas : booliResult.Areas)
    {  
        if (areas.BooliId == 930508)
        {
	  EXPECT_EQ(areas.Name, "Nacka Strand");
	  EXPECT_EQ(areas.ParentTypes[0], "Kommun");
	  EXPECT_EQ(areas.FullName, "Nacka Strand, Nacka");
	  found = true;
        }	
    }

  if (!found)
    FAIL() << "BooliId 930508 could not be found in the test json file!";
  
  delete b;
}

//TEST(jsonRetriverTest, SimpleTest) {

//  std::string returnStr = "https://api.booli.se/listings.q=Nacka&limit=10&callerId=blabla&time=.*&unique=.*";
  
//  std::shared_ptr<MockJsonRetriver> jsonRetriver(new MockJsonRetriver());
//  EXPECT_CALL(*jsonRetriver, RetriveJson(testing::ContainsRegex(returnStr))).Times(AtLeast(1));
  
//  listingsSearchCondition lSC = listingsSearchCondition();
//  lSC.SetQ("Nacka");

//  std::shared_ptr<urlGenerator> urlGen(new urlGenerator);
  
//  Booli booli(jsonRetriver, urlGen);
  //booli.FetchResult(&lSC, "blabla", "");
  
//}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
