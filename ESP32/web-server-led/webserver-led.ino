#include <WiFi.h>
#include <WebServer.h>

// Pon aquí el nombre y contraseña de tu Wi-Fi de casa
// const char* ssid = "GABRIELA";
// const char* password = "3163098801";

const char* ssid = "soyCampusLands";
const char* password = "transformandovidas";


// Creamos el servidor web en el puerto 80 (el puerto estándar de internet)
WebServer server(80);

// Definimos el pin donde conectamos el LED
const int pinLED = 2;

void setup() {
  Serial.begin(115200);
  
  // Configuramos el pin del LED como salida
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW); // Empezamos con el LED apagado

  // Iniciamos la conexión a tu Wi-Fi
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Esperamos a que se conecte
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Si se conecta, mostramos la dirección IP en el monitor serie
  Serial.println("");
  Serial.println("¡Wi-Fi conectado!");
  Serial.print("Dirección IP del ESP32: ");
  Serial.println(WiFi.localIP());

  // Definimos qué pasa cuando entramos a las direcciones del navegador
  server.on("/encender", []() {
    digitalWrite(pinLED, HIGH); // Enciende el LED
    server.send(200, "text/plain", "El LED esta ENCENDIDO");
  });

  server.on("/apagar", []() {
    digitalWrite(pinLED, LOW); // Apaga el LED
    server.send(200, "text/plain", "El LED esta APAGADO");
  });

  // Iniciamos el servidor
  server.begin();
  Serial.println("Servidor web iniciado");
}

void loop() {
  // Le decimos al ESP32 que se quede escuchando las peticiones del navegador
  server.handleClient();
}
