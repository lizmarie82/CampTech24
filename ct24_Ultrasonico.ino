#define TRIG 5    // Pin para Trigger
#define ECHO 18   // Pin para Echo

void setup() {
  Serial.begin(115200);  // Iniciar el monitor serial
  pinMode(TRIG, OUTPUT); // Configurar TRIG como salida
  pinMode(ECHO, INPUT);  // Configurar ECHO como entrada
}

void loop() {
  long dur, dist;

  // Enviar pulso ultrasónico de 10 microsegundos
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Medir el tiempo que tarda en recibir el eco
  dur = pulseIn(ECHO, HIGH);

  // Calcular la distancia en centímetros
  dist = dur * 0.034 / 2; // La velocidad del sonido es aproximadamente 0.034 cm/µs

  // Imprimir la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(dist);
  Serial.println(" cm");

  delay(5000); // Esperar medio segundo antes de la siguiente lectura
}
