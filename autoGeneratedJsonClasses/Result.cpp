



//
//  Result.cpp
//
//  Created by js2Model on 2017-12-31.
//

#include "Result.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

result_t::result_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto TotalCount_iter = json_value.FindMember("totalCount");
    if ( TotalCount_iter != json_value.MemberEnd() ) {

        if (!TotalCount_iter->value.IsNull()) {
            assert(TotalCount_iter->value.IsInt());
            TotalCount = TotalCount_iter->value.GetInt();
        }
    }

    auto Offset_iter = json_value.FindMember("offset");
    if ( Offset_iter != json_value.MemberEnd() ) {

        if (!Offset_iter->value.IsNull()) {
            assert(Offset_iter->value.IsInt());
            Offset = Offset_iter->value.GetInt();
        }
    }

    auto SearchParams_iter = json_value.FindMember("searchParams");
    if ( SearchParams_iter != json_value.MemberEnd() ) {

        if (!SearchParams_iter->value.IsNull()) {
            assert(SearchParams_iter->value.IsObject());
            SearchParams = searchParams_t(SearchParams_iter->value);
        }
    }

    auto Limit_iter = json_value.FindMember("limit");
    if ( Limit_iter != json_value.MemberEnd() ) {

        if (!Limit_iter->value.IsNull()) {
            assert(Limit_iter->value.IsInt());
            Limit = Limit_iter->value.GetInt();
        }
    }

    auto Listings_iter = json_value.FindMember("listings");
    if ( Listings_iter != json_value.MemberEnd() ) {

        for( auto array_item = Listings_iter->value.Begin(); array_item != Listings_iter->value.End(); array_item++  ) {

            assert(array_item->IsObject());
            Listings.push_back(listings_t(*array_item));
        }
    }

    auto Count_iter = json_value.FindMember("count");
    if ( Count_iter != json_value.MemberEnd() ) {

        if (!Count_iter->value.IsNull()) {
            assert(Count_iter->value.IsInt());
            Count = Count_iter->value.GetInt();
        }
    }

}

string to_string(const result_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"TotalCount\": " << val.TotalCount << "," << endl;
    os << indent << pretty_print << "\"Offset\": " << val.Offset << "," << endl;
    os << indent << pretty_print << "\"SearchParams\": " << to_string(val.SearchParams, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"Limit\": " << val.Limit << "," << endl;
    os << indent << pretty_print << "\"Listings\": [";
    for( auto &array_item : val.Listings ) {

        os << endl << to_string(array_item, indent + pretty_print + pretty_print, pretty_print) << "," << endl;
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << pretty_print << "\"Count\": " << val.Count << "," << endl;
    os << indent << "}";

    return os.str();
}


result_t ResultFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return result_t(doc);
}

result_t ResultFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    result_t instance = ResultFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<result_t> ResultArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<result_t> ResultArray;
    ResultArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        result_t instance = result_t(*array_item);
        ResultArray.push_back(instance);
    }

    return ResultArray;
}

} // namespace models
} // namespace tr

