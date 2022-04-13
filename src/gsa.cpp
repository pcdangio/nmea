#include <nmea/gsa.hpp>

using namespace nmea;

// CONSTRUCTORS
gsa::gsa(const nmea::sentence& sentence)
{
    // Get talker.
    gsa::talker = sentence.talker();

    // Parse mode.
    std::string mode_string = sentence.get_field(0);
    if(!mode_string.empty())
    {
        if(mode_string == "M")
        {
            gsa::mode.set(gsa::mode_type::MANUAL);
        }
        else if(mode_string == "A")
        {
            gsa::mode.set(gsa::mode_type::AUTOMATIC);
        }
    }

    // Parse fix type.
    std::string fix_string = sentence.get_field(1);
    if(!fix_string.empty())
    {
        gsa::fix.set(static_cast<gsa::fix_type>(std::stoi(fix_string)));
    }

    // Parse satellite IDs.
    gsa::satellites.reserve(12);
    for(uint8_t i = 0; i < 12; ++i)
    {
        // Get current satellite field.
        std::string satellite_string = sentence.get_field(2 + i);
        if(!satellite_string.empty())
        {
            gsa::satellites.push_back(std::stoul(satellite_string));
        }
        else
        {
            break;
        }
    }

    // Parse PDOP.
    std::string pdop_string = sentence.get_field(14);
    if(!pdop_string.empty())
    {
        gsa::pdop.set(std::stof(pdop_string));
    }

    // Parse HDOP.
    std::string hdop_string = sentence.get_field(15);
    if(!hdop_string.empty())
    {
        gsa::hdop.set(std::stof(hdop_string));
    }

    // Parse VDOP.
    std::string vdop_string = sentence.get_field(16);
    if(!vdop_string.empty())
    {
        gsa::vdop.set(std::stof(vdop_string));
    }

    // Parse system type.
    std::string system_string = sentence.get_field(17);
    if(!system_string.empty())
    {
        gsa::system.set(static_cast<gsa::system_type>(std::stoi(system_string)));
    }
}