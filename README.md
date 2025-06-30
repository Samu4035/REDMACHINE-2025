# Documento de ingeniería / Red Machine 

Este repositorio contiene todos los materiales necesarios para crear a "pompo", el robot autonomo creado por el equipo "Red Machine", con el objetivo de participar en la categoría de Futuros Ingenieros en las diferentes etapas de la WRO Venezuela, en su edición 2025. 

![Image](https://github.com/user-attachments/assets/86d8b3ba-9f00-4d94-9a0b-7fb3f87d222e)


# Índice

 -  [Miembros del equipo Red Machine](https://github.com/Samu4035/REDMACHINE-2025/blob/main/README.md#Miembros-de-Red-Machine)
 -  [Introduccion](https://github.com/Samu4035/REDMACHINE-2025/blob/main/README.md#Introducción)
 -  [Diseño mecánico](https://github.com/Samu4035/REDMACHINE-2025/blob/main/README.md#Diseño-mecánico)
 -  [Diseño del software](https://github.com/Samu4035/REDMACHINE-2025/blob/main/README.md#Diseño-del-software)
 -  [Videos del funcionamiento de pompo](https://github.com/Samu4035/REDMACHINE-2025/blob/main/README.md#Videos-del-funcionamiento-de-pompo)
 -  [Historia y cronología](https://github.com/Samu4035/REDMACHINE-2025/blob/main/README.md#Historia-y-cronología)

# Contenido del repositorio

Este repositorio contiene los siguientes directorios para organizar nuestro proyecto:

* `t-photos`: Incluye fotos del equipo, además de fotos del trabajo realizado durante todos los años de competencia y fotos de los robots construidos por el equipo
* `v-photos`: Contiene 6 fotos del vehículo (desde todos los ángulos).
* `video`: Archivo `video.md` con el enlace a los videos de rendimiento del robot.
* `schemes`: Diagramas esquemáticos (JPEG, PNG o PDF) de los componentes electromecánicos, ilustrando la conexión de elementos electrónicos y motores, además de la explicación del funcionamiento de cada uno de estos.
* `src`: Código del software de control para todos los componentes programados para la competición.
* `models`: Archivos para el diseño 3D del vehículo.
* `other`: Archivos adicionales para entender cómo preparar el vehículo para la competición.
     
# Introducción
El equipo ha hecho su mayor esfuerzo para conseguir construir el mejor robot posible. Nuestra preparación para estas olimpiadas se ha basado en un largo aprendizaje en construcción, diseño y programación, y la experiencia de competencias anteriores ha sido fundamental. Largas horas de análisis y estudio de la pista ha llevado a la creación de una estrategia propia, basada en los componentes con los que el equipo deseó trabajar, y esperando conseguir la mejor participación posible en las diversas etapas de esta competencia. 
A lo largo de este documento y de todo el repositorio se explica con precisión todo el trabajo de diseño, programación y construcción del robot. 

# Miembros de Red Machine
-Samuel Jose Galban Franco

-Juan Diego Cano Barros

-Angel Saul Rodriguez Guerra

![red machine 2024](https://github.com/RoboticaLLR/redmachine2024/assets/146040533/d5bb5fc0-b1bd-47a8-9ac3-c190587ae5ae)

# Fotos del robot (todos los ángulos)

| ![Image](https://github.com/user-attachments/assets/eec7817b-bb41-493e-9b78-a5a6004a4a2e)  |  ![Izquierda](https://github.com/user-attachments/assets/4f20ba4c-f271-4861-a9cf-31022f7be0d2)  |  ![Frontal](https://github.com/user-attachments/assets/4b648131-29e0-4cb0-a01b-d3b699d62968) |
| :----: | :-------------------: | :----------: |
| ![Debajo](https://github.com/user-attachments/assets/45f55e40-cd16-4492-b856-0ac1671db0f4)  |  ![Derecha](https://github.com/user-attachments/assets/15a16250-3cc5-4dcb-8e0c-482e2bc499f7)  |  ![Atras](https://github.com/user-attachments/assets/f761cfdf-7320-499f-b884-d6290f5e50bb) |

# Diseño mecánico
"Pompo" es un robot autónomo diseñado con piezas de lego, con la finalidad de conseguir la mayor presición y estabilidad posible durante las rondas de competencia. Dichas piezas fueron extraídas de un kit lego spike prime código 45678 y spike prime expansion set código 45681. 
El fundamento que llevó a utilizar piezas de lego para el cuerpo de pompo se basa en la conocida eficiencia de los robots construidos de dicha manera, tomando en cuenta los resultados positivos y la facilidad que permiten a la hora de la construcción. 
Además, en el apartado "v-photos" se muestran fotos del diseño de Pompo, donde se pueden ver y analizar eficientemente todos los componentes, piezas y estructuras.
A continuación el diseño 3D de las diversas bases de lego que se usan en la estructura (en el apartado "models" se ve el archivo original del diseño): 

![Image](https://github.com/user-attachments/assets/5b7af0b6-441f-4880-8d1f-e71637f6b006)

![Image](https://github.com/user-attachments/assets/a4c70eec-a4b5-4d26-86e3-5d2190d3b326)

![Image](https://github.com/user-attachments/assets/dd3a7d52-695a-4912-9071-1e9b083b1505)


| Imagen | Nombre de Componente | Descripción |
| :----: | :------------------- | :---------- |
| ![servo pequeño](https://github.com/RoboticaLLR/RedMachine/assets/146040533/57aaa91d-b5e5-4360-aef2-06025d15f8b0) | **Servo motor de Rev Robotics** | Es un motor eléctrico con sensor de retroalimentación de posición integrado, que permite realizar movimientos angulares perfectos, utilizando una señal que va de 0V a 5V, donde cada valor que pueda tener el voltaje representa un ángulo exacto, cumpliendo con excelencia la función de realizar los giros. |
| ![Image](https://github.com/user-attachments/assets/05c10969-e9a6-404b-a141-5e44218d54df) | **Motor lego ev3** | Dispositivo que convierte la energía eléctrica en movimiento mecánico, permitiendo en este caso mover una caja de cambios y movilizar las ruedas. La velocidad y el par que tiene vienen determinados por la tensión enviada a través del puente en H, siendo moderados por el Arduino. |


## Componentes electrónicos 
A pesar de que la construcción del robot fue hecha con piezas de lego, para todo el apartado electrónico el equipo se decidió por utilizar piezas externas con las que ya se han familiarizado. Entre estas se encuentran los siguientes sensores y actuadores:


Arduino Mega 2560: Es una placa microcontroladora basada en el ATmega2560. Tiene 54 pines de entrada/salida digital y 16 entradas analógicas, un oscilador de cristal de 16 MHz, una conexión USB, una toma de alimentación, una cabecera ICSP y un botón reset. El arduino es la placa que contiene el código para el funcionamiento de pompo, encargándose de analizar toda la información obtenida por los sensores para así lograr cumplir con el reto. 

![mega 2560](https://github.com/user-attachments/assets/edc71e77-3581-48eb-af96-6dfae65660ac)


Puente-H: Es un tipo de controlador que permite cambiar la polaridad de un motor de corriente continua, hacia delante y hacia atrás, además de ser la fuente de energía de diversos sensores. El modelo de puente H utilizado es el L298N, que nos permite cambiar la velocidad de los motores en función de la tensión enviada por el Arduino.

![puente H pequeño](https://github.com/RoboticaLLR/RedMachine/assets/146040533/264757f2-118f-42c9-9dd8-2a3c91455834)

Sensor de ultrasonido: Es un sensor que utiliza sonidos ultrasónicos para detectar el tiempo de rebote del sonido de un lado a otro. Utilizando el Arduino Mega 2560 se determina la distancia en base al tiempo que tarda la onda en volver, teniendo así este sensor la función de determinar cuando hay una pared cerca para así realizar el giro correspondiente.
El modelo utilizado de este sensor es el HC-sr04.

![HC-sr04](https://github.com/user-attachments/assets/a59b0102-8994-4ac4-aa06-3d6553ae1a2d)

Giroscopio: Es un sensor que mide la orientación del robot en grados. Se utiliza para poder realizar giros precisos, principalmente con la función de los giros para cambio de sección (giros de 90°), y mantener el robot con un movimiento en línea recta. 
El modelo utilizado de este sensor es 

![BNO055](https://github.com/user-attachments/assets/02c487ce-d624-411f-9db3-a2a3ef82a514)

Pixy 2.1: Es una cámara que tiene guardados valores que corresponden a los colores rgb de las señales de tráfico. Para detectar, la cámara busca esos valores en los píxeles de la imagen y, cuando se detecta un número exacto de pixeles de alguno de los colores anexados, pixy envía los datos al arduino, el cual se encarga luego de realizar los movimientos precisos para evitar los semáforos. 

![pixy2 1 2](https://github.com/user-attachments/assets/6397d5c9-d6fe-4c80-a7b9-d097bee0ba3e)


Raspberry pi 5: Es la última versión de las computadoras de placa única desarrolladas por la Fundación Raspberry Pi, lanzada en 2023. Esta versión incluye un procesador Broadcom BCM2712 de cuatro núcleos Arm Cortex-A76 a 2,4 GHz, lo que la hace entre dos y tres veces más rápida que la generación anterior. Viene en versiones de 4 GB y 8 GB de memoria RAM LPDDR4X, incorpora una GPU mejorada compatible con OpenGL ES 3.1 y Vulkan 1.2, y permite conectar dos monitores 4K a 60 Hz al mismo tiempo. Además, ofrece conectividad avanzada con Wi-Fi 5, Bluetooth 5.0, Ethernet Gigabit, dos puertos USB 3.0, dos USB 2.0, dos micro HDMI, ranura microSD de alta velocidad, conectores MIPI para cámaras y pantallas, y un puerto PCIe para discos SSD u otros periféricos rápidos (usando un adaptador). También cuenta con un botón de encendido, reloj en tiempo real, soporte para ventilador y mejoras en la gestión de energía. Gracias a estas características, la Raspberry Pi 5 es ideal tanto para proyectos de electrónica y robótica como para usarse como mini PC, servidor, centro multimedia o incluso para tareas más exigentes como inteligencia artificial y procesamiento de imágenes, representando un gran avance en potencia y versatilidad dentro del mundo de las computadoras compactas y económicas.

![Image](https://github.com/user-attachments/assets/33d23ad4-043a-4c6b-8bab-c31a648c3e4a)

Sensor LiDAR: Un sensor LiDAR (Light Detection and Ranging) es un dispositivo de teledetección que utiliza pulsos de luz láser para medir distancias con gran precisión y crear mapas tridimensionales del entorno. Su funcionamiento se basa en emitir miles de pulsos de láser por segundo hacia los objetos; estos pulsos rebotan y regresan al sensor, que mide el tiempo que tarda cada pulso en ir y volver. Como la velocidad de la luz es conocida, este tiempo de vuelo permite calcular la distancia exacta entre el sensor y los objetos o superficies. Los datos recolectados se procesan para formar una nube de puntos, que es una representación 3D detallada del área escaneada.

![Image](https://github.com/user-attachments/assets/234ebb64-bf87-4ec4-82ca-5e8cac3d7af3)

En este momento la raspberry y el sensor LiDAR estan incluidos en la estructura del robot, sin embargo no se utilizan para la realización del reto.

El Arduino está alimentado por una batería de 9v, y enciende mediante un interruptor. Se encarga de alimentar y dar las respectivas señales al servomotor, para que sea capaz de realizar los cruces de forma efectiva con facilidad al giroscopio, además de dar y recibir señales del resto de sensores. 

Por último, el puente H está conectado y alimentado por dos baterías de 3,7v y se enciende con el mismo interruptor que enciende el Arduino.
El puente H recibe señales del Arduino que llevan a mover el motor en diferentes direcciones y velocidades. También se encarga de alimentar los sensores ultrasónicos.
  

# Diseño del software

1. Análisis de imágenes
-  [Procesamiento de imágenes](https://github.com/Samu4035/REDMACHINE-2025/blob/main/src/software.md#Procesamiento-de-imágenes)
-  [Detección de color](https://github.com/Samu4035/REDMACHINE-2025/blob/main/src/software.md#Detección-de-color)
-  [Programación](https://github.com/Samu4035/REDMACHINE-2025/blob/main/src/software.md#Programación)



# Videos del funcionamiento de pompo
 - [FUTUROS INGENIEROS-Reto 1](https://youtu.be/I5WXGXlZpG4?si=D2IsjQdoafDccQmA)

[![Image](https://github.com/user-attachments/assets/3a998c08-fef1-4247-a1c7-fdddfd4fdfc8)](https://youtu.be/I5WXGXlZpG4?si=D2IsjQdoafDccQmA)
 

- [FUTUROS INGENIEROS-Reto 2](https://youtu.be/XvPb05R_A2o?si=kEyuvRi_PKU7EDct)

[![Image](https://github.com/user-attachments/assets/7d8d684a-25f8-4bad-a824-62b761711ac8)](https://youtu.be/XvPb05R_A2o?si=kEyuvRi_PKU7EDct)


# Índice mecánico
Para más información sobre la mecánica, se ha creado un documento en el que puedes consultar las especificaciones de las piezas y mecanismos del robot.

- [Motores](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Análisis-del-funcionamiento-de-los-motores)
- [Sensores](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Sensores)
- [Camera](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Cámara)
- [Placas controladora](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Placas-controladoras)
- [Alimentación del robot](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Alimentación-del-robot)



# Historia y cronología del equipo

1. Temporada 2023
- [Julio 2023](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Julio-2023)
- [Agosto 2023](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Agosto-2023)
- [Septiembre 2023](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Septiembre-2023)
- [Octubre 2023](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Octubre-2023)
2. Temporada 2024 
- [Febrero 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Febrero-2024)
- [Marzo 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Marzo-2024)
- [Abril 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Abril-2024)
- [Mayo 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Mayo-2024)
- [Junio 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Junio-2024)
- [Octubre 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Octubre-2024)
- [Noviembre 2024](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Noviembre-2024)
3. Temporada 2025
- [Febrero 2025](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Febrero-2025)
- [Marzo 2025](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Marzo-2025)
- [Abril 2025](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Abril-2025)
- [Mayo 2025](https://github.com/Samu4035/REDMACHINE-2025/blob/main/t-photos/Historia.md#Mayo-2025)
4. Julian, Luka y Pompo
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





