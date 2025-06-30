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

## 👤 Juan Diego Cano Barros

### 🧠 Logros Académicos

- 🥉 **Medalla de Bronce – Olimpiada Iberoamericana de Matemáticas (2023)**  
  Representó a Venezuela en la XXIX edición de esta competencia internacional organizada por la OMA en Argentina, tras ser seleccionado como uno de los 10 mejores del segundo nivel nacional por la @acmvenojm.

- 🥈 **Subcampeón – Olimpiada Matemática Argentina Ñandú (2019)**  
  Participó en la prueba oral en Buenos Aires, destacándose como subcampeón en el nivel 1.

---

### 🤖 Trayectoria en Robótica

- 🇻🇪 **Bicampeón Nacional – Categoría Futuros Ingenieros (WRO Venezuela)**  
  Ganador de la Olimpiada Nacional de Robótica en dos ediciones consecutivas, representando al estado Zulia y clasificando a la final internacional.

- 🌍 **Finalista Internacional – WRO Panamá 2023**  
  Representó a Venezuela en la Olimpiada Mundial de Robótica, obteniendo el puesto 25 de 40 equipos en la categoría *Futuros Ingenieros*.

- 🇹🇷 **Participación Internacional – WRO Turquía 2024**  
  Formó parte de la delegación venezolana que compitió en la edición mundial celebrada en Turquía, consolidando su experiencia en escenarios globales de alto nivel.

---

### 💡 Motivación y Enfoque
Comer, Dormir, Conocer Gente, Disfrutar los viajes y Dormir 
---

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

El archivo original del diseño 3D se encuentra en el apartado models.

Principales compentes de los sistemas de tracción: 

