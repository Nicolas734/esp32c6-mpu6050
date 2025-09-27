#ifndef __MPU_6050_H__
#define __MPU_6050_H__ 1

#include <Arduino.h>
#include <Wire.h> 

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
        static constexpr uint8_t REG_PWR_MGMT_1 = 0x6B;
        static constexpr uint8_t REG_ACCEL_XOUT_H = 0x3B;
        static constexpr float ACC_SCALE = 16384.0f; // LSB/g
        static constexpr float GYR_SCALE = 131.0f;   // LSB/(°/s)
};

#endif