#ifndef NMEA_PARSER_H
#define NMEA_PARSER_H

#include <string>
#include <optional>

#include "nmea/message/rmc.hpp"
#include "nmea/message/gga.hpp"
#include "nmea/message/gll.hpp"
#include "nmea/message/gsa.hpp"
#include "nmea/message/gsv.hpp"
#include "nmea/message/vtg.hpp"
#include "nmea/message/gst.hpp"

struct ParsedNmea {
    nmea::rmc rmc;
    nmea::gga gga;
    nmea::gll gll;
    nmea::gst gst;
    nmea::vtg vtg;

    std::vector<nmea::gsa> gsa_list;
    std::vector<nmea::gsv> gsv_list;

    ParsedNmea(
        const nmea::rmc& rmc_sentence,
        const nmea::gga& gga_sentence,
        const nmea::gll& gll_sentence,
        const nmea::gst& gst_sentence,
        const nmea::vtg& vtg_sentence,
        std::vector<nmea::gsa> gsa_sentence_list,
        std::vector<nmea::gsv> gsv_sentence_list
    ) :
        rmc{rmc_sentence},
        gga{gga_sentence},
        gll{gll_sentence},
        gst{gst_sentence},
        vtg{vtg_sentence},
        gsa_list{std::move(gsa_sentence_list)},
        gsv_list{std::move(gsv_sentence_list)} {
    }
};

class NmeaParser {
public:
    static NmeaParser& singleton();
    std::optional<ParsedNmea> parse(const std::vector<std::string>& nmea_list);

private:
    NmeaParser() = default;
};

static NmeaParser& NmeaParserSingleton = NmeaParser::singleton();

#endif //NMEA_PARSER_H
