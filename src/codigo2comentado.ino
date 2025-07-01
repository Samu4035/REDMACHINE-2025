/*
 * Programa de Control para Robot
 * Este código controla un robot con sensores ultrasónicos, servo motor, IMU MPU6050 y cámara Pixy2
 * El robot navega evitando obstáculos y detectando objetos de colores
 */

// Declaración de Librerías
#include <Servo.h>          // Control de motores servo
#include <NewPing.h>        // Control de sensores ultrasónicos
#include "Wire.h"           // Comunicación I2C
#include <MPU6050_light.h>  // Control del IMU MPU6050
#include <Pixy2.h>          // Control de cámara Pixy2

Pixy2 pixy;  // Objeto para la cámara Pixy2

// Pines para sensor ultrasónico izquierdo
#define TRIGGER_sensor_1  30
#define ECO_sensor_1  31

// Pines para sensor ultrasónico central
#define TRIGGER_sensor_2  18
#define ECO_sensor_2  19

// Pines para sensor ultrasónico derecho
#define TRIGGER_sensor_3 12
#define ECO_sensor_3  11

// Distancia máxima que pueden detectar los ultrasónicos (valor muy grande)
#define MAX_DISTANCE 10000000000000

// Declaración de los sensores ultrasónicos (usando librería NewPing.h)
NewPing sensor_1(TRIGGER_sensor_1, ECO_sensor_1, MAX_DISTANCE);  // Izquierdo
NewPing sensor_2(TRIGGER_sensor_2, ECO_sensor_2, MAX_DISTANCE);  // Central
NewPing sensor_3(TRIGGER_sensor_3, ECO_sensor_3, MAX_DISTANCE);  // Derecho

Servo pro;  // Objeto para el servo de dirección
int distanciagirovueltacompleta = 20;  // Umbral de distancia para giro completo

// Variables para detección y conteo de conos
int cono1 = 0;
int cono2 = 0;
int vuelta = 0;    // Contador de vueltas
int bloque = 0;    // Bloque detectado
int ybloque;       // Posición Y del bloque
// ... (otras variables de conteo)

// Variables de control y sensores
float gyro = 0;   // Lectura del giroscopio
float error = 0;   // Error para control PID
float kp = 1;      // Constante proporcional para PID
int rec = 140;     // Posición central del servo
int vel = 170;     // Velocidad normal
// ... (otras variables de control)

MPU6050 mpu(Wire);  // Objeto para el IMU MPU6050

void setup() {
    // Inicialización del MPU6050
    byte status = mpu.begin();
    
    // Configuración de pines
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    // ... (configuración de otros pines)
    
    pro.attach(9);  // Conectar servo al pin 9
    pro.write(rec); // Centrar el servo
    
    Serial.begin(115200); // Iniciar comunicación serial
    Wire.begin();         // Inicializar I2C
    pixy.init();          // Inicializar cámara Pixy
    
    Serial.println(F("Calculando offsets, no mover el MPU6050"));
    mpu.calcOffsets();    // Calibrar el IMU
    delay(1000);
    Serial.println("Listo!\n");
    
    angulof = mpu.getAngleZ(); // Obtener ángulo inicial
    
    // Esperar señal de inicio
    char dato;
    int comenzar = 0;
    pro.write(rec);
    
    while(comenzar != 1) {
        dato = Serial.read(); // Leer entrada serial
        if(digitalRead(23) == LOW) {  // Si se presiona botón
            comenzar = 1;
        }
        if(dato == '1') {  // Comando por serial
            comenzar = 1;
        }
    }
    
    // Comenzar movimiento hacia adelante
    digitalWrite(atras, 0);
    digitalWrite(adelante, 1);
    analogWrite(5, vel);
    Serial.println("Iniciado");
    delay(20);
    primeravuelta = 0;
    prueba = 0;
}

void loop() {
    // Bucle principal de control
    detectardistancias(0);  // Leer distancias
    detectarladocorto();    // Detectar objetos cercanos
    girosegundoreto();      // Lógica del segundo reto
    detectarpixyY();        // Detectar objetos con Pixy
    esquivarconos();        // Lógica para evitar conos
}

// Función para detectar distancias con los sensores ultrasónicos
void detectardistancias(int serial) {
    d = sensor_2.ping_cm();  // Distancia central
    di = sensor_1.ping_cm(); // Distancia izquierda
    dd = sensor_3.ping_cm(); // Distancia derecha
    
    mpu.update();
    gyro = mpu.getAngleZ();  // Obtener ángulo actual
    
    if(serial == 1) {
        // Mostrar distancias si se solicita
        Serial.print("gyro: ");
        Serial.println(gyro);  
        Serial.print("di: ");
        Serial.println(di);
        Serial.print("d: ");
        Serial.println(d);
        Serial.print("dd: ");
        Serial.println(dd);
    }
}

