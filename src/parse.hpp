/// \file parse.hpp
/// \brief Defines common NMEA parsing functions.
#ifndef NMEA___PARSE_H
#define NMEA___PARSE_H

#include <nmea/field.hpp>
#include <nmea/sentence.hpp>

#include <string>

namespace nmea {

/// \brief Contains all code for parsing common NMEA field strings.
namespace parse {

// BASE
/// \brief Parses a UINT8 field from an NMEA sentence.
/// \param field The NMEA field to parse the value into.
/// \param sentence The NMEA sentence to read the value from.
/// \param field_index The index of the field in the NMEA sentence.
void set_uint8(nmea::field<uint8_t>& field, const nmea::sentence& sentence, uint8_t field_index);
/// \brief Parses a UINT16 field from an NMEA sentence.
/// \param field The NMEA field to parse the value into.
/// \param sentence The NMEA sentence to read the value from.
/// \param field_index The index of the field in the NMEA sentence.
void set_uint16(nmea::field<uint16_t>& field, const nmea::sentence& sentence, uint8_t field_index);
/// \brief Parses a float field from an NMEA sentence.
/// \param field The NMEA field to parse the value into.
/// \param sentence The NMEA sentence to read the value from.
/// \param field_index The index of the field in the NMEA sentence.
void set_float(nmea::field<float>& field, const nmea::sentence& sentence, uint8_t field_index);
/// \brief Parses an enumeration field from an NMEA sentence.
/// \tparam enum_type The object type of the enumeration to parse.
/// \param field The NMEA field to parse the value into.
/// \param sentence The NMEA sentence to read the value from.
/// \param field_index The index of the field in the NMEA sentence.
template <class enum_type>
void set_enum(nmea::field<enum_type>& field, const nmea::sentence& sentence, uint8_t field_index)
{
    // Get field string.
    std::string field_string = sentence.get_field(field_index);

    // Check if field exists.
    if(!field_string.empty())
    {
        // Set field with enum value.
        field.set(static_cast<enum_type>(std::stoi(field_string)));
    }
}

// EXTENDED
/// \brief Parses UTC time of day from an NMEA sentence.
/// \param field The NMEA field to parse the value into.
/// \param sentence The NMEA sentence to read the value from.
/// \param field_index The index of the field in the NMEA sentence.
void set_utc(nmea::field<double>& field, const nmea::sentence& sentence, uint8_t field_index);
/// \brief Parses latitude from an NMEA sentence.
/// \param field The NMEA field to parse the value into.
/// \param sentence The NMEA sentence to read the value from.
/// \param field_index The index of the field in the NMEA sentence.
void set_latitude(nmea::field<double>& field, const nmea::sentence& sentence, uint8_t field_index);
/// \brief Parses longitude from an NMEA sentence.
/// \param field The NMEA field to parse the value into.
/// \param sentence The NMEA sentence to read the value from.
/// \param field_index The index of the field in the NMEA sentence.
void set_longitude(nmea::field<double>& field, const nmea::sentence& sentence, uint8_t field_index);

}}

#endif