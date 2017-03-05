



//
//  region.cpp
//
//  Created by js2Model on 2017-03-05.
//

#include "region.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

region_t::region_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto municipalityName_iter = json_value.FindMember("municipalityName");
    if ( municipalityName_iter != json_value.MemberEnd() ) {

        if (municipalityName_iter->value.IsNull()) {
            municipalityName.clear();
        }
        else {
            assert(municipalityName_iter->value.IsString());
            municipalityName = municipalityName_iter->value.GetString();
        }
    }

    auto countyName_iter = json_value.FindMember("countyName");
    if ( countyName_iter != json_value.MemberEnd() ) {

        if (countyName_iter->value.IsNull()) {
            countyName.clear();
        }
        else {
            assert(countyName_iter->value.IsString());
            countyName = countyName_iter->value.GetString();
        }
    }

}

string to_string(const region_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"municipalityName\": \"" << val.municipalityName << "\"," << endl;
    os << indent << pretty_print << "\"countyName\": \"" << val.countyName << "\"," << endl;
    os << indent << "}";

    return os.str();
}


region_t regionFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return region_t(doc);
}

region_t regionFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    region_t instance = regionFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<region_t> regionArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<region_t> regionArray;
    regionArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        region_t instance = region_t(*array_item);
        regionArray.push_back(instance);
    }

    return regionArray;
}

} // namespace models
} // namespace tr

