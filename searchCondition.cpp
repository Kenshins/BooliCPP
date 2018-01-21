#include "searchCondition.h"
#include <string>
#include <algorithm>
#include <stdexcept>
#include <sstream>
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
  stringstream ss;
  ss << latitude << "," <<longitude;
  return ss.str(); 
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
  stringstream ss;
  ss << x << "," << y;
  return ss.str();
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
  stringstream ss;
  ss << latLo << "," << lngLo << "," << latHi << "," << lngHi;
  return ss.str();
}

objectType::objectType(std::string oT)
{
  std::transform(oT.begin(), oT.end(),oT.begin(), ::tolower);
  
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
       throw std::invalid_argument( "objectType:" + oT + "unknown objectType!" );
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
  std::string month = "";
  if (minPubDateTime->tm_mon < 10)
    month = "0" + std::to_string(minPubDateTime->tm_mon);
  else
    month = std::to_string(minPubDateTime->tm_mon);
  
  return std::to_string(minPubDateTime->tm_year) + month + std::to_string(minPubDateTime->tm_mday);
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
  std::string month = "";
  if (maxPubDateTime->tm_mon < 10)
    month = "0" + std::to_string(maxPubDateTime->tm_mon);
  else
    month = std::to_string(maxPubDateTime->tm_mon);
  
    return std::to_string(maxPubDateTime->tm_year) + month + std::to_string(maxPubDateTime->tm_mday);
}

minSoldDate::minSoldDate(tm *t)
{
  if (!util::valid_date(t->tm_year, t->tm_mon, t->tm_mday))
    {
      throw std::invalid_argument( "minPublishedDate: date is invalid!" );
    }
  
  minSoldDateTime = t;
}

std::string minSoldDate::retMinSoldDate()
{
  std::string month = "";
  if (minSoldDateTime->tm_mon < 10)
    month = "0" + std::to_string(minSoldDateTime->tm_mon);
  else
    month = std::to_string(minSoldDateTime->tm_mon);
  
  return std::to_string(minSoldDateTime->tm_year) + month + std::to_string(minSoldDateTime->tm_mday);
}

maxSoldDate::maxSoldDate(tm *t)
{

  if (!util::valid_date(t->tm_year, t->tm_mon, t->tm_mday))
    {
      throw std::invalid_argument( "minPublishedDate: date is invalid!" );
    }

  maxSoldDateTime = t;
}

std::string maxSoldDate::retMaxSoldDate()
{
  std::string month = "";
  if (maxSoldDateTime->tm_mon < 10)
    month = "0" + std::to_string(maxSoldDateTime->tm_mon);
  else
    month = std::to_string(maxSoldDateTime->tm_mon);
  
    return std::to_string(maxSoldDateTime->tm_year) + month + std::to_string(maxSoldDateTime->tm_mday);
}

// searchCondition

listingsSearchCondition::listingsSearchCondition()
{

}

void searchCondition::SetQ(std::string q)
{
  checkNoDuplicateMainInput(Q);
  query = q;
}

void searchCondition::SetC(center *c)
{
  checkNoDuplicateMainInput(CENTER);
  if (c)
    cent = c;
}

void searchCondition::SetDim(dimension *d)
{
  checkNoDuplicateMainInput(DIM);
  if (dim)
    dim = d;
}

void searchCondition::SetBbox(bbox *b)
{
  checkNoDuplicateMainInput(BBOX);
  if (bB)
    bB = b;
}

void searchCondition::SetAreaId(std::string aId)
{
  checkNoDuplicateMainInput(AREAID);
  areaId = aId;
}

void searchCondition::SetMinRooms(int minR)
{
  if (minR < 0)
    throw std::invalid_argument( "SetMinRooms: min rooms cannot be negative!" );

  minRooms = minR;
}

void searchCondition::SetMaxRooms(int maxR)
{
  if (maxR < 0)
    throw std::invalid_argument( "SetMaxRooms: max rooms cannot be negative!" );

  maxRooms = maxR;
}

void searchCondition::SetMaxRent(int maxRe)
{
  if (maxRe < 0)
    throw std::invalid_argument( "SetMaxRent: max rent cannot be negative!" );

  maxRent = maxRe;
}

void searchCondition::SetMinLivingArea(int minLA)
{
  if (minLA < 0)
    throw std::invalid_argument( "SetMinLivingArea: min living area cannot be negative!" );

  minLivingArea = minLA;
}

