#include <nmea/gga.hpp>

#include "parse.hpp"

#include <sstream>
#include <iomanip>

using namespace nmea;

// CONSTRUCTORS
gga::gga(const nmea::sentence& sentence)
{
    // Get talker.
    gga::talker = sentence.talker();

    // Parse UTC time of day.
    std::string utc_string = sentence.get_field(0);
    if(!utc_string.empty())
    {
        gga::utc.set(nmea::parse::utc(utc_string));
    }

    // Parse latitude.
    std::string latitude_string = sentence.get_field(1);
    std::string latitude_direction_string = sentence.get_field(2);
    if(!latitude_string.empty() && !latitude_direction_string.empty())
    {
        gga::latitude.set(nmea::parse::latitude(latitude_string, latitude_direction_string));
    }

    // Parse longitude.
    std::string longitude_string = sentence.get_field(3);
    std::string longitude_direction_string = sentence.get_field(4);
    if(!longitude_string.empty() && !longitude_direction_string.empty())
    {
        gga::longitude.set(nmea::parse::longitude(longitude_string, longitude_direction_string));
    }

    // Parse fix type.
    std::string fix_string = sentence.get_field(5);
    if(!fix_string.empty())
    {
        gga::fix.set(static_cast<gga::fix_type>(std::stoi(fix_string)));
    }

    // Parse satellite count.
    std::string satellite_count_string = sentence.get_field(6);
    if(!satellite_count_string.empty())
    {
        gga::satellite_count.set(std::stoul(satellite_count_string));
    }

    // Parse HDOP.
    std::string hdop_string = sentence.get_field(7);
    if(!hdop_string.empty())
    {
        gga::hdop.set(std::stof(hdop_string));
    }

    // Parse altitude.
    std::string altitude_string = sentence.get_field(8);
    if(!altitude_string.empty())
    {
        gga::altitude.set(std::stof(altitude_string));
    }

    // Parse geoid separation.
    std::string geoid_separation_string = sentence.get_field(10);
    if(!geoid_separation_string.empty())
    {
        gga::geoid_separation.set(std::stof(geoid_separation_string));
    }

    // Parse DGPS age.
    std::string dgps_age_string = sentence.get_field(12);
    if(!dgps_age_string.empty())
    {
        gga::dgps_age.set(std::stof(dgps_age_string));
    }

    // Parse DGPS station.
    std::string dgps_station_string = sentence.get_field(13);
    if(!dgps_station_string.empty())
    {
        gga::dgps_station.set(std::stoul(dgps_station_string));
    }
}