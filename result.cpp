



//
//  result.cpp
//
//  Created by js2Model on 2017-04-06.
//

#include "result.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

result_t::result_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto count_iter = json_value.FindMember("count");
    if ( count_iter != json_value.MemberEnd() ) {

        if (!count_iter->value.IsNull()) {
            assert(count_iter->value.IsInt());
            count = count_iter->value.GetInt();
        }
    }

    auto searchParams_iter = json_value.FindMember("searchParams");
    if ( searchParams_iter != json_value.MemberEnd() ) {

        if (!searchParams_iter->value.IsNull()) {
            assert(searchParams_iter->value.IsObject());
            searchParams = searchParams_t(searchParams_iter->value);
        }
    }

    auto listings_iter = json_value.FindMember("listings");
    if ( listings_iter != json_value.MemberEnd() ) {

        for( auto array_item = listings_iter->value.Begin(); array_item != listings_iter->value.End(); array_item++  ) {

            assert(array_item->IsObject());
            listings.push_back(listings_t(*array_item));
        }
    }

    auto totalCount_iter = json_value.FindMember("totalCount");
    if ( totalCount_iter != json_value.MemberEnd() ) {

        if (!totalCount_iter->value.IsNull()) {
            assert(totalCount_iter->value.IsInt());
            totalCount = totalCount_iter->value.GetInt();
        }
    }

    auto limit_iter = json_value.FindMember("limit");
    if ( limit_iter != json_value.MemberEnd() ) {

        if (!limit_iter->value.IsNull()) {
            assert(limit_iter->value.IsInt());
            limit = limit_iter->value.GetInt();
        }
    }

    auto offset_iter = json_value.FindMember("offset");
    if ( offset_iter != json_value.MemberEnd() ) {

        if (!offset_iter->value.IsNull()) {
            assert(offset_iter->value.IsInt());
            offset = offset_iter->value.GetInt();
        }
    }

}

string to_string(const result_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"count\": " << val.count << "," << endl;
    os << indent << pretty_print << "\"searchParams\": " << to_string(val.searchParams, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"listings\": [";
    for( auto &array_item : val.listings ) {

        os << endl << to_string(array_item, indent + pretty_print + pretty_print, pretty_print) << "," << endl;
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << pretty_print << "\"totalCount\": " << val.totalCount << "," << endl;
    os << indent << pretty_print << "\"limit\": " << val.limit << "," << endl;
    os << indent << pretty_print << "\"offset\": " << val.offset << "," << endl;
    os << indent << "}";

    return os.str();
}


result_t resultFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return result_t(doc);
}

result_t resultFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    result_t instance = resultFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<result_t> resultArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<result_t> resultArray;
    resultArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        result_t instance = result_t(*array_item);
        resultArray.push_back(instance);
    }

    return resultArray;
}

} // namespace models
} // namespace tr

