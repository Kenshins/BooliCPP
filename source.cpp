



//
//  source.cpp
//
//  Created by js2Model on 2017-04-06.
//

#include "source.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

source_t::source_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

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

    auto type_iter = json_value.FindMember("type");
    if ( type_iter != json_value.MemberEnd() ) {

        if (type_iter->value.IsNull()) {
            type.clear();
        }
        else {
            assert(type_iter->value.IsString());
            type = type_iter->value.GetString();
        }
    }

    auto id_iter = json_value.FindMember("id");
    if ( id_iter != json_value.MemberEnd() ) {

        if (!id_iter->value.IsNull()) {
            assert(id_iter->value.IsInt());
            id = id_iter->value.GetInt();
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

string to_string(const source_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"url\": \"" << val.url << "\"," << endl;
    os << indent << pretty_print << "\"type\": \"" << val.type << "\"," << endl;
    os << indent << pretty_print << "\"id\": " << val.id << "," << endl;
    os << indent << pretty_print << "\"name\": \"" << val.name << "\"," << endl;
    os << indent << "}";

    return os.str();
}


source_t sourceFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return source_t(doc);
}

source_t sourceFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    source_t instance = sourceFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<source_t> sourceArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<source_t> sourceArray;
    sourceArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        source_t instance = source_t(*array_item);
        sourceArray.push_back(instance);
    }

    return sourceArray;
}

} // namespace models
} // namespace tr

