#ifndef GCUROBOT_H
#define GCUROBOT_H

#include <Servo.h>
class GCURobot {
  public:
    GCURobot();
    int connect();
    boolean isconnected(){return connected;};
	boolean OpenGripper();
	boolean CloseGripper();
	boolean SetJointAngle(int nJoint, double angle);
	double GetJointAngle(int nJoint);
	boolean GetGripperState() {return GripperState;};
	boolean go();

  private:
    boolean connected;
	boolean GripperState;
	double angles[2];
	Servo joint1;
	Servo joint2;
	Servo gripper;
};

#endif