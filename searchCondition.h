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

class searchCondition_t
{
 public:
  void SetQ(std::string q);
  virtual std::string SearchConditionResult() = 0;

 private:
  std::string q;
};

// Listings search condition

class listingsSearchCondition_t : public searchCondition_t
{
 public:
  listingsSearchCondition_t();
  std::string SearchConditionResult();
  void SetC(center *c);
  void SetDim(dimension *d);
  void SetBbox(bbox *b);
  void SetAreaId(std::string a);
  void SetMinListPrice(double minLP);
  void SetMaxListPrice(double maxLP);
  void SetMinListSqmPrice(double minLSP);
  void SetMaxListSqmPrice(double maxLSP);
  void SetMinRooms(int minR);
  void SetMaxRooms(int maxR);
  void SetMaxRent(double maxRent);
  void SetMinLivingArea(int minLA);
  void SetMaxLivingArea(int maxLA);
  void SetMinPlotArea(int minPA);
  void SetMaxPlotArea(int maxPA);
  void SetObjectType(std::string *oT);
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
  center *c;
  dimension *dim;
  bbox *bB;
  std::string areaId;
  double minListPrice;
  double maxListPrice;
  double minListSqmPrice;
  double maxListSqmPrice;
  int minRooms;
  int maxRooms;
  double maxRent;
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
};

class soldSearchCondition_t : public searchCondition_t
{
 public:
  soldSearchCondition_t();
  std::string SearchConditionResult();

};

class areasSearchCondition_t : public searchCondition_t
{
 public:
  areasSearchCondition_t();
  std::string SearchConditionResult();

};

class util
{
 public:
  static bool valid_date(int year,int month,int day);

 private:
  static bool isleapyear(int year);
};

#endif // SEARCHCONDITION_H
