



//
//  Listings.h
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

class listings_t  {

public:
    int IsNewConstruction;
    double LivingArea;
    source_t Source;
    location_t Location;
    std::string Published;
    double ListPrice;
    std::string ObjectType;
    double Rent;
    int BooliId;
    std::string Url;
    double Rooms;
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
