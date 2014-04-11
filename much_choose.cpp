/* Pseudo code for buying a new smartphone
 * Opensource by Taoling Yang, version 1.0
 * NOTE: there are no classes supplied with this, please using imagination drivers v4.0
 * and up in order to compile.
 * 26/02/2014
 */
#include <imagination>
#include <basiclogicio>
#include <pseudocppinterpret.h>

typedef enum {
    MOTO_X = 0,
    GALAXY_NOTE_3,
    GALAXY_S_5,
    LG_G_2,
    BLACKBERRY_Z_30,
    //bleh
    IPHONE,
    phone_enum_t_SIZE
} phone_enum_t;
 
 
smartphone_t pick(person_t tao, events_t events)
{
    smartphone_t phone;
    phone.carrier = "fido";
    if (tao.osapEstimate(2014) < 500) {
        phone.name =  MOTO_X;
        phone.contract = true;
        return phone;
    }
    if (events.size == 0) {
        phone.name = GALAXY_NOTE_3;
        phone.carrier = "rogers";
        tao.argue = true;
        phone.contract = true;
        if (tao.osapEstimate(2014) >= 2500) {
            phone.contract = false;
        }
        return phone;
    }
    int points[phone_enum_t_SIZE];
    for (int i = 0; i < events.size(); i++) {
        switch (events[i].names()) {
            case PRICE_DROP: 
                points[events[i].happenedTo()] += events[i].value() / 10 + 1;
                break;
            case NEW_RELEASE:
                // whichever product line
                points[events[i].happenedTo()] += 5;
                break;
            case MOAR_ANDROID_SUPPORT:
                if (events[i].extra() == "added pebble support") {
                    points[BLACKBERRY_Z_30] += 100;
                } else {
                    points[BLACKBERRY_Z_30] += 10;
                }
                break;
            case CARRIER_HAS_GOOD_PLAN:
                if (events[i].extra() == "rogers") {
                    points[LG_G_2] += 10;
                    points[GALAXY_NOTE_3] += 10;
                    points[GALAXY_S_3] += 10;
                    points[IPHONE] += 10;
                    phone.carrier = "rogers";
                } else if (events[i].extra() == "fido") {
                    points[MOTO_X] += 20;
                    points[GALAXY_S_5] += 100;
                }
                break;
            case WIND_IMPROVES_NETWORK:
                if (events[i].extra() == "added lte") {
                    points[GALAXY_NOTE_3] += 50;
                } else if (events[i].extra() == "added lte and improved coverage to my house") {
                    points[GALAXY_NOTE_3] += 100;
                }
                break;
            case FIDO_CARRIES_NOTE_3:
                points[GALAXY_NOTE_3] += 100;
                phone.carrier = "fido";
                break;
            default:
                break;
        }
    }
    // find max defaults to moto x if no max, i.e. all 0.
    int num = findMax(points);
    phone.name = num;
    phone.contract = true;
    return phone;
}
