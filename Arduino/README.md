# Arduino

Arduino es una plataforma de hardware y software libre orientada a la creacion
de prototipos electronicos. Combina placas con microcontroladores, un entorno
de desarrollo sencillo y una comunidad amplia de librerias, ejemplos y
componentes compatibles.

## Origen

Arduino nacio alrededor de 2005 en el Interaction Design Institute Ivrea, en
Italia. Fue impulsado por Massimo Banzi, David Cuartielles, Tom Igoe,
Gianluca Martino y David Mellis como una forma accesible de ensenar
electronica, programacion y prototipado interactivo.

## Para que sirve

Arduino se usa para construir proyectos que conectan software con el mundo
fisico. Permite leer sensores, controlar motores, encender luces, comunicarse
por puerto serial, automatizar procesos simples y crear prototipos de Internet
de las Cosas.

Algunos usos comunes son:

- Medicion de temperatura, humedad, luz, distancia o movimiento.
- Control de LEDs, pantallas, servomotores, reles y motores DC.
- Automatizacion domestica o educativa.
- Prototipos de robots y sistemas embebidos basicos.
- Practicas de electronica, control y programacion.

## Fundamentos

Un programa de Arduino normalmente se llama sketch y se escribe con una sintaxis
basada en C/C++. Todo sketch suele tener dos funciones principales:

- `setup()`: se ejecuta una sola vez al iniciar la placa. Sirve para configurar
  pines, comunicacion serial, sensores o librerias.
- `loop()`: se ejecuta continuamente mientras la placa este encendida. Aqui se
  coloca la logica principal del proyecto.

Conceptos importantes:

- Pines digitales: trabajan con estados `HIGH` y `LOW`.
- Pines analogicos: permiten leer valores variables desde sensores.
- PWM: simula salidas analogicas mediante pulsos digitales.
- Serial: permite comunicar la placa con el computador u otros dispositivos.
- Librerias: agregan soporte para sensores, pantallas, motores y protocolos.

## Herramientas habituales

- Arduino IDE o Arduino CLI.
- Placas como Arduino Uno, Nano, Mega o compatibles.
- Cable USB para programar y alimentar la placa.
- Protoboard, resistencias, LEDs, sensores y actuadores.

## Buenas practicas

- Revisar voltajes y corriente antes de conectar componentes.
- Usar resistencias cuando sean necesarias, por ejemplo con LEDs.
- Separar la configuracion inicial de la logica repetitiva.
- Documentar la placa usada, librerias requeridas y conexiones fisicas.
- Probar los componentes por separado antes de integrarlos en un circuito mayor.
