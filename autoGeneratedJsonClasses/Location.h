



//
//  Location.h
//
//  Created by js2Model on 2017-12-31.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "Region.h"
#include "Position.h"
#include "Address.h"
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class location_t  {

public:
    std::vector<std::string> NamedAreas;
    region_t Region;
    position_t Position;
    address_t Address;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    location_t() = default;
    location_t(const location_t &other) = default;
    location_t(const rapidjson::Value &value);

}; // class location_t

std::string to_string(const location_t &val, std::string indent = "", std::string pretty_print = "");

location_t LocationFromJsonData(const char * jsonData, size_t len);
location_t LocationFromFile(std::string filename);
std::vector<location_t> LocationArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
