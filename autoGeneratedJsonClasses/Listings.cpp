



//
//  Listings.cpp
//
//  Created by js2Model on 2017-12-31.
//

#include "Listings.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

listings_t::listings_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto Url_iter = json_value.FindMember("url");
    if ( Url_iter != json_value.MemberEnd() ) {

        if (Url_iter->value.IsNull()) {
            Url.clear();
        }
        else {
            assert(Url_iter->value.IsString());
            Url = Url_iter->value.GetString();
        }
    }

    auto ListPrice_iter = json_value.FindMember("listPrice");
    if ( ListPrice_iter != json_value.MemberEnd() ) {

        if (!ListPrice_iter->value.IsNull()) {
            assert(ListPrice_iter->value.IsInt());
            ListPrice = ListPrice_iter->value.GetInt();
        }
    }

    auto ObjectType_iter = json_value.FindMember("objectType");
    if ( ObjectType_iter != json_value.MemberEnd() ) {

        if (ObjectType_iter->value.IsNull()) {
            ObjectType.clear();
        }
        else {
            assert(ObjectType_iter->value.IsString());
            ObjectType = ObjectType_iter->value.GetString();
        }
    }

    auto LivingArea_iter = json_value.FindMember("livingArea");
    if ( LivingArea_iter != json_value.MemberEnd() ) {

        if (!LivingArea_iter->value.IsNull()) {
            assert(LivingArea_iter->value.IsInt());
            LivingArea = LivingArea_iter->value.GetInt();
        }
    }

    auto IsNewConstruction_iter = json_value.FindMember("isNewConstruction");
    if ( IsNewConstruction_iter != json_value.MemberEnd() ) {

        if (!IsNewConstruction_iter->value.IsNull()) {
            assert(IsNewConstruction_iter->value.IsInt());
            IsNewConstruction = IsNewConstruction_iter->value.GetInt();
        }
    }

    auto Source_iter = json_value.FindMember("source");
    if ( Source_iter != json_value.MemberEnd() ) {

        if (!Source_iter->value.IsNull()) {
            assert(Source_iter->value.IsObject());
            Source = source_t(Source_iter->value);
        }
    }

    auto BooliId_iter = json_value.FindMember("booliId");
    if ( BooliId_iter != json_value.MemberEnd() ) {

        if (!BooliId_iter->value.IsNull()) {
            assert(BooliId_iter->value.IsInt());
            BooliId = BooliId_iter->value.GetInt();
        }
    }

    auto Location_iter = json_value.FindMember("location");
    if ( Location_iter != json_value.MemberEnd() ) {

        if (!Location_iter->value.IsNull()) {
            assert(Location_iter->value.IsObject());
            Location = location_t(Location_iter->value);
        }
    }

    auto Published_iter = json_value.FindMember("published");
    if ( Published_iter != json_value.MemberEnd() ) {

        if (Published_iter->value.IsNull()) {
            Published.clear();
        }
        else {
            assert(Published_iter->value.IsString());
            Published = Published_iter->value.GetString();
        }
    }

    auto Rooms_iter = json_value.FindMember("rooms");
    if ( Rooms_iter != json_value.MemberEnd() ) {

        if (!Rooms_iter->value.IsNull()) {
            assert(Rooms_iter->value.IsInt());
            Rooms = Rooms_iter->value.GetInt();
        }
    }

    auto Rent_iter = json_value.FindMember("rent");
    if ( Rent_iter != json_value.MemberEnd() ) {

        if (!Rent_iter->value.IsNull()) {
            assert(Rent_iter->value.IsInt());
            Rent = Rent_iter->value.GetInt();
        }
    }

}

string to_string(const listings_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"Url\": \"" << val.Url << "\"," << endl;
    os << indent << pretty_print << "\"ListPrice\": " << val.ListPrice << "," << endl;
    os << indent << pretty_print << "\"ObjectType\": \"" << val.ObjectType << "\"," << endl;
    os << indent << pretty_print << "\"LivingArea\": " << val.LivingArea << "," << endl;
    os << indent << pretty_print << "\"IsNewConstruction\": " << val.IsNewConstruction << "," << endl;
    os << indent << pretty_print << "\"Source\": " << to_string(val.Source, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"BooliId\": " << val.BooliId << "," << endl;
    os << indent << pretty_print << "\"Location\": " << to_string(val.Location, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"Published\": \"" << val.Published << "\"," << endl;
    os << indent << pretty_print << "\"Rooms\": " << val.Rooms << "," << endl;
    os << indent << pretty_print << "\"Rent\": " << val.Rent << "," << endl;
    os << indent << "}";

    return os.str();
}


listings_t ListingsFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return listings_t(doc);
}

listings_t ListingsFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    listings_t instance = ListingsFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<listings_t> ListingsArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<listings_t> ListingsArray;
    ListingsArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        listings_t instance = listings_t(*array_item);
        ListingsArray.push_back(instance);
    }

    return ListingsArray;
}

} // namespace models
} // namespace tr

