#include <Arduino.h>
#include <Wire.h> 
#include "drivers/mpu6050.h"
#include "modules/stepper.h"
#include "modules/bluetooth.h"
#include "modules/app.h"


#define MPU_ADDR 0x68 
#define MPU_SDA 6 
#define MPU_SCL 7 

bool check_mpu() { 
  bool found68 = false; 
  for (int addr = 1; addr < 127; addr++) { 
    Wire.beginTransmission(addr); 
    if (Wire.endTransmission() == 0) { 
      if (addr == MPU_ADDR) found68 = true; 
    } 
  } 
  return found68;
}

void setup() { 
  Serial.begin(115200); 
  Wire.begin(MPU_SDA, MPU_SCL); 
  if (!check_mpu()) { 
    Serial.println("MPU6050 (0x68) não encontrado"); 
    while (1) delay(1000); 
  } 
  Wire.beginTransmission(MPU_ADDR); 
  Wire.write(0x6B); 
  Wire.write(0x00); 
  Wire.endTransmission(true); 
} 

void read_mpu_raw_data( int16_t& ax, int16_t& ay, int16_t& az, int16_t& gx, int16_t& gy, int16_t& gz, int16_t& t) { 
  Wire.beginTransmission(MPU_ADDR); 
  Wire.write(0x3B); 
  Wire.endTransmission(false); 
  Wire.requestFrom(MPU_ADDR, (uint8_t)14, true); 
  ax = (Wire.read() << 8) | Wire.read(); 
  ay = (Wire.read() << 8) | Wire.read(); 
  az = (Wire.read() << 8) | Wire.read(); 
  t = (Wire.read() << 8) | Wire.read(); 
  gx = (Wire.read() << 8) | Wire.read(); 
  gy = (Wire.read() << 8) | Wire.read(); 
  gz = (Wire.read() << 8) | Wire.read(); 
} 

void loop() { 
  // Leitura 
  int16_t axRaw, ayRaw, azRaw, gxRaw, gyRaw, gzRaw, tRaw; 
  read_mpu_raw_data(axRaw, ayRaw, azRaw, gxRaw, gyRaw, gzRaw, tRaw); 
  float tempC = (tRaw / 340.0) + 36.53; 
  Serial.print("Accel: "); 
  Serial.print("X="); 
  Serial.print(axRaw); 
  Serial.print(" Y="); 
  Serial.print(ayRaw); 
  Serial.print(" Z="); 
  Serial.print(azRaw); 
  Serial.print(" | Gyro: "); 
  Serial.print("X="); 
  Serial.print(gxRaw);
  Serial.print(" Y="); 
  Serial.print(gyRaw); 
  Serial.print(" Z="); 
  Serial.print(gzRaw); 
  Serial.print(" | Temp: "); 
  Serial.print(tempC, 2); 
  Serial.println(" °C"); 
  delay(100); 
}