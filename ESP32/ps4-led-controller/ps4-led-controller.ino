#include <PS4Controller.h>

// Definir el pin del LED azul (en la mayoría de ESP32 es el pin 2)
#define LED_PIN 2

void setup() {
  Serial.begin(115200);

  // Configurar el pin del LED como salida
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Iniciar apagado

  // Iniciar la conexión Bluetooth con una dirección MAC simulada
  // NOTA: Reemplaza esta MAC por la dirección MAC real de tu ESP32 si es necesario
  PS4.begin("01:02:03:04:05:06"); 
  
  Serial.println("ESP32 listo. Esperando conexión del control de PS4...");
}

void loop() {
  // Verificar si el control de PS4 está conectado al ESP32
  if (PS4.isConnected()) {
    
    // Si presionas el botón Cruz (X), enciende el LED azul
    if (PS4.Cross()) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Botón Cruz presionado -> LED ENCENDIDO");
    } 
    // Si dejas de presionarlo, el LED se apaga
    else {
      digitalWrite(LED_PIN, LOW);
    }

  }
  
  // Pequeña pausa para no saturar el procesador
  delay(10);
}


/*
Pasos clave para que funcione la conexión Bluetooth
Para que el control de PS4 se conecte al ESP32, ambos deben compartir la misma dirección física (MAC address).
Sigue estos pasos:
  1. Obtén la MAC del ESP32: Sube un código vacío que solo 
  imprima WiFi.macAddress(); en el monitor serie para conocer la 
  dirección MAC real de tu placa ESP32.
  
  2. Configura el control de PS4: Descarga en tu computadora un 
  programa gratuito llamado SixaxisPairTool (para Windows). 
  Conecta tu control de PS4 a la PC con un cable USB, abre el programa y escribe 
  la dirección MAC de tu ESP32 en el cuadro de texto. Haz clic en "Update".
  
  3. ¡A conectar!: Desconecta el mando de la PC. Enciende tu ESP32 con el 
  código de arriba cargado. Presiona el botón PS del control. La luz del 
  mando parpadeará y luego se quedará fija de un color. ¡Eso significa 
  que ya está conectado!

  https://forum.arduino.cc/t/conectar-mando-ps4-a-esp32-por-bluetooth/1159614
*/