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
    nmea::parse::set_utc(gga::utc, sentence, 0);

    // Parse latitude.
    nmea::parse::set_latitude(gga::latitude, sentence, 1);

    // Parse longitude.
    nmea::parse::set_longitude(gga::longitude, sentence, 3);

    // Parse fix type.
    nmea::parse::set_enum(gga::fix, sentence, 5);

    // Parse satellite count.
    nmea::parse::set_uint8(gga::satellite_count, sentence, 6);

    // Parse HDOP.
    nmea::parse::set_float(gga::hdop, sentence, 7);

    // Parse altitude.
    nmea::parse::set_float(gga::altitude, sentence, 8);

    // Parse geoid separation.
    nmea::parse::set_float(gga::geoid_separation, sentence, 10);

    // Parse DGPS age.
    nmea::parse::set_float(gga::dgps_age, sentence, 12);

    // Parse DGPS station.
    nmea::parse::set_uint16(gga::dgps_station, sentence, 13);
}