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
