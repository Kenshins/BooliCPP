#ifndef BOOLI_H
#define BOOLI_H
#include <string>

class Booli
{
 public:
  Booli();

 private:
  std::string GenerateUnique();
  std::string GenerateSHA1Hash();
  std::string GenerateTime();

};

#endif // BOOLI_H
