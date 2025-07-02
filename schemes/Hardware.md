# Índice
- [Motores](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Análisis-del-funcionamiento-de-los-motores)
- [Sensores](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Sensores)
- [Camera](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Cámara)
- [Placas controladora](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Placas-controladoras)
- [Alimentación del robot](https://github.com/Samu4035/REDMACHINE-2025/blob/main/schemes/Hardware.md#Alimentación-del-robot)
 



# Análisis del funcionamiento de los motores
En el siguiente espacio se mostrarán aspectos del funcionamiento de los 2 motores de nuestro robot.

## Motor ev3

Se utilizó un servomor grande ev3 para la tracción de pompo. 

- Instalación: Se utilizaron múltiples piezas de lego para diseñar una base en la que este motor se sostiene, quedando a una altura precisa para conseguir que las ruedas queden a una altura deseada del piso.
Además, para su conexión, se modificó el cable incluido en el kit de lego minstorms, dejando un extremo de este intacto, y cortando el otro extremo, para luego tomar los dos cables de alimentación que se encontraban dentro y conectando estos a un puente h. 

- Precisión: Utiliza retroalimentación tacométrica (sensor de rotación) con una precisión de 1 grado, lo que permite un control muy exacto de la posición y el movimiento.

- Velocidad: Puede girar a una velocidad de 160–170 revoluciones por minuto (RPM).

- Torque (par de fuerza):
     Par de funcionamiento: 20 N·cm (aproximadamente 30 oz/in).
     Par de parada (stall torque): 40 N·cm (aproximadamente 60 oz/in).




## Servomotor Rev Robotics

![Screenshot 2024-11-08 103745](https://github.com/user-attachments/assets/473534ce-37d2-4f08-9721-a207be8490b3)


- Instalación: Así como en luka, el robot anterior, para conectar este servo con la tracción delantera se ancló un doble brazo servo de aluminio cortado al Smart Robot Servo. Luego se colocó un tornillo en una de las entradas del brazo de aluminio, que lo unió con dos piezas de Lego. Un segundo tornillo une las dos piezas de Lego antes mencionadas.  Asimismo, dos tornillos del chasis se anclaron en la tercera pieza de Lego, para que funcionara como soporte. Por último se colocaron las ruedas, que encajaron entre las tres piezas de Lego. 

Ejemplo del sistema: 
 
 ![Screenshot 2024-11-08 103852](https://github.com/user-attachments/assets/43367d50-6ccf-498b-9c06-c9612c199d0e)


![foto sistema direccion 2](https://github.com/user-attachments/assets/d22ed9c8-2579-46ad-96a0-f00472432b56)


![foto sistema direccion  1](https://github.com/user-attachments/assets/fb4946ed-f055-4171-9542-48f1bef775e9)

El servo se sostiene unido al chasis en una posición fija con un conjunto de piezas de lego. 

- Tensión de funcionamiento: De 4,8V a 7,4V. En el robot, el servo funciona con 5V. 

- Radio de giro: Puede girar hasta 270

- Par: 13,5 kg-cm

- Velocidad: 0,13s/60º

- Peso: 2,05 onzas

- Material del engranaje: Latón

- Potencia: La potencia del servo se especifica a continuación. 

- Pulso de entrada:    
Mínimo-500 μs        
Centro-1500 μs       
Máximo-2500 μs

![Screenshot 2024-11-08 104017](https://github.com/user-attachments/assets/26bf1371-24b6-427f-be1d-9da5c48c0dc1)




# Sensores
A continuación se mostrarán las especificaciones de los sensores que se encuentran en Pompo.

## Ultrasonidos
Se utilizan tres ultrasonidos para definir la distancia entre el robot y las paredes de la pista, concretamente las paredes laterales y frontales según la dirección en la que se dirija el robot.

![Screenshot 2024-11-08 104130](https://github.com/user-attachments/assets/1e2dcd67-23b4-4e43-9aa0-8c34c85a97e9)

- Pines de conexión:        
VCC            
Trig (disparo de ultrasonidos)                 
Echo (Recepción de ultrasonidos)             
GND

![image](https://github.com/RoboticaLLR/redmachine2024/assets/146040533/9cfeae57-2def-47ad-9158-ded9577fc56a)


- Tensión de alimentación: 5 V

- Frecuencia de trabajo: 40 KHz

- Alcance máximo de detección: 450cm

- Alcance mínimo de detección: 2cm

- Ángulo de detección: 15 grados

- Corriente de consumo: 15mA



## giroscopio
Se utiliza un MPU6050 para medir los grados de cada giro y saber cuándo debe dejar de girar el robot. El giroscopio se utiliza tanto para evitar las señales de tráfico como para tomar los giros y ayudar al robot a mantenerse recto mediante un proceso de PID. 

![Image](https://github.com/user-attachments/assets/7824610c-7fcc-4221-9153-1aeb8aedeb60)

- Pines de conexión:    
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

El equipo utiliza la entrada Vin para alimentar el sensor, el pin de GND, y el SDA y SCL para establecer una comunicación entre el arduino y el MPU6050. 

Salida de datos:
El BNO055 puede dar salida a los siguientes datos del sensor:

- Orientación absoluta (vector de Euler, 100 Hz): Datos de orientación de tres ejes basados en una esfera de 360

- Orientación absoluta (cuaternión, 100 Hz): Salida de cuaterniones de cuatro puntos para una manipulación de datos más precisa

- Vector de velocidad angular (100 Hz): Tres ejes de «velocidad de rotación» en rad/s

- Vector de aceleración (100 Hz): Tres ejes de aceleración (gravedad + movimiento lineal) en m/s^2

- Vector de intensidad del campo magnético (20 Hz): Tres ejes de detección del campo magnético en micro Tesla (uT)

- Vector de aceleración lineal (100 Hz): Tres ejes de datos de aceleración lineal (aceleración menos gravedad) en m/s^2

- Vector de gravedad (100 Hz): Tres ejes de aceleración gravitatoria (menos cualquier movimiento) en m/s^2



 

# Cámara
Pompo utiliza una cámara para detectar el color de las señales de tráfico. Esta es la pixy2. 

![pixy2.1](https://github.com/user-attachments/assets/46298b4d-2184-4b40-9b81-577219ed9214)

La pixy2 trabaja a 60 fps, y es capaz de detectar objetos, líneas y colores. En luka el objetivo principal de la camara es detectar colores (rojo y verde). 
Se conecta al arduino con un cable IDC 2 ICSP Arduino que va en los pines ICSP del arduino, que proporciona todas las conexiones necesarias para alimentar y comunicarse con el pixy. 

# Placas controladoras
Luka utiliza una única placa controladora: un Arduino Mega 2560. El Arduino se encarga de controlar los actuadores, los sensores y todo el movimiento del robot.

## Arduino mega 2560

![Screenshot 2024-11-08 104239](https://github.com/user-attachments/assets/877f86c1-f333-4b46-bc66-869465ee6ebf)
  

- Alimentación: 9V

- Pines utilizados: 21

- Corriente máxima por pin 40 mA

- Memoria Flash: 256 KB

- SRAM: 8 KB

- Peso: 37 gramos

- Consumo: 93 mA




# Alimentación del robot
Pompo utilza tres sistemas de alimentación individuales.

## Circuito de alimentación del motor
Este circuito utiliza 2 baterías, cada una contiene 4v aproximadamente. Las 3 baterías están conectadas en serie, por lo que el voltaje se suma. El puente H es el componente eléctrico que recibe esta energía, y la utiliza para alimentar los ultrasonidos y el motor de tracción. 
Para conectar las baterías el equipo utiliza dos packs de dos baterías cada uno, pero uno de ellos está modificado para que sólo utilice una batería. 

![2 packs de baterias 4V 4](https://github.com/user-attachments/assets/7a6248cc-fc05-4bf4-bfd4-aad78766bb06)


## Circuito arduino
Este circuito utiliza 2 baterías de 9V conectadas en paralelo, por lo que el amperaje se suma, manteniendo los mismos 9V. Se conecta directamente a la placa arduino, que alimenta la pixy y el servomotor. Cada uno de estos componentes son alimentados por un pin de salida de 5V del arduino. 

![Primera foto 9 voltios 2](https://github.com/user-attachments/assets/79c1b298-762f-4a96-95a9-bb6aa8bb3e1f)

## Circuito sensores
Este último circuito utiliza una tercera batería de 9V conectada a un puente-H, a través del cuales se alimentan los sensores (ultrasonidos y giroscopio).

# Diagramas de conecciones
Para entender mejor los circuitos eléctricos de pompo, se presentan a continuación los diagramas de conecciones de nuestro robot: 

## Diagrama de sensores

![Image](https://github.com/user-attachments/assets/c35217f0-d546-4963-a06b-0cf20b41dffe)

## Diagrama de motores

![Image](https://github.com/user-attachments/assets/444b414a-24fc-4942-8d5c-f002e175a080)

