#include "retriver.h"
#include "rapidjson/document.h"
#include "result.h"
#include <iostream>
#include <curl/curl.h>

using namespace std;
using namespace rapidjson;

size_t retriver_t::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

std::string retriver_t::Retrive(std::string url)
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

    std::cout << readBuffer << std::endl << std::endl;
  }

  Document document;
  document.Parse(readBuffer.c_str());
  tr::models::result_t r = tr::models::result_t(document);
  std::cout << tr::models::to_string(r) << std::endl;
  
  return readBuffer;
}

retriver_t::retriver_t() 
{
  // Not implemented
}


