#include "mpu6050.h"


//@todo: Ao calcular as amostras é necessario recupera-lás dos atributos da classe, exemplo: this->ax;
//@todo: Modificar a classe MPU6050Driver para que ao coletar as informações no método readRawData salva-los como atributos da classe


bool MPU6050Driver::begin(int sda, int scl){
    Wire.begin(sda, scl);
    delay(10);
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(this->REG_PWR_MGMT_1);
    Wire.write(0x0);
    if(Wire.endTransmission(true) != 0){
        return false;
    }
    return this->isPresent();
}

bool MPU6050Driver::isPresent(){
    Wire.beginTransmission(MPU_ADDR);
    return (Wire.endTransmission(true) == 0);
}

void MPU6050Driver::readRawData(int16_t& ax, int16_t& ay, int16_t& az,
    int16_t& gx, int16_t& gy, int16_t& gz, int16_t& temp) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(this->REG_ACCEL_XOUT_H);
    Wire.endTransmission(false); 
    Wire.requestFrom(MPU_ADDR, (uint8_t)14, true); 
    ax = (Wire.read() << 8) | Wire.read(); 
    ay = (Wire.read() << 8) | Wire.read(); 
    az = (Wire.read() << 8) | Wire.read(); 
    temp = (Wire.read() << 8) | Wire.read(); 
    gx = (Wire.read() << 8) | Wire.read(); 
    gy = (Wire.read() << 8) | Wire.read(); 
    gz = (Wire.read() << 8) | Wire.read(); 
}

void MPU6050Driver::readAccelG(float& ax_g, float& ay_g, float& az_g){
    int16_t ax, ay, az, gx, gy, gz, t;
    this->readRawData(ax, ay, az, gx, gy, gz, t);
    ax_g = ax / this->ACC_SCALE;
    ay_g = ay / this->ACC_SCALE;
    az_g = az / this->ACC_SCALE;
}

void MPU6050Driver::readGyroDps(float& gx_dps, float& gy_dps, float& gz_dps) {
    int16_t ax, ay, az, gx, gy, gz, t;
    this->readRawData(ax, ay, az, gx, gy, gz, t);
    gx_dps = gx / this->GYR_SCALE;
    gy_dps = gy / this->GYR_SCALE;
    gz_dps = gz / this->GYR_SCALE;
}

float MPU6050Driver::readTempC() { 
    int16_t ax, ay, az, gx, gy, gz, t;
    this->readRawData(ax, ay, az, gx, gy, gz, t);
    return (t / 340.0) + 36.53; 
}

void MPU6050Driver::calibrateAccel(size_t) {
    
}