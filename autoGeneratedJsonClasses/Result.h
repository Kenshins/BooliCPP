



//
//  Result.h
//
//  Created by js2Model on 2018-01-07.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "SearchParams.h"
#include "Listings.h"
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class result_t  {

public:
    int TotalCount;
    int Offset;
    std::vector<listings_t> Listings;
    int Limit;
    int Count;
    searchParams_t SearchParams;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    result_t() = default;
    result_t(const result_t &other) = default;
    result_t(const rapidjson::Value &value);

}; // class result_t

std::string to_string(const result_t &val, std::string indent = "", std::string pretty_print = "");

result_t ResultFromJsonData(const char * jsonData, size_t len);
result_t ResultFromFile(std::string filename);
std::vector<result_t> ResultArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
