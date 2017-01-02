#ifndef SEARCHCONDITION_H
#define SEARCHCONDITION_H
#include <string>

class SearchCondition
{
 public:
  SearchCondition();
  void SetQ(std::string q);
  virtual std::string SearchConditionResult() = 0;

 private:
  std::string q;
};

class ListingsSearchCondition : public SearchCondition
{
 public:
  ListingsSearchCondition();
  std::string SearchConditionResult();

 private:
    
};

class SoldSearchCondition : public SearchCondition
{
 public:
  SoldSearchCondition();
  std::string SearchConditionResult();

};

class AreasSearchCondition : public SearchCondition
{
 public:
  AreasSearchCondition();
  std::string SearchConditionResult();

};

#endif // SEARCHCONDITION_H
