



//
//  Position.h
//
//  Created by js2Model on 2017-12-31.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class position_t  {

public:
    double Longitude;
    double Latitude;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    position_t() = default;
    position_t(const position_t &other) = default;
    position_t(const rapidjson::Value &value);

}; // class position_t

std::string to_string(const position_t &val, std::string indent = "", std::string pretty_print = "");

position_t PositionFromJsonData(const char * jsonData, size_t len);
position_t PositionFromFile(std::string filename);
std::vector<position_t> PositionArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
