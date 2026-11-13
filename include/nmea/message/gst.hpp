/// \file nmea/message/gst.hpp
/// \brief Defines the nmea::gst struct.
#ifndef NMEA___GST_H
#define NMEA___GST_H

#include <nmea/sentence.hpp>
#include <nmea/field.hpp>

namespace nmea {

/// \brief An NMEA GST sentence.
struct gst
{
    // CONSTRUCTORS
    /// \brief Creates a new GST instance from an NMEA sentence.
    /// \param sentence The NMEA sentence to parse the GST sentence from.
    gst(const nmea::sentence& sentence);

    // FIELDS
    /// \brief The name of the sentence talker.
    std::string talker;
    /// \brief The UTC time of day, in seconds.
    nmea::field<double> utc;
    /// \brief RMS value of the standard deviation of the range inputs to the navigation process
    nmea::field<float> rms;
    /// \brief Standard deviation of semi-major axis of error ellipse (m)
    nmea::field<float> smjr_std;
    /// \brief Standard deviation of semi-minor axis of error ellipse (m)
    nmea::field<float> smnr_std;
    /// \brief Orientation of semi-major axis of error ellipse (degrees from true north)
    nmea::field<float> orient;
    /// \brief Standard deviation of latitude error (m)
    nmea::field<float> lat_std;
    /// \brief Standard deviation of longitude error (m)
    nmea::field<float> lon_std;
    /// \brief Standard deviation of altitude error (m)
    nmea::field<float> alt_std;
};

}

#endif