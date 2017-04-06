



//
//  searchParams.h
//
//  Created by js2Model on 2017-04-06.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class searchParams_t  {

public:
    int areaId;
    int upcomingSale;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    searchParams_t() = default;
    searchParams_t(const searchParams_t &other) = default;
    searchParams_t(const rapidjson::Value &value);

}; // class searchParams_t

std::string to_string(const searchParams_t &val, std::string indent = "", std::string pretty_print = "");

searchParams_t searchParamsFromJsonData(const char * jsonData, size_t len);
searchParams_t searchParamsFromFile(std::string filename);
std::vector<searchParams_t> searchParamsArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
