#include "parse.hpp"

// BASE
void nmea::parse::set_uint8(nmea::field<uint8_t>& field, const nmea::sentence& sentence, uint8_t field_index)
{
    // Get field string.
    std::string field_string = sentence.get_field(field_index);

    // Check if field exists.
    if(!field_string.empty())
    {
        // Set field with enum value.
        field.set(std::stoul(field_string));
    }
}
void nmea::parse::set_uint16(nmea::field<uint16_t>& field, const nmea::sentence& sentence, uint8_t field_index)
{
    // Get field string.
    std::string field_string = sentence.get_field(field_index);

    // Check if field exists.
    if(!field_string.empty())
    {
        // Set field with enum value.
        field.set(std::stoul(field_string));
    }
}
void nmea::parse::set_float(nmea::field<float>& field, const nmea::sentence& sentence, uint8_t field_index)
{
    // Get field string.
    std::string field_string = sentence.get_field(field_index);

    // Check if field exists.
    if(!field_string.empty())
    {
        // Set field with enum value.
        field.set(std::stof(field_string));
    }
}

// EXTENDED
void nmea::parse::set_utc(nmea::field<double>& field, const nmea::sentence& sentence, uint8_t field_index)
{
    // Get field string.
    std::string field_string = sentence.get_field(field_index);

    // Check that field exists.
    if(!field_string.empty())
    {
        // FORMAT: hhmmss.ss...

        // Parse hours.
        double utc = std::stod(field_string.substr(0,2)) * 3600.0;

        // Parse minutes.
        utc += std::stod(field_string.substr(2,2)) * 60.0;

        // Parse seconds.
        utc += std::stod(field_string.substr(4));

        // Set field.
        field.set(utc);
    }
}
void nmea::parse::set_latitude(nmea::field<double>& field, const nmea::sentence& sentence, uint8_t field_index)
{
    // Get field strings.
    std::string latitude_string = sentence.get_field(field_index);
    std::string direction_string = sentence.get_field(field_index + 1);

    // Check that both fields exist.
    if(!latitude_string.empty() && !direction_string.empty())
    {
        // FORMAT: ddmm.mm...

        // Parse degrees.
        double latitude = std::stod(latitude_string.substr(0,2));

        // Parse minutes and convert to decimal degrees.
        latitude += std::stod(latitude_string.substr(2)) / 60.0;

        // Get latitude direction.
        if(direction_string == "S")
        {
            latitude *= -1.0;
        }

        // Set field.
        field.set(latitude);
    }
}
void nmea::parse::set_longitude(nmea::field<double>& field, const nmea::sentence& sentence, uint8_t field_index)
{
    // Get field strings.
    std::string longitude_string = sentence.get_field(field_index);
    std::string direction_string = sentence.get_field(field_index + 1);

    // Check that both fields exist.
    if(!longitude_string.empty() && !direction_string.empty())
    {
        // FORMAT: dddmm.mm...

        // Parse degrees.
        double longitude = std::stod(longitude_string.substr(0,3));

        // Parse minutes and convert to decimal degrees.
        longitude += std::stod(longitude_string.substr(2)) / 60.0;

        // Get longitude direction.
        if(direction_string == "W")
        {
            longitude *= -1.0;
        }

        // Set field.
        field.set(longitude);
    }
}