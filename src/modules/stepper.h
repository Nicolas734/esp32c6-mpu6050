#ifndef __STEPPER_H__
#define __STEPPER_H__ 1

#include <Arduino.h>

enum class MotionState : uint8_t { IDLE=0, WALK=1, RUN=2 };

struct StepParams {
  float thHigh = 0.25f;
  float thLow  = 0.10f;
  uint16_t refractoryMs = 300;
  float alphaGrav = 0.02f;
  float alphaSmooth = 0.2f;
  uint8_t hysteresisK = 3;
};

class StepDetector {
public:
    void setParams(const StepParams& params);
    void reset();
    bool update(float ax_g, float ay_g, float az_g, uint32_t unixtime);
    uint32_t steps();
    uint16_t cadenceSpm();
    MotionState state();
private:
    StepParams params;
    uint32_t stepCount = 0;
    MotionState state_ = MotionState::IDLE;
};

#endif