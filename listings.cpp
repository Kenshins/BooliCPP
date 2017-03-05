



//
//  listings.cpp
//
//  Created by js2Model on 2017-03-05.
//

#include "listings.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

listings_t::listings_t(const rapidjson::Value &json_value) {

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
	  if (livingArea_iter->value.IsInt())
	    {
	      livingArea = (float)livingArea_iter->value.GetInt();
	    }
	  else if (livingArea_iter->value.IsFloat())
	    {
	      livingArea = livingArea_iter->value.GetFloat();
	    }
	  else
	    {
	      assert(livingArea_iter->value.IsFloat());
	    }
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

    auto location_iter = json_value.FindMember("location");
    if ( location_iter != json_value.MemberEnd() ) {

        if (!location_iter->value.IsNull()) {
            assert(location_iter->value.IsObject());
            location = location_t(location_iter->value);
        }
    }

    auto source_iter = json_value.FindMember("source");
    if ( source_iter != json_value.MemberEnd() ) {

        if (!source_iter->value.IsNull()) {
            assert(source_iter->value.IsObject());
            source = source_t(source_iter->value);
        }
    }

    auto rent_iter = json_value.FindMember("rent");
    if ( rent_iter != json_value.MemberEnd() ) {

	if (!rent_iter->value.IsNull()) {
	  if (rent_iter->value.IsInt())
	    {
	      rent = (float)rent_iter->value.GetInt();
	    }
	  else if (rent_iter->value.IsFloat())
	    {
	      rent = rent_iter->value.GetFloat();
	    }
	  else
	    {
	      assert(rent_iter->value.IsFloat());
	    }
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

    auto isNewConstruction_iter = json_value.FindMember("isNewConstruction");
    if ( isNewConstruction_iter != json_value.MemberEnd() ) {

        if (!isNewConstruction_iter->value.IsNull()) {
            assert(isNewConstruction_iter->value.IsInt());
            isNewConstruction = isNewConstruction_iter->value.GetInt();
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

    auto listPrice_iter = json_value.FindMember("listPrice");
    if ( listPrice_iter != json_value.MemberEnd() ) {

	if (!listPrice_iter->value.IsNull()) {
	  if (listPrice_iter->value.IsInt())
	    {
	      listPrice = (float)listPrice_iter->value.GetInt();
	    }
	  else if (listPrice_iter->value.IsFloat())
	    {
	      listPrice = listPrice_iter->value.GetFloat();
	    }
	  else
	    {
	      assert(listPrice_iter->value.IsFloat());
	    }
        }
    }

    auto rooms_iter = json_value.FindMember("rooms");
    if ( rooms_iter != json_value.MemberEnd() ) {

	if (!rooms_iter->value.IsNull()) {
	  if (rooms_iter->value.IsInt())
	    {
	      rooms = (float)rooms_iter->value.GetInt();
	    }
	  else if (rooms_iter->value.IsFloat())
	    {
	      rooms = rooms_iter->value.GetFloat();
	    }
	  else
	    {
	      assert(rooms_iter->value.IsFloat());
	    }
        }
    }

}

string to_string(const listings_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"booliId\": " << val.booliId << "," << endl;
    os << indent << pretty_print << "\"livingArea\": " << val.livingArea << "," << endl;
    os << indent << pretty_print << "\"url\": \"" << val.url << "\"," << endl;
    os << indent << pretty_print << "\"location\": " << to_string(val.location, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"source\": " << to_string(val.source, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"rent\": " << val.rent << "," << endl;
    os << indent << pretty_print << "\"published\": \"" << val.published << "\"," << endl;
    os << indent << pretty_print << "\"isNewConstruction\": " << val.isNewConstruction << "," << endl;
    os << indent << pretty_print << "\"objectType\": \"" << val.objectType << "\"," << endl;
    os << indent << pretty_print << "\"listPrice\": " << val.listPrice << "," << endl;
    os << indent << pretty_print << "\"rooms\": " << val.rooms << "," << endl;
    os << indent << "}";

    return os.str();
}


listings_t listingsFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return listings_t(doc);
}

listings_t listingsFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    listings_t instance = listingsFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<listings_t> listingsArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<listings_t> listingsArray;
    listingsArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        listings_t instance = listings_t(*array_item);
        listingsArray.push_back(instance);
    }

    return listingsArray;
}

} // namespace models
} // namespace tr

