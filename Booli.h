#ifndef BOOLI_H
#define BOOLI_H
#include "jsonRetriverInterface.h"
#include "urlGeneratorInterface.h"
#include "Result.h"
#include "searchCondition.h"

#include <string>
#include <memory>
#include <cstddef>

class Booli
{
 public:
  Booli(std::shared_ptr<jsonRetriverInterface> jRetriver, std::shared_ptr<urlGeneratorInterface> uRetriver);
  ~Booli();
  tr::models::result_t FetchListingsResult(searchCondition* searchCondition, std::string const& caller, std::string const& hash);
  std::string FetchListingsJson(searchCondition* searchCondition, std::string const& caller, std::string const& hash);
  private:
  std::shared_ptr<jsonRetriverInterface> m_jsonRetriver;
  std::shared_ptr<urlGeneratorInterface> m_urlGenerator;
  };

#endif // BOOLI_H
