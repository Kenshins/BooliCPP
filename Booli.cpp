#include "Booli.h"
#include "jsonRetriverInterface.h"
#include "searchCondition.h"
#include "rapidjson/document.h"
#include "result.h"

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

Booli::Booli(shared_ptr<jsonRetriverInterface> jRetriver)
{
  m_jsonRetriver = jRetriver;
}

Booli::~Booli()
{
}

tr::models::result_t Booli::FetchListingsResult(listingsSearchCondition* listSearchCondition, std::string const& caller, std::string const& hash)
{
  std::string readBuffer = FetchListingsJson(listSearchCondition, caller, hash);
  Document document;
  document.Parse(readBuffer.c_str());
  return tr::models::result_t(document);
}

std::string Booli::FetchListingsJson(listingsSearchCondition* listSearchCondition, std::string const& caller, std::string const &hash)
{
  std::string unique = GenerateUnique();
  std::string ti = GenerateTime();
  std::string ha = GenerateSHA1Hash(caller + ti + hash + unique);
  std::string readBuffer = m_jsonRetriver->RetriveJson("https://api.booli.se/listings?" + listSearchCondition->SearchConditionResult() + "&callerId=" + caller + "&time=" + ti + "&unique=" + unique  + "&hash=" + ha);
  return readBuffer;
}

std::string Booli::GenerateUnique()
{
  std::string s;
  s.reserve(16);

  const int len = 16;

  const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  
  for (int i = 0; i <= len; ++i)
    {
      int ra = rand() % (sizeof(alphanum)-1);
      char r = alphanum[ra];
      s += r;
    }

  return s;
}

std::string Booli::GenerateSHA1Hash(std::string data)
{
  unsigned char sbuf[data.length()];

  memcpy(sbuf, data.data(),data.length());
  sbuf[data.length()] = '\0';

  unsigned char hash[SHA_DIGEST_LENGTH]; // == 20
  SHA1(sbuf, sizeof(sbuf), hash);

  char buf[40];
  for (int n = 0; n <= SHA_DIGEST_LENGTH - 1; n++)
    {
      sprintf(buf+(n*2),"%02x",hash[n]);
    }

  std::string retStr(buf);
  return retStr;
}

std::string Booli::GenerateTime()
{
  char buf[16];
  snprintf(buf, 16, "%lu", time(NULL));
  std::string s(buf);
  return s;
}

