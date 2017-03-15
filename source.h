



//
//  source.h
//
//  Created by js2Model on 2017-03-10.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class source_t  {

public:
    std::string url;
    std::string type;
    int id;
    std::string name;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    source_t() = default;
    source_t(const source_t &other) = default;
    source_t(const rapidjson::Value &value);

}; // class source_t

std::string to_string(const source_t &val, std::string indent = "", std::string pretty_print = "");

source_t sourceFromJsonData(const char * jsonData, size_t len);
source_t sourceFromFile(std::string filename);
std::vector<source_t> sourceArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
