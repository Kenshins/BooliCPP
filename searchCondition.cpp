#include "searchCondition.h"
#include <string>
#include <stdexcept>
#include <ctime>
#include <time.h>

using namespace std;

// Supporting types

center::center(int la, int ln)
{
  SetLatLong(la, ln);
}

void center::SetLatLong(int la, int ln)
{
  SetLat(la);
  SetLong(ln);
}

void center::SetLat(int la)
{
    if (la < 0 || la > 90)
    {
      throw std::invalid_argument( "center la cannot be lower then 0 or higher then 90!" );
    }
    latitude = la;
}

void center::SetLong(int ln)
{
   if (ln < 0 || ln > 180)
    {
      throw std::invalid_argument( "center ln cannot be lower then 0 or higher then 180!" );
    }
   longitude = ln;
}

std::string center::RetCenter()
{
  // TODO
}

dimension::dimension(int x, int y)
{
  SetX(x);
  SetY(y);
}

void dimension::SetX(int inx)
{
  if (inx < 0)
    throw std::invalid_argument( "dimension x cannot be negative!" );

  x = inx;
}

void dimension::SetY(int iny)
{
  if (iny < 0)
    throw std::invalid_argument( "dimension y cannot be negative!" );

  y = iny;
}

std::string dimension::RetDim()
{
}

bbox::bbox(double lat_lo, double lng_lo, double lat_hi, double lng_hi)
{
  if (lat_lo < 0 || lat_lo > 90)
    {
      throw std::invalid_argument( "bbox: lat_lo cannot be lower then 0 or higher then 90!" );
    } 

  if (lng_lo < 0 || lng_lo > 180)
    {
      throw std::invalid_argument( "bbox: lng_lo cannot be lower then 0 or higher then 180!" );
    }

    if (lat_hi < 0 || lat_hi > 90)
    {
      throw std::invalid_argument( "bbox: lat_hi cannot be lower then 0 or higher then 90!" );
    }  

  if (lng_hi < 0 || lng_hi > 180)
    {
      throw std::invalid_argument( "bbox: lng_hi cannot be lower then 0 or higher then 180!" );
    }

  if ( lat_lo > lat_hi)
    {
      throw std::invalid_argument( "bbox: lat_lo cannot be higher then lat_hi!" );
    }

  if ( lng_lo > lng_hi)
    {
      throw std::invalid_argument( "bbox: lng_lo cannot be higer then lng_hi!" );
    } 

  latLo = lat_lo;
  lngLo = lng_lo;
  latHi = lat_hi;
  lngHi = lng_hi;
}

std::string bbox::RetBbox()
{
  // TODO
}

objectType::objectType(std::string oT)
{
  if (oT == "villa")
    {
      object_type = oT;
    }
  else if (oT == "lägenhet")
    {
      object_type = oT;
    }
  else if (oT == "gård")
    {
      object_type = oT;
    }
   else if (oT == "tomt-mark")
    {
      object_type = oT;
    }
   else if (oT == "fritidshus")
    {
      object_type = oT;
    }
   else if (oT == "parhus")
    {
      object_type = oT;
    }
   else if (oT == "radhus")
    {
      object_type = oT;
    }
   else if (oT == "kedjehus")
    {
      object_type = oT;
    }
   else
     {
       throw std::invalid_argument( "objectType: unknown objectType!" );
     }
}

std::string objectType::retObjectType()
{
  return object_type;
}

minPublishedDate::minPublishedDate(tm *t)
{
  if (!util::valid_date(t->tm_year, t->tm_mon, t->tm_mday))
    {
      throw std::invalid_argument( "minPublishedDate: date is invalid!" );
    }
  
  minPubDateTime = t;
}

std::string minPublishedDate::retMinPublishedDate()
{
  return std::to_string(minPubDateTime->tm_year) + std::to_string(minPubDateTime->tm_mon) + std::to_string(minPubDateTime->tm_mday);
}

maxPublishedDate::maxPublishedDate(tm *t)
{

  if (!util::valid_date(t->tm_year, t->tm_mon, t->tm_mday))
    {
      throw std::invalid_argument( "minPublishedDate: date is invalid!" );
    }

  maxPubDateTime = t;
}

std::string maxPublishedDate::retMaxPublishedDate()
{
    return std::to_string(maxPubDateTime->tm_year) + std::to_string(maxPubDateTime->tm_mon) + std::to_string(maxPubDateTime->tm_mday);
}

// Main type

listingsSearchCondition_t::listingsSearchCondition_t()
{
}

// Listing Search Condition sub class

void listingsSearchCondition_t::SetC(center *c)
{
  if (c)
    cent = c;
}

void listingsSearchCondition_t::SetDim(dimension *d)
{
  if (dim)
    dim = d;
}

void listingsSearchCondition_t::SetBbox(bbox *b)
{
  if (bB)
    bB = b;
}

void listingsSearchCondition_t::SetAreaId(std::string aId)
{
  areaId = aId;
}

