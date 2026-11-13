#include <nmea/message/gst.hpp>

#include "parse.hpp"

using namespace nmea;

// CONSTRUCTORS
gst::gst(const nmea::sentence& sentence)
{
    // Get talker.
    gst::talker = sentence.talker();

    // Parse UTC.
    nmea::parse_utc(gst::utc, sentence, 0);

    // Parse RMS value of the standard deviation.
    nmea::parse_float(gst::rms, sentence, 1);

    // Parse Standard deviation of semi-major axis.
    nmea::parse_float(gst::smjr_std, sentence, 2);

    // Parse Standard deviation of semi-minor axis.
    nmea::parse_float(gst::smnr_std, sentence, 3);

    // Parse Orientation of semi-major axis.
    nmea::parse_float(gst::orient, sentence, 4);

    // Parse Standard deviation of latitude error.
    nmea::parse_float(gst::lat_std, sentence, 5);

    // Parse Standard deviation of longitude  error.
    nmea::parse_float(gst::lon_std, sentence, 6);

    // Parse Standard deviation of altitude  error.
    nmea::parse_float(gst::alt_std, sentence, 7);
}