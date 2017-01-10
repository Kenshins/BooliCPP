#ifndef SEARCHCONDITION_H
#define SEARCHCONDITION_H
#include <string>

// Supporting datatypes

class center
{
 public:
  center();
  center(int la, int ln);
  void SetLatLong(int la, int ln);
  void SetLat(int la);
  void SetLong(int ln);

 private:
  int latitude;
  int longitude;

};

class searchCondition_t
{
 public:
  void SetQ(std::string q);
  virtual std::string SearchConditionResult() = 0;

 private:
  std::string q;
};

class listingsSearchCondition_t : public searchCondition_t
{
 public:
  listingsSearchCondition_t();
  std::string SearchConditionResult();
  void SetC(int la, int ln);
  void SetDim(std::string d);
  void SetBbox(std::string b);
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
  void SetMinConstructionYear(int minCY);
  void SetMaxConstructionYear(int maxCY);
  void SetPriceDecrease(bool pD);
  void SetIsNewConstruction(bool nC);
  void SetIncludeUnset(bool iU);
  void SetLimit(int l);
  void SetOffset(int o);
  
 private:
  center c; // Should be own type
  std::string dim; // Should be own type
  std::string bbox; // Should be own type
  std::string areaId; // Should be own type
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
  // objectType, should be a enum
  int minConstructionYear;
  int maxConstructionYear;
  // minPublished date type
  // maxPublished date type
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


#endif // SEARCHCONDITION_H
