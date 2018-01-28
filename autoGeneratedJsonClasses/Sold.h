



//
//  Sold.h
//
//  Created by js2Model on 2018-01-28.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "Location.h"
#include "Source.h"
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class sold_t  {

public:
    std::string SoldDate;
    source_t Source;
    double LivingArea;
    double Rooms;
    double AdditionalArea;
    int PlotArea;
    double ListPrice;
    location_t Location;
    std::string Published;
    std::string Url;
    std::string SoldPriceSource;
    double Rent;
    int BooliId;
    double SoldPrice;
    std::string ObjectType;
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
