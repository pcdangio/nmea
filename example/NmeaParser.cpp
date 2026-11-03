#include <memory>

#include "NmeaParser.h"
#include "nmea/sentence.hpp"

NmeaParser& NmeaParser::singleton() {
    static NmeaParser instance;
    return instance;
}

std::optional<ParsedNmea> NmeaParser::parse(const std::vector<std::string>& nmea_list) {
    std::unique_ptr<nmea::rmc> rmc;
    std::unique_ptr<nmea::gga> gga;
    std::unique_ptr<nmea::gll> gll;
    std::unique_ptr<nmea::gst> gst;
    std::unique_ptr<nmea::vtg> vtg;

    std::vector<nmea::gsa> gsa_list;
    std::vector<nmea::gsv> gsv_list;

    for (auto& nmea_str : nmea_list) {
        auto nmea_sentence = nmea::sentence(nmea_str);

        if (nmea_sentence.type() == "RMC") {
            rmc = std::make_unique<nmea::rmc>(nmea_sentence);
        }

        if (nmea_sentence.type() == "GGA") {
            gga = std::make_unique<nmea::gga>(nmea_sentence);
        }

        if (nmea_sentence.type() == "GLL") {
            gll = std::make_unique<nmea::gll>(nmea_sentence);
        }

        if (nmea_sentence.type() == "GST") {
            gst = std::make_unique<nmea::gst>(nmea_sentence);
        }

        if (nmea_sentence.type() == "VTG") {
            vtg = std::make_unique<nmea::vtg>(nmea_sentence);
        }

        if (nmea_sentence.type() == "GSA") {
            gsa_list.emplace_back(nmea::gsa(nmea_sentence));
        }

        if (nmea_sentence.type() == "GSV") {
            gsv_list.emplace_back(nmea::gsv(nmea_sentence));
        }
    }

    if (rmc && gga && gll && gst && vtg && !gsa_list.empty() && !gsv_list.empty()) {

        auto ret = ParsedNmea{*rmc, *gga, *gll, *gst, *vtg, gsa_list, gsv_list};

        return ret;
    }

    return std::nullopt;
}
