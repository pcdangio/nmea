#include <nmea/sentence.hpp>
#include <nmea/message/gga.hpp>
#include <nmea/message/gll.hpp>
#include <nmea/message/gsa.hpp>
#include <nmea/message/gsv.hpp>
#include <nmea/message/rmc.hpp>
#include <nmea/message/vtg.hpp>
#include <nmea/message/zda.hpp>

#include <iostream>
#include <iomanip>

int32_t main(int32_t argc, char** argv)
{
    // GGA
    std::string gga_string = "$GPGGA,172814.0,3723.46587704,N,12202.26957864,W,2,6,1.2,18.893,M,-25.669,M,2.0,0031*4F\r\n";
    std::cout << gga_string << std::endl;
    nmea::sentence gga_sentence(gga_string);
    nmea::gga gga(gga_sentence);
    std::cout << "UTC: " << std::fixed << std::setprecision(2) << gga.utc.get() << std::endl;
    std::cout << "Latitude: " << std::fixed << std::setprecision(6) << gga.latitude.get() << std::endl;
    std::cout << "Longitude: " << std::fixed << std::setprecision(6) << gga.longitude.get() << std::endl;
    std::cout << "Fix Type: " << (uint32_t)gga.fix.get() << std::endl;
    std::cout << "Satellite Count: " << (uint32_t)gga.satellite_count.get() << std::endl;
    std::cout << "HDOP: " << gga.hdop.get() << std::endl;
    std::cout << "Altitude: " << gga.altitude.get() << std::endl;
    std::cout << "Geoid Separation: " << gga.geoid_separation.get() << std::endl;
    std::cout << "DGPS Age: " << gga.dgps_age.get() << std::endl;
    std::cout << "DGPS Station: " << gga.dgps_station.get() << std::endl;

    // GLL
    std::string gll_string = "$GPGLL,3953.88008971,N,10506.75318910,W,034138.00,A,D*7A\r\n";
    std::cout << gll_string << std::endl;
    nmea::sentence gll_sentence(gll_string);
    nmea::gll gll(gll_sentence);
    std::cout << "Latitude: " << std::fixed << std::setprecision(6) << gll.latitude.get() << std::endl;
    std::cout << "Longitude: " << std::fixed << std::setprecision(6) << gll.longitude.get() << std::endl;
    std::cout << "UTC: " << std::fixed << std::setprecision(2) << gll.utc.get() << std::endl;
    std::cout << "Status: " << (uint32_t)gll.status.get() << std::endl;
    std::cout << "Mode: " << (uint32_t)gll.mode.get() << std::endl;

    // GSA
    std::string gsa_string = "$GNGSA,A,3,21,5,29,25,12,10,26,2,,,,,1.2,0.7,1.0*27\r\n";
    std::cout << gsa_string << std::endl;
    nmea::sentence gsa_sentence(gsa_string);
    nmea::gsa gsa(gsa_sentence);
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

    // GSV
    std::string gsv_string = "$GPGSV,8,1,25,21,44,141,47,15,14,049,44,6,31,255,46,3,25,280,44*75\r\n";
    std::cout << gsv_string << std::endl;
    nmea::sentence gsv_sentence(gsv_string);
    nmea::gsv gsv(gsv_sentence);
    std::cout << "Message Count: " << (uint32_t)gsv.message_count.get() << std::endl;
    std::cout << "Message Number: " << (uint32_t)gsv.message_number.get() << std::endl;
    std::cout << "Satellite Count: " << (uint32_t)gsv.satellite_count.get() << std::endl;
    for(auto satellite = gsv.satellites.begin(); satellite != gsv.satellites.end(); ++satellite)
    {
        std::cout << "Satellite:" << std::endl;
        std::cout << "PRN: " << (uint32_t)satellite->prn.get() << std::endl;
        std::cout << "Elevation: " << (uint32_t)satellite->elevation.get() << std::endl;
        std::cout << "Azimuth: " << (uint32_t)satellite->azimuth.get() << std::endl;
        std::cout << "SNR: " << (uint32_t)satellite->snr.get() << std::endl;
    }

    // RMC
    std::string rmc_string = "$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A\r\n";
    std::cout << rmc_string << std::endl;
    nmea::sentence rmc_sentence(rmc_string);
    nmea::rmc rmc(rmc_sentence);
    std::cout << "UTC: " << std::fixed << std::setprecision(2) << rmc.utc.get() << std::endl;
    std::cout << "Status: " << (uint32_t)rmc.status.get() << std::endl;
    std::cout << "Latitude: " << std::fixed << std::setprecision(6) << rmc.latitude.get() << std::endl;
    std::cout << "Longitude: " << std::fixed << std::setprecision(6) << rmc.longitude.get() << std::endl;
    std::cout << "Speed: " << rmc.speed.get() << std::endl;
    std::cout << "Track Angle: " << rmc.track_angle.get() << std::endl;
    std::cout << "Date: " << (uint32_t)rmc.date.get().day << "/" << (uint32_t)rmc.date.get().month << "/" << (uint32_t)rmc.date.get().year << std::endl;
    std::cout << "Magnetic Variation: " << rmc.magnetic_variation.get() << std::endl;
    std::cout << "Mode: " << (uint32_t)rmc.mode.get() << std::endl;

    // VTG
    std::string vtg_string = "$GPVTG,140.88,T,,M,8.04,N,14.89,K,D*05\r\n";
    std::cout << vtg_string << std::endl;
    nmea::sentence vtg_sentence(vtg_string);
    nmea::vtg vtg(vtg_sentence);
    std::cout << "Track Angle True: " << vtg.track_angle_true.get() << std::endl;
    std::cout << "Track Angle Magnetic: " << vtg.track_angle_magnetic.get() << std::endl;
    std::cout << "Speed Knots: " << vtg.speed_knots.get() << std::endl;
    std::cout << "Speed KPH: " << vtg.speed_kph.get() << std::endl;
    std::cout << "Mode: " << (uint32_t)vtg.mode.get() << std::endl;

    // ZDA
    std::string zda_string = "$GPZDA,172809.456,12,07,1996,-11,23*7B\r\n";
    std::cout << zda_string << std::endl;
    nmea::sentence zda_sentence(zda_string);
    nmea::zda zda(zda_sentence);
    std::cout << "UTC: " << zda.utc.get() << std::endl;
    std::cout << "Day: " << (uint32_t)zda.day.get() << std::endl;
    std::cout << "Month: " << (uint32_t)zda.month.get() << std::endl;
    std::cout << "Year: " << (uint32_t)zda.year.get() << std::endl;
    std::cout << "GMT Hour: " << (int32_t)zda.gmt_offset_hours.get() << std::endl;
    std::cout << "GMT Minutes: " << (uint32_t)zda.gmt_offset_minutes.get() << std::endl;
}