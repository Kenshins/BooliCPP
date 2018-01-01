



//
//  Distance.cpp
//
//  Created by js2Model on 2017-12-31.
//

#include "Distance.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

distance_t::distance_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto Ocean_iter = json_value.FindMember("ocean");
    if ( Ocean_iter != json_value.MemberEnd() ) {

        if (!Ocean_iter->value.IsNull()) {
            assert(Ocean_iter->value.IsInt());
            Ocean = Ocean_iter->value.GetInt();
        }
    }

}

string to_string(const distance_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"Ocean\": " << val.Ocean << "," << endl;
    os << indent << "}";

    return os.str();
}


distance_t DistanceFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return distance_t(doc);
}

distance_t DistanceFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    distance_t instance = DistanceFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<distance_t> DistanceArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<distance_t> DistanceArray;
    DistanceArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        distance_t instance = distance_t(*array_item);
        DistanceArray.push_back(instance);
    }

    return DistanceArray;
}

} // namespace models
} // namespace tr