// Función para determinar qué lado tiene más espacio
void detectarlado() {
    if(d < 30 && d > 0) {
        detectardistancias(1);
        if(d < 30 && d > 0) {
            Serial.print("Detectó d ");
            Serial.println(d);     
            
            // Determinar qué lado tiene más espacio
            if(di == 0 && a == 0) {
                a = 1;
                Serial.print("Detectó di 0 di:");
                Serial.println(di);
                Serial.print("dd");
                Serial.println(dd);               
                Serial.print(" a ==1 izquierda");   
            }
            // ... (resto de condiciones)
        }
    }
}

// Función para avanzar recto con corrección de ángulo
void rectificadosolo(int target) {
    detectardistancias(0);
    int erroultra;
    int kpultra = 0; 
    kp = 1.5;
    angulof += target;
    
    mpu.update();
    gyro = mpu.getAngleZ();
    error = angulof - gyro;
    
    if(error > 180) {
        error = error - 360;
    } 
    
    dd = sensor_3.ping_cm();
    pro.write(rec + kpultra * -1 + error * kp);
}

// Función para girar 90° a la izquierda
void giroizq90() {
    int erroultra;
    int kpultra = -3; 
    kp = 2;
    angulof += 90;
    mpu.update();
    gyro = mpu.getAngleZ();
    
    while(gyro > angulof + 10 || gyro < angulof - 5) {
        mpu.update();
        gyro = mpu.getAngleZ();
        pro.write(izquierda);
        Serial.println("Girando izquierda ");
        Serial.println(gyro);
        Serial.println(angulof);
    }
    Serial.println("Terminó giro izquierda");
    pro.write(rec);
}

// Función para detectar objetos con la cámara Pixy
void detectarpixyY() {
    ybloque = 0;
    bloque = 0;
    pixy.ccc.getBlocks(); // Obtener bloques de color
    
    if(pixy.ccc.numBlocks) {
        Serial.println(pixy.ccc.numBlocks);

        for(int i = 0; i < pixy.ccc.numBlocks; i++) {
            int signature = pixy.ccc.blocks[i].m_signature; // Firma de color
            int x = pixy.ccc.blocks[i].m_x; // Posición X
            int y = pixy.ccc.blocks[i].m_y; // Posición Y
            
            // Seguir el bloque más bajo (más cercano)
            if(y > ybloque) {
                bloque = signature;
                ybloque = y;
            }
        }

        // Mostrar colores detectados
        if(bloque % 2 == 1) {
            Serial.print("Rojo: ");
            Serial.println(ybloque);
        }
        
        if(bloque % 2 == 0) {
            Serial.print("Verde: ");
            Serial.println(ybloque);
        }
    }

    // Recordar último bloque detectado si no hay ninguno ahora
    if(bloque != 0) {
        lastblock = bloque;
    }
    if(bloque == 0) {
        bloque = lastblock;
    }
}

// Función para evitar conos basado en colores detectados
void esquivarconos() {
    // Lógica para cuando el robot está en el lado derecho
    if(a == 2) {
        // Cono rojo en carril 0
        if(bloque == 1 && carril == 0) {
            if(listo == 0) {
                giroderf(45);  // Girar 45° derecha
                pro.write(rec);
                delay(100);
                giroizqf(45);  // Girar 45° izquierda
                listo = 1;
            }
            carril = 1;
        }
        // ... (resto de lógica de evitación)
    }

    // Lógica para cuando el robot está en el lado izquierdo
    if(a == 1) {
        // Cono rojo en carril 0
        if(bloque == 1 && carril == 0) {
            giroderf(45);  // Girar 45° derecha
            pro.write(rec);
            delay(200);
            giroizqf(45);  // Girar 45° izquierda
            carril = 1;
        }
        // ... (resto de lógica de evitación)
    }
}

// Función para girar a la izquierda con corrección
void giroizqf(int cantidad) {
    int error = 0;
    int kp = 1;  
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro + cantidad; // Ángulo objetivo
    
    while(abs(error) > 2) {
        mpu.update();
        gyro = mpu.getAngleZ();
        error = gyro - angulof;
        int ajuste = constrain(error * kp, -25, 25); // Limitar ajuste
        pro.write(rec - ajuste); // Aplicar corrección
        
        Serial.println("Girando izquierda");
        Serial.println("Ángulo actual: " + String(gyro));
        Serial.println("Error: " + String(error));
        Serial.println("Objetivo: " + String(angulof));
    }
    
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro;
    pro.write(rec); // Detener después de corregir
    
    Serial.println("Finalizó giro izquierda");
    Serial.print("gyro");
    Serial.println(gyro);
    Serial.print("angulof");
    Serial.println(angulof);
}

// Función para detener los motores
void detener() {
    digitalWrite(adelante, 0);
    digitalWrite(atras, 0);
}

// Función para avanzar
void avanzar() {
    digitalWrite(adelante, 1);
    digitalWrite(atras, 0);
}

// Función para retroceder
void retroceder() {
    digitalWrite(adelante, 0);
    digitalWrite(atras, 1);
}