| Imagen | Nombre de Componente | Descripción |
| :----: | :-------------------: | :----------: |
| ![servo pequeño](https://github.com/RoboticaLLR/RedMachine/assets/146040533/57aaa91d-b5e5-4360-aef2-06025d15f8b0) | **Servo motor de Rev Robotics** | Es un motor eléctrico con sensor de retroalimentación de posición integrado, que permite realizar movimientos angulares perfectos, utilizando una señal que va de 0V a 5V, donde cada valor que pueda tener el voltaje representa un ángulo exacto, cumpliendo con excelencia la función de realizar los giros. |
| ![Image](https://github.com/user-attachments/assets/05c10969-e9a6-404b-a141-5e44218d54df) | **Motor lego ev3** | Dispositivo que convierte la energía eléctrica en movimiento mecánico, permitiendo en este caso mover una caja de cambios y movilizar las ruedas. La velocidad y el par que tiene vienen determinados por la tensión enviada a través del puente en H, siendo moderados por el Arduino. |


## Componentes electrónicos 
A pesar de que la construcción del robot fue hecha con piezas de lego, para todo el apartado electrónico el equipo se decidió por utilizar piezas externas con las que ya se han familiarizado. Entre estas se encuentran los siguientes sensores y actuadores:

### 📦 Descripción de Componentes Principales del Sistema

| Imagen | Nombre de Componente         | Descripción |
|:------:|:----------------------------:|:------------|
| ![HC-sr04](https://github.com/user-attachments/assets/a59b0102-8994-4ac4-aa06-3d6553ae1a2d) | **Sensor ultrasónico (HC-SR04)** | Utiliza ondas ultrasónicas para medir la distancia a obstáculos. El Arduino Mega 2560 calcula la distancia en base al tiempo que tarda la onda en ir y volver, permitiendo que el robot detecte paredes y realice giros cuando sea necesario. |
| ![BNO055](https://github.com/user-attachments/assets/02c487ce-d624-411f-9db3-a2a3ef82a514) | **Sensor giroscopio (MPU6050)** | Mide la orientación del robot en grados. Permite mantener trayectorias rectas y ejecutar giros precisos, especialmente en transiciones de secciones como curvas de 90°. |
| ![pixy2 1 2](https://github.com/user-attachments/assets/6397d5c9-d6fe-4c80-a7b9-d097bee0ba3e) | **Cámara Pixy 2.1** | Detecta colores específicos preconfigurados que representan señales o zonas de tráfico. Reconoce patrones de color en la imagen y transmite datos al Arduino para ejecutar maniobras de evasión o reacción automática. |
| ![mega 2560](https://github.com/user-attachments/assets/edc71e77-3581-48eb-af96-6dfae65660ac) | **Arduino Mega 2560** | Microcontrolador ATmega2560 que actúa como cerebro central del sistema. Procesa información proveniente de sensores, ejecuta el control de motores y gestiona las decisiones lógicas del robot. Dispone de múltiples pines digitales y analógicos, ideales para proyectos complejos. |
| ![puente H pequeño](https://github.com/RoboticaLLR/RedMachine/assets/146040533/264757f2-118f-42c9-9dd8-2a3c91455834) | **Módulo Puente-H (L298N)** | Permite controlar la dirección y velocidad de motores de corriente continua. Recibe señales del Arduino y regula la tensión de salida, habilitando el cambio de giro y la aceleración del motor según lo requiera el algoritmo de control. |

### 🔋 Cálculo del Consumo Energético Total

| Componente                      | Cantidad | Consumo estimado (mA) | Total (mA) |
|--------------------------------|----------|------------------------|------------|
| Motor grande LEGO EV3          | 1        | 250 mA (típico)        | 250 mA     |
| Servo motor REV Robotics       | 1        | 180 mA (típico)        | 180 mA     |
| Sensor ultrasónico HC-SR04     | 3        | 15 mA c/u              | 45 mA      |
| PixyCam (CMUcam5)              | 1        | 140 mA                 | 140 mA     |
| Sensor MPU6050                 | 1        | 6 mA                   | 6 mA       |
| **TOTAL**                      | —        | —                      | **621 mA** |

---

### ⚡ Distribución de Energía y Estimación de Autonomía

El sistema se alimenta de forma distribuida para mejorar la eficiencia y facilitar la gestión energética:

- 🔌 **2 baterías de 9V**: Alimentan el Arduino y el servo motor.
- 🔋 **1 batería de 9V**: Suministra energía a todos los sensores (ultrasónicos, MPU6050, PixyCam).
- 🔋 **2 baterías 18650 (3.7V, 2000 mAh c/u, conectadas en serie para 7.4V)**: Alimentan el motor grande EV3.

| Fuente de Energía            | Componentes Alimentados           | Consumo estimado (mA) | Capacidad Aprox. | Autonomía Estimada |
|------------------------------|------------------------------------|------------------------|------------------|---------------------|
| 2x 9V                        | Arduino + Servo REV                | ~230 mA               | ~500 mAh         | ~2 horas            |
| 1x 9V                        | Sensores (PixyCam, HC-SR04, MPU)   | ~191 mA               | ~500 mAh         | ~2.6 horas          |
| 2x 18650 (7.4V, 4000 mAh)    | Motor grande EV3                   | ~250 mA               | 4000 mAh         | ~16 horas           |

> 💡 *Nota: Los valores de autonomía son teóricos y pueden variar según condiciones reales como carga del motor, procesamiento visual o intensidad de uso de sensores.*


### 🧪 Registro de Pruebas – Primer Reto

| #  | ¿Lo logró?   | Tiempo (s) | Error Detectado                            |
|----|--------------|------------|---------------------------------------------|
| 1  | Sí           | 118        | Ninguno                                     |
| 2  | Sí           | 121        | Ninguno                                     |
| 3  | No           | 10         | Detección incorrecta del lado de inicio     |
| 4  | Sí           | 119        | Ninguno                                     |
| 5  | Sí           | 117        | Ninguno                                     |
| 6  | Sí           | 122        | Ninguno                                     |
| 7  | Sí           | 120        | Ninguno                                     |
| 8  | No           | 10         | Detección incorrecta del lado de inicio     |
| 9  | Sí           | 118        | Ninguno                                     |
|10  | Sí           | 123        | Ninguno                                     |
|11  | Sí           | 120        | Ninguno                                     |
|12  | Sí           | 119        | Ninguno                                     |
|13  | No           | 10         | Detección incorrecta del lado de inicio     |
|14  | Sí           | 118        | Ninguno                                     |
|15  | Sí           | 120        | Ninguno                                     |
|16  | No           | 10         | Detección incorrecta del lado de inicio     |
|17  | Sí           | 117        | Ninguno                                     |
|18  | Sí           | 121        | Ninguno                                     |
|19  | Sí           | 122        | Ninguno                                     |
|20  | No           | 10         | Detección incorrecta del lado de inicio     |
|21  | Sí           | 120        | Ninguno                                     |
|22  | Sí           | 119        | Ninguno                                     |
|23  | Sí           | 118        | Ninguno                                     |
|24  | Sí           | 121        | Ninguno                                     |
|25  | No           | 10         | Detección incorrecta del lado de inicio     |
  

Tiempo promedio de recorrido, precisión, errores frecuentes.
Durante la etapa de pruebas del primer reto, se llevaron a cabo 25 intentos consecutivos para evaluar el rendimiento y la estabilidad del sistema robótico bajo condiciones controladas. Los resultados obtenidos permiten estimar métricas clave sobre el comportamiento del vehículo autónomo:

⏱ Tiempo promedio de recorrido: 120 segundos

🎯 Precisión en la ejecución de la trayectoria: 76%

❌ Errores frecuentes detectados:

El error más común consistió en una detección incorrecta del lado de inicio, lo que ocasionó desvíos temporales o reinicios de la lógica de navegación.
En menor medida, se registraron leves oscilaciones en línea recta provocadas por variaciones de lectura del giroscopio en las primeras etapas del recorrido.

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





