



//
//  Region.h
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

class region_t  {

public:
    std::string MunicipalityName;
    std::string CountyName;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    region_t() = default;
    region_t(const region_t &other) = default;
    region_t(const rapidjson::Value &value);

}; // class region_t

std::string to_string(const region_t &val, std::string indent = "", std::string pretty_print = "");

region_t RegionFromJsonData(const char * jsonData, size_t len);
region_t RegionFromFile(std::string filename);
std::vector<region_t> RegionArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr