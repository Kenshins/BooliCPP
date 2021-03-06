#ifndef BOOLI_H
#define BOOLI_H
#include "jsonRetriverInterface.h"
#include "urlGeneratorInterface.h"
#include "autoGeneratedJsonClasses/Booliresult.h"
#include "searchCondition.h"

#include <string>
#include <memory>
#include <cstddef>

class Booli
{
 public:
  Booli(std::shared_ptr<jsonRetriverInterface> jRetriver, std::shared_ptr<urlGeneratorInterface> uRetriver);
  ~Booli();
  tr::models::booliresult_t FetchResult(searchConditonBase* searchCondition, std::string const& caller, std::string const& hash);
  std::string FetchListingsJson(std::string searchCondition, std::string const& caller, std::string const& hash);
 private:
  tr::models::booliresult_t FetchBooliResult(std::string readBuffer);
  std::shared_ptr<jsonRetriverInterface> m_jsonRetriver;
  std::shared_ptr<urlGeneratorInterface> m_urlGenerator;
  };

#endif // BOOLI_H
