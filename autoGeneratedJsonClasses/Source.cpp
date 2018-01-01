



//
//  Source.cpp
//
//  Created by js2Model on 2017-12-31.
//

#include "Source.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

source_t::source_t(const rapidjson::Value &json_value) {

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

    auto Id_iter = json_value.FindMember("id");
    if ( Id_iter != json_value.MemberEnd() ) {

        if (!Id_iter->value.IsNull()) {
            assert(Id_iter->value.IsInt());
            Id = Id_iter->value.GetInt();
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

    auto Type_iter = json_value.FindMember("type");
    if ( Type_iter != json_value.MemberEnd() ) {

        if (Type_iter->value.IsNull()) {
            Type.clear();
        }
        else {
            assert(Type_iter->value.IsString());
            Type = Type_iter->value.GetString();
        }
    }

}

string to_string(const source_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"Url\": \"" << val.Url << "\"," << endl;
    os << indent << pretty_print << "\"Id\": " << val.Id << "," << endl;
    os << indent << pretty_print << "\"Name\": \"" << val.Name << "\"," << endl;
    os << indent << pretty_print << "\"Type\": \"" << val.Type << "\"," << endl;
    os << indent << "}";

    return os.str();
}


source_t SourceFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return source_t(doc);
}

source_t SourceFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    source_t instance = SourceFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<source_t> SourceArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<source_t> SourceArray;
    SourceArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        source_t instance = source_t(*array_item);
        SourceArray.push_back(instance);
    }

    return SourceArray;
}

} // namespace models
} // namespace tr

