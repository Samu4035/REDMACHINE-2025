/*
 * Robot Control Program
 * This code controls a robot with ultrasonic sensors, servo motor, MPU6050 IMU, and Pixy2 camera
 * The robot navigates while avoiding obstacles and detecting colored objects
 */

// Declaration of Libraries
#include <Servo.h>          // Servo motor control
#include <NewPing.h>        // Ultrasonic sensor control
#include "Wire.h"           // I2C communication
#include <MPU6050_light.h>  // MPU6050 IMU control
#include <Pixy2.h>          // Pixy2 camera control

Pixy2 pixy;  // Create Pixy2 object

// Ultrasonic sensor pins - left
#define TRIGGER_sensor_1  30
#define ECO_sensor_1  31

// Ultrasonic sensor pins - center
#define TRIGGER_sensor_2  18
#define ECO_sensor_2  19

// Ultrasonic sensor pins - right
#define TRIGGER_sensor_3 12
#define ECO_sensor_3  11

// Maximum distance ultrasonic sensors can detect (very large value)
#define MAX_DISTANCE 10000000000000

// Declare ultrasonic sensors (using NewPing library)
NewPing sensor_1(TRIGGER_sensor_1, ECO_sensor_1, MAX_DISTANCE);  // Left
NewPing sensor_2(TRIGGER_sensor_2, ECO_sensor_2, MAX_DISTANCE);  // Center
NewPing sensor_3(TRIGGER_sensor_3, ECO_sensor_3, MAX_DISTANCE);  // Right

Servo pro;  // Servo object for steering
int distanciagirovueltacompleta = 20;  // Distance threshold for full turn

// Variables for cone detection and counting
int cono1 = 0;
int cono2 = 0;
int vuelta = 0;    // Lap counter
int bloque = 0;    // Detected block
int ybloque;       // Y position of block
int cono11 = 0;
int cono12 = 0;
int cono21 = 0;
int cono22 = 0;
int cono31 = 0;
int cono32 = 0;
int listo2 = 0;
int cono41 = 0;
int cono42 = 0;
int signature;     // Color signature from Pixy
int prueba;        // Test variable
float gyro = 0;   // Gyro reading
float error = 0;   // Error for PID control
float kp = 1;      // Proportional constant for PID
int angf = 0;      // Final angle
int cercarec = 10; // Close distance threshold
int lejosrec = 15; // Far distance threshold
int potenciarectificado = 7; // Rectification power
int i;             // General counter
int rojo1;         // Red color value
int verde1;        // Green color value
int preocupado = 0; // Concern flag
int total = 0;     // Total count
int rojo = 0;      // Red count
int verde = 0;     // Green count
int azul = 0;      // Blue count
int clear = 0;     // Clear count
int k = 0;         // Counter
int j = 0;         // Counter
int b;             // General variable
int primera = 0;   // First time flag
int X;             // General variable
int d = 0;         // Left ultrasonic distance
int giro = 0;      // Turn state
int rec = 140;     // Servo center position
int da;            // Right ultrasonic distance
int t;             // Left ultrasonic ping time
int te;            // Right ultrasonic ping time
int lastblock;     // Last detected block
int vel = 170;     // Normal speed
int velrapida = 150; // Fast speed
int veln = 100;    // Slow speed
int gi = vel;      // Turning speed
int vueltacompleta = 0; // Full turn counter
int listo = 0;     // Ready flag
int td;            // Time distance
int dd;            // Right distance
int ti;            // Time left
int di;            // Left distance
int izquierda = rec + 35; // Left turn servo position
int derecha = rec - 35;   // Right turn servo position
int linea = 1;     // Line following state
int rectofijo = rec; // Fixed center position
int rectofijo2 = rec; // Secondary center position
int x, y, z;       // IMU axes
float geografico, acimut; // Geographic direction
float declinacion = -10.26; // Magnetic declination
int direccion = 0;  // Direction
int angulo1min = 330; // Angle range 1 min
int angulo1max = 360; // Angle range 1 max
int angulo2min = 75;  // Angle range 2 min
int angulo2max = 100; // Angle range 2 max
int angulo3min = 165; // Angle range 3 min
int angulo3max = 190; // Angle range 3 max
int angulo4min = 245; // Angle range 4 min
int angulo4max = 270; // Angle range 4 max
int maxactual = 0;  // Current max
int minactual = 0;  // Current min
int cono = 0;       // Cone count
int primeravuelta = 0; // First lap flag
int a = 0;          // General state
int hola = 0;       // Test variable
int carril = 0;     // Lane position
float angulo = acimut - 10.26; // Adjusted angle
int adelante = 7;   // Forward pin
int atras = 6;      // Backward pin
float angulof = 0;  // Target angle
float angulom;      // Measured angle
MPU6050 mpu(Wire);  // MPU6050 object

