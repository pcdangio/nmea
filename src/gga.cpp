#include <nmea/gga.hpp>

#include <sstream>
#include <iomanip>

using namespace nmea;

// CONSTRUCTORS
gga::gga(nmea::sentence& sentence)
{
    // Get talker.
    gga::talker = sentence.talker();

    // Parse UTC time of day.
    std::string utc_string = sentence.get_field(0);
    if(!utc_string.empty())
    {
        // Calculate the UTC value.
        double utc = std::stod(utc_string.substr(0,2)) * 3600.0;
        utc += std::stod(utc_string.substr(2,2)) * 60.0;
        utc += std::stod(utc_string.substr(4));
        // Set the UTC value.
        gga::utc.set(utc);
    }

    // Parse latitude.
    std::string latitude_string = sentence.get_field(1);
    std::string latitude_direction_string = sentence.get_field(2);
    if(!latitude_string.empty() && !latitude_direction_string.empty())
    {
        // Get latitude number.
        double latitude = std::stod(latitude_string.substr(0,2));
        latitude += std::stod(latitude_string.substr(2)) / 60.0;
        // Get latitude direction.
        if(latitude_direction_string == "S")
        {
            latitude *= -1.0;
        }
        // Set latitude value.
        gga::latitude.set(latitude);
    }

    // Parse longitude.
    std::string longitude_string = sentence.get_field(3);
    std::string longitude_direction_string = sentence.get_field(4);
    if(!longitude_string.empty() && !longitude_direction_string.empty())
    {
        // Get longitude number.
        double longitude = std::stod(longitude_string.substr(0,3));
        longitude += std::stod(longitude_string.substr(3)) / 60.0;
        // Get longitude direction.
        if(longitude_direction_string == "W")
        {
            longitude *= -1.0;
        }
        // Set longitude value.
        gga::longitude.set(longitude);
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