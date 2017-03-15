#ifndef RETRIVER_H
#define RETRIVER_H
#include<string>

class jsonRetriver {
 public:
  jsonRetriver();
  std::string RetriveJson(std::string url);

 private:
  static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void *userp);
    };

#endif /* RETRIVER_H */
