



//
//  Sold.cpp
//
//  Created by js2Model on 2018-01-28.
//

#include "Sold.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

sold_t::sold_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto SoldDate_iter = json_value.FindMember("soldDate");
    if ( SoldDate_iter != json_value.MemberEnd() ) {

        if (SoldDate_iter->value.IsNull()) {
            SoldDate.clear();
        }
        else {
            assert(SoldDate_iter->value.IsString());
            SoldDate = SoldDate_iter->value.GetString();
        }
    }

    auto Source_iter = json_value.FindMember("source");
    if ( Source_iter != json_value.MemberEnd() ) {

        if (!Source_iter->value.IsNull()) {
            assert(Source_iter->value.IsObject());
            Source = source_t(Source_iter->value);
        }
    }

    auto LivingArea_iter = json_value.FindMember("livingArea");
    if ( LivingArea_iter != json_value.MemberEnd() ) {

	if (!LivingArea_iter->value.IsNull()) {
	  if (LivingArea_iter->value.IsInt())
	    {
	      LivingArea = (double)LivingArea_iter->value.GetInt();
	    }
	  else if (LivingArea_iter->value.IsDouble())
	    {
	      LivingArea = LivingArea_iter->value.GetDouble();
	    }
	  else
	    {
	      assert(LivingArea_iter->value.IsFloat());
	    }
        }
    }

    auto Rooms_iter = json_value.FindMember("rooms");
    if ( Rooms_iter != json_value.MemberEnd() ) {

	if (!Rooms_iter->value.IsNull()) {
	  if (Rooms_iter->value.IsInt())
	    {
	      Rooms = (double)Rooms_iter->value.GetInt();
	    }
	  else if (Rooms_iter->value.IsDouble())
	    {
	      Rooms = Rooms_iter->value.GetDouble();
	    }
	  else
	    {
	      assert(Rooms_iter->value.IsFloat());
	    }
        }
    }

    auto AdditionalArea_iter = json_value.FindMember("additionalArea");
    if ( AdditionalArea_iter != json_value.MemberEnd() ) {

	if (!AdditionalArea_iter->value.IsNull()) {
	  if (AdditionalArea_iter->value.IsInt())
	    {
	      AdditionalArea = (double)AdditionalArea_iter->value.GetInt();
	    }
	  else if (AdditionalArea_iter->value.IsDouble())
	    {
	      AdditionalArea = AdditionalArea_iter->value.GetDouble();
	    }
	  else
	    {
	      assert(AdditionalArea_iter->value.IsFloat());
	    }
        }
    }

    auto PlotArea_iter = json_value.FindMember("plotArea");
    if ( PlotArea_iter != json_value.MemberEnd() ) {

        if (!PlotArea_iter->value.IsNull()) {
            assert(PlotArea_iter->value.IsInt());
            PlotArea = PlotArea_iter->value.GetInt();
        }
    }

    auto ListPrice_iter = json_value.FindMember("listPrice");
    if ( ListPrice_iter != json_value.MemberEnd() ) {

	if (!ListPrice_iter->value.IsNull()) {
	  if (ListPrice_iter->value.IsInt())
	    {
	      ListPrice = (double)ListPrice_iter->value.GetInt();
	    }
	  else if (ListPrice_iter->value.IsDouble())
	    {
	      ListPrice = ListPrice_iter->value.GetDouble();
	    }
	  else
	    {
	      assert(ListPrice_iter->value.IsFloat());
	    }
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

    auto SoldPriceSource_iter = json_value.FindMember("soldPriceSource");
    if ( SoldPriceSource_iter != json_value.MemberEnd() ) {

        if (SoldPriceSource_iter->value.IsNull()) {
            SoldPriceSource.clear();
        }
        else {
            assert(SoldPriceSource_iter->value.IsString());
            SoldPriceSource = SoldPriceSource_iter->value.GetString();
        }
    }

    auto Rent_iter = json_value.FindMember("rent");
    if ( Rent_iter != json_value.MemberEnd() ) {

	if (!Rent_iter->value.IsNull()) {
	  if (Rent_iter->value.IsInt())
	    {
	      Rent = (double)Rent_iter->value.GetInt();
	    }
	  else if (Rent_iter->value.IsDouble())
	    {
	      Rent = Rent_iter->value.GetDouble();
	    }
	  else
	    {
	      assert(Rent_iter->value.IsFloat());
	    }
        }
    }

    auto BooliId_iter = json_value.FindMember("booliId");
    if ( BooliId_iter != json_value.MemberEnd() ) {

        if (!BooliId_iter->value.IsNull()) {
            assert(BooliId_iter->value.IsInt());
            BooliId = BooliId_iter->value.GetInt();
        }
    }

    auto SoldPrice_iter = json_value.FindMember("soldPrice");
    if ( SoldPrice_iter != json_value.MemberEnd() ) {

	if (!SoldPrice_iter->value.IsNull()) {
	  if (SoldPrice_iter->value.IsInt())
	    {
	      SoldPrice = (double)SoldPrice_iter->value.GetInt();
	    }
	  else if (SoldPrice_iter->value.IsDouble())
	    {
	      SoldPrice = SoldPrice_iter->value.GetDouble();
	    }
	  else
	    {
	      assert(SoldPrice_iter->value.IsFloat());
	    }
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

}

string to_string(const sold_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"SoldDate\": \"" << val.SoldDate << "\"," << endl;
    os << indent << pretty_print << "\"Source\": " << to_string(val.Source, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"LivingArea\": " << val.LivingArea << "," << endl;
    os << indent << pretty_print << "\"Rooms\": " << val.Rooms << "," << endl;
    os << indent << pretty_print << "\"AdditionalArea\": " << val.AdditionalArea << "," << endl;
    os << indent << pretty_print << "\"PlotArea\": " << val.PlotArea << "," << endl;
    os << indent << pretty_print << "\"ListPrice\": " << val.ListPrice << "," << endl;
    os << indent << pretty_print << "\"Location\": " << to_string(val.Location, indent + pretty_print, pretty_print) << "," << endl;
    os << indent << pretty_print << "\"Published\": \"" << val.Published << "\"," << endl;
    os << indent << pretty_print << "\"Url\": \"" << val.Url << "\"," << endl;
    os << indent << pretty_print << "\"SoldPriceSource\": \"" << val.SoldPriceSource << "\"," << endl;
    os << indent << pretty_print << "\"Rent\": " << val.Rent << "," << endl;
    os << indent << pretty_print << "\"BooliId\": " << val.BooliId << "," << endl;
    os << indent << pretty_print << "\"SoldPrice\": " << val.SoldPrice << "," << endl;
    os << indent << pretty_print << "\"ObjectType\": \"" << val.ObjectType << "\"," << endl;
    os << indent << "}";

    return os.str();
}


sold_t SoldFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return sold_t(doc);
}

sold_t SoldFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    sold_t instance = SoldFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<sold_t> SoldArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<sold_t> SoldArray;
    SoldArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        sold_t instance = sold_t(*array_item);
        SoldArray.push_back(instance);
    }

    return SoldArray;
}

} // namespace models
} // namespace tr

