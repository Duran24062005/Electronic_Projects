# ESP32 web server LED

Este ejemplo levanta un servidor HTTP en el ESP32 para encender y apagar el LED
del pin 2. Las credenciales Wi-Fi no deben quedar en el codigo fuente.

## Credenciales Wi-Fi

El firmware no puede leer variables de entorno del computador en tiempo de
ejecucion. Por eso, `web-server-led.ino` espera que el SSID y la contrasena se
inyecten en compilacion como macros:

- `WIFI_SSID`
- `WIFI_PASSWORD`

Las variables locales recomendadas son:

```sh
export ESP32_WIFI_SSID="nombre-de-la-red"
export ESP32_WIFI_PASSWORD="contrasena-de-la-red"
```

Con Arduino CLI, compila pasando esas variables como flags:

```sh
arduino-cli compile --fqbn esp32:esp32:esp32 ESP32/web-server-led \
  --build-property "compiler.cpp.extra_flags=-DWIFI_SSID=\\\"${ESP32_WIFI_SSID}\\\" -DWIFI_PASSWORD=\\\"${ESP32_WIFI_PASSWORD}\\\""
```

Si usas un archivo `.env` local, mantenlo fuera de Git y cargalo antes de
compilar:

```sh
set -a
. ESP32/web-server-led/.env
set +a
```

El archivo `.env.example` solo documenta los nombres esperados y no debe tener
credenciales reales.
