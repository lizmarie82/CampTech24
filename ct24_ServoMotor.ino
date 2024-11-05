#include <ESP32Servo.h>

// Creamos un objeto servo
Servo miServo;

// Pin GPIO donde conectaremos el servo
// Para ESP32-CAM, podemos usar el GPIO 2 que es accesible
const int servoPin = 2;

void setup() {
  // Iniciamos la comunicación serial para debug
  Serial.begin(115200);
  
  // Permitimos la asignación del canal PWM para el servo
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  
  // Configuramos el servo
  // Frecuencia estándar para servos digitales: 50Hz
  miServo.setPeriodHertz(50);
  
  // Adjuntamos el servo al pin y configuramos sus límites
  miServo.attach(servoPin, 500, 2400);
}

void loop() {
  // Movimiento a 0 grados
  Serial.println("Moviendo a 0 grados");
  miServo.write(0);
  delay(5000);  // Pausa de 5 segundos
  
  // Movimiento a 90 grados
  Serial.println("Moviendo a 90 grados");
  miServo.write(90);
  delay(5000);  // Pausa de 5 segundos
  
  // Movimiento a 180 grados
  Serial.println("Moviendo a 180 grados");
  miServo.write(180);
  delay(5000);  // Pausa de 5 segundos
}