#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <curl/curl.h>

void enviarDatos() {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    int numero = 1;

    while (true) {
        curl = curl_easy_init();

        if (curl) {
            // 1. La URL debe ser estática hacia tu endpoint POST
            std::string url = "http://localhost:3000/send";

            // 2. Construir el cuerpo en formato JSON {"number": X}
            std::string jsonPayload = "{\"number\": " + std::to_string(numero) + "}";

            // Configurar la URL
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            // 3. Forzar a libcurl a realizar una petición POST
            curl_easy_setopt(curl, CURLOPT_POST, 1L);

            // 4. Pasar el JSON al cuerpo de la petición
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload.c_str());

            // 5. Configurar las cabeceras obligatorias (Content-Type: application/json)
            struct curl_slist* headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            // Configurar redirecciones automáticas si fueran necesarias
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

            // Ejecutar la petición
            res = curl_easy_perform(curl);

            // Validar errores
            if (res != CURLE_OK) {
                std::cerr << "Error enviando dato: "
                          << curl_easy_strerror(res)
                          << std::endl;
            } else {
                std::cout << "Enviado exitosamente: " << jsonPayload << std::endl;
            }

            // 6. Limpiar memoria local de esta iteración
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }

        numero++;

        if (numero > 100) {
            numero = 1;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    curl_global_cleanup();
}

int main() {
    std::cout << "Iniciando emisor..." << std::endl;

    std::thread emisor(enviarDatos);

    emisor.join();

    return 0;
}
