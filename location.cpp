



//
//  location.cpp
//
//  Created by js2Model on 2017-03-05.
//

#include "location.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

location_t::location_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto position_iter = json_value.FindMember("position");
    if ( position_iter != json_value.MemberEnd() ) {

        if (!position_iter->value.IsNull()) {
            assert(position_iter->value.IsObject());
            position = position_t(position_iter->value);
        }
    }

    auto region_iter = json_value.FindMember("region");
    if ( region_iter != json_value.MemberEnd() ) {

        if (!region_iter->value.IsNull()) {
            assert(region_iter->value.IsObject());
            region = region_t(region_iter->value);
        }
    }

    auto namedAreas_iter = json_value.FindMember("namedAreas");
    if ( namedAreas_iter != json_value.MemberEnd() ) {

        for( auto array_item = namedAreas_iter->value.Begin(); array_item != namedAreas_iter->value.End(); array_item++  ) {

            if (!array_item->IsNull()) {
                assert(array_item->IsString());
                namedAreas.push_back(array_item->GetString());
            }
        }
    }

    auto address_iter = json_value.FindMember("address");
    if ( address_iter != json_value.MemberEnd() ) {

        if (!address_iter->value.IsNull()) {
            assert(address_iter->value.IsObject());
            address = address_t(address_iter->value);
        }
    }

}

string to_string(const location_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"position\": " << to_string(val.position, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"region\": " << to_string(val.region, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"namedAreas\": [";
    for( auto &array_item : val.namedAreas ) {

        os << "\"" << array_item << "\",";
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << pretty_print << "\"address\": " << to_string(val.address, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << "}";

    return os.str();
}


location_t locationFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return location_t(doc);
}

location_t locationFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    location_t instance = locationFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<location_t> locationArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<location_t> locationArray;
    locationArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        location_t instance = location_t(*array_item);
        locationArray.push_back(instance);
    }

    return locationArray;
}

} // namespace models
} // namespace tr

