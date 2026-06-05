# C++

C++ es un lenguaje de programacion compilado, de alto rendimiento y
multiparadigma. Permite programacion procedural, orientada a objetos, generica
y, en versiones modernas, estilos funcionales y concurrentes. Se usa cuando se
necesita eficiencia, control y abstracciones potentes.

## Origen

C++ fue creado por Bjarne Stroustrup en Bell Labs. El trabajo comenzo en 1979
como "C with Classes" y el nombre C++ se adopto en 1983. Su objetivo fue
conservar la eficiencia y cercania al hardware de C, agregando mecanismos de
abstraccion como clases, objetos y sobrecarga de operadores.

## Para que sirve

C++ se usa en sistemas donde importan el rendimiento, la gestion explicita de
recursos y la posibilidad de construir abstracciones sin perder eficiencia.

Usos comunes:

- Videojuegos y motores graficos.
- Sistemas embebidos y aplicaciones de tiempo real.
- Software de escritorio de alto rendimiento.
- Simuladores, computacion cientifica y procesamiento intensivo.
- Navegadores, bases de datos, compiladores y herramientas de infraestructura.
- Bibliotecas donde el rendimiento y la portabilidad son importantes.

## Fundamentos

Conceptos clave de C++:

- Sintaxis base heredada de C: variables, funciones, estructuras y control de
  flujo.
- Clases y objetos: agrupan datos y comportamiento.
- Encapsulamiento: controla el acceso a datos mediante `public`, `private` y
  `protected`.
- Herencia y polimorfismo: permiten reutilizar interfaces y comportamientos.
- Constructores y destructores: administran el ciclo de vida de los objetos.
- RAII: tecnica para asociar recursos al tiempo de vida de objetos y evitar
  fugas de memoria o recursos.
- Referencias y punteros: permiten trabajar con datos sin copiarlos
  innecesariamente.
- Plantillas: habilitan programacion generica.
- STL: biblioteca estandar con contenedores como `vector`, `map` y `set`, ademas
  de algoritmos reutilizables.

## C++ moderno

Las versiones modernas del lenguaje, como C++11, C++14, C++17, C++20 y C++23,
agregan herramientas para escribir codigo mas seguro y expresivo:

- `auto` para inferencia de tipos.
- `nullptr` para punteros nulos.
- Smart pointers como `std::unique_ptr` y `std::shared_ptr`.
- Lambdas para funciones anonimas.
- `constexpr` para calculos en tiempo de compilacion.
- Ranges, conceptos y mejoras de concurrencia en versiones recientes.

## Flujo de compilacion

Ejemplo con `g++`:

```bash
g++ sketch.cpp -std=c++17 -Wall -Wextra -o sketch
./sketch
```

## Buenas practicas

- Preferir objetos con ciclo de vida claro en lugar de memoria manual.
- Usar contenedores de la STL antes de crear estructuras propias.
- Evitar punteros crudos cuando `std::unique_ptr`, `std::shared_ptr` o
  referencias expresan mejor la propiedad.
- Compilar con advertencias activas.
- Mantener interfaces simples y separar responsabilidades en clases o funciones
  pequenas.
