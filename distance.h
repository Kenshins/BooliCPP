



//
//  distance.h
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

class distance_t  {

public:
    int ocean;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    distance_t() = default;
    distance_t(const distance_t &other) = default;
    distance_t(const rapidjson::Value &value);

}; // class distance_t

std::string to_string(const distance_t &val, std::string indent = "", std::string pretty_print = "");

distance_t distanceFromJsonData(const char * jsonData, size_t len);
distance_t distanceFromFile(std::string filename);
std::vector<distance_t> distanceArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
