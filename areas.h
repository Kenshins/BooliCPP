



//
//  areas.h
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

class areas_t  {

public:
    int booliId;
    std::string parentName;
    int parentBooliId;
    std::vector<std::string> parentTypes;
    std::string fullName;
    std::string urlFriendlyName;
    std::vector<std::string> types;
    std::string name;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    areas_t() = default;
    areas_t(const areas_t &other) = default;
    areas_t(const rapidjson::Value &value);

}; // class areas_t

std::string to_string(const areas_t &val, std::string indent = "", std::string pretty_print = "");

areas_t areasFromJsonData(const char * jsonData, size_t len);
areas_t areasFromFile(std::string filename);
std::vector<areas_t> areasArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
