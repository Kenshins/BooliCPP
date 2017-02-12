#include "searchCondition.h"
#include <string>
#include <stdexcept>
#include <ctime>

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
  minPubDateTime = t;
}

std::string minPublishedDate::retMinPublishedDate()
{
  return std::to_string(minPubDateTime->tm_year) + std::to_string(minPubDateTime->tm_mon) + std::to_string(minPubDateTime->tm_mday);
}

maxPublishedDate::maxPublishedDate(tm *t)
{
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
