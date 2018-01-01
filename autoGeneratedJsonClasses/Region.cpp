



//
//  Region.cpp
//
//  Created by js2Model on 2017-12-31.
//

#include "Region.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

region_t::region_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto MunicipalityName_iter = json_value.FindMember("municipalityName");
    if ( MunicipalityName_iter != json_value.MemberEnd() ) {

        if (MunicipalityName_iter->value.IsNull()) {
            MunicipalityName.clear();
        }
        else {
            assert(MunicipalityName_iter->value.IsString());
            MunicipalityName = MunicipalityName_iter->value.GetString();
        }
    }

    auto CountyName_iter = json_value.FindMember("countyName");
    if ( CountyName_iter != json_value.MemberEnd() ) {

        if (CountyName_iter->value.IsNull()) {
            CountyName.clear();
        }
        else {
            assert(CountyName_iter->value.IsString());
            CountyName = CountyName_iter->value.GetString();
        }
    }

}

string to_string(const region_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"MunicipalityName\": \"" << val.MunicipalityName << "\"," << endl;
    os << indent << pretty_print << "\"CountyName\": \"" << val.CountyName << "\"," << endl;
    os << indent << "}";

    return os.str();
}


region_t RegionFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return region_t(doc);
}

region_t RegionFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    region_t instance = RegionFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<region_t> RegionArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<region_t> RegionArray;
    RegionArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        region_t instance = region_t(*array_item);
        RegionArray.push_back(instance);
    }

    return RegionArray;
}

} // namespace models
} // namespace tr

