



//
//  Booliresult.h
//
//  Created by js2Model on 2018-01-28.
//

#include <string>
#include <unordered_map>
#include <vector>
#include "Sold.h"
#include "Listings.h"
#include "Areas.h"
#include "SearchParams.h"
#include "rapidjson/document.h"


#pragma once

namespace tr {
namespace models {

class booliresult_t  {

public:
    std::vector<listings_t> Listings;
    int Offset;
    std::vector<areas_t> Areas;
    searchParams_t SearchParams;
    int TotalCount;
    std::vector<sold_t> Sold;
    int Limit;
    int Count;
    std::unordered_map<std::string, std::string> additionalProperties;

public:

    booliresult_t() = default;
    booliresult_t(const booliresult_t &other) = default;
    booliresult_t(const rapidjson::Value &value);

}; // class booliresult_t

std::string to_string(const booliresult_t &val, std::string indent = "", std::string pretty_print = "");

booliresult_t BooliresultFromJsonData(const char * jsonData, size_t len);
booliresult_t BooliresultFromFile(std::string filename);
std::vector<booliresult_t> BooliresultArrayFromData(const char *jsonData, size_t len);


} // namespace models
} // namespace tr
