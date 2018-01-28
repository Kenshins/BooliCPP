#include <iostream>

#include "jsonRetriverFake.h"

#include <fstream>

using namespace std;

std::string jsonRetriverFake::RetriveJson(std::string url)
{
  std::string readBuffer = "";
  std::ifstream file;

  std::size_t found = url.find("sold");
  if (found!=std::string::npos)
    {
    file.open("soldtestdata.json");
    }
  else
    {
      std::size_t found = url.find("listings");
      if (found!=std::string::npos)
	{
	  file.open("listingstestdata.json");
	}
    }

  std::string line;
  while(std::getline(file, line)) {
    readBuffer += line;
  }
  
  file.close();
  return readBuffer;
}