void listingsSearchCondition_t::SetMinListPrice(double minLP)
{
  if (minLP < 0)
    throw std::invalid_argument( "SetMinListPrice: Min list price cannot be negative!" );

  minListPrice = minLP;
}

void listingsSearchCondition_t::SetMaxListPrice(double maxLP)
{
  if (maxLP < 0)
    throw std::invalid_argument( "SetMaxListPrice: Max list price cannot be negative!" );

  maxListPrice = maxLP;
}

void listingsSearchCondition_t::SetMinListSqmPrice(double minLSP)
{
  if (minLSP < 0)
    throw std::invalid_argument( "SetMinListSqmPrice: Min list square meter price cannot be negative!" );

  minListSqmPrice = minLSP;
}

void listingsSearchCondition_t::SetMaxListSqmPrice(double maxLSP)
{
  if (maxLSP < 0)
    throw std::invalid_argument( "SetMaxListSqmPrice: Max list square meter price cannot be negative!" );

  maxListSqmPrice = maxLSP;
}

void listingsSearchCondition_t::SetMinRooms(int minR)
{
  if (minR < 0)
    throw std::invalid_argument( "SetMinRooms: min rooms cannot be negative!" );

  minRooms = minR;
}

void listingsSearchCondition_t::SetMaxRooms(int maxR)
{
  if (maxR < 0)
    throw std::invalid_argument( "SetMaxRooms: max rooms cannot be negative!" );

  maxRooms = maxR;
}

void listingsSearchCondition_t::SetMaxRent(double maxRe)
{
  if (maxRe < 0)
    throw std::invalid_argument( "SetMaxRent: max rent cannot be negative!" );

  maxRent = maxRe;
}

void listingsSearchCondition_t::SetMinLivingArea(int minLA)
{
  if (minLA < 0)
    throw std::invalid_argument( "SetMinLivingArea: min living area cannot be negative!" );

  minLivingArea = minLA;
}

void listingsSearchCondition_t::SetMaxLivingArea(int maxLA)
{
  if (maxLA < 0)
    throw std::invalid_argument( "SetMaxLivingArea: max living area cannot be negative!" );

  maxLivingArea = maxLA;
}

void listingsSearchCondition_t::SetMinPlotArea(int minPA)
{
  if (minPA < 0)
    throw std::invalid_argument( "SetMinPlotArea: min plot area cannot be negative!" );

  minPlotArea = minPA;
}

void listingsSearchCondition_t::SetMaxPlotArea(int maxPA)
{
  if (maxPA < 0)
    throw std::invalid_argument( "SetMaxPlotArea: max plot area cannot be negative!" );

  maxPlotArea = maxPA;
}

void listingsSearchCondition_t::SetObjectType(std::string oT)
{
      objectT = new objectType(oT);
}

void listingsSearchCondition_t::SetMinConstructionYear(int minCY)
{
  if (minCY < 0)
    throw std::invalid_argument( "SetMinConstructionYear: min construction year cannot be negative!" );

  minConstructionYear = minCY;
}

void listingsSearchCondition_t::SetMaxConstructionYear(int maxCY)
{
  if (maxCY < 0)
    throw std::invalid_argument( "SetMaxConstructionYear: max construction year cannot be negative!" );

  maxConstructionYear = maxCY;
}

void listingsSearchCondition_t::SetMinPublishDate(minPublishedDate *minPD)
{
  if (minPD)
      minPubDate = minPD;
}

void listingsSearchCondition_t::SetMaxPublishDate(maxPublishedDate *maxPD)
{
  if (maxPD)
    maxPubDate = maxPD;
}

void listingsSearchCondition_t::SetPriceDecrease(bool pD)
{
  priceDecrease = pD;
}

void listingsSearchCondition_t::SetIsNewConstruction(bool nC)
{
  isNewConstruction = nC;
}

void listingsSearchCondition_t::SetIncludeUnset(bool iU)
{
  includeUnset = iU;
}

void listingsSearchCondition_t::SetLimit(int l)
{
  limit = l;
}

void listingsSearchCondition_t::SetOffset(int o)
{
  offset = o;
}

std::string listingsSearchCondition_t::SearchConditionResult()
{
  return "";
}

soldSearchCondition_t::soldSearchCondition_t()
{
}

std::string soldSearchCondition_t::SearchConditionResult()
{
  return "";
}

areasSearchCondition_t::areasSearchCondition_t()
{
}

std::string areasSearchCondition_t::SearchConditionResult()
{
  return "";
}

bool util::isleapyear(int year){
	return (!(year%4) && (year%100) || !(year%400));
}

// TODO: Maybe I rewrite this to return a error string instead
bool util::valid_date(int year,int month,int day){
	unsigned short monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if (!year || !month || !day || month>12)
	  return 0;
	if (year < 1800 || year > 3000)
	  return 0;
	if (month < 0 || month > 11)
	  return 0;
	if (isleapyear(year) && month==2)
	  monthlen[1]++;
	if (day>monthlen[month-1])
	  return 0;
	return 1;
}
