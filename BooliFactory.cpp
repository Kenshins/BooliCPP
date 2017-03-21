#include "BooliFactory.h"
#include "Booli.h"
#include "jsonRetriver.h"

Booli* BooliFactory::Create()
{
  return new Booli(new jsonRetriver());
}
