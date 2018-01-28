#include "Booli.h"
#include "jsonRetriverInterface.h"
#include "urlGeneratorInterface.h"
#include "searchCondition.h"
#include "rapidjson/document.h"
#include "Result.h"

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

tr::models::result_t Booli::FetchListingsResult(searchCondition* searchCondition, std::string const& caller, std::string const& hash)
{
  std::string readBuffer = FetchListingsJson(searchCondition, caller, hash);
  Document document;
  document.Parse(readBuffer.c_str());
  return tr::models::result_t(document);
}

std::string Booli::FetchListingsJson(searchCondition* searchCondition, std::string const& caller, std::string const &hash)
{
  std::string readBuffer = m_jsonRetriver->RetriveJson(m_urlGenerator->GenerateUrl(searchCondition->SearchConditionResult(), caller, hash));
  return readBuffer;
}


