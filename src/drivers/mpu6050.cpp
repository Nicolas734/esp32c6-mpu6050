#include "mpu6050.h"

bool MPU6050Driver::begin(int sda, int scl){
    return true;
}

bool MPU6050Driver::isPresent(){
    return true;
}

void MPU6050Driver::readRawData(int16_t& ax, int16_t& ay, int16_t& az,
    int16_t& gx, int16_t& gy, int16_t& gz, int16_t& temp) {
    ax = ay = az = gx = gy = gz = temp = 0;
}

void MPU6050Driver::readAccelG(float& ax_g, float& ay_g, float& az_g){
    ax_g = ay_g = az_g = 0.0f;
}

void MPU6050Driver::readGyroDps(float& gx_dps, float& gy_dps, float& gz_dps) {
    gx_dps = gy_dps = gz_dps = 0.0f;
}

float MPU6050Driver::readTempC() { return 25.0f; }

void MPU6050Driver::calibrateAccel(size_t) {
    
}