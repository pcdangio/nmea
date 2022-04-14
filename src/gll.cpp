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
    nmea::parse::set_latitude(gll::latitude, sentence, 0);

    // Parse longitude.
    nmea::parse::set_longitude(gll::longitude, sentence, 2);

    // Parse UTC time of day.
    nmea::parse::set_utc(gll::utc, sentence, 4);

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