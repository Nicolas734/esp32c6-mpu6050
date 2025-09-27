#include "stepper.h"

void StepDetector::setParams(const StepParams& params){
    this->params = params;
}

void StepDetector::reset(){
    this->stepCount = 0;
    this->state_ = MotionState::IDLE;
}

bool StepDetector::update(float ax_g, float ay_g, float az_g, uint32_t unixtime){
    return false;
}

uint32_t StepDetector::steps(){
    return this->stepCount;
}

uint16_t StepDetector::cadenceSpm(){
    return 0;
}

MotionState StepDetector::state(){
    return this->state_;
}