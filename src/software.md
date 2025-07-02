# Diseño del software

1. Análisis de imágenes
-  [Procesamiento de imágenes](https://github.com/Samu4035/REDMACHINE-2025/blob/main/src/software.md#Procesamiento-de-imágenes)
-  [Detección de color](https://github.com/Samu4035/REDMACHINE-2025/blob/main/src/software.md#Detección-de-color)
-  [Programación](https://github.com/Samu4035/REDMACHINE-2025/blob/main/src/software.md#Programación)
-  [Sistema de Control de Robot](https://github.com/Samu4035/REDMACHINE-2025/blob/main/src/software.md#Sistema-de-Control-de-Robot)

# Procesamiento de imágenes
Para procesar la imagen, Luka utiliza una cámara. Esta es la pixy2. 

![pixy2.1](https://github.com/user-attachments/assets/46298b4d-2184-4b40-9b81-577219ed9214)

La pixy2 trabaja a 60 fps, y es capaz de detectar objetos, líneas y colores. En luka el objetivo principal de la camara es detectar colores (rojo y verde). 
Se conecta al arduino con un cable IDC 2 ICSP Arduino que va en los pines ICSP del arduino, que proporciona todas las conexiones necesarias para alimentar y comunicarse con el pixy. 

## Detección de color
Pixy2 utiliza un algoritmo de filtrado basado en el color para detectar objetos llamado el algoritmo Color Connected Components (CCC). Pixy2 calcula el color (tono) y la saturación de cada píxel RGB del sensor de imagen y los utiliza como parámetros principales de filtrado. El tono de un objeto permanece prácticamente inalterado con los cambios de iluminación y exposición. El algoritmo CCC de Pixy2 recuerda hasta 7 firmas de color diferentes.

Después de guardar un color en una firma de color, el pixy lo añadirá a una tabla de objetos que está rastreando actualmente y le asignará un índice de rastreo. A continuación, intentará encontrar el objeto (y todos los objetos de la tabla) en el siguiente fotograma buscando su mejor coincidencia. Cada objeto rastreado recibe un índice entre 0 y 255 que mantendrá hasta que abandone el campo de visión de Pixy2. 

![seguimiento_color](https://github.com/user-attachments/assets/46d2f0c5-c726-4a08-a899-b9a19b0e1dee)


## Programación 
Para establecer los colores que debe detectar la cámara, el equipo utiliza pixymon. PixyMon es una aplicación que funciona en Windows, MacOs y Linux. Te permite ver lo que Pixy2 ve, ya sea como vídeo en bruto o procesado. También te permite configurar tu Pixy2, establecer el puerto de salida y gestionar las firmas de color. PixyMon se comunica con Pixy2 a través de un cable mini USB estándar.

![Screenshot 2024-11-11 103435](https://github.com/user-attachments/assets/f58a573e-7a54-49de-9017-4953aa863677)

En pixymon el equipo establece 6 firmas, tres para el verde y tres para el rojo. Las firmas 1, 3 y 5 para el rojo, y las firmas 2, 4 y 6 para el verde. 

Después de esto el arduino proccesing necesitaba ser hecho. 

En el arduino, el equipo utiliza la librería pixy2, que permite obtener toda la información necesaria de la detección de pixeles. Entonces, usando el siguiente código, el equipo guarda cuando el pixy detecta un color y a qué firmas corresponde el color en una variable llamada «hola». Si hola es divisible por dos, entonces el color es verde, y si hola no es divisible por dos, entonces el color es rojo. 

# Sistema de Control de Robot

> Flujo de Operación y Lógica de Navegación para Competencia WRO

---

# Explicacion Codigo Reto 2


---

## 1. Inicialización y Configuración

- Calibración del IMU (MPU6050)  
- Configuración de pines y comunicación (Serial, I²C, servo, motores, botón)  
- Centrado del servomotor de dirección (`rec`)  
- Espera de señal de inicio (botón en pin 23 o comando serial `'1'`)

---

## 2. Secuencia Principal de Operación (loop)

El robot repite continuamente el siguiente ciclo:

### a) Lectura de Sensores

![Lectura de Sensores](https://github.com/user-attachments/assets/d3549fd1-adc8-48e8-ba60-03aa1c59fb70)

- Ultrasonidos izquierdo (`di`), central (`d`) y derecho (`dd`)  
- Actualización de ángulo con IMU (`gyro`)

### b) Detección de Obstáculos Cercanos

**Función**: `detectarladocorto()`

- Si `d < 10 cm`:  
  - Relee distancias  
  - Compara `di` vs. `dd`  
  - Asigna lateralidad:  
    - `a = 1` → giro por la izquierda  
    - `a = 2` → giro por la derecha  

### c) Gestión del Segundo Reto (girosegundoreto())

Cuando `d < 10 cm` detecta pared frontal:

| Carril | Secuencia de Maniobra                                                                                         |
| ------ | -------------------------------------------------------------------------------------------------------------- |
| Impar  | 1. Retroceder<br/>2. Girar 90° opuesto a la pared<br/>3. Retroceder 2.5 s<br/>4. Avanzar                       |
| Par    | 1. Retroceder 1.8 s<br/>2. Girar 90° hacia la pared<br/>3. Retroceder 2.5 s<br/>4. Avanzar                     |

Al final de cada reto, `vuelta++`.

### d) Detección de Conos (detectarpixyY())

- La cámara Pixy2 captura bloques de color.  
- Identifica firma de color:  
  - Rojo si `signature % 2 == 1`  
  - Verde si `signature % 2 == 0`  
- Selecciona el bloque más cercano (mayor `m_y`).  
- Conserva `lastblock` si la detección momentánea falla.

### e) Evasión de Conos

![Evasión de Conos](https://github.com/user-attachments/assets/c6af0941-932f-4e8a-8245-58376482faaa)

**Función**: `esquivarconos()`

- Según `a` (lado) y `carril` actual, realiza maniobras:  
  - Cono rojo en carril 0 →  
    1. `giroderf(45)`  
    2. Servo a posición neutra + delay  
    3. `giroizqf(45)`  
    4. Actualiza `carril` y `listo`  
  - Lógicas análogas para conos verdes y otros carriles

### f) Control de Dirección

- **Navegación recta** (`rectificadosolo(target)`):  
  - Ajusta servo con control proporcional (PID)  
  - Mantiene ángulo objetivo `angulof`  
- **Giros precisos** (`giroizqf()`, `giroizq90()`):  
  - Calculan `angulof = gyro + Δ°`  
  - Corrigen en bucle hasta error < 2°  
  - Detienen servo en posición neutra

---

## 3. Mecanismos Clave de Control

### 3.1 Sistema de Carriles

| Carril | Comportamiento                              |
| ------ | ------------------------------------------- |
| 0      | Búsqueda del primer cono                   |
| 1      | Tras esquivar cono rojo desde la derecha    |
| 2      | Tras esquivar cono verde desde la derecha   |
| 3      | Tras esquivar segundo cono rojo             |
| 4      | Tras esquivar segundo cono verde            |

### 3.2 Lógica de Evasión

- **Conos rojos**  
  - 1ª detección: esquivado suave (45°)  
  - 2ª detección: maniobra pronunciada (80°)  
- **Conos verdes**  
  - Maniobra en sentido opuesto a los rojos  
  - Actualiza carril según color

---

## 4. Gestión de Movimiento

![Gestión de Movimiento](https://github.com/user-attachments/assets/c1dad286-1b72-4b76-b381-61271ac7dd70)

- **Avanzar**: motor frontal activado  
- **Retroceder**: motor trasero activado  
- **Girar**: comando mixto servomotor + marcha  
- **Detenido**: ambos motores desactivados  

---

## 5. Estrategia de Navegación

![Estrategia de Navegación](https://github.com/user-attachments/assets/fd7c3e0d-5b96-4052-a3e4-bf6aa35f9961)

Este sistema permite al robot:

- Navegar en entornos desconocidos  
- Identificar y esquivar obstáculos dinámicos  
- Mantener orientación precisa con IMU  
- Adaptar comportamiento según patrones de color  
- Completar circuitos con múltiples vueltas  

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
