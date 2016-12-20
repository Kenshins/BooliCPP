



//
//  areas.cpp
//
//  Created by js2Model on 2016-12-13.
//

#include "areas.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

areas_t::areas_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto booliId_iter = json_value.FindMember("booliId");
    if ( booliId_iter != json_value.MemberEnd() ) {

        if (!booliId_iter->value.IsNull()) {
            assert(booliId_iter->value.IsInt());
            booliId = booliId_iter->value.GetInt();
        }
    }

    auto parentName_iter = json_value.FindMember("parentName");
    if ( parentName_iter != json_value.MemberEnd() ) {

        if (parentName_iter->value.IsNull()) {
            parentName.clear();
        }
        else {
            assert(parentName_iter->value.IsString());
            parentName = parentName_iter->value.GetString();
        }
    }

    auto parentBooliId_iter = json_value.FindMember("parentBooliId");
    if ( parentBooliId_iter != json_value.MemberEnd() ) {

        if (!parentBooliId_iter->value.IsNull()) {
            assert(parentBooliId_iter->value.IsInt());
            parentBooliId = parentBooliId_iter->value.GetInt();
        }
    }

    auto parentTypes_iter = json_value.FindMember("parentTypes");
    if ( parentTypes_iter != json_value.MemberEnd() ) {

        for( auto array_item = parentTypes_iter->value.Begin(); array_item != parentTypes_iter->value.End(); array_item++  ) {

            if (!array_item->IsNull()) {
                assert(array_item->IsString());
                parentTypes.push_back(array_item->GetString());
            }
        }
    }

    auto fullName_iter = json_value.FindMember("fullName");
    if ( fullName_iter != json_value.MemberEnd() ) {

        if (fullName_iter->value.IsNull()) {
            fullName.clear();
        }
        else {
            assert(fullName_iter->value.IsString());
            fullName = fullName_iter->value.GetString();
        }
    }

    auto urlFriendlyName_iter = json_value.FindMember("urlFriendlyName");
    if ( urlFriendlyName_iter != json_value.MemberEnd() ) {

        if (urlFriendlyName_iter->value.IsNull()) {
            urlFriendlyName.clear();
        }
        else {
            assert(urlFriendlyName_iter->value.IsString());
            urlFriendlyName = urlFriendlyName_iter->value.GetString();
        }
    }

    auto types_iter = json_value.FindMember("types");
    if ( types_iter != json_value.MemberEnd() ) {

        for( auto array_item = types_iter->value.Begin(); array_item != types_iter->value.End(); array_item++  ) {

            if (!array_item->IsNull()) {
                assert(array_item->IsString());
                types.push_back(array_item->GetString());
            }
        }
    }

    auto name_iter = json_value.FindMember("name");
    if ( name_iter != json_value.MemberEnd() ) {

        if (name_iter->value.IsNull()) {
            name.clear();
        }
        else {
            assert(name_iter->value.IsString());
            name = name_iter->value.GetString();
        }
    }

}

string to_string(const areas_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"booliId\": " << val.booliId << "," << endl;
    os << indent << pretty_print << "\"parentName\": \"" << val.parentName << "\"," << endl;
    os << indent << pretty_print << "\"parentBooliId\": " << val.parentBooliId << "," << endl;
    os << indent << pretty_print << "\"parentTypes\": [";
    for( auto &array_item : val.parentTypes ) {

        os << "\"" << array_item << "\",";
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << pretty_print << "\"fullName\": \"" << val.fullName << "\"," << endl;
    os << indent << pretty_print << "\"urlFriendlyName\": \"" << val.urlFriendlyName << "\"," << endl;
    os << indent << pretty_print << "\"types\": [";
    for( auto &array_item : val.types ) {

        os << "\"" << array_item << "\",";
    }
    os << indent << pretty_print << "]," << endl;
    os << indent << pretty_print << "\"name\": \"" << val.name << "\"," << endl;
    os << indent << "}";

    return os.str();
}


areas_t areasFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return areas_t(doc);
}

areas_t areasFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    areas_t instance = areasFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<areas_t> areasArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<areas_t> areasArray;
    areasArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        areas_t instance = areas_t(*array_item);
        areasArray.push_back(instance);
    }

    return areasArray;
}

} // namespace models
} // namespace tr

