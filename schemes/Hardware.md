# Index
- [Motors](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Analysis-of-Motor-Function)
- [Sensors](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Sensors)
- [Camera](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Camera)
- [Controller Boards](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Controller-Boards)
- [Robot Power Supply](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Robot-Power-Supply)
- [Connection Diagrams](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Connection-Diagrams-🔌)



# Analysis of Motor Function
The following section will display aspects of the function of the 2 motors of our robot.

## EV3 Motor 🤖
A large EV3 servo motor was used for the traction of "Pompo" (likely the robot's name or a part of it).

- Installation: Multiple Lego pieces were used to design a base on which this motor is supported, resulting in a precise height to ensure the wheels are at a desired height from the floor.
Furthermore, for its connection, the cable included in the Lego Mindstorms kit was modified: one end was left intact, and the other end was cut. The two power cables found inside were then taken out and connected to an H-bridge.

- Precision: It uses tachometric feedback (rotation sensor) with a precision of 1 degree, allowing for very exact control of position and movement.

- Speed: It can rotate at a speed of 160–170 revolutions per minute (RPM).
 
- Torque (Force Couple):
     Operating Torque: 20 N·cm (approximately 30 oz/in).
     Stall Torque: 40 N·cm (approximately 60 oz/in).




## Rev Robotics Servomotor

![Screenshot 2024-11-08 103745](https://github.com/user-attachments/assets/473534ce-37d2-4f08-9721-a207be8490b3)


- Installation: As with "Luka," the previous robot, to connect this servo to the front-wheel drive, a cut double aluminum servo arm was anchored to the Smart Robot Servo. Then, a screw was placed in one of the inputs of the aluminum arm, which connected it to two Lego pieces. A second screw joins the two aforementioned Lego pieces. Likewise, two chassis screws were anchored to the third Lego piece, so that it would function as a support. Finally, the wheels were placed, which fit between the three Lego pieces.

System Example:
 
 ![Screenshot 2024-11-08 103852](https://github.com/user-attachments/assets/43367d50-6ccf-498b-9c06-c9612c199d0e)


![foto sistema direccion 2](https://github.com/user-attachments/assets/d22ed9c8-2579-46ad-96a0-f00472432b56)


![foto sistema direccion  1](https://github.com/user-attachments/assets/fb4946ed-f055-4171-9542-48f1bef775e9)

The servo is held joined to the chassis in a fixed position with a set of Lego pieces.

- Operating Voltage: From 4.8V to 7.4V. In the robot, the servo operates at 5V.
  
- Rotation Range: It can rotate up to 270 degrees.

- Torque: 13.5 kg-cm

- Speed: 0.13s/60º

- Weight: 2.05 ounces

- Gear Material: Brass

- Power: The servo's power is specified below.

- Input Pulse:
   Minimum-500 μs
   Center-1500 μs
   Maximum-2500 μs

![Screenshot 2024-11-08 104017](https://github.com/user-attachments/assets/26bf1371-24b6-427f-be1d-9da5c48c0dc1)




# Sensors
The specifications for the sensors found in "Pompo" will be displayed below.

## Ultrasonic Sensors
Three ultrasonic sensors are used to define the distance between the robot and the track walls, specifically the lateral and frontal walls depending on the direction the robot is moving.

![Screenshot 2024-11-08 104130](https://github.com/user-attachments/assets/1e2dcd67-23b4-4e43-9aa0-8c34c85a97e9)

- Connection Pins:
   VCC
   Trig (ultrasound trigger)
   Echo (ultrasound reception)
   GND

![image](https://github.com/RoboticaLLR/redmachine2024/assets/146040533/9cfeae57-2def-47ad-9158-ded9577fc56a)


- Power Supply Voltage: 5 V

- Operating Frequency: 40 KHz

- Maximum Detection Range: 450cm

- Minimum Detection Range: 2cm

- Detection Angle: 15 degrees

- Current Consumption: 15mA



## Gyroscope
An MPU6050 is used to measure the degrees of each turn and to know when the robot should stop turning. The gyroscope is used both to avoid traffic signals and to execute turns, as well as to help the robot stay straight through a PID process.

![Image](https://github.com/user-attachments/assets/7824610c-7fcc-4221-9153-1aeb8aedeb60)

- Connection Pins:
Vin           
3V      
P50       
GND         
PS1          
SDA         
INT          
SCL  
ADR      
RST 

The team uses the Vin input to power the sensor, the GND pin, and the SDA and SCL pins to establish communication between the Arduino and the MPU6050.

Data Output (BNO055)
The BNO055 can output the following sensor data:

- Absolute Orientation (Euler Vector, 100 Hz): Three-axis orientation data based on a 360-degree sphere.

- Absolute Orientation (Quaternion, 100 Hz): Four-point quaternion output for more precise data manipulation.

- Angular Velocity Vector (100 Hz): Three axes of "rotation speed" in rad/s.

- Acceleration Vector (100 Hz): Three axes of acceleration (gravity + linear motion) in m/s^2.
  
- Magnetic Field Strength Vector (20 Hz): Three axes of magnetic field detection in micro Tesla (uT).

- Linear Acceleration Vector (100 Hz): Three axes of linear acceleration data (acceleration minus gravity) in m/s^2.

- Gravity Vector (100 Hz): Three axes of gravitational acceleration (minus any movement) in m/s^2.



 

# Camera
Pompo uses a camera to detect the color of traffic signals. This is the Pixy2.

![pixy2.1](https://github.com/user-attachments/assets/46298b4d-2184-4b40-9b81-577219ed9214)

The Pixy2 works at 60 fps, and is capable of detecting objects, lines, and colors. In Pompo, the main objective of the camera is to detect colors (red and green). It connects to the Arduino with an IDC 2 ICSP Arduino cable that goes into the ICSP pins of the Arduino, which provides all the necessary connections for power and communication with the Pixy.

# Controller Boards
Pompo uses a single controller board: an Arduino Mega 2560. The Arduino is in charge of controlling the actuators, sensors, and all movement of the robot.

## Arduino Mega 2560

![Screenshot 2024-11-08 104239](https://github.com/user-attachments/assets/877f86c1-f333-4b46-bc66-869465ee6ebf)
  

- Power Supply: 9V

- Pins Used: 21

- Maximum Current per Pin: 40 mA

- Flash Memory: 256 KB

- SRAM: 8 KB

- Weight: 37 grams

- Consumption: 93 mA



# Robot Power Supply 
Pompo uses three individual power supply systems.

## Motor Power Circuit 
This circuit uses three batteries, each containing approximately 4V. The three batteries are connected in series, so the voltage is summed. The H-bridge is the electrical component that receives this energy and uses it to power the ultrasonic sensors and the traction motor.
To connect the batteries, the team uses two battery packs of two batteries each, but one of them is modified to only use a single battery.

![2 packs de baterias 4V 4](https://github.com/user-attachments/assets/7a6248cc-fc05-4bf4-bfd4-aad78766bb06)


## Arduino Circuit 
This circuit uses two 9V batteries connected in parallel, which adds the amperage while maintaining the same 9V. It connects directly to the Arduino board, which powers the Pixy camera and the servomotor. Each of these components is powered by a 5V output pin from the Arduino.

![Primera foto 9 voltios 2](https://github.com/user-attachments/assets/79c1b298-762f-4a96-95a9-bb6aa8bb3e1f)

## Sensor Circuit 
This final circuit uses a third 9V battery connected to an H-bridge, through which the sensors (ultrasonic sensors and gyroscope) are powered.

# Connection Diagrams 🔌
To better understand Pompo's electrical circuits, the connection diagrams for our robot are presented below:

## Sensors diagram

<img width="1000" height="560" alt="Image" src="https://github.com/user-attachments/assets/5dff59cf-70bc-4497-ae3c-e04c4a344cda" />

## Motors diagram

<img width="1000" height="570" alt="Image" src="https://github.com/user-attachments/assets/3c6ce305-ddb9-4906-b1e0-248059342b02" />

