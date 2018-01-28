



//
//  Areas.cpp
//
//  Created by js2Model on 2018-01-28.
//

#include "Areas.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

areas_t::areas_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto Types_iter = json_value.FindMember("types");
    if ( Types_iter != json_value.MemberEnd() ) {

        for( auto array_item = Types_iter->value.Begin(); array_item != Types_iter->value.End(); array_item++  ) {

            if (!array_item->IsNull()) {
                assert(array_item->IsString());
                Types.push_back(array_item->GetString());
            }
        }
    }

    auto UrlFriendlyName_iter = json_value.FindMember("urlFriendlyName");
    if ( UrlFriendlyName_iter != json_value.MemberEnd() ) {

        if (UrlFriendlyName_iter->value.IsNull()) {
            UrlFriendlyName.clear();
        }
        else {
            assert(UrlFriendlyName_iter->value.IsString());
            UrlFriendlyName = UrlFriendlyName_iter->value.GetString();
        }
    }

    auto FullName_iter = json_value.FindMember("fullName");
    if ( FullName_iter != json_value.MemberEnd() ) {

        if (FullName_iter->value.IsNull()) {
            FullName.clear();
        }
        else {
            assert(FullName_iter->value.IsString());
            FullName = FullName_iter->value.GetString();
        }
    }

    auto BooliId_iter = json_value.FindMember("booliId");
    if ( BooliId_iter != json_value.MemberEnd() ) {

        if (!BooliId_iter->value.IsNull()) {
            assert(BooliId_iter->value.IsInt());
            BooliId = BooliId_iter->value.GetInt();
        }
    }

    auto ParentName_iter = json_value.FindMember("parentName");
    if ( ParentName_iter != json_value.MemberEnd() ) {

        if (ParentName_iter->value.IsNull()) {
            ParentName.clear();
        }
        else {
            assert(ParentName_iter->value.IsString());
            ParentName = ParentName_iter->value.GetString();
        }
    }

    auto ParentBooliId_iter = json_value.FindMember("parentBooliId");
    if ( ParentBooliId_iter != json_value.MemberEnd() ) {

        if (!ParentBooliId_iter->value.IsNull()) {
            assert(ParentBooliId_iter->value.IsInt());
            ParentBooliId = ParentBooliId_iter->value.GetInt();
        }
    }

    auto ParentTypes_iter = json_value.FindMember("parentTypes");
    if ( ParentTypes_iter != json_value.MemberEnd() ) {

        for( auto array_item = ParentTypes_iter->value.Begin(); array_item != ParentTypes_iter->value.End(); array_item++  ) {

            if (!array_item->IsNull()) {
                assert(array_item->IsString());
                ParentTypes.push_back(array_item->GetString());
            }
        }
    }

    auto Name_iter = json_value.FindMember("name");
    if ( Name_iter != json_value.MemberEnd() ) {

        if (Name_iter->value.IsNull()) {
            Name.clear();
        }
        else {
            assert(Name_iter->value.IsString());
            Name = Name_iter->value.GetString();
        }
    }

}

string to_string(const areas_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"Types\": [";
    for( auto &array_item : val.Types ) {

        os << "\"" << array_item << "\",";
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << pretty_print << "\"UrlFriendlyName\": \"" << val.UrlFriendlyName << "\"," << endl;
    os << indent << pretty_print << "\"FullName\": \"" << val.FullName << "\"," << endl;
    os << indent << pretty_print << "\"BooliId\": " << val.BooliId << "," << endl;
    os << indent << pretty_print << "\"ParentName\": \"" << val.ParentName << "\"," << endl;
    os << indent << pretty_print << "\"ParentBooliId\": " << val.ParentBooliId << "," << endl;
    os << indent << pretty_print << "\"ParentTypes\": [";
    for( auto &array_item : val.ParentTypes ) {

        os << "\"" << array_item << "\",";
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << pretty_print << "\"Name\": \"" << val.Name << "\"," << endl;
    os << indent << "}";

    return os.str();
}


areas_t AreasFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return areas_t(doc);
}

areas_t AreasFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    areas_t instance = AreasFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<areas_t> AreasArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<areas_t> AreasArray;
    AreasArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        areas_t instance = areas_t(*array_item);
        AreasArray.push_back(instance);
    }

    return AreasArray;
}

} // namespace models
} // namespace tr

