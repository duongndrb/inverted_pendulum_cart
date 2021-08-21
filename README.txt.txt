1. Build a model system in Solidworks.
2. Setting with Simscape Multibody Link on Solidworks and afterwards export into Matlab.
3. Open Matlab with the folder that contain the file model Solidworks after convert, text smimport('.xml').
4. Wait for convert into Simulink.
5. Build the system simulation on the Simulink on matlab.
6. Run the matlab and see the results.

SIMULINK ON MATLAB to build the system of inverted pendulum cart
A, With the subsysem (plant)
 Add 1 - the Transform Sensor ( choose translation -> Distance) => connect primastic
	2,- add the simulink PS converter
	3,- flip the Primastic 
	4,- Primastic : sensing -> Position
	5.- Copy new the Transform Sensor => connect to the Revolute
		+, choose Rotation -> angle
		+, tick the Axis
	6,- build more Scope for display
	7,- build Display door
	8,- choose Gain
		+, the angle: 180/pi
		+, the K*u Matrix, with the value [0 0 -1]
	9,- add the product block to link two gain => angle theta
	10,- add the External force => connect F to cord_force
		+> choose force distance -> Force X to choose the direction of the force 
	11,- simulink S-PS convert
	12,-repeat 10 + 11 for the force to pendulum => cord_pendulum
	13,- choose all the blocks => subsystem
B, With the PID system
 Change the name of output and input
	input 1: force to cart
	input 2: force to pendulum
	output1: angle theta
	output2: distance
	output3: cart position sensor
 Add blocks:
	1, constant => 0
	2, sum => +-
	3, PID system , tune the PID or change the Kp, Ki, Kd
	4, setting, change auto-value to fixed-value when the sampling
		+, set fixed-value : 0.001
	5, build the full system with scope,....
	6,* buld the force builder with the force at 5s and add new PID system for cart position into cart
	7, change the PID value for suitable.
C, Run simulation