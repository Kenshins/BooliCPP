#include "Booli.h"
#include "Retriver.h"
#include <openssl/sha.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <bitset>

using namespace std;

Booli::Booli()
{
  Retriver* r = new Retriver();
  std::string caller = "xxxxxx";
  std::string unique = GenerateUnique();
  std::string ti = GenerateTime();
  std::string ha = GenerateSHA1Hash(caller + ti + "xxx" + unique);
  r->Retrive("https://api.booli.se/listings?q=nacka&limit=3&offset=0&callerId=" + caller + "&time=" + ti + "&unique=" + unique  + "&hash=" + ha);
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
