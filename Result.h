#ifndef RESULT_H
#define RESULT_H
#include <string>

class Result
{
 public:
  Result();
  GetTotalCount();
  GetCount();
  
 private:
  int totalCount;
  int count;
};

class AreaResult: public Result
{

};

class ListingsResult: public Result
{

};

class SoldResult: public Result
{

};

class Listings
{

};

class Location
{

};

#endif // RESULT_H
