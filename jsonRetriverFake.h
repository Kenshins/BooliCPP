#ifndef JSONRETRIVERFAKE_H
#define JSONRETRIVERFAKE_H
#include "jsonRetriverInterface.h"

#include<string>

class jsonRetriverFake : public jsonRetriverInterface {

 public:
  std::string RetriveJson(std::string url);
    };

#endif /* JSONRETRIVERFAKE_H */
