



//
//  Location.cpp
//
//  Created by js2Model on 2018-01-07.
//

#include "Location.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

location_t::location_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto Address_iter = json_value.FindMember("address");
    if ( Address_iter != json_value.MemberEnd() ) {

        if (!Address_iter->value.IsNull()) {
            assert(Address_iter->value.IsObject());
            Address = address_t(Address_iter->value);
        }
    }

    auto Position_iter = json_value.FindMember("position");
    if ( Position_iter != json_value.MemberEnd() ) {

        if (!Position_iter->value.IsNull()) {
            assert(Position_iter->value.IsObject());
            Position = position_t(Position_iter->value);
        }
    }

    auto Region_iter = json_value.FindMember("region");
    if ( Region_iter != json_value.MemberEnd() ) {

        if (!Region_iter->value.IsNull()) {
            assert(Region_iter->value.IsObject());
            Region = region_t(Region_iter->value);
        }
    }

    auto NamedAreas_iter = json_value.FindMember("namedAreas");
    if ( NamedAreas_iter != json_value.MemberEnd() ) {

        for( auto array_item = NamedAreas_iter->value.Begin(); array_item != NamedAreas_iter->value.End(); array_item++  ) {

            if (!array_item->IsNull()) {
                assert(array_item->IsString());
                NamedAreas.push_back(array_item->GetString());
            }
        }
    }

}

string to_string(const location_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"Address\": " << to_string(val.Address, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"Position\": " << to_string(val.Position, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"Region\": " << to_string(val.Region, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"NamedAreas\": [";
    for( auto &array_item : val.NamedAreas ) {

        os << "\"" << array_item << "\",";
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << "}";

    return os.str();
}


location_t LocationFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return location_t(doc);
}

location_t LocationFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    location_t instance = LocationFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<location_t> LocationArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<location_t> LocationArray;
    LocationArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        location_t instance = location_t(*array_item);
        LocationArray.push_back(instance);
    }

    return LocationArray;
}

} // namespace models
} // namespace tr

