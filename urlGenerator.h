#ifndef URLGENERATOR_H
#define URLGERERATOR_H
#include "urlGeneratorInterface.h"

class urlGenerator : public urlGeneratorInterface {
 public:
  std::string GenerateUrl(std::string searchConditonResult, std::string const& caller, std::string const& hash);

 private:
  std::string GenerateUnique();
  std::string GenerateSHA1Hash(std::string);
  std::string GenerateTime();
};

#endif /* URLGENERATORINTERFACE */
