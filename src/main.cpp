#include <nmea/sentence.hpp>
#include <nmea/gga.hpp>
#include <nmea/gll.hpp>
#include <nmea/gsa.hpp>

#include <iostream>
#include <iomanip>

int32_t main(int32_t argc, char** argv)
{
    // // GGA
    // std::string nmea_string = "$GPGGA,172814.0,3723.46587704,N,12202.26957864,W,2,6,1.2,18.893,M,-25.669,M,2.0,0031*4F\r\n";
    // std::cout << nmea_string << std::endl;
    // nmea::sentence sentence(nmea_string);
    // nmea::gga gga(sentence);
    // std::cout << "UTC: " << std::fixed << std::setprecision(2) << gga.utc.get() << std::endl;
    // std::cout << "Latitude: " << std::fixed << std::setprecision(6) << gga.latitude.get() << std::endl;
    // std::cout << "Longitude: " << std::fixed << std::setprecision(6) << gga.longitude.get() << std::endl;
    // std::cout << "Fix Type: " << (uint32_t)gga.fix.get() << std::endl;
    // std::cout << "Satellite Count: " << (uint32_t)gga.satellite_count.get() << std::endl;
    // std::cout << "HDOP: " << gga.hdop.get() << std::endl;
    // std::cout << "Altitude: " << gga.altitude.get() << std::endl;
    // std::cout << "Geoid Separation: " << gga.geoid_separation.get() << std::endl;
    // std::cout << "DGPS Age: " << gga.dgps_age.get() << std::endl;
    // std::cout << "DGPS Station: " << gga.dgps_station.get() << std::endl;

    // // GLL
    // std::string nmea_string = "$GPGLL,3953.88008971,N,10506.75318910,W,034138.00,A,D*7A\r\n";
    // std::cout << nmea_string << std::endl;
    // nmea::sentence sentence(nmea_string);
    // nmea::gll gll(sentence);
    // std::cout << "Latitude: " << std::fixed << std::setprecision(6) << gll.latitude.get() << std::endl;
    // std::cout << "Longitude: " << std::fixed << std::setprecision(6) << gll.longitude.get() << std::endl;
    // std::cout << "UTC: " << std::fixed << std::setprecision(2) << gll.utc.get() << std::endl;
    // std::cout << "Status: " << (uint32_t)gll.status.get() << std::endl;
    // std::cout << "Mode: " << (uint32_t)gll.mode.get() << std::endl;

    // GSA
    std::string nmea_string = "$GNGSA,A,3,21,5,29,25,12,10,26,2,,,,,1.2,0.7,1.0*27\r\n";
    std::cout << nmea_string << std::endl;
    nmea::sentence sentence(nmea_string);
    nmea::gsa gsa(sentence);
    std::cout << "Mode: " << (uint32_t)gsa.mode.get() << std::endl;
    std::cout << "Fix: " << (uint32_t)gsa.fix.get() << std::endl;
    for(auto satellite = gsa.satellites.begin(); satellite != gsa.satellites.end(); ++satellite)
    {
        std::cout << "Satellite: " << (uint32_t)(*satellite) << std::endl;
    }
    std::cout << "PDOP: " << gsa.pdop.get() << std::endl;
    std::cout << "HDOP: " << gsa.hdop.get() << std::endl;
    std::cout << "VDOP: " << gsa.vdop.get() << std::endl;
    std::cout << "System: " << (uint32_t)gsa.system.get() << std::endl;
}