void setup() {
    // Initialize MPU6050
    byte status = mpu.begin();
    
    // Pin configuration
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, INPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, INPUT);
    pinMode(10, OUTPUT); // Trigger
    pinMode(11, INPUT);  // Echo
    pinMode(12, INPUT);  // Trigger
    pinMode(13, OUTPUT); // Echo
    pinMode(22, OUTPUT);
    pinMode(23, INPUT_PULLUP);
    pinMode(24, INPUT);
    pinMode(25, INPUT);
    pinMode(A15, INPUT);
    pinMode(A14, INPUT);
    pinMode(A13, INPUT);
    pinMode(A12, INPUT);
    pinMode(26, OUTPUT);
    pinMode(27, OUTPUT);
    pinMode(28, OUTPUT);
    pinMode(29, INPUT);
    pinMode(36, INPUT_PULLUP);
    pinMode(49, INPUT_PULLUP);
    pinMode(51, INPUT);
    pinMode(50, OUTPUT);
    pinMode(53, INPUT);
    pinMode(30, OUTPUT);
    pinMode(40, OUTPUT);
    pinMode(31, INPUT); 
    pinMode(42, OUTPUT);
    pinMode(43, INPUT);
    pinMode(47, OUTPUT);
    pinMode(45, OUTPUT);
    pinMode(49, OUTPUT);
    pinMode(52, OUTPUT); 
    
    pro.attach(9);  // Attach servo to pin 9
    pro.write(rec); // Center servo
    
    Serial.begin(115200); // Start serial communication
    Wire.begin();         // Initialize I2C
    pixy.init();          // Initialize Pixy camera
    
    Serial.println(F("Calculating offsets, do not move MPU6050"));
    mpu.calcOffsets();    // Calculate IMU offsets
    delay(1000);
    Serial.println("Done!\n");
    
    angulof = mpu.getAngleZ(); // Get initial angle
    char dato;
    int comenzar = 0;
    pro.write(rec);
    
    // Wait for start signal
    while(comenzar != 1) {
        dato = Serial.read(); // Read serial input
        if(digitalRead(23) == LOW) {  // Button press
            comenzar = 1;
        }
        if(dato == '1') {  // Serial command
            comenzar = 1;
        }
    }
    
    // Start moving forward
    digitalWrite(atras, 0);
    digitalWrite(adelante, 1);
    analogWrite(5, vel);
    Serial.println("Iniciado");
    delay(20);
    primeravuelta = 0;
    prueba = 0;
}

void loop() {
    // Main control loop
    detectardistancias(0);  // Read distances
    detectarladocorto();    // Detect close objects
    girosegundoreto();      // Second challenge logic
    detectarpixyY();        // Detect objects with Pixy
    esquivarconos();        // Cone avoidance logic
}

