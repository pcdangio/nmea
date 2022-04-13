/// \file parse.hpp
/// \brief Defines common NMEA parsing functions.
#ifndef NMEA___PARSE_H
#define NMEA___PARSE_H

#include <string>

namespace nmea {

/// \brief Contains all code for parsing common NMEA field strings.
namespace parse {

/// \brief Parses the UTC time of day from an NMEA UTC field.
/// \param utc_string The UTC field as a string.
/// \returns The UTC as a decimal, in seconds.
double utc(const std::string& utc_string);
/// \brief Parses the latitude from NMEA latitude/direction fields.
/// \param latitude_string The latitude field as a string.
/// \param direction_string The latitude direction field as a string.
/// \returns The latitude as a decimal, in degrees (N = +, S = -).
double latitude(const std::string& latitude_string, const std::string& direction_string);
/// \brief Parses the longitude from NMEA longitude/direction fields.
/// \param longitude_string The longitude field as a string.
/// \param direction_string The longitude direction field as a string.
/// \returns The longitude as a decimal, in degrees (E = +, W = -).
double longitude(const std::string& longitude_string, const std::string& direction_string);

}}

#endif