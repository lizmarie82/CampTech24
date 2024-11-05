// Pines donde están conectados los LEDs
const int redLedPin = 5;    // GPIO 5 - LED rojo
const int yellowLedPin = 2; // GPIO 2 - LED amarillo
const int greenLedPin = 4;  // GPIO 4 - LED verde

void setup() {
  // Inicializa el Monitor Serial a 115200 baudios
  Serial.begin(115200);

  // Configura los pines de los LEDs como salida
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  Serial.println("Iniciando secuencia de semáforo...");
}

void loop() {
  // Secuencia de semáforo
  digitalWrite(greenLedPin, HIGH);  // Enciende el LED verde
  delay(5000);                      // Mantén el verde encendido por 5 segundos
  digitalWrite(greenLedPin, LOW);   // Apaga el LED verde

  digitalWrite(yellowLedPin, HIGH); // Enciende el LED amarillo
  delay(5000);                      // Mantén el amarillo encendido por 5 segundos
  digitalWrite(yellowLedPin, LOW);  // Apaga el LED amarillo

  digitalWrite(redLedPin, HIGH);    // Enciende el LED rojo
  delay(5000);                      // Mantén el rojo encendido por 5 segundos
  digitalWrite(redLedPin, LOW);     // Apaga el LED rojo
}
