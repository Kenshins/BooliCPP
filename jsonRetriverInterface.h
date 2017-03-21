#ifndef JSONRETRIVERINTERFACE_H
#define JSONRETRIVERINTERFACE_H
#include<string>

class jsonRetriverInterface {
 public:
  virtual std::string RetriveJson(std::string url) = 0;
    };

#endif /* JSONRETRIVERINTERFACE_H */
