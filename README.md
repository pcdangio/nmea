# nmea
A C++ library for reading and writing NMEA 0183 messages.

# Overview
This library provides tools for parsing and generating NMEA 0183 messages. It includes a base ```sentence``` class for getting/setting fields in a generic NMEA string. It also includes typical NMEA message structures (e.g. GGA, GLL, RMC, etc.) for parsing numerical fields from NMEA sentences. A ```field``` class is provided to handle optional fields that may or may not have data. Users may write their own NMEA message structures (e.g. for proprietary NMEA messages) similarly to how the provided messages are implemented. A doxyfile is provided to generate documentation for each class/struct.

# Usage

## Parsing
```cpp
#include <nmea/sentence.hpp>
#include <nmea/gga.hpp>
#include <iostream>

// Read an NMEA string from your serial port
std::string nmea_string = "$GPGGA,172814.0,3723.46587704,N,12202.26957864,W,2,6,1.2,18.893,M,-25.669,M,2.0,0031*4F\r\n";

// Parse the NMEA string into an NMEA sentence.
nmea::sentence nmea_sentence(nmea_string);

// Check if the NMEA message type is GGA.
if(nmea_sentence.type() == "GGA")
{
    // Parse GGA message from NMEA sentence.
    nmea::gga gga(nmea_sentence);

    // Print UTC time of day (seconds since 12:00AM UTC).
    std::cout << "UTC: " << std::fixed << std::setprecision(2) << gga.utc.get() << std::endl;

    // Check if latitude is provided in the message.
    if(gga.latitude.exists())
    {
        // Print latitude.
        std::cout << "Latitude: " << std::fixed << std::setprecision(6) << gga.latitude.get() << std::endl;
    }

    // Check if longitude is provided in the message.
    if(gga.longitude.exists())
    {
        // Print longitude.
        std::cout << "Longitude: " << std::fixed << std::setprecision(6) << gga.longitude.get() << std::endl;
    }
}
```

## Generating
```cpp
#include <nmea/sentence.hpp>

// Create NMEA sentence to populate.
// For this custom/proprietary message, the talker is XY and the type is CMD.
// The message has 3 fields.
nmea::sentence nmea_sentence("XY", "CMD", 3);

// Populate the first two fields using their field index.
// The third field is optional and left blank.
nmea_sentence.set_field(0, std::to_string(1.23));
nmea_sentence.set_field(1, "abc");

// Convert NMEA sentence to an NMEA string for sending over serial.
std::string nmea_string = nmea_sentence.nmea_string();

// Print NMEA string.
std::cout << nmea_string << std::endl;
```