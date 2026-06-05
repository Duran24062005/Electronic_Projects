# ESP32

ESP32 es una familia de microcontroladores y sistemas en chip de bajo costo y
bajo consumo creados por Espressif Systems. Es conocida por integrar
conectividad Wi-Fi y Bluetooth, lo que la hace muy usada en proyectos de
Internet de las Cosas, automatizacion, monitoreo y control remoto.

## Origen

ESP32 fue desarrollado por Espressif Systems como sucesor del ESP8266. La
familia ESP32 se popularizo por ofrecer mas potencia, mas pines, mejor soporte
de perifericos y conectividad inalambrica integrada en placas accesibles para
prototipado y produccion.

## Para que sirve

ESP32 permite crear dispositivos que leen sensores, controlan actuadores y se
comunican con otros sistemas por red. Es util cuando un proyecto necesita
electronica embebida con conectividad.

Usos comunes:

- Sensores conectados a Wi-Fi.
- Automatizacion del hogar o de laboratorios.
- Envio de datos a APIs, servidores o dashboards.
- Control remoto de luces, motores, reles o alarmas.
- Proyectos con Bluetooth o BLE.
- Prototipos de IoT, telemetria y monitoreo ambiental.

## Fundamentos

Conceptos importantes al trabajar con ESP32:

- GPIO: pines digitales para leer o escribir estados.
- ADC: lectura de senales analogicas desde sensores.
- PWM: control de brillo, velocidad o intensidad mediante pulsos.
- I2C, SPI y UART: protocolos para comunicarse con sensores, pantallas y otros
  modulos.
- Wi-Fi: conexion a redes locales, APIs HTTP, MQTT o servidores propios.
- Bluetooth/BLE: comunicacion inalambrica de corto alcance.
- Deep sleep: modo de bajo consumo para proyectos alimentados por bateria.
- FreeRTOS: base de tareas concurrentes usada por el ecosistema ESP32.

## Herramientas habituales

- Arduino IDE con soporte para placas ESP32.
- ESP-IDF, el framework oficial de Espressif.
- PlatformIO para proyectos mas estructurados.
- Monitor serial para depurar mensajes y estados.
- Librerias de red como Wi-Fi, HTTPClient o MQTT segun el entorno usado.

## Organizacion recomendada

Esta carpeta puede contener firmware real para ESP32 y tambien codigo auxiliar
para simular o probar comunicacion con servicios externos. Cuando un archivo no
se ejecute directamente en la placa, debe indicarse en su documentacion o en sus
comentarios principales.

Ejemplos de separacion util:

- `firmware/`: codigo que se compila y carga en una placa ESP32.
- `tools/`: scripts o programas auxiliares para pruebas desde el computador.
- `docs/`: diagramas de conexion, endpoints, protocolos o reglas de operacion.

## Buenas practicas

- Documentar la placa exacta usada y sus pines disponibles.
- Evitar conectar perifericos sin revisar voltaje y corriente.
- Separar credenciales de red del codigo fuente.
- Definir claramente si la comunicacion usa HTTP, MQTT, WebSocket u otro
  protocolo.
- Probar sensores y actuadores por separado antes de integrar la solucion.
- Registrar dependencias, librerias y version del framework usado.
