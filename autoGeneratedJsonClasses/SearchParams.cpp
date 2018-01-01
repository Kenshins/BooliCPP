



//
//  SearchParams.cpp
//
//  Created by js2Model on 2017-12-31.
//

#include "SearchParams.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

searchParams_t::searchParams_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto Listings_iter = json_value.FindMember("listings");
    if ( Listings_iter != json_value.MemberEnd() ) {

        if (!Listings_iter->value.IsNull()) {
            assert(Listings_iter->value.IsInt());
            Listings = Listings_iter->value.GetInt();
        }
    }

    auto Transactions_iter = json_value.FindMember("transactions");
    if ( Transactions_iter != json_value.MemberEnd() ) {

        if (!Transactions_iter->value.IsNull()) {
            assert(Transactions_iter->value.IsInt());
            Transactions = Transactions_iter->value.GetInt();
        }
    }

    auto Q_iter = json_value.FindMember("q");
    if ( Q_iter != json_value.MemberEnd() ) {

        if (Q_iter->value.IsNull()) {
            Q.clear();
        }
        else {
            assert(Q_iter->value.IsString());
            Q = Q_iter->value.GetString();
        }
    }

}

string to_string(const searchParams_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"Listings\": " << val.Listings << "," << endl;
    os << indent << pretty_print << "\"Transactions\": " << val.Transactions << "," << endl;
    os << indent << pretty_print << "\"Q\": \"" << val.Q << "\"," << endl;
    os << indent << "}";

    return os.str();
}


searchParams_t SearchParamsFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return searchParams_t(doc);
}

searchParams_t SearchParamsFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    searchParams_t instance = SearchParamsFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<searchParams_t> SearchParamsArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<searchParams_t> SearchParamsArray;
    SearchParamsArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        searchParams_t instance = searchParams_t(*array_item);
        SearchParamsArray.push_back(instance);
    }

    return SearchParamsArray;
}

} // namespace models
} // namespace tr

