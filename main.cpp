#include <iostream>
#include "BooliFactory.h"
#include "result.h"
#include "searchCondition.h"

using namespace std;

int main (void)
{

  Booli* b = BooliFactory::Create();
  listingsSearchCondition lSC = listingsSearchCondition();
  lSC.SetQ("Nacka");
  std::string caller = "xxx";
  std::string hash = "P8rfkdJvKOXgHjvXM1npRXVGGGkHPmXpd9NZetHS";
  //tr::models::result_t result = b->FetchListingsResult(&lSC, caller, hash);
  //cout << to_string(result);

  cout << b->FetchListingsJson(&lSC, caller, hash);
    
return 0;
}
