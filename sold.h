



//
//  sold.h
//
//  Created by js2Model on 2016-12-13.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "location.h"
#include "source.h"
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class sold_t  {

public:
    int booliId;
    int livingArea;
    std::string url;
    int constructionYear;
    location_t location;
    int soldPrice;
    source_t source;
    std::string soldDate;
    int rooms;
    std::string published;
    int additionalArea;
    std::string objectType;
    int rent;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    sold_t() = default;
    sold_t(const sold_t &other) = default;
    sold_t(const rapidjson::Value &value);

}; // class sold_t

std::string to_string(const sold_t &val, std::string indent = "", std::string pretty_print = "");

sold_t soldFromJsonData(const char * jsonData, size_t len);
sold_t soldFromFile(std::string filename);
std::vector<sold_t> soldArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
