#include "Arduino.h"
#include "GCURobot.h"
#include <Servo.h>

GCURobot::GCURobot()
{
  connected = false;
  angles[0] = 0;
  angles[1] = 0;
}

int GCURobot::connect()
{
	joint1.attach(3);
	delay(100);
	joint2.attach(5);
	delay(100);
	gripper.attach(6);
	delay(100);
	connected = true;
}

boolean GCURobot::OpenGripper()
{
	if(!GripperState)
	{
		gripper.write(90);
		delay(45);
		GripperState = true;
	}
	
	return true;
}

boolean GCURobot::CloseGripper()
{
	if (GripperState)
	{
		gripper.write(0);
		delay(45);
		GripperState = false;
	}
	return true;
}

boolean GCURobot::SetJointAngle(int nJoint, double angle)
{
	if ((angle < 0) || (angle > 180))
		return false;
	
	switch (nJoint)
	{
	case 1:
		angles[0] = angle;
		break;
	case 2:
		angles[1] = angle;
		break;
	default:
		return false;
	}
	return true;
}

double GCURobot::GetJointAngle(int nJoint)
{
	switch (nJoint)
	{
	case 1:
		return angles[0];
	case 2:
		return angles[1];
	default:
		return -1;
	}
}

boolean GCURobot::go()
{
	if (!connected)
		return false;
	joint1.write(angles[0]);
	delay(45);
	joint2.write(angles[1]);
	delay(45);
	return true;
}