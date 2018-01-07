



//
//  Listings.h
//
//  Created by js2Model on 2018-01-07.
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

class listings_t  {

public:
    source_t Source;
    std::string Published;
    double Rooms;
    location_t Location;
    int IsNewConstruction;
    std::string Url;
    std::string ObjectType;
    double LivingArea;
    int BooliId;
    double Rent;
    double ListPrice;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    listings_t() = default;
    listings_t(const listings_t &other) = default;
    listings_t(const rapidjson::Value &value);

}; // class listings_t

std::string to_string(const listings_t &val, std::string indent = "", std::string pretty_print = "");

listings_t ListingsFromJsonData(const char * jsonData, size_t len);
listings_t ListingsFromFile(std::string filename);
std::vector<listings_t> ListingsArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
