



//
//  Areas.h
//
//  Created by js2Model on 2018-01-28.
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
    std::vector<std::string> ParentTypes;
    int BooliId;
    std::vector<std::string> Types;
    int ParentBooliId;
    std::string ParentName;
    std::string UrlFriendlyName;
    std::string Name;
    std::string FullName;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    areas_t() = default;
    areas_t(const areas_t &other) = default;
    areas_t(const rapidjson::Value &value);

}; // class areas_t

std::string to_string(const areas_t &val, std::string indent = "", std::string pretty_print = "");

areas_t AreasFromJsonData(const char * jsonData, size_t len);
areas_t AreasFromFile(std::string filename);
std::vector<areas_t> AreasArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
