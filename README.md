Line Follower Robot (LFR) is a simple autonomously guided robot that follows a line drawn on the ground to either detect a dark line on a white surface or a white line on a dark.
As stated earlier, line follower robot (LFR) follows a line, and in order to follow a line, robot must detect the line first. So, we are going to use this property of light to detect the line. To detect light, either LDR (light-dependent resistor) or an IR sensor can be used. For this project, we are going with the IR sensor because of its higher accuracy. To detect the line, we place two IR sensors two on the left and other two on the right side of the robot as marked in the diagram below.
Infrared sensors consist of two elements, a transmitter and a receiver. The transmitter is basically an IR LED, which produces the signal and the IR receiver is a photodiode, which senses the signal produced by the transmitter. The IR sensors emits the infrared light on an object, the light hitting the black part gets absorbed thus giving a low output but the light hitting the white part reflects back to the transmitter which is then detected by the infrared receiver, thereby giving an analog output. Using the stated principle, we control the movement of the robot by driving the wheels attached to the motors, the motors are controlled by a microcontroller.
LSRB Algorithm
This LSRB algorithm can be simplified into these simple conditions:
1.	If you can turn left then go ahead and turn left,
2.	else if you can continue driving straight then drive straight,
3.	else if you can turn right then turn right.
4.	If you are at a dead end then turn around.

The expunction of LSRB is shown below:
5.	L- Left
6.	R- Right
7.	S- Straight
8.	B- Turning around (Back).
The robot has to make these decisions when at an intersection. An intersection is any point on the maze where you have the opportunity to turn. If the robot comes across an opportunity to turn and does not turn then this is considered going straight. Each move was taken at an intersection or when turning around has to be stored.
 
