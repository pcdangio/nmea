#include <nmea/gll.hpp>

#include "parse.hpp"

#include <sstream>
#include <iomanip>

using namespace nmea;

// CONSTRUCTORS
gll::gll(const nmea::sentence& sentence)
{
    // Get talker.
    gll::talker = sentence.talker();

    // Parse latitude.
    std::string latitude_string = sentence.get_field(0);
    std::string latitude_direction_string = sentence.get_field(1);
    if(!latitude_string.empty() && !latitude_direction_string.empty())
    {
        gll::latitude.set(nmea::parse::latitude(latitude_string, latitude_direction_string));
    }

    // Parse longitude.
    std::string longitude_string = sentence.get_field(2);
    std::string longitude_direction_string = sentence.get_field(3);
    if(!longitude_string.empty() && !longitude_direction_string.empty())
    {
        gll::longitude.set(nmea::parse::longitude(longitude_string, longitude_direction_string));
    }

    // Parse UTC time of day.
    std::string utc_string = sentence.get_field(4);
    if(!utc_string.empty())
    {
        gll::utc.set(nmea::parse::utc(utc_string));
    }

    // Parse status.
    std::string status_string = sentence.get_field(5);
    if(!status_string.empty())
    {
        if(status_string == "A")
        {
            gll::status.set(gll::status_type::DATA_VALID);
        }
        else if(status_string == "V")
        {
            gll::status.set(gll::status_type::DATA_INVALID);
        }
    }

    // Parse mode.
    std::string mode_string = sentence.get_field(6);
    if(!mode_string.empty())
    {
        if(mode_string == "A")
        {
            gll::mode.set(gll::mode_type::AUTONOMOUS);
        }
        else if(mode_string == "D")
        {
            gll::mode.set(gll::mode_type::DIFFERENTIAL);
        }
        else if(mode_string == "E")
        {
            gll::mode.set(gll::mode_type::ESTIMATED);
        }
        else if(mode_string == "M")
        {
            gll::mode.set(gll::mode_type::MANUAL);
        }
        else if(mode_string == "S")
        {
            gll::mode.set(gll::mode_type::SIMULATED);
        }
        else if(mode_string == "N")
        {
            gll::mode.set(gll::mode_type::INVALID);
        }
    }
}