#ifndef __BLUETOOTH_BLE_H__
#define __BLUETOOTH_BLE_H__ 1

#include <Arduino.h>


class BLE {
public:
    bool begin(const char* ble_name);
    void notifySteps(uint32_t steep_count);
    void notifyCadence(uint16_t cadence_value);
    void notifyStatus(uint8_t motion_state);
};

#endif