void searchCondition::SetMaxLivingArea(int maxLA)
{
  if (maxLA < 0)
    throw std::invalid_argument( "SetMaxLivingArea: max living area cannot be negative!" );

  maxLivingArea = maxLA;
}

void searchCondition::SetMinPlotArea(int minPA)
{
  if (minPA < 0)
    throw std::invalid_argument( "SetMinPlotArea: min plot area cannot be negative!" );

  minPlotArea = minPA;
}

void searchCondition::SetMaxPlotArea(int maxPA)
{
  if (maxPA < 0)
    throw std::invalid_argument( "SetMaxPlotArea: max plot area cannot be negative!" );

  maxPlotArea = maxPA;
}

void searchCondition::SetMinPublishDate(minPublishedDate *minPD)
{
  if (minPD)
      minPubDate = minPD;
}

void searchCondition::SetMaxPublishDate(maxPublishedDate *maxPD)
{
  if (maxPD)
    maxPubDate = maxPD;
}

void searchCondition::SetObjectType(std::string oT)
{
      objectT = new objectType(oT);
}

void searchCondition::SetMinConstructionYear(int minCY)
{
  if (minCY < 0)
    throw std::invalid_argument( "SetMinConstructionYear: min construction year cannot be negative!" );

  minConstructionYear = minCY;
}

void searchCondition::SetMaxConstructionYear(int maxCY)
{
  if (maxCY < 0)
    throw std::invalid_argument( "SetMaxConstructionYear: max construction year cannot be negative!" );

  maxConstructionYear = maxCY;
}

void searchCondition::SetIsNewConstruction(bool nC)
{
  isNewConstruction = nC;
}

void searchCondition::SetIncludeUnset(bool iU)
{
  includeUnset = iU;
}

void searchCondition::SetLimit(int l)
{
  limit = l;
}

void searchCondition::SetOffset(int o)
{
  offset = o;
}

// listing search condition

void listingsSearchCondition::SetMinListPrice(int minLP)
{
  if (minLP < 0)
    throw std::invalid_argument( "SetMinListPrice: Min list price cannot be negative!" );

  minListPrice = minLP;
}

void listingsSearchCondition::SetMaxListPrice(int maxLP)
{
  if (maxLP < 0)
    throw std::invalid_argument( "SetMaxListPrice: Max list price cannot be negative!" );

  maxListPrice = maxLP;
}

void listingsSearchCondition::SetMinListSqmPrice(int minLSP)
{
  if (minLSP < 0)
    throw std::invalid_argument( "SetMinListSqmPrice: Min list square meter price cannot be negative!" );

  minListSqmPrice = minLSP;
}

void listingsSearchCondition::SetMaxListSqmPrice(int maxLSP)
{
  if (maxLSP < 0)
    throw std::invalid_argument( "SetMaxListSqmPrice: Max list square meter price cannot be negative!" );

  maxListSqmPrice = maxLSP;
}

void listingsSearchCondition::SetPriceDecrease(bool pD)
{
  priceDecrease = pD;
}

void listingsSearchCondition::checkNoDuplicateMainInput(MainInput in)
{
  if (in == BBOX)
    {
      if (cent != NULL || dim != NULL || areaId != "" || query != "")
	{
	  throw std::invalid_argument( "SetBbox: Cannot set bbox if center, dimension, areaid or q is set!" );
	}
    }
  else if (in == Q)
    {
      if (bB != NULL || dim != NULL || areaId != "" || cent != NULL)
	{
	  throw std::invalid_argument( "SetQ: Cannot set center if bbox, dimension, areaid or center is set!" );
	}
    }
  else if (in == CENTER)
    {
      if (bB != NULL || dim != NULL || areaId != "" || query != "")
	{
	  throw std::invalid_argument( "SetC: Cannot set center if bbox, dimension, areaid or q is set!" );
	}
    }
  else if (in == DIM)
    {
      if (bB != NULL || cent != NULL || areaId != "" || query != "")
	{
	   throw std::invalid_argument( "SetDim: Cannot set dimension if bbox, areaid, center or q is set!" );
	}
    }
  else if (in == AREAID)
    {
      if (bB != NULL || cent != NULL || dim != NULL || query != "")
	{
	  throw std::invalid_argument( "SetAreaId: Cannot set areaid if dimension, center, bbox or q is set!" );
	}
    }
}

