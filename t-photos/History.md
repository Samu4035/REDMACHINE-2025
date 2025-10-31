# History and Timeline of Red Machine

1. 2023 Season
- [Julio 2023](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Julio-2023)
- [Agosto 2023](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Agosto-2023)
- [Septiembre 2023](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Septiembre-2023)
- [Octubre 2023](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Octubre-2023)
2. 2024 Season
- [Febrero 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Febrero-2024)
- [Marzo 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Marzo-2024)
- [Abril 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Abril-2024)
- [Mayo 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Mayo-2024)
- [Junio 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Junio-2024)
- [Octubre 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Octubre-2024)
- [Noviembre 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Noviembre-2024)
3. 2025 Season
- [Febrero 2025](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Febrero-2025)
- [Marzo 2025](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Marzo-2025)
- [Abril 2025](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Abril-2025)
- [Mayo 2025](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Mayo-2025)
4. Julian, Luka and Pompo
- [JULIAN 1.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#JULIAN-1.0)
- [JULIAN 2.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#JULIAN-2.0)
- [JULIAN 3.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#JULIAN-3.0)
- [JULIAN 4.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#JULIAN-4.0)
- [JULIAN 5.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#JULIAN-5.0)
- [LUKA 1.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#LUKA-1.0)

- [LUKA 2.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md)

- [LUKA 3.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#LUKA-3.0)

- [POMPO 1.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#POMPO-1.0)

- [POMPO 2.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#POMPO-2.0)

- [POMPO 3.0](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#POMPO-3.0)

    
## 2023 Season

### July 2023

After participating in a regional robotics competition, the team decided to take part in the WRO, specifically in the Future Engineers category. As a first step, the team began studying and analyzing the competition rules.

![1ra julio](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/66f7c8f1-b10c-4261-86b3-32c87bcd3b81)

In the following days, the team began studying what could be the first version of the chassis and investigated various ways to address the initial challenges, which were how to design the steering system and which motor to use to achieve the required speed and torque.

![2da julio](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/3c73dc50-b3c4-4f2d-a4ad-92f87ee21a87)

Next, the team began searching for motors that could be used, disassembling toys, printers, and other devices, ultimately obtaining the necessary motor by dismantling a Nikko Dodge T-rex Ram remote-controlled car, which provided the mechanical parts needed to design the steering system.

![3rajulio](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/dbdfbd4e-9594-40f0-b34e-6d0528d7b328) 

![4julio](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/32158385-5185-4d74-b19a-fd5dca851590)

Subsequently, the team proceeded to assemble both systems, along with the various devices the robot would need, onto acrylic bases, completing the first prototype of what would become the chassis and allowing them to move forward with the programming phase.

![5julio](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/5d1d2414-1c38-4973-b7b8-8c7c55b3b648)

For programming, an Arduino Mega 2560 was used as the controller, a dual H-bridge as a power and speed regulator, and an ultrasonic sensor to measure distance. Subsequently, the team resumed searching for solutions to detect traffic light colors, deciding to use an ESP32-CAM with an OV2640 lens, with the next challenge being how to program it with Arduino.

![6julio](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/eb1e7891-75de-4a19-87ab-400c2de48bbc)

The team investigated which power source to use for the robot, since after using 9V batteries, they realized these were not ideal as they depleted very quickly. Consequently, two battery packs were connected, each containing eight 1.2V rechargeable cells in series, ultimately providing a total of 9.6V.

Due to space requirements, a second prototype was designed, adding a second level to the robot. The electronics were placed on the upper level, while the first level housed the batteries, the traction system, and the steering system.
![7julio](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/aa52095a-ea01-412f-901e-da4eb791124c)

Without being able to solve the programming yet, it was decided to use an RGB 34725 sensor so that the robot could detect which direction it should cross.

![8julio](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/e1047aac-374b-4cdb-8531-4b916cac0f36)

A strategy was proposed: it was decided to cross by detecting the color of the track lines, also using two additional ultrasonic sensors, one on each side of the robot, so that once it detected a wall, it could cross to avoid a collision. However, these two ultrasonic sensors ended up being more of a problem than a help, because when they detected something, the robot lost its trajectory. Consequently, it was ultimately decided not to use these two ultrasonic sensors.

![9julio](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/c96458f7-a354-4cbc-b139-bbab67d7a71c)

Before the competition, the team found rechargeable batteries with a higher voltage (3.7 V), so it was decided to remove one of the two battery packs and modify the remaining pack to operate with 3 batteries.

![10julio](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/cab0ff29-43a8-4808-9a1b-f93d4ca45027)

### August 2023

After participating in the first regional competition, the team began seeking solutions to the problems encountered. It was decided to change the steering system, creating a new one using parts from a Spike Prime robotics kit, number 45678, since this new steering system would allow a larger turning radius as well as more precise turns.

![1ago](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/2e470dc5-3636-41a1-9733-a62f20ae0db0)

New strategies were proposed, for which it was decided that the ideal way to cross would be with the help of ultrasonic sensors, and that the TCS34725 sensor would only detect the first line to determine whether the robot should cross clockwise or counterclockwise.

Continuing with the second part of the challenge, the team began programming the camera, looking for a way to transfer the camera’s information to the Arduino without using Wi-Fi. After researching several sources, they found a solution: transmitting the data through serial ports.

Then, the motor used during all this time began to fail frequently, preventing the team from progressing in the second challenge. A few days before the competition, the team extracted the motor—and consequently the gearbox—from another remote-controlled car to integrate it into the robot.

![2ago](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/6dbc1ef9-7d96-4ca5-839e-63c8bb6c3e24)

To provide a larger turning radius, the steering system was modified using pieces from a Lego Spike Prime kit.

![3ago](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/528c8a5c-2b6b-4996-9143-c09bb9472b1b)

### September 2023

Practice sessions were conducted on the track to improve the robot’s performance in challenges one and two, aiming for the best results in the 2023 national championship. The report was drafted and updated based on the progress achieved so far, followed by additional track practice to further enhance the robot’s performance in challenges one and two for the 2023 national championship.

![4ago](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/e132722b-7d13-4236-8e9b-7d837b6f065d) ![5 ago](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/eb82c5c2-2d85-4bf3-a0a5-0326dc07f3d5)

The time has come for the national competition, where the team successfully achieved the goal of qualifying for the 2023 WRO World Cup in Panama.

![sep2](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/41c23672-ecf9-4970-a691-882c736f0801)![sep1](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/454f09af-68c2-41fe-842e-51191bca02c3)
 

### October 2023

Work continued on programming the camera for Challenge 2. The wheels of the steering system were changed to improve safety and aesthetics, and the construction of the third prototype of the robot began, focusing on restoring the acrylic parts and organizing the cables through connectors to enhance the robot’s overall appearance.

![sep3](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/38c0d5d6-7739-47c4-ac14-718439dbf9c6)

The time for the World Cup arrives, where the team ranked among the top 25 in the world and within the top 2 among Latin American countries.

![oc1](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/d7f5104d-0fcb-45c1-b448-8e1b9b5449bd)![oct2](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/93173685-2fc5-4110-bf5e-b1adf484abe1)

## 2024 season

### February 2024

The first thing the team did to start this season was study the new rulebook, to identify the differences in the challenge and consider possible strategies for the new year.

![febrero 1](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/543ccce4-e258-4f4d-ab56-94f6a3207c77)

The team began designing the new robot, taking into account everything they had learned at the World Cup. During this design phase, aspects such as size, weight, which components would be used, their placement, and the distance between the traction and steering systems were considered.

![feb2](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/e518fc97-dbcd-4631-86c7-ceff1295411f)

The team continued planning which strategy to use. To avoid revealing the improvements and advancements planned for the new robot, they decided it would be best to compete with Julián (the 2023 robot) during the regional competitions and use the new robot (Luka) in the national competition, which would be the biggest challenge at the time.

![feb3](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/c918252f-6495-4227-b0c1-6020686d0f09)

### March 2024

During this month, the construction of the robot for the 2024 national competition began. In the first week of March, the acrylic bases were cut and the missing components for the robot were purchased.
First, the traction system and the steering system were installed on the robot. At this stage, the steering system was built using three acrylic pieces. Afterward, the Arduino and the Raspberry Pi were installed.

![feb4](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/23bb3e40-7f24-499d-9f17-81d077cd7c80)![feb5](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/bf47b801-3b39-4c64-8e48-dd82d7b7f9e9)

At the end of March, the construction of the robot was completed after installing all the sensors it would use. Additionally, programming for Challenge 1 was started, along with Python programming for Challenge 2.

![feb6](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/ba34c027-6287-45b2-a1b7-981fea57a367)

### April 2024

Since the team decided to participate with Julián in the regional competitions, work began on some improvements to the robot’s performance. One of these improvements was replacing the 34725 RGB sensor with the TCS3200 color sensor.

![feb7](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/48b506e4-a226-4501-9297-ab61940ddbd8)

In preparation for the upcoming regional competition, the report was updated according to the work completed so far. The most important updates included the timeline, the wiring diagram, and the specifications of the color sensor.

![feb8](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/e74d6b44-9a5a-4ff3-aa44-223e3d5b8257)

2024 Regional Competitions:

Colegio Santo Tomás de Aquino 05-04-2024
![feb9](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/0569d301-fa0c-444f-8521-f688f98e4dcd)

### May 2024
Liceo Los Robles 05-18-2024
![feb10](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/da1b210c-ddeb-4e1a-85d9-211e8c0ffc5c)


### June 2024

In preparation for the national competition, the team continued testing both challenges, focusing primarily on the second one; at the same time, they worked on Luka's report.
During the tests, it was decided to remove the color sensor, as it was not functioning optimally, and the side ultrasonic sensors began to be used to determine which path Luka should follow.

![jun1](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/4ec63c83-89a8-4a1b-ab29-952e07b1f754)

The team managed to fully complete the report and finished uploading all the information to GitHub by the end of the month, being fully prepared for the 2024 National WRO competition.

![JUN2](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/ec3a2df2-7dff-4fec-b924-b2d1eb7ead83) ![JUN3](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/cd6712cd-9323-48ea-98b8-636553662499)


### October 2024

After winning the national competition, the team managed to become part of the delegation representing Venezuela in the international finals of the Robotics Olympiad in Izmir, Turkey. This required extensive preparation and practice, so they began working on Luka.

During the first two weeks of preparation, the team started making structural changes to Luka to reduce the size of the robot. To achieve this, both the traction and steering systems were modified. The steering system was rotated 180 degrees so that the wheels were positioned more toward the front, and the traction motor was repositioned vertically to occupy less horizontal space. After this, approximately 5 cm of unused space at the rear of the robot was removed, completing this process with the robot measuring 18 cm in length.

![motor comparation](https://github.com/user-attachments/assets/00b11495-df00-430e-b246-063aeed43f5f)
![Traction comparation](https://github.com/user-attachments/assets/34566443-f982-43b6-9cad-7033e43392aa)


The third week of work marked the start of programming. After encountering issues with powering the Raspberry Pi, the team decided to look for a new method to detect traffic signals. After evaluating solutions, they chose to use a Pixy Cam because it took up less space, weighed less, and could be powered directly by the Arduino. The team also realized that a gyroscope would be necessary, especially for the second challenge, so they began using the HMS5883L magnetometer.

![pixy2 1](https://github.com/user-attachments/assets/0d5ba0ac-d5ba-47c5-957f-c5cc7350b439)
![HMC5883L](https://github.com/user-attachments/assets/fdfc00e6-27a0-4843-81a8-c86973bba489)


The Pixy Cam turned out to be an excellent choice, but the magnetometer was not, so the team started looking for a new one and chose the MPU6050. After extensive practice with the accelerometer, the team was able to use it on full curves, but due to its large margin of error, they could not rely on it to make the car turn exactly 90 degrees.

![prueba pixy](https://github.com/user-attachments/assets/ba0a2a27-5e38-4ecf-aacf-253b168c61ea)
![MPU6050](https://github.com/user-attachments/assets/14ad7f2f-d015-4d14-b35c-de9057ae6749)


Therefore, the team used the fourth week to design a new strategy. With this new strategy, the robot was calibrated with the outer walls. 

### November 2024

The first week of November was devoted entirely to preparation and practice. During this week, the robot managed to complete two consistent laps in the second challenge, but the team remained concerned about the gyroscope issue. 

![ramdom practice](https://github.com/user-attachments/assets/0c77eda4-712e-47df-84f0-b20429e7cd49)



Therefore, in the second week of November, the team began practicing with a new gyroscope, the BNO055. This sensor is a hybrid of a magnetometer and an accelerometer, which allows it to provide almost exact data. 

![BNO055](https://github.com/user-attachments/assets/9bccdb43-f634-4808-92c7-ae4d567bc054)

Finally, on the 28th, 29th, and 30th of this month, the team competed in the international finals in Turkey, achieving 19th place worldwide and second place in Latin America. 

"FOTO"

This competition left the team highly motivated for the upcoming national competitions, with the goal of qualifying and achieving the best results in the international final to be held in Singapore. 

![Image](https://github.com/user-attachments/assets/2f67bc4d-b872-4518-9a7e-bd1731d2f31f)

## 2025 season

### February 2025

As in previous years, Red Machine's first action at the start of a new season was to review the changes in the competition rules and scoring. The team carefully studied the new rules to ensure that everything they did was in accordance with them, and to develop and create the best robot possible. 

Under these rules, in the following weeks of this first month, work began on creating the first prototype of the new robot, “Pompo.”


### March 2025

This month, the team finished the first pompo prototype and began programming, using ROBOTC as the environment to program the ev3 module, which was the brain of this first pompo prototype. 
After long practice sessions, the team completed the first challenge perfectly, so it was time to move on to the second one. At this point, the team encountered a major problem: adapting the Pixycam to this EV3 module. 

### April 2025

After spending time looking for solutions to this problem, the team decided that it would be best to go back to working with Arduino, as the programming is very similar and the current problem could be solved much more quickly. 
Based on this, they worked for a long time to modify the entire robot chassis to adapt it to Arduino and the new sensors and motors that would be used, as those from EV3 are not directly compatible with Arduino.
Once construction was complete, the team returned to programming, but when they tested Pompo on the track, its chassis began to malfunction. 

### May 2025

For this reason, the team began working again on improving the chassis, finally achieving what would be the first definitive pompo chassis.
The scheduling of the first challenge was quick, so work on the second challenge began almost immediately. 

## Julian, luka and pompo

### JULIAN 1.0

![Primer Julian ](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/09cf93c9-366d-4cb8-a5c8-3ff131a1eefd)

### JULIAN 2.0

![segundo julian](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/e478974d-5332-49b8-afac-896d01656986)

### JULIAN 3.0

![Tercer Julian](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/cdd24993-e070-411b-bbf5-a24d7a4b233f)

### JULIAN 4.0

![Cuarto Julian](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/074197a0-749a-46c5-a047-525aad2b035c)

### JULIAN 5.0

![Quinto Julian ](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/0ce756c7-e496-4795-b2be-6cf495847561)

### LUKA 1.0

![Primer Luka](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/72f9fc19-2931-4442-80e8-b228e3491019)

### LUKA 2.0

![Segundo Luka ](https://github.com/RoboticaLLR/redmachine2024/assets/155327813/565f334d-1133-470b-ba16-1d1ea5e7b660)

### LUKA 3.0

![Luka`s right](https://github.com/user-attachments/assets/7adb4b68-6ba3-44b4-b7dc-02d3c609dd1a)


### POMPO 1.0

![Image](https://github.com/user-attachments/assets/02ba46a0-c65a-447c-a863-a571f83f3bbb)

### POMPO 2.0

![Image](https://github.com/user-attachments/assets/36442ffd-411f-4371-bcaa-29c3b6fd4452)


### POMPO 3.0

![Image](https://github.com/user-attachments/assets/40842456-c271-4c38-b15f-77bbeb7e6772)
