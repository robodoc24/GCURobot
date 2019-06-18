 Class GCURobot
 Members:
    int connect();
		Connects the Robot to the Arduino Board, this function sets up the servo motors and defines their locations.
		Return:	true if successfully connected.
		
    boolean isconnected(){return connected;};
		Returns the current connection state.
		
	boolean OpenGripper();
		Opens the gripper hand of the robot.
		Return: Success of Opening the gripper
		
	boolean CloseGripper();
		Closes the gripper hand of the robot.
		Return: Success of closing the gripper
		
	boolean SetJointAngle(int nJoint, double angle);
		Sets a new joint angle, but does not move the robot. This will impact the results of GetJointAngle, but allows for complex joint motion.
		Inputs:		nJoint	-	Which joint to move, choices are 1 or 2
					angle	-	The angle to set the joint to in degrees, must be between 0 and 180
	
		Return:	Success of setting the joint angles, will return false on incorrect inputs
		
	double GetJointAngle(int nJoint);
		Gets the joint angle for a specified joint.
		Inputs:		nJoint	-	The joint which is being queried, choices are 1 and 2
		Return: The angle in degrees of the specified joint
		
	boolean GetGripperState() {return GripperState;};
		Get the current state (open or closed) of the gripper
		Return: true if the gripper is open or false if the gripper is closed
		
	boolean go();
		Move the robot to the currently set joint angles
		Return: Success of the movements