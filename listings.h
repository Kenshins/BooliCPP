



//
//  listings.h
//
//  Created by js2Model on 2017-03-05.
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

class listings_t  {

public:
    int booliId;
    float livingArea;
    std::string url;
    location_t location;
    source_t source;
    float rent;
    std::string published;
    int isNewConstruction;
    std::string objectType;
    float listPrice;
    float rooms;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    listings_t() = default;
    listings_t(const listings_t &other) = default;
    listings_t(const rapidjson::Value &value);

}; // class listings_t

std::string to_string(const listings_t &val, std::string indent = "", std::string pretty_print = "");

listings_t listingsFromJsonData(const char * jsonData, size_t len);
listings_t listingsFromFile(std::string filename);
std::vector<listings_t> listingsArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
