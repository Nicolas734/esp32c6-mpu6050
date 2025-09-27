#ifndef __APP_PEDOMETER_H__
#define __APP_PEDOMETER_H__ 1

#include <Arduino.h>

struct AppParams {
    float thHigh = 0.25f;
    float thLow  = 0.10f;
    uint16_t refractoryMs = 300;
};

class AppConfig {
public:
    bool load();
    bool save();
    AppParams params;
};

#endif