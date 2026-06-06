void setup() {
  // Inicialización de puerto serie a alta velocidad
  Serial.begin(115200);

  // Crear Tarea 1 y asignarla específicamente al Núcleo 0 del ESP32
  xTaskCreatePinnedToCore(
    Task1Code,          // Función que contiene el código de la tarea
    "Tarea_Uno",        // Nombre identificativo de la tarea (para depuración)
    10000,              // Tamaño de la pila (Stack size en palabras)
    NULL,               // Parámetros de entrada para la tarea
    1,                  // Prioridad de la tarea (valores más altos = mayor prioridad)
    NULL,               // Descriptor/Rastreador de la tarea
    0                   // Núcleo del hardware asignado (0 o 1)
  );
}

void loop() {
  // El bucle loop() corre por defecto en el Núcleo 1.
  // Podemos dejarlo vacío o usarlo para otras tareas menores, 
  // ya que FreeRTOS se encarga de gestionar el Núcleo 0 en segundo plano.
}

// Implementación de la Tarea 1
void Task1Code( void * pvParameters ){
  // Las tareas en sistemas operativos embebidos no deben terminar nunca (bucle infinito)
  for(;;){
    Serial.println("Tarea ejecutándose en un núcleo independiente gracias a FreeRTOS");
    
    // Pausa la tarea de forma eficiente sin bloquear el procesador principal.
    // Esto permite que el planificador ejecute otras tareas mientras transcurre el tiempo.
    vTaskDelay(2000 / portTICK_PERIOD_MS); 
  }
}
