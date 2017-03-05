



//
//  position.cpp
//
//  Created by js2Model on 2017-03-05.
//

#include "position.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

position_t::position_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto latitude_iter = json_value.FindMember("latitude");
    if ( latitude_iter != json_value.MemberEnd() ) {

	if (!latitude_iter->value.IsNull()) {
	  if (latitude_iter->value.IsInt())
	    {
	      latitude = (float)latitude_iter->value.GetInt();
	    }
	  else if (latitude_iter->value.IsFloat())
	    {
	      latitude = latitude_iter->value.GetFloat();
	    }
	  else
	    {
	      assert(latitude_iter->value.IsFloat());
	    }
        }
    }

    auto longitude_iter = json_value.FindMember("longitude");
    if ( longitude_iter != json_value.MemberEnd() ) {

	if (!longitude_iter->value.IsNull()) {
	  if (longitude_iter->value.IsInt())
	    {
	      longitude = (float)longitude_iter->value.GetInt();
	    }
	  else if (longitude_iter->value.IsFloat())
	    {
	      longitude = longitude_iter->value.GetFloat();
	    }
	  else
	    {
	      assert(longitude_iter->value.IsFloat());
	    }
        }
    }

}

string to_string(const position_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"latitude\": " << val.latitude << "," << endl;
    os << indent << pretty_print << "\"longitude\": " << val.longitude << "," << endl;
    os << indent << "}";

    return os.str();
}


position_t positionFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return position_t(doc);
}

position_t positionFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    position_t instance = positionFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<position_t> positionArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<position_t> positionArray;
    positionArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        position_t instance = position_t(*array_item);
        positionArray.push_back(instance);
    }

    return positionArray;
}

} // namespace models
} // namespace tr

