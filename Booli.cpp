#include "Booli.h"
#include "jsonRetriverInterface.h"
#include "urlGeneratorInterface.h"
#include "searchCondition.h"
#include "rapidjson/document.h"
#include "autoGeneratedJsonClasses/Result.h"

#include <openssl/sha.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <bitset>
#include <memory>

using namespace std;
using namespace rapidjson;

Booli::Booli(shared_ptr<jsonRetriverInterface> jRetriver, shared_ptr<urlGeneratorInterface> uGenerator)
{
  m_jsonRetriver = jRetriver;
  m_urlGenerator = uGenerator;
}

Booli::~Booli()
{
}

// maybe do some cast magic here


// Listings
tr::models::result_t Booli::FetchListingsResult(listingsSearchCondition* listSearchCondition, std::string const& caller, std::string const& hash)
{
  std::string readBuffer = FetchListingsJson(listSearchCondition, caller, hash);
  Document document;
  document.Parse(readBuffer.c_str());
  return tr::models::result_t(document);
}

std::string Booli::FetchListingsJson(listingsSearchCondition* listSearchCondition, std::string const& caller, std::string const &hash)
{
  std::string readBuffer = m_jsonRetriver->RetriveJson(m_urlGenerator->GenerateUrl(listSearchCondition->SearchConditionResult(), caller, hash));
  return readBuffer;
}

// Sold

tr::models::result_t Booli::FetchListingsResult(soldSearchCondition* sSearchCondition, std::string const& caller, std::string const& hash)
{
  std::string readBuffer = FetchListingsJson(sSearchCondition, caller, hash);
  Document document;
  document.Parse(readBuffer.c_str());
  return tr::models::result_t(document);
}

std::string Booli::FetchListingsJson(soldSearchCondition* sSearchCondition, std::string const& caller, std::string const &hash)
{
  std::string readBuffer = m_jsonRetriver->RetriveJson(m_urlGenerator->GenerateUrl(sSearchCondition->SearchConditionResult(), caller, hash));
  return readBuffer;
}


