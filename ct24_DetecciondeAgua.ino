// Definición del pin para el sensor
const int sensorPin = 13;    // GPIO 13 para el sensor analógico
const int ledPin = 12;       // GPIO 12 para LED indicador

// Umbral para detectar agua
const int umbralAgua = 1000;  // Ajusta este valor según la sensibilidad deseada

void setup() {
  // Inicializar comunicación serial
  Serial.begin(115200);
  
  // Configurar pines
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  
  Serial.println("Detector de agua iniciado");
}

void loop() {
  // Leer el valor del sensor
  int valorSensor = analogRead(sensorPin);
  
  // Verificar si hay agua
  if (valorSensor > umbralAgua) {
    digitalWrite(ledPin, HIGH);  // Encender LED
    Serial.println("¡Agua detectada!");
  } else {
    digitalWrite(ledPin, LOW);   // Apagar LED
    Serial.println("No hay agua");
  }
  
  delay(1000);  // Esperar 1 segundo antes de la siguiente lectura
}