



//
//  Areas.h
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

class areas_t  {

public:
    std::string UrlFriendlyName;
    std::vector<std::string> ParentTypes;
    std::vector<std::string> Types;
    std::string ParentName;
    int ParentBooliId;
    std::string FullName;
    int BooliId;
    std::string Name;
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
