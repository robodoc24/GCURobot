#include "Arduino.h"
#include "GCURobot.h"
#include <Servo.h>

GCURobot::GCURobot()
{
  connected = false;
  angles[0] = 45;
  angles[1] = 45;
}

int GCURobot::connect()
{
	joint1.attach(3);
	joint1.write(45);
	joint2.attach(5);
	joint2.write(45);
	gripper.attach(6);
	gripper.write(85);
	go();
	connected = true;
}

boolean GCURobot::OpenGripper()
{
	if(!GripperState)
	{
		gripper.write(0);
		delay(45);
		GripperState = true;
	}
	
	return true;
}

boolean GCURobot::CloseGripper()
{
	if (GripperState)
	{
		gripper.write(80);
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