



//
//  SearchParams.h
//
//  Created by js2Model on 2018-01-07.
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
    int Listings;
    std::string Q;
    int Transactions;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    searchParams_t() = default;
    searchParams_t(const searchParams_t &other) = default;
    searchParams_t(const rapidjson::Value &value);

}; // class searchParams_t

std::string to_string(const searchParams_t &val, std::string indent = "", std::string pretty_print = "");

searchParams_t SearchParamsFromJsonData(const char * jsonData, size_t len);
searchParams_t SearchParamsFromFile(std::string filename);
std::vector<searchParams_t> SearchParamsArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
