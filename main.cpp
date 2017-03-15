#include <iostream>
#include "Booli.h"
#include "result.h"
#include "searchCondition.h"

using namespace std;

int main (void)
{


  Booli b = Booli();
  listingsSearchCondition lSC = listingsSearchCondition();
  lSC.SetQ("Nacka");
  std::string caller = "bopren";
  std::string hash = "P8rfkeJvKOXgHjvXZ1npRXVGG2kHPmXpd5NZetHS";
  tr::models::result_t result = b.FetchListings(&lSC, caller, hash);
  cout << to_string(result);
    
return 0;
}
