/// \file nmea/gll.hpp
/// \brief Defines the nmea::gll struct.
#ifndef NMEA___GLL_H
#define NMEA___GLL_H

#include <nmea/sentence.hpp>
#include <nmea/field.hpp>

namespace nmea {

/// \brief An NMEA GLL sentence.
struct gll
{
    // OBJECTS
    /// \brief Enumerates data status types.
    enum class status_type
    {
        DATA_VALID = 0,     ///< Data is valid.
        DATA_INVALID = 1    ///< Data is invalid.
    };
    /// \brief Enumerates the FFA mode types.
    enum class mode_type
    {
        AUTONOMOUS = 0,     ///< Autonomous mode.
        DIFFERENTIAL = 1,   ///< Differential GPS (DGPS) mode.
        ESTIMATED = 2,      ///< Estimated dead-reckoning mode.
        MANUAL = 3,         ///< Manual input mode.
        SIMULATED = 4,      ///< Simulation mode.
        INVALID = 5         ///< Data is invalid.
    };

    // CONSTRUCTORS
    /// \brief Creates a new GLL instance from an NMEA sentence.
    /// \param sentence The NMEA sentence to parse the GLL sentence from.
    gll(const nmea::sentence& sentence);

    // FIELDS
    /// \brief The name of the sentence talker.
    std::string talker;
    /// \brief The latitude measurement in degrees (N = +, S = -).
    nmea::field<double> latitude;
    /// \brief The longitude measurement in degrees (E = +, W = -).
    nmea::field<double> longitude;
    /// \brief The UTC time of day, in seconds.
    nmea::field<double> utc;
    /// \brief The status of the fix data.
    nmea::field<status_type> status;
    /// \brief The mode of the receiver.
    nmea::field<mode_type> mode;
};

}

#endif