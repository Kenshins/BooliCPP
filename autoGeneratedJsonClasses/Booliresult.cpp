



//
//  Booliresult.cpp
//
//  Created by js2Model on 2018-01-28.
//

#include "Booliresult.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

booliresult_t::booliresult_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto SearchParams_iter = json_value.FindMember("searchParams");
    if ( SearchParams_iter != json_value.MemberEnd() ) {

        if (!SearchParams_iter->value.IsNull()) {
            assert(SearchParams_iter->value.IsObject());
            SearchParams = searchParams_t(SearchParams_iter->value);
        }
    }

    auto Offset_iter = json_value.FindMember("offset");
    if ( Offset_iter != json_value.MemberEnd() ) {

        if (!Offset_iter->value.IsNull()) {
            assert(Offset_iter->value.IsInt());
            Offset = Offset_iter->value.GetInt();
        }
    }

    auto Areas_iter = json_value.FindMember("areas");
    if ( Areas_iter != json_value.MemberEnd() ) {

        for( auto array_item = Areas_iter->value.Begin(); array_item != Areas_iter->value.End(); array_item++  ) {

            assert(array_item->IsObject());
            Areas.push_back(areas_t(*array_item));
        }
    }

    auto Listings_iter = json_value.FindMember("listings");
    if ( Listings_iter != json_value.MemberEnd() ) {

        for( auto array_item = Listings_iter->value.Begin(); array_item != Listings_iter->value.End(); array_item++  ) {

            assert(array_item->IsObject());
            Listings.push_back(listings_t(*array_item));
        }
    }

    auto Limit_iter = json_value.FindMember("limit");
    if ( Limit_iter != json_value.MemberEnd() ) {

        if (!Limit_iter->value.IsNull()) {
            assert(Limit_iter->value.IsInt());
            Limit = Limit_iter->value.GetInt();
        }
    }

    auto Count_iter = json_value.FindMember("count");
    if ( Count_iter != json_value.MemberEnd() ) {

        if (!Count_iter->value.IsNull()) {
            assert(Count_iter->value.IsInt());
            Count = Count_iter->value.GetInt();
        }
    }

    auto Sold_iter = json_value.FindMember("sold");
    if ( Sold_iter != json_value.MemberEnd() ) {

        for( auto array_item = Sold_iter->value.Begin(); array_item != Sold_iter->value.End(); array_item++  ) {

            assert(array_item->IsObject());
            Sold.push_back(sold_t(*array_item));
        }
    }

    auto TotalCount_iter = json_value.FindMember("totalCount");
    if ( TotalCount_iter != json_value.MemberEnd() ) {

        if (!TotalCount_iter->value.IsNull()) {
            assert(TotalCount_iter->value.IsInt());
            TotalCount = TotalCount_iter->value.GetInt();
        }
    }

}

string to_string(const booliresult_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"SearchParams\": " << to_string(val.SearchParams, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"Offset\": " << val.Offset << "," << endl;
    os << indent << pretty_print << "\"Areas\": [";
    for( auto &array_item : val.Areas ) {

        os << endl << to_string(array_item, indent + pretty_print + pretty_print, pretty_print) << "," << endl;
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << pretty_print << "\"Listings\": [";
    for( auto &array_item : val.Listings ) {

        os << endl << to_string(array_item, indent + pretty_print + pretty_print, pretty_print) << "," << endl;
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << pretty_print << "\"Limit\": " << val.Limit << "," << endl;
    os << indent << pretty_print << "\"Count\": " << val.Count << "," << endl;
    os << indent << pretty_print << "\"Sold\": [";
    for( auto &array_item : val.Sold ) {

        os << endl << to_string(array_item, indent + pretty_print + pretty_print, pretty_print) << "," << endl;
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << pretty_print << "\"TotalCount\": " << val.TotalCount << "," << endl;
    os << indent << "}";

    return os.str();
}


booliresult_t BooliresultFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return booliresult_t(doc);
}

booliresult_t BooliresultFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    booliresult_t instance = BooliresultFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<booliresult_t> BooliresultArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<booliresult_t> BooliresultArray;
    BooliresultArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        booliresult_t instance = booliresult_t(*array_item);
        BooliresultArray.push_back(instance);
    }

    return BooliresultArray;
}

} // namespace models
} // namespace tr