std::string listingsSearchCondition::SearchConditionResult()
{
  std::string  booliString = "";
  
  if (query != "")
    booliString = "q=" + query;

  if (cent)
    {
    booliString = "center=" + cent->RetCenter();

    if (dim)
      booliString += "&dim=" +  dim->RetDim();
    }

  if (bB)
    booliString = "bbox=" + bB->RetBbox();

  if (areaId != "")
    booliString = "areaId=" + areaId;
  
  if (minListPrice != 0)
    booliString += "&minListPrice=" + util::intToString(minListPrice);

  if (maxListPrice != 0)
    booliString += "&maxListPrice=" + std::to_string(maxListPrice);
  
  if (minListSqmPrice != 0)
    booliString += "&minListSqmPrice=" + util::intToString(minListSqmPrice);

  if (maxListSqmPrice != 0)
    booliString += "&maxListSqmPrice=" + util::intToString(maxListSqmPrice);

  if (minRooms != 0)
    booliString += "&minRooms=" + util::intToString(minRooms);

  if (maxRooms != 0)
    booliString += "&maxRooms=" + util::intToString(maxRooms);

  if (maxRent != 0)
    booliString += "&maxRent=" + util::intToString(maxRent);
  
  if (minLivingArea != 0)
    booliString += "&minLivingArea=" + util::intToString(minLivingArea);

  if (maxLivingArea != 0)
    booliString += "&maxLivingArea=" + util::intToString(maxLivingArea);

  if (minPlotArea != 0)
    booliString += "&minPlotArea=" + util::intToString(minPlotArea);

  if (maxPlotArea != 0)
    booliString += "&maxPlotArea=" + util::intToString(maxPlotArea);
  
  if (objectT != NULL)
    booliString += "&objectType=" + objectT->retObjectType();

  if (minConstructionYear != 0)
    booliString += "&minConstructionYear=" + util::intToString(minConstructionYear);

  if (maxConstructionYear != 0)
    booliString += "&maxConstructionYear=" + util::intToString(maxConstructionYear);

  if (minPubDate != NULL)
    booliString += "&minPublished=" + minPubDate->retMinPublishedDate();

  if (maxPubDate != NULL)
    booliString += "&maxPublished=" + maxPubDate->retMaxPublishedDate();

  if (priceDecrease)
    booliString += "&priceDecrease=1";

  if (isNewConstruction)
    booliString += "&isNewConstruction=1";

  if (!includeUnset)
    booliString += "&includeUnset=0";
    
  booliString += "&limit=" + util::intToString(limit);

  if (offset != 0)
    booliString += "&offset=" + util::intToString(offset);
  
  return booliString;
}

// sold  search condition

void soldSearchCondition::SetMinSoldPrice(int minSP)
{
  if (minSP < 0)
    throw std::invalid_argument( "SetMinSoldPrice: Min sold price cannot be negative!" );

  minSoldPrice = minSP;
}

void soldSearchCondition::SetMaxSoldPrice(int maxSP)
{
  if (maxSP < 0)
    throw std::invalid_argument( "SetMaxSoldPrice: Max sold price cannot be negative!" );

  maxSoldPrice = maxSP;
}

void soldSearchCondition::SetMinSoldSqmPrice(int minSSP)
{
  if (minSSP < 0)
    throw std::invalid_argument( "SetMinSoldSqmPrice: Min sold square meter price cannot be negative!" );

  minSoldSqmPrice = minSSP;
}

void soldSearchCondition::SetMaxSoldSqmPrice(int maxSSP)
{
  if (maxSSP < 0)
    throw std::invalid_argument( "SetMaxSoldSqmPrice: Max sold square meter price cannot be negative!" );

  maxSoldSqmPrice = maxSSP;
}

void soldSearchCondition::SetMinSoldDate(minSoldDate *minSD)
{
  if (minSD)
      minSDate = minSD;
}

void soldSearchCondition::SetMaxSoldDate(maxSoldDate *maxSD)
{
  if (maxSD)
    maxSDate = maxSD;
}


soldSearchCondition::soldSearchCondition()
{
}

void soldSearchCondition::checkNoDuplicateMainInput(MainInput in)
{
}

std::string soldSearchCondition::SearchConditionResult()
{
  return "";
}

// area search condition

areasSearchCondition::areasSearchCondition()
{
}

std::string areasSearchCondition::SearchConditionResult()
{
  return "";
}

std::string util::intToString(int d)
{
  std::ostringstream strs;
  strs << d;
  return strs.str();
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
