// Guardar el tiempo de la última vez que se ejecutó cada tarea
unsigned long tiempoTarea1 = 0;
unsigned long tiempoTarea2 = 0;

// Intervalos de tiempo para cada tarea (en milisegundos)
const unsigned long intervaloTarea1 = 1000; // Ejecutar cada 1 segundo (1000 ms)
const unsigned long intervaloTarea2 = 500;  // Ejecutar cada medio segundo (500 ms)

void setup() {
  // Inicialización de la comunicación serie a 9600 baudios
  Serial.begin(9600);
  
  // Configuración del pin del LED integrado como salida
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Obtener el reloj global del sistema en este instante
  unsigned long tiempoActual = millis(); 

  // PLANIFICADOR: Evalúa si es momento de ejecutar la Tarea 1
  if (tiempoActual - tiempoTarea1 >= intervaloTarea1) {
    tiempoTarea1 = tiempoActual;
    ejecutarTarea1();
  }

  // PLANIFICADOR: Evalúa si es momento de ejecutar la Tarea 2
  if (tiempoActual - tiempoTarea2 >= intervaloTarea2) {
    tiempoTarea2 = tiempoActual;
    ejecutarTarea2();
  }
}

// Tarea 1: Alternar el estado físico del LED integrado (Parpadeo)
void ejecutarTarea1() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

// Tarea 2: Transmitir telemetría básica a través del puerto serie
void ejecutarTarea2() {
  Serial.println("Hola desde la Tarea 2 del Sistema Operativo");
}