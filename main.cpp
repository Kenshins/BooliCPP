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
  std::string caller = "bopren";
  std::string hash = "P8rfkeJvKOXgHjvXZ1npRXVGG2kHPmXpd5NZetHS";
  tr::models::result_t result = b->FetchListingsResult(&lSC, caller, hash);
  cout << to_string(result);
    
return 0;
}
