#ifndef URLGENERATORINTERFACE_H
#define URLGENERATORINTERFACE_H
#include<string>

class urlGeneratorInterface {
 public:
  virtual std::string GenerateUrl(std::string searchConditionResult, std::string const& caller, std::string const &hash) = 0;
    };

#endif /* URLGENERATORINTERFACE_H */
