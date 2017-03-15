#ifndef BOOLI_H
#define BOOLI_H
#include <string>
#include "retriver.h"
#include "result.h"
#include "searchCondition.h"

class Booli
{
 public:
  Booli();
  ~Booli();
  tr::models::result_t FetchListings(listingsSearchCondition* listSearchCondition, std::string caller, std::string hash);

 private:
  std::string GenerateUnique();
  std::string GenerateSHA1Hash(std::string);
  std::string GenerateTime();
  jsonRetriver* m_jsonRetriver;
  
};

#endif // BOOLI_H
