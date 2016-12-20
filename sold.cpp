



//
//  sold.cpp
//
//  Created by js2Model on 2016-12-13.
//

#include "sold.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

sold_t::sold_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto booliId_iter = json_value.FindMember("booliId");
    if ( booliId_iter != json_value.MemberEnd() ) {

        if (!booliId_iter->value.IsNull()) {
            assert(booliId_iter->value.IsInt());
            booliId = booliId_iter->value.GetInt();
        }
    }

    auto livingArea_iter = json_value.FindMember("livingArea");
    if ( livingArea_iter != json_value.MemberEnd() ) {

        if (!livingArea_iter->value.IsNull()) {
            assert(livingArea_iter->value.IsInt());
            livingArea = livingArea_iter->value.GetInt();
        }
    }

    auto url_iter = json_value.FindMember("url");
    if ( url_iter != json_value.MemberEnd() ) {

        if (url_iter->value.IsNull()) {
            url.clear();
        }
        else {
            assert(url_iter->value.IsString());
            url = url_iter->value.GetString();
        }
    }

    auto constructionYear_iter = json_value.FindMember("constructionYear");
    if ( constructionYear_iter != json_value.MemberEnd() ) {

        if (!constructionYear_iter->value.IsNull()) {
            assert(constructionYear_iter->value.IsInt());
            constructionYear = constructionYear_iter->value.GetInt();
        }
    }

    auto location_iter = json_value.FindMember("location");
    if ( location_iter != json_value.MemberEnd() ) {

        if (!location_iter->value.IsNull()) {
            assert(location_iter->value.IsObject());
            location = location_t(location_iter->value);
        }
    }

    auto soldPrice_iter = json_value.FindMember("soldPrice");
    if ( soldPrice_iter != json_value.MemberEnd() ) {

        if (!soldPrice_iter->value.IsNull()) {
            assert(soldPrice_iter->value.IsInt());
            soldPrice = soldPrice_iter->value.GetInt();
        }
    }

    auto source_iter = json_value.FindMember("source");
    if ( source_iter != json_value.MemberEnd() ) {

        if (!source_iter->value.IsNull()) {
            assert(source_iter->value.IsObject());
            source = source_t(source_iter->value);
        }
    }

    auto soldDate_iter = json_value.FindMember("soldDate");
    if ( soldDate_iter != json_value.MemberEnd() ) {

        if (soldDate_iter->value.IsNull()) {
            soldDate.clear();
        }
        else {
            assert(soldDate_iter->value.IsString());
            soldDate = soldDate_iter->value.GetString();
        }
    }

    auto rooms_iter = json_value.FindMember("rooms");
    if ( rooms_iter != json_value.MemberEnd() ) {

        if (!rooms_iter->value.IsNull()) {
            assert(rooms_iter->value.IsInt());
            rooms = rooms_iter->value.GetInt();
        }
    }

    auto published_iter = json_value.FindMember("published");
    if ( published_iter != json_value.MemberEnd() ) {

        if (published_iter->value.IsNull()) {
            published.clear();
        }
        else {
            assert(published_iter->value.IsString());
            published = published_iter->value.GetString();
        }
    }

    auto additionalArea_iter = json_value.FindMember("additionalArea");
    if ( additionalArea_iter != json_value.MemberEnd() ) {

        if (!additionalArea_iter->value.IsNull()) {
            assert(additionalArea_iter->value.IsInt());
            additionalArea = additionalArea_iter->value.GetInt();
        }
    }

    auto objectType_iter = json_value.FindMember("objectType");
    if ( objectType_iter != json_value.MemberEnd() ) {

        if (objectType_iter->value.IsNull()) {
            objectType.clear();
        }
        else {
            assert(objectType_iter->value.IsString());
            objectType = objectType_iter->value.GetString();
        }
    }

    auto rent_iter = json_value.FindMember("rent");
    if ( rent_iter != json_value.MemberEnd() ) {

        if (!rent_iter->value.IsNull()) {
            assert(rent_iter->value.IsInt());
            rent = rent_iter->value.GetInt();
        }
    }

}

string to_string(const sold_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"booliId\": " << val.booliId << "," << endl;
    os << indent << pretty_print << "\"livingArea\": " << val.livingArea << "," << endl;
    os << indent << pretty_print << "\"url\": \"" << val.url << "\"," << endl;
    os << indent << pretty_print << "\"constructionYear\": " << val.constructionYear << "," << endl;
    os << indent << pretty_print << "\"location\": " << to_string(val.location, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"soldPrice\": " << val.soldPrice << "," << endl;
    os << indent << pretty_print << "\"source\": " << to_string(val.source, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"soldDate\": \"" << val.soldDate << "\"," << endl;
    os << indent << pretty_print << "\"rooms\": " << val.rooms << "," << endl;
    os << indent << pretty_print << "\"published\": \"" << val.published << "\"," << endl;
    os << indent << pretty_print << "\"additionalArea\": " << val.additionalArea << "," << endl;
    os << indent << pretty_print << "\"objectType\": \"" << val.objectType << "\"," << endl;
    os << indent << pretty_print << "\"rent\": " << val.rent << "," << endl;
    os << indent << "}";

    return os.str();
}


sold_t soldFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return sold_t(doc);
}

sold_t soldFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    sold_t instance = soldFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<sold_t> soldArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<sold_t> soldArray;
    soldArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        sold_t instance = sold_t(*array_item);
        soldArray.push_back(instance);
    }

    return soldArray;
}

} // namespace models
} // namespace tr

