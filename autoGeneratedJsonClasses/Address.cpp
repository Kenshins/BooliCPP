



//
//  Address.cpp
//
//  Created by js2Model on 2018-01-28.
//

#include "Address.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

address_t::address_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto StreetAddress_iter = json_value.FindMember("streetAddress");
    if ( StreetAddress_iter != json_value.MemberEnd() ) {

        if (StreetAddress_iter->value.IsNull()) {
            StreetAddress.clear();
        }
        else {
            assert(StreetAddress_iter->value.IsString());
            StreetAddress = StreetAddress_iter->value.GetString();
        }
    }

}

string to_string(const address_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"StreetAddress\": \"" << val.StreetAddress << "\"," << endl;
    os << indent << "}";

    return os.str();
}


address_t AddressFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return address_t(doc);
}

address_t AddressFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    address_t instance = AddressFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<address_t> AddressArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<address_t> AddressArray;
    AddressArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        address_t instance = address_t(*array_item);
        AddressArray.push_back(instance);
    }

    return AddressArray;
}

} // namespace models
} // namespace tr

