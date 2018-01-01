



//
//  Sold.h
//
//  Created by js2Model on 2017-12-31.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "Source.h"
#include "Location.h"
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class sold_t  {

public:
    std::string Published;
    std::string ObjectType;
    std::string SoldDate;
    int PlotArea;
    int AdditionalArea;
    std::string SoldPriceSource;
    int Rooms;
    int Rent;
    source_t Source;
    int ListPrice;
    location_t Location;
    std::string Url;
    int BooliId;
    int SoldPrice;
    int LivingArea;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    sold_t() = default;
    sold_t(const sold_t &other) = default;
    sold_t(const rapidjson::Value &value);

}; // class sold_t

std::string to_string(const sold_t &val, std::string indent = "", std::string pretty_print = "");

sold_t SoldFromJsonData(const char * jsonData, size_t len);
sold_t SoldFromFile(std::string filename);
std::vector<sold_t> SoldArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
