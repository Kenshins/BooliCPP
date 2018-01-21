#include "urlGenerator.h"

#include <openssl/sha.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <bitset>
#include <memory>

std::string urlGenerator::GenerateUrl(std::string searchConditionResult, std::string const& caller, std::string const& hash)
{
  std::string unique = GenerateUnique();
  std::string ti = GenerateTime();
  std::string ha = GenerateSHA1Hash(caller + ti + hash + unique);
  return "https://api.booli.se/" + searchConditionResult + "&callerId=" + caller + "&time=" + ti + "&unique=" + unique  + "&hash=" + ha;
}

std::string urlGenerator::GenerateUnique()
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

std::string urlGenerator::GenerateSHA1Hash(std::string data)
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

std::string urlGenerator::GenerateTime()
{
  char buf[16];
  snprintf(buf, 16, "%lu", time(NULL));
  std::string s(buf);
  return s;
}

