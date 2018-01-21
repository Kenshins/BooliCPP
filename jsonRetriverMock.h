#include <gmock/gmock.h>
#include <string>

class MockJsonRetriver : public jsonRetriverInterface
{
public:
  MOCK_METHOD1(RetriveJson, std::string(std::string url));
};
