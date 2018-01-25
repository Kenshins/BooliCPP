#ifndef SEARCHCONDITION_H
#define SEARCHCONDITION_H
#include <string>
#include <ctime>

// Supporting datatypes

class center
{
 public:
  center(int la, int ln);
  void SetLatLong(int la, int ln);
  void SetLat(int la);
  void SetLong(int ln);
  std::string RetCenter();

 private:
  int latitude;
  int longitude;

};

class dimension
{
 public:
  dimension(int x, int y);
  void SetX(int x);
  void SetY(int y);
  std::string RetDim();
  
 private:
  int x;
  int y;
};

class bbox
{
 public:
  bbox(double lat_lo, double lng_lo, double lat_hi, double lng_hi);
  void setBbox(double lat_lo, double lng_lo, double lat_hi, double lng_hi);
  std::string RetBbox();
  
 private:
  double latLo;
  double lngLo;
  double latHi;
  double lngHi;
};

class objectType
{
 public:
  objectType(std::string oT);
  void setObjectType(std::string oT);
  std::string retObjectType();
  
 private:
  std::string object_type;
};

class minPublishedDate
{
 public:
  minPublishedDate(tm *t);
  std::string retMinPublishedDate();
  
 private:
  tm *minPubDateTime;
};

class maxPublishedDate
{
public:
  maxPublishedDate(tm *t);
  std::string retMaxPublishedDate();

 private:
  tm *maxPubDateTime;
};

class minSoldDate
{
 public:
  minSoldDate(tm *t);
  std::string retMinSoldDate();
  
 private:
  tm *minSoldDateTime;
};

class maxSoldDate
{
public:
  maxSoldDate(tm *t);
  std::string retMaxSoldDate();

 private:
  tm *maxSoldDateTime;
};

// Search condition base class

class searchCondition
{
 public:
  enum MainInput {Q, BBOX, DIM, CENTER, AREAID}; 
  void SetQ(std::string q);
  virtual std::string SearchConditionResult() = 0;
  virtual void checkNoDuplicateMainInput(MainInput in) = 0;
  void SetC(center *c);
  void SetDim(dimension *d);
  void SetBbox(bbox *b);
  void SetAreaId(std::string aId);
  void SetMinRooms(int minR);
  void SetMaxRooms(int maxR);
  void SetMaxRent(int maxRe);
  void SetMinLivingArea(int minLA);
  void SetMaxLivingArea(int maxLA);
  void SetMinPlotArea(int minPA);
  void SetMaxPlotArea(int maxPA);
  void SetObjectType(std::string oT);
  void SetMinConstructionYear(int minCY);
  void SetMaxConstructionYear(int maxCY);
  void SetMinPublishDate(minPublishedDate *miPD);
  void SetMaxPublishDate(maxPublishedDate *maPD);
  void SetPriceDecrease(bool pD);
  void SetIsNewConstruction(bool nC);
  void SetIncludeUnset(bool iU);
  void SetLimit(int l);
  void SetOffset(int o);
  
 protected:
  std::string CommonSearchConditionResult(std::string tableSpecific);
  std::string query = "";
  center *cent = NULL;
  dimension *dim = NULL;
  bbox *bB = NULL;
  std::string areaId = "";
  int minRooms = 0;
  int maxRooms = 0;
  int maxRent = 0;
  int minLivingArea = 0;
  int maxLivingArea = 0; 
  int minPlotArea = 0;
  int maxPlotArea = 0;
  objectType *objectT = NULL;
  int minConstructionYear = 0;
  int maxConstructionYear = 0;
  minPublishedDate *minPubDate = NULL;
  maxPublishedDate *maxPubDate = NULL;
  bool isNewConstruction  = false;
  bool includeUnset = true;
  int limit = 10;
  int offset = 0;
};

// Sold search condition

class soldSearchCondition : public searchCondition
{
 public:
  soldSearchCondition();
  std::string SearchConditionResult();
  void SetMinSoldPrice(int minSP);
  void SetMaxSoldPrice(int maxSP);
  void SetMinSoldSqmPrice(int minSSP);
  void SetMaxSoldSqmPrice(int maxSSP);
  void SetMinSoldDate(minSoldDate *minSD);
  void SetMaxSoldDate(maxSoldDate *maxSD);

 private:
  int minSoldPrice = 0;
  int maxSoldPrice = 0;
  int minSoldSqmPrice = 0;
  int maxSoldSqmPrice = 0;
  minSoldDate *minSDate = NULL;
  maxSoldDate *maxSDate = NULL;

  void checkNoDuplicateMainInput(MainInput in);  
};

// Area search condition

// Todo, not done
class areasSearchCondition : public searchCondition
{
 public:
  areasSearchCondition();
  std::string SearchConditionResult();
};


class listingsSearchCondition : public searchCondition
{  
 public:
  listingsSearchCondition();
  std::string SearchConditionResult();
  void SetMinListPrice(int minLP);
  void SetMaxListPrice(int maxLP);
  void SetMinListSqmPrice(int minLSP);
  void SetMaxListSqmPrice(int maxLSP);
  void SetPriceDecrease(bool pD);
  
 private:
  
  int minListPrice = 0;
  int maxListPrice = 0;
  int minListSqmPrice = 0;
  int maxListSqmPrice = 0;
  bool priceDecrease = false;
  
  void checkNoDuplicateMainInput(MainInput in);
};

class util
{
 public:
  static bool valid_date(int year,int month,int day);
  static std::string intToString(int d);
  
 private:
  static bool isleapyear(int year);
  
};

#endif // SEARCHCONDITION_H
