



//
//  address.cpp
//
//  Created by js2Model on 2017-03-05.
//

#include "address.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

address_t::address_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto streetAddress_iter = json_value.FindMember("streetAddress");
    if ( streetAddress_iter != json_value.MemberEnd() ) {

        if (streetAddress_iter->value.IsNull()) {
            streetAddress.clear();
        }
        else {
            assert(streetAddress_iter->value.IsString());
            streetAddress = streetAddress_iter->value.GetString();
        }
    }

}

string to_string(const address_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"streetAddress\": \"" << val.streetAddress << "\"," << endl;
    os << indent << "}";

    return os.str();
}


address_t addressFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return address_t(doc);
}

address_t addressFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    address_t instance = addressFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<address_t> addressArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<address_t> addressArray;
    addressArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        address_t instance = address_t(*array_item);
        addressArray.push_back(instance);
    }

    return addressArray;
}

} // namespace models
} // namespace tr

