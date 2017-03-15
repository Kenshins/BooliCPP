



//
//  result.h
//
//  Created by js2Model on 2017-03-10.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "searchParams.h"
#include "listings.h"
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class result_t  {

public:
    int count;
    searchParams_t searchParams;
    std::vector<listings_t> listings;
    int totalCount;
    int limit;
    int offset;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    result_t() = default;
    result_t(const result_t &other) = default;
    result_t(const rapidjson::Value &value);

}; // class result_t

std::string to_string(const result_t &val, std::string indent = "", std::string pretty_print = "");

result_t resultFromJsonData(const char * jsonData, size_t len);
result_t resultFromFile(std::string filename);
std::vector<result_t> resultArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