// Function to detect distances from ultrasonic sensors
void detectardistancias(int serial) {
    d = sensor_2.ping_cm();  // Center distance
    di = sensor_1.ping_cm(); // Left distance
    dd = sensor_3.ping_cm(); // Right distance
    
    mpu.update();
    gyro = mpu.getAngleZ();  // Get current angle
    
    if(serial == 1) {
        // Print distances if requested
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

// Function to detect which side has more space
void detectarlado() {
    if(d < 30 && d > 0) {
        detectardistancias(1);
        if(d < 30 && d > 0) {
            Serial.print("detecto d ");
            Serial.println(d);     
            
            // Determine which side has more space
            if(di == 0 && a == 0) {
                a = 1;
                Serial.print("detecto di 0 di:");
                Serial.println(di);
                Serial.print("dd");
                Serial.println(dd);               
                Serial.print(" a ==1 izquierda");   
            }
            
            if(dd == 0 && a == 0) {
                Serial.print("detecto dd 0 dd:");
                Serial.println(dd);
                Serial.print("di");
                Serial.println(di);       
                Serial.print(" a ==2 derecha");   
                a = 2;
            }
            
            if(di > dd && a == 0) {
                Serial.print("detecto dd:");
                Serial.println(dd);
                Serial.print("di");
                Serial.println(di);
                Serial.print(" a ==1 izquierda");
                a = 1;
            }
            
            if(dd > di && a == 0) {
                Serial.print("detecto di:");
                Serial.println(di);
                Serial.print("dd");
                Serial.println(dd);       
                Serial.print(" a ==2 derecha");
                a = 2;
            }
            primeravuelta = 1;
        }
    }
}

// Function to drive straight with angle correction
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

// Function to drive straight correcting right distance
void rectderecha(int targetult, int target) {
    int erroultra; 
    int kpultra = -2; 
    kp = 1.5;

    detectardistancias(0); 
    angulof += target;
    mpu.update();
    gyro = mpu.getAngleZ();
    error = angulof - gyro;

    if(error > 180) {
        error -= 360; 
    }

    dd = sensor_3.ping_cm();
    erroultra = targetult - dd;

    // Adjust steering to maintain distance
    int ajuste = constrain(erroultra * kpultra * -1 + error * kp, -20, 20);
    pro.write(rec + ajuste);
}

// Function to drive straight correcting left distance
void rectizquierda(int targetult, int target) {
    int erroultra; 
    int kpultra = -2; 
    kp = 1.5;

    angulof += target;
    mpu.update();
    gyro = mpu.getAngleZ();
    error = angulof - gyro;

    if(error > 180) {
        error -= 360;
    }

    Serial.print("Angulof: ");
    Serial.println(angulof);
    Serial.print("Error: ");
    Serial.println(error);

    di = sensor_1.ping_cm();
    erroultra = targetult - di;

    // Adjust steering to maintain distance
    int ajuste = constrain(erroultra * kpultra * -1 + error * kp, -20, 20);
    pro.write(rec + ajuste);
}

// Function to detect close objects on sides
void detectarladocorto() {
    if(d < 10 && d > 0) {
        detectardistancias(1);
        if(d < 10 && d > 0) {
            Serial.print("detecto d ");
            Serial.println(d);     
            
            // Determine which side has more space
            if(di == 0 && a == 0) {
                a = 1;
                Serial.print("detecto di 0 di:");
                Serial.println(di);
                Serial.print("dd");
                Serial.println(dd);               
                Serial.print(" a ==1 izquierda");   
            }
            
            if(dd == 0 && a == 0) {
                Serial.print("detecto dd 0 dd:");
                Serial.println(dd);
                Serial.print("di");
                Serial.println(di);       
                Serial.print(" a ==2 derecha");   
                a = 2;
            }
            
            if(di > dd && a == 0) {
                Serial.print("detecto dd:");
                Serial.println(dd);
                Serial.print("di");
                Serial.println(di);
                Serial.print(" a ==1 izquierda");
                a = 1;
            }
            
            if(dd > di && a == 0) {
                Serial.print("detecto di:");
                Serial.println(di);
                Serial.print("dd");
                Serial.println(dd);       
                Serial.print(" a ==2 derecha");
                a = 2;
            }
            primeravuelta = 1;
        }
    }
}

// Function to turn left 90 degrees (non-corrected)
void giroizq90n() {
    int erroultra;
    int kpultra = -3; 
    kp = 2;
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro + 90;
    mpu.update();
    gyro = mpu.getAngleZ();
    
    while(gyro > angulof + 10 || gyro < angulof - 5) {
        mpu.update();
        gyro = mpu.getAngleZ();
        pro.write(izquierda);
        Serial.println("Girando derecha ");
        Serial.println(gyro);
        Serial.println(angulof);
    }
    Serial.println("termino derecha");
    pro.write(rec);
}

// Function to turn right 90 degrees (non-corrected)
void giroder90n() {
    int erroultra;
    int kpultra = -3; 
    kp = 2;
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro - 90;
    mpu.update();
    gyro = mpu.getAngleZ();
    
    while(gyro < angulof - 5 || gyro > angulof + 5) {
        mpu.update();
        gyro = mpu.getAngleZ();
        pro.write(derecha);
        Serial.println("Girando Izquierda");
        Serial.println(gyro);
        Serial.println(angulof);
    }
    pro.write(rec);
    Serial.println("termino izquierda ");
}

// Function to detect objects with Pixy camera
void detectarpixyY() {
    ybloque = 0;
    bloque = 0;
    pixy.ccc.getBlocks(); // Get color blocks
    
    if(pixy.ccc.numBlocks) {
        Serial.println(pixy.ccc.numBlocks);

        for(int i = 0; i < pixy.ccc.numBlocks; i++) {
            int signature = pixy.ccc.blocks[i].m_signature; // Color signature
            int x = pixy.ccc.blocks[i].m_x; // X position
            int y = pixy.ccc.blocks[i].m_y; // Y position
            
            // Track the lowest (closest) block
            if(y > ybloque) {
                bloque = signature;
                ybloque = y;
            }
        }

        // Print detected colors
        if(bloque % 2 == 1) {
            Serial.print("Rojo: ");
            Serial.println(ybloque);
        }
        
        if(bloque % 2 == 0) {
            Serial.print("Verde: ");
            Serial.println(ybloque);
        }
    }

    // Remember last detected block if none detected now
    if(bloque != 0) {
        lastblock = bloque;
    }
    if(bloque == 0) {
        bloque = lastblock;
    }
}

// Function to turn left 90 degrees (corrected)
void giroizq90nc() {
    int erroultra;
    int kpultra = -3; 
    kp = 2;
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro + 90;
    mpu.update();
    gyro = mpu.getAngleZ();
    
    while(gyro > angulof + 10 || gyro < angulof - 5) {
        mpu.update();
        gyro = mpu.getAngleZ();
        pro.write(derecha);
        Serial.println("Girando derecha ");
        Serial.println(gyro);
        Serial.println(angulof);
    }
    Serial.println("termino derecha");
    pro.write(rec);
}

// Function to turn right 90 degrees (corrected)
void giroder90nc() {
    int erroultra;
    int kpultra = -3; 
    kp = 2;
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro - 90;
    mpu.update();
    gyro = mpu.getAngleZ();
    
    while(gyro < angulof - 5 || gyro > angulof + 5) {
        mpu.update();
        gyro = mpu.getAngleZ();
        pro.write(izquierda);
        Serial.println("Girando Izquierda");
        Serial.println(gyro);
        Serial.println(angulof);
    }
    pro.write(rec);
    Serial.println("termino izquierda ");
}

// Function to stop motors
void detener() {
    digitalWrite(adelante, 0);
    digitalWrite(atras, 0);
}

// Function to move forward
void avanzar() {
    digitalWrite(adelante, 1);
    digitalWrite(atras, 0);
}

// Function to move backward
void retroceder() {
    digitalWrite(adelante, 0);
    digitalWrite(atras, 1);
}

// Function to turn left by specified angle
void giroizq(int cantidad) {
    int erroultra;
    int kpultra = -3; 
    kp = 2;
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro + cantidad;
    mpu.update();
    gyro = mpu.getAngleZ();
    
    while(gyro > angulof + 10 || gyro < angulof - 5) {
        mpu.update();
        gyro = mpu.getAngleZ();
        pro.write(izquierda);
        Serial.println("Girando derecha ");
        Serial.println(gyro);
        Serial.println(angulof);
    }
    Serial.println("termino derecha");
    pro.write(rec);
}

// Function to turn right by specified angle
void giroder(int cantidad) {
    int erroultra;
    int kpultra = -3; 
    kp = 2;
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro - cantidad;
    mpu.update();
    gyro = mpu.getAngleZ();
    
    while(gyro < angulof - 5 || gyro > angulof + 5) {
        mpu.update();
        gyro = mpu.getAngleZ();
        pro.write(derecha);
        Serial.println("Girando Izquierda");
        Serial.println(gyro);
        Serial.println(angulof);
    }
    pro.write(rec);
    Serial.println("termino derecha ");
}

// Function to drive straight with right distance correction (safe version)
void derechasafe(int targetult, int target, int sensibilidad) {
    int erroultra;
    int kpultra = -2; 
    kp = 2;
    mpu.update();
    gyro = mpu.getAngleZ();
    error = target - gyro;
    
    if(error > 180) {
        error = error - 360;
    } 
    
    dd = sensor_3.ping_cm();
    erroultra = targetult - dd;
    Serial.print("erroultra");
    Serial.println(erroultra);
    
    // Adjust steering only if within sensitivity range
    if(erroultra > 0 && erroultra < sensibilidad) {
        pro.write(rec + erroultra * kpultra * -1 + error * kp);
    }
    else {
        pro.write(rec);
    }
    
    if(erroultra < 0 && erroultra > sensibilidad) {
        pro.write(rec + erroultra * kpultra * -1 + error * kp);
    }
    else {
        pro.write(rec);
    }
}

// Function to drive straight with left distance correction (safe version)
void izquierdasafe(int targetult, int target, int sensibilidad) {
    int erroultra;
    int kpultra = 2; 
    kp = 2;
    angulof += target;
    mpu.update();
    gyro = mpu.getAngleZ();
    error = angulof - gyro;
    
    if(error > 180) {
        error = error - 360;
    } 
    
    Serial.print("Angulof");
    Serial.println(angulof);
    Serial.println("Error");
    Serial.println(error);
    
    di = sensor_1.ping_cm();
    erroultra = targetult - di;
    
    // Adjust steering only if within sensitivity range
    if(erroultra > 0 && erroultra < sensibilidad) {
        pro.write(rec + erroultra * kpultra * -1 + error * kp);
    }
    else {
        pro.write(rec);
    }
    
    if(erroultra < 0 && erroultra > sensibilidad) {
        pro.write(rec + erroultra * kpultra * -1 + error * kp);
    }
    else {
        pro.write(rec);
    }
}

// Function to move backward until reaching specified distance
void retrocedercondistancias(int distancia) {
    while(d < distancia || d == 0) {
        while(d < distancia || d == 0) {
            detectardistancias(0);
        }
        detectardistancias(0);
    }
}

// Function to move forward until reaching specified distance
void avanzarhasta(int distancia) {
    detectardistancias(0);
    while(d > distancia && d != 0) {
        detectardistancias(0);
    }
}

// Function to reset variables
void reiniciarvariables() {
    listo = 0;
    carril = 0;
    bloque = 0;
    lastblock = 0;
}

// Function to avoid cones based on detected colors
void esquivarconos() {
    // Right side logic
    if(a == 2) {
        // Red cone in lane 0
        if(bloque == 1 && carril == 0) {
            if(listo == 0) {
                giroderf(45);  // Turn right 45°
                pro.write(rec);
                delay(100);
                giroizqf(45);  // Turn left 45°
                listo = 1;
            }
            carril = 1;
        }

        // Red cone in lane 2
        if(bloque == 1 && carril == 2) {
            giroderf(80);  // Turn right 80°
            pro.write(rec);
            avanzarhasta(35);  // Move forward until 35cm
            giroizqf(80);      // Turn left 80°
            carril = 3;
        }

        // Odd lanes (1, 3, etc.)
        if(carril % 2 == 1) {
            if(dd > 60) {
                rectizquierda(60, 0);  // Correct left to maintain 60cm
            }
            if(dd < 60 && d > 100) {
                rectderecha(23, 0);    // Correct right to maintain 23cm
            }
            else {
                rectificadosolo(0);     // Drive straight
            }
            Serial.println("Izquierda");
        }

        // Even lanes (0, 2, etc.)
        if(carril % 2 == 0) {
            rectizquierda(23, 0);  // Correct left to maintain 23cm
            Serial.println("Izquierda");
        }

        // No cone detected
        if(bloque == 0) {
            rectizquierda(40, 0);  // Correct left to maintain 40cm
            Serial.println("Izquierda");
        }
        
        // Green cone in lane 0
        if(bloque == 2 && carril == 0) {
            if(listo == 0) {
                giroizqf(45);  // Turn left 45°
                pro.write(rec);
                delay(200);
                giroderf(45);  // Turn right 45°
                listo = 1;
            }
            rectizquierda(16, 0);  // Correct left to maintain 16cm
            Serial.println("Izquierda");
            carril = 2;
        }
        
        // Green cone in lane 1
        if(bloque == 2 && carril == 1) {
            giroizqf(80);  // Turn left 80°
            pro.write(rec);
            avanzarhasta(40);  // Move forward until 40cm
            giroderf(80);     // Turn right 80°
            listo = 1;
            carril = 4;
        }
    }

    // Left side logic
    if(a == 1) {
        // Red cone in lane 0
        if(bloque == 1 && carril == 0) {
            giroderf(45);  // Turn right 45°
            pro.write(rec);
            delay(200);
            giroizqf(45);  // Turn left 45°
            carril = 1;
        }

        // Red cone in lane 2
        if(bloque == 1 && carril == 2) {
            giroderf(80);  // Turn right 80°
            pro.write(rec);
            detectardistancias(0);
            avanzarhasta(40);  // Move forward until 40cm
            giroizqf(70);      // Turn left 70°
            carril = 3;
        }

        // Even lanes (0, 2, etc.) except 0
        if(carril % 2 == 0 && carril != 0) {
            if(di > 25) {
                rectderecha(55, 0);  // Correct right to maintain 55cm
            }
            if(di < 25 && d > 100) {
                rectizquierda(16, 0);  // Correct left to maintain 16cm
            }
            else {
                rectificadosolo(0);     // Drive straight
            }
            Serial.println("Izquierda");
        }

        // Odd lanes (1, 3, etc.)
        if(carril % 2 == 1) {
            rectderecha(23, 0);  // Correct right to maintain 23cm
            Serial.println("Izquierda");
        }

        // Lane 0
        if(carril == 0) {
            rectderecha(40, 0);  // Correct right to maintain 40cm
            Serial.println("Izquierda");
        }

        // No cone detected
        if(bloque == 0) {
            rectderecha(40, 0);  // Correct right to maintain 40cm
            Serial.println("Izquierda");
        }

        // Green cone in lane 0
        if(bloque == 2 && carril == 0) {
            if(listo == 0) {
                giroizqf(45);  // Turn left 45°
                pro.write(rec);
                delay(200);
                giroderf(45);  // Turn right 45°
                listo = 1;
            }
            Serial.println("Izquierda");
            carril = 2;
        }

        // Green cone in lane 1
        if(bloque == 2 && carril == 1) {
            giroizqf(80);  // Turn left 80°
            pro.write(rec);
            avanzarhasta(40);  // Move forward until 40cm
            giroderf(80);     // Turn right 80°
            listo = 1;
            carril = 4;
        }
    }
}

// Function to turn left with angle correction
void giroizqf(int cantidad) {
    int error = 0;
    int kp = 1;  
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro + cantidad; // Target angle
    
    while(abs(error) > 2) {
        mpu.update();
        gyro = mpu.getAngleZ();
        error = gyro - angulof;
        int ajuste = constrain(error * kp, -25, 25); // Limit adjustment
        pro.write(rec - ajuste); // Apply correction
        
        Serial.println("Girando Izquierda");
        Serial.println("Ángulo actual: " + String(gyro));
        Serial.println("Error: " + String(error));
        Serial.println("Objetivo: " + String(angulof));
    }
    
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro;
    pro.write(rec); // Stop after correction
    
    Serial.println("Finalizó el giro hacia la izquierda");
    Serial.print("gyro");
    Serial.println(gyro);
    Serial.print("angulof");
    Serial.println(angulof);
}

// Function to turn right with angle correction
void giroderf(int cantidad) {
    int error = 0;
    int kp = 1;  
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro - cantidad; // Target angle
    
    while(abs(error) > 2) {
        mpu.update();
        gyro = mpu.getAngleZ();
        error = angulof - gyro;
        int ajuste = constrain(error * kp, -25, 25); // Limit adjustment
        pro.write(rec + ajuste); // Apply correction
        
        Serial.println("Girando Derecha");
        Serial.println("Ángulo actual: " + String(gyro));
        Serial.println("Error: " + String(error));
        Serial.println("Objetivo: " + String(angulof));
    }
    
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro;
    pro.write(rec); // Stop after correction
    
    Serial.println("Finalizó el giro hacia la derecha");
    Serial.print("gyro");
    Serial.println(gyro);
    Serial.print("angulof");
    Serial.println(angulof);
}

// Function to turn left while moving backward
void giroizqatras(int cantidad) {
    retroceder(); // Move backward
    int error = 0;
    int kp = 2;  
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro + cantidad; // Target angle
    
    while(abs(error) > 5 || gyro < angulof - 5) {
        mpu.update();
        gyro = mpu.getAngleZ();
        error = gyro - angulof;
        int ajuste = constrain(error * kp, -25, 25); // Limit adjustment
        pro.write(rec + ajuste); // Apply correction
        
        Serial.println("Girando Izquierda");
        Serial.println("Ángulo actual: " + String(gyro));
        Serial.println("Error: " + String(error));
        Serial.println("Objetivo: " + String(angulof));
    }
    
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro;
    pro.write(rec); // Stop after correction
    
    Serial.println("Finalizó el giro hacia la izquierda");
    Serial.print("gyro");
    Serial.println(gyro);
    Serial.print("angulof");
    Serial.println(angulof);
}

// Function to turn right while moving backward
void giroderatras(int cantidad) {
    retroceder(); // Move backward
    int error = 0;
    int kp = 2;  
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro - cantidad; // Target angle
    
    while(abs(error) > 5 || gyro > angulof + 5) {
        mpu.update();
        gyro = mpu.getAngleZ();
        error = angulof - gyro;
        int ajuste = constrain(error * kp, -25, 25); // Limit adjustment
        pro.write(rec - ajuste); // Apply correction
        
        Serial.println("Girando Derecha");
        Serial.println("Ángulo actual: " + String(gyro));
        Serial.println("Error: " + String(error));
        Serial.println("Objetivo: " + String(angulof));
    }
    
    mpu.update();
    gyro = mpu.getAngleZ();
    angulof = gyro;
    pro.write(rec); // Stop after correction
    
    Serial.println("Finalizó el giro hacia la derecha");
    Serial.print("gyro");
    Serial.println(gyro);
    Serial.print("angulof");
    Serial.println(angulof);
}