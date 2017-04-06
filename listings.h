



//
//  listings.h
//
//  Created by js2Model on 2017-04-06.
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
    double livingArea;
    double floor;
    std::string url;
    int constructionYear;
    location_t location;
    double plotArea;
    source_t source;
    double rooms;
    std::string published;
    bool isNewConstruction;
    double additionalArea;
    std::string objectType;
    double listPrice;
    double rent;
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
