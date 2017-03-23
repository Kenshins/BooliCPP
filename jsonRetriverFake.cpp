#include "jsonRetriverFake.h"

#include <fstream>

using namespace std;

std::string jsonRetriverFake::RetriveJson(std::string url)
{
  std::string readBuffer = "";   
  
  std::ifstream file("testdata.json");
  std::string line;
  while(std::getline(file, line)) {
    readBuffer += line;
  }
  
  file.close();
  return readBuffer;
}


