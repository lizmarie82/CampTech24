#include <ESP32Servo.h>

// Definición de pines
const int trigPin = 5;    // GPIO 12 para Trigger
const int echoPin = 18;    // GPIO 13 para Echo
const int servoPin = 2;    // GPIO 2 para el Servo

// Crear objeto servo
Servo miServo;

void setup() {
  Serial.begin(115200);
  
  // Configurar pines del sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Configurar el servo
  miServo.attach(servoPin);
  
  // Posición inicial
  miServo.write(0);
  
  Serial.println("Iniciado");
}

void loop() {
  // Medir distancia
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Calcular distancia
  long duracion = pulseIn(echoPin, HIGH);
  float distancia = duracion * 0.034 / 2;
  
  Serial.print("Distancia: ");
  Serial.println(distancia);
  
  // Control del servo
  if (distancia <= 10 && distancia > 0) {
    miServo.write(180);
    Serial.println("Objeto detectado");
  } else {
    miServo.write(0);
  }
  
  delay(1000);
}