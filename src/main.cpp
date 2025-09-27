#include <Arduino.h>
#include <Wire.h> 
#include "drivers/mpu6050.h"
#include "modules/stepper.h"
#include "modules/bluetooth.h"
#include "modules/app.h"


MPU6050Driver mpu;

void setup() { 
  Serial.begin(115200);
  if (!mpu.begin(MPU_SDA, MPU_SCL)){
    Serial.println("Falha ao iniciar o MPU-6050.");
    while (true) { 
      delay(1000); 
    }
  }
  if(!mpu.isPresent()){
    Serial.println("MPU-6050 (0x68) não encontrado.");
    while (true) { 
      delay(1000); 
    }
  }
  Serial.println("MPU-6050 OK. Lendo a 50 Hz...");
} 


void loop() { 
  // Leitura 
  float ax, ay, az;
  float gx, gy, gz;
  float temp;

  mpu.readAccelG(ax, ay, az);
  mpu.readGyroDps(gx, gy, gz);
  temp = mpu.readTempC();

  Serial.print("Accel[g]: ");
  Serial.print(ax, 3); Serial.print(", ");
  Serial.print(ay, 3); Serial.print(", ");
  Serial.print(az, 3);

  Serial.print(" | Gyro[dps]: ");
  Serial.print(gx, 1); Serial.print(", ");
  Serial.print(gy, 1); Serial.print(", ");
  Serial.print(gz, 1);

  Serial.print(" | Temp[C]: ");
  Serial.println(temp, 2);

  delay(100); 
}