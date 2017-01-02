#ifndef SEARCHCONDITION_H
#define SEARCHCONDITION_H
#include <string>

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

 private:
    
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
