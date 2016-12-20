



//
//  address.h
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

class address_t  {

public:
    std::string city;
    std::string streetAddress;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    address_t() = default;
    address_t(const address_t &other) = default;
    address_t(const rapidjson::Value &value);

}; // class address_t

std::string to_string(const address_t &val, std::string indent = "", std::string pretty_print = "");

address_t addressFromJsonData(const char * jsonData, size_t len);
address_t addressFromFile(std::string filename);
std::vector<address_t> addressArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
