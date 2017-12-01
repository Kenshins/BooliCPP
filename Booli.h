#ifndef BOOLI_H
#define BOOLI_H
#include "jsonRetriverInterface.h"
#include "result.h"
#include "searchCondition.h"

#include <string>
#include <memory>
#include <cstddef>

class Booli
{
 public:
  Booli(std::shared_ptr<jsonRetriverInterface> jRetriver);
  ~Booli();
  tr::models::result_t FetchListingsResult(listingsSearchCondition* listSearchCondition, std::string const& caller, std::string const& hash);
  std::string FetchListingsJson(listingsSearchCondition* listSearchCondition, std::string const& caller, std::string const& hash);
  
 private:
  std::string GenerateUnique();
  std::string GenerateSHA1Hash(std::string);
  std::string GenerateTime();
  std::shared_ptr<jsonRetriverInterface> m_jsonRetriver;
  
};

#endif // BOOLI_H
