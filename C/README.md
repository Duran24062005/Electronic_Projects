# C

C es un lenguaje de programacion de proposito general, compilado y cercano al
hardware. Es conocido por su eficiencia, control de memoria y uso extendido en
sistemas operativos, compiladores, controladores, firmware y software donde el
rendimiento es importante.

## Origen

C fue creado a comienzos de la decada de 1970 por Dennis Ritchie en Bell Labs.
Nacio como evolucion del lenguaje B y fue usado para reescribir gran parte del
sistema operativo Unix, lo que ayudo a convertirlo en uno de los lenguajes mas
influyentes de la historia de la computacion.

## Para que sirve

C se utiliza cuando se necesita control fino sobre recursos del sistema,
memoria, rendimiento o comunicacion directa con hardware.

Usos comunes:

- Sistemas operativos y utilidades de bajo nivel.
- Firmware y sistemas embebidos.
- Controladores de dispositivos.
- Bibliotecas de alto rendimiento.
- Herramientas de consola y software de infraestructura.
- Bases para aprender arquitectura de computadores y gestion de memoria.

## Fundamentos

Los conceptos principales de C incluyen:

- Tipos de datos: `int`, `char`, `float`, `double`, arreglos y estructuras.
- Variables y constantes: permiten almacenar datos durante la ejecucion.
- Control de flujo: `if`, `else`, `switch`, `for`, `while` y `do while`.
- Funciones: dividen el programa en bloques reutilizables.
- Punteros: almacenan direcciones de memoria y permiten trabajar directamente
  con datos, arreglos y estructuras.
- Memoria manual: funciones como `malloc`, `calloc`, `realloc` y `free`
  permiten reservar y liberar memoria dinamica.
- Archivos de cabecera: los `.h` declaran funciones, constantes, tipos y
  estructuras compartidas.

## Flujo de compilacion

Un programa en C normalmente pasa por estas etapas:

1. Preprocesado: resuelve directivas como `#include` y `#define`.
2. Compilacion: traduce el codigo fuente a codigo objeto.
3. Enlazado: une objetos y bibliotecas para crear el ejecutable final.

Ejemplo con `gcc`:

```bash
gcc sketch.c -o sketch
./sketch
```

## Buenas practicas

- Inicializar variables antes de usarlas.
- Liberar toda memoria reservada dinamicamente.
- Validar punteros antes de desreferenciarlos.
- Separar declaraciones en archivos `.h` e implementaciones en archivos `.c`
  cuando el programa crezca.
- Compilar con advertencias activas, por ejemplo `-Wall -Wextra`.
