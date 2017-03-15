#ifndef CURL_EXCEPTION_H
#define CURL_EXCEPTION_H

#include <exception>

using namespace std;

class CurlException: public exception
{
 public:
 CurlException(int err): errorCode(err) {} 
  ~CurlException(void) {}
  const char* what()
  {
    char errorString[10];
    snprintf(errorString, 10, "%d", errorCode);
    const char* returnPointer = errorString;
    return returnPointer;
  }
  
 private:
  int errorCode;
};

#endif // CURL_EXCEPTION_H
