#ifndef __MPU_6050_H__
#define __MPU_6050_H__ 1

#include <Arduino.h>

class MPU6050Driver {
    public:
        bool begin(int sda, int scl);
        bool isPresent();
        void readRawData(int16_t& ax, int16_t& ay, int16_t& az,
            int16_t& gx, int16_t& gy, int16_t& gz, int16_t& temp);
        void readAccelG(float& ax_g, float& ay_g, float& az_g);
        void readGyroDps(float& gx_dps, float& gy_dps, float& gz_dps);
        float readTempC();
        void calibrateAccel(size_t n = 500);

    private:
        float _accelScale = 16384.0f; // ±2g
        float _gyroScale  = 131.0f;   // ±250 dps
};

#endif