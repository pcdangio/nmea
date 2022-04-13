#include "parse.hpp"

double nmea::parse::utc(const std::string& utc_string)
{
    // FORMAT: hhmmss.ss...

    // Parse hours.
    double utc = std::stod(utc_string.substr(0,2)) * 3600.0;

    // Parse minutes.
    utc += std::stod(utc_string.substr(2,2)) * 60.0;

    // Parse seconds.
    utc += std::stod(utc_string.substr(4));

    return utc;
}
double nmea::parse::latitude(const std::string& latitude_string, const std::string& direction_string)
{
    // FORMAT: ddmm.mm...

    // Parse degrees.
    double latitude = std::stod(latitude_string.substr(0,2));

    // Parse minutes and convert to decimal degrees.
    latitude += std::stod(latitude_string.substr(2)) / 60.0;

    // Get latitude direction.
    if(direction_string == "S")
    {
        latitude *= -1.0;
    }

    return latitude;
}
double nmea::parse::longitude(const std::string& longitude_string, const std::string& direction_string)
{
    // FORMAT: dddmm.mm...

    // Parse degrees.
    double longitude = std::stod(longitude_string.substr(0,3));

    // Parse minutes and convert to decimal degrees.
    longitude += std::stod(longitude_string.substr(3)) / 60.0;

    // Get longitude direction.
    if(direction_string == "W")
    {
        longitude *= -1.0;
    }

    return longitude;
}