# BooliCPP

## Version 1.0 Beta

Backlog
* Date type needs refactroring
* jsonRetriverFake needs refactoring
* searchCondition.cpp and h file needs to be split up (too big)
* unitTests.cpp needs to be split up (too big)
* Integers in booliresult.schema.json needs to be change to number (or at least checked)
* Write some more examples

### Environment versions

* Ubuntu 14.04.1 LTS
* gcc 5.4.0
* glibc 2.23

### Libraries to be able to compile

sudo apt-get install libssl-dev

sudo apt-get install libcurl4-openssl-dev

### For unit tests install google test

sudo apt-get install libgtest-dev

Note that this package only install source files. You have to compile the code yourself to create the necessary library files. These source files should be located at /usr/src/gtest. Browse to this folder and use cmake to compile the library:

sudo apt-get install cmake

cd /usr/src/gtest

sudo cmake CMakeLists.txt

sudo make

copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder

sudo cp *.a /usr/lib

## Examples
<pre>

#include <iostream>
#include "BooliFactory.h"
#include "autoGeneratedJsonClasses/Booliresult.h"
#include "searchCondition.h"

using namespace std;

void listingsSearchTest()
{
  Booli* b = BooliFactory::Create();
  listingsSearchCondition lSC = listingsSearchCondition();
  lSC.SetQ("Nacka");
  lSC.SetLimit(30);
  std::string caller = "<-- your booli id here -->";
  std::string hash = "<-- your hash here -->";

  // Write to model
  tr::models::booliresult_t booliResult = b->FetchResult(&lSC, caller, hash);
  cout << to_string(booliResult);  
}

void soldSearchTest()
{
  Booli* b = BooliFactory::Create();
  soldSearchCondition sSC = soldSearchCondition();
  sSC.SetQ("Nacka");
  sSC.SetLimit(30);
  std::string caller = "<-- your booli id here -->";
  std::string hash = "<-- your hash here -->";

  // Write to model
  tr::models::booliresult_t booliResult = b->FetchResult(&sSC, caller, hash);
  cout << to_string(booliResult);  
}

void areaSearchTest()
{
  Booli* b = BooliFactory::Create();
  areaSearchCondition aSC = areaSearchCondition();
  aSC.SetQ("Nacka");
  aSC.SetLimit(30);
  std::string caller = "<-- your booli id here -->";
  std::string hash = "<-- your hash here -->";

  // Write to model
  tr::models::booliresult_t booliResult = b->FetchResult(&aSC, caller, hash);
  cout << to_string(booliResult);  
}

int main (void)
{

  listingsSearchTest();
  soldSearchTest();
  areaSearchTest();
    
  return 0;
}

</pre>

## License

This Booli C++ wrapper is released under the MIT License (MIT).

Copyright (c) 2018 Martin Kleberger

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.




