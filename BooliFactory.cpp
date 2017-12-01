#include "BooliFactory.h"
#include "Booli.h"
#include "jsonRetriver.h"

#include <memory>

Booli* BooliFactory::Create()
{
  return new Booli(std::make_shared<jsonRetriver>());
}
