



//
//  location.h
//
//  Created by js2Model on 2016-12-13.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "address.h"
#include "position.h"
#include "region.h"
#include "distance.h"
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class location_t  {

public:
    position_t position;
    region_t region;
    address_t address;
    std::vector<std::string> namedAreas;
    distance_t distance;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    location_t() = default;
    location_t(const location_t &other) = default;
    location_t(const rapidjson::Value &value);

}; // class location_t

std::string to_string(const location_t &val, std::string indent = "", std::string pretty_print = "");

location_t locationFromJsonData(const char * jsonData, size_t len);
location_t locationFromFile(std::string filename);
std::vector<location_t> locationArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
