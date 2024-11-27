// Ejemplo básico de servidor web con la cámara
#include "esp_camera.h"
#include <WiFi.h>

const char* ssid = "TuRedWiFi";
const char* password = "TuContraseña";

void startCameraServer();

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("WiFi fallo");
        return;
    }
    startCameraServer();
}

void loop() {
    delay(10000);
}
