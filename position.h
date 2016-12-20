



//
//  position.h
//
//  Created by js2Model on 2016-12-13.
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
    float latitude;
    float longitude;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    position_t() = default;
    position_t(const position_t &other) = default;
    position_t(const rapidjson::Value &value);

}; // class position_t

std::string to_string(const position_t &val, std::string indent = "", std::string pretty_print = "");

position_t positionFromJsonData(const char * jsonData, size_t len);
position_t positionFromFile(std::string filename);
std::vector<position_t> positionArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
