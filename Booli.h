#ifndef BOOLI_H
#define BOOLI_H
#include <string>
#include "jsonRetriverInterface.h"
#include "result.h"
#include "searchCondition.h"

class Booli
{
 public:
  Booli(jsonRetriverInterface* jRetriver);
  ~Booli();
  tr::models::result_t FetchListingsResult(listingsSearchCondition* listSearchCondition, std::string caller, std::string hash);
  std::string FetchListingsJson(listingsSearchCondition* listSearchCondition, std::string caller, std::string hash);
  
 private:
  std::string GenerateUnique();
  std::string GenerateSHA1Hash(std::string);
  std::string GenerateTime();
  jsonRetriverInterface* m_jsonRetriver;
  
};

#endif // BOOLI_H
