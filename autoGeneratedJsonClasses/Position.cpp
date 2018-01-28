



//
//  Position.cpp
//
//  Created by js2Model on 2018-01-28.
//

#include "Position.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using namespace rapidjson;

namespace tr {
namespace models {

position_t::position_t(const rapidjson::Value &json_value) {

    assert(json_value.IsObject());

    auto Latitude_iter = json_value.FindMember("latitude");
    if ( Latitude_iter != json_value.MemberEnd() ) {

	if (!Latitude_iter->value.IsNull()) {
	  if (Latitude_iter->value.IsInt())
	    {
	      Latitude = (double)Latitude_iter->value.GetInt();
	    }
	  else if (Latitude_iter->value.IsDouble())
	    {
	      Latitude = Latitude_iter->value.GetDouble();
	    }
	  else
	    {
	      assert(Latitude_iter->value.IsFloat());
	    }
        }
    }

    auto Longitude_iter = json_value.FindMember("longitude");
    if ( Longitude_iter != json_value.MemberEnd() ) {

	if (!Longitude_iter->value.IsNull()) {
	  if (Longitude_iter->value.IsInt())
	    {
	      Longitude = (double)Longitude_iter->value.GetInt();
	    }
	  else if (Longitude_iter->value.IsDouble())
	    {
	      Longitude = Longitude_iter->value.GetDouble();
	    }
	  else
	    {
	      assert(Longitude_iter->value.IsFloat());
	    }
        }
    }

}

string to_string(const position_t &val, std::string indent/* = "" */, std::string pretty_print/* = "" */) {

    ostringstream os;

    os << indent << "{" << endl;
    os << indent << pretty_print << "\"Latitude\": " << val.Latitude << "," << endl;
    os << indent << pretty_print << "\"Longitude\": " << val.Longitude << "," << endl;
    os << indent << "}";

    return os.str();
}


position_t PositionFromJsonData(const char *data, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], data, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    return position_t(doc);
}

position_t PositionFromFile(string filename) {

    ifstream is;

    stringstream buffer;

    is.open(filename);
    buffer << is.rdbuf();

    position_t instance = PositionFromJsonData(buffer.str().c_str(), buffer.str().length());

    return instance;
}

std::vector<position_t> PositionArrayFromData(const char *jsonData, size_t len) {

    std::vector<char> buffer(len + 1);

    std::memcpy(&buffer[0], jsonData, len);

    Document doc;

    doc.ParseInsitu(&buffer[0]);

    assert(doc.IsArray());

    std::vector<position_t> PositionArray;
    PositionArray.reserve(doc.Size());

    for( auto array_item = doc.Begin(); array_item != doc.End(); array_item++  ) {

        position_t instance = position_t(*array_item);
        PositionArray.push_back(instance);
    }

    return PositionArray;
}

} // namespace models
} // namespace tr

