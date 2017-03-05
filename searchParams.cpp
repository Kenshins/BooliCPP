



//
//  searchParams.cpp
//
//  Created by js2Model on 2017-03-05.
//

#include "searchParams.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

searchParams_t::searchParams_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto areaId_iter = json_value.FindMember("areaId");
    if ( areaId_iter != json_value.MemberEnd() ) {

        if (!areaId_iter->value.IsNull()) {
            assert(areaId_iter->value.IsInt());
            areaId = areaId_iter->value.GetInt();
        }
    }

    auto upcomingSale_iter = json_value.FindMember("upcomingSale");
    if ( upcomingSale_iter != json_value.MemberEnd() ) {

        if (!upcomingSale_iter->value.IsNull()) {
            assert(upcomingSale_iter->value.IsInt());
            upcomingSale = upcomingSale_iter->value.GetInt();
        }
    }

}

string to_string(const searchParams_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"areaId\": " << val.areaId << "," << endl;
    os << indent << pretty_print << "\"upcomingSale\": " << val.upcomingSale << "," << endl;
    os << indent << "}";

    return os.str();
}


searchParams_t searchParamsFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return searchParams_t(doc);
}

searchParams_t searchParamsFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    searchParams_t instance = searchParamsFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<searchParams_t> searchParamsArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<searchParams_t> searchParamsArray;
    searchParamsArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        searchParams_t instance = searchParams_t(*array_item);
        searchParamsArray.push_back(instance);
    }

    return searchParamsArray;
}

} // namespace models
} // namespace tr

