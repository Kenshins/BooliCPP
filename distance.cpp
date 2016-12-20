



//
//  distance.cpp
//
//  Created by js2Model on 2016-12-13.
//

#include "distance.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

distance_t::distance_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto ocean_iter = json_value.FindMember("ocean");
    if ( ocean_iter != json_value.MemberEnd() ) {

        if (!ocean_iter->value.IsNull()) {
            assert(ocean_iter->value.IsInt());
            ocean = ocean_iter->value.GetInt();
        }
    }

}

string to_string(const distance_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"ocean\": " << val.ocean << "," << endl;
    os << indent << "}";

    return os.str();
}


distance_t distanceFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return distance_t(doc);
}

distance_t distanceFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    distance_t instance = distanceFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<distance_t> distanceArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<distance_t> distanceArray;
    distanceArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        distance_t instance = distance_t(*array_item);
        distanceArray.push_back(instance);
    }

    return distanceArray;
}

} // namespace models
} // namespace tr

