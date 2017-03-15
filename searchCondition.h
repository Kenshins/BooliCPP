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

// Search condition base class

class searchCondition
{
 public:
  void SetQ(std::string q);
  virtual std::string SearchConditionResult() = 0;

 protected:
  std::string q;
};

// Listings search condition

class listingsSearchCondition : public searchCondition
{
  enum MainInput {Q, BBOX, DIM, CENTER, AREAID}; 
  
 public:
  listingsSearchCondition();
  std::string SearchConditionResult();
  void SetQ(std::string q);
  void SetC(center *c);
  void SetDim(dimension *d);
  void SetBbox(bbox *b);
  void SetAreaId(std::string aId);
  void SetMinListPrice(int minLP);
  void SetMaxListPrice(int maxLP);
  void SetMinListSqmPrice(int minLSP);
  void SetMaxListSqmPrice(int maxLSP);
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
  
 private:
  std::string query;
  center *cent;
  dimension *dim;
  bbox *bB;
  std::string areaId;
  int minListPrice;
  int maxListPrice;
  int minListSqmPrice;
  int maxListSqmPrice;
  int minRooms;
  int maxRooms;
  int maxRent;
  int minLivingArea;
  int maxLivingArea;
  int minPlotArea;
  int maxPlotArea;
  objectType *objectT;
  int minConstructionYear;
  int maxConstructionYear;
  minPublishedDate *minPubDate;
  maxPublishedDate *maxPubDate;
  bool priceDecrease;
  bool isNewConstruction;
  bool includeUnset;
  int limit;
  int offset;
  void checkNoDuplicateMainInput(MainInput in);
};

class soldSearchCondition : public searchCondition
{
 public:
  soldSearchCondition();
  std::string SearchConditionResult();
};

class areasSearchCondition : public searchCondition
{
 public:
  areasSearchCondition();
  std::string SearchConditionResult();
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
