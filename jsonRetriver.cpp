#include "jsonRetriver.h"
#include "curlException.h"

#include <iostream>
#include <curl/curl.h>

using namespace std;

size_t jsonRetriver::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

std::string jsonRetriver::RetriveJson(std::string url)
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    std::cout << url << std::endl;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);

    if (res != 0)
      throw new CurlException(res);
    
    std::cout << readBuffer << std::endl << std::endl;
  }
  
  return readBuffer;
}


