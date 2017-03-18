#ifndef END_PUBLISHER_H
#define END_PUBLISHER_H

#include "ros/ros.h"
#include "encoder.h"
#include "kinematicCtrl.h"
#include "std_msgs/UInt16MultiArray.h"

uint16_t reverse_MotorPerformance(double Speed, double Torque);

void publishToWheels(double* steerVal, double* driveVal, double* Torque);

void publishToUser();

#endif
