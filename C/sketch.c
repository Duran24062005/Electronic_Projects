#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <curl/curl.h>

void* enviarDatos(void* arg) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    int numero = 1;

    while (1) {
        curl = curl_easy_init();

        if (curl) {
            const char* url = "http://localhost:3000/send";

            char jsonPayload[64];
            snprintf(
                jsonPayload,
                sizeof(jsonPayload),
                "{\"number\": %d}",
                numero
            );

            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload);

            struct curl_slist* headers = NULL;
            headers = curl_slist_append(
                headers,
                "Content-Type: application/json"
            );

            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                fprintf(
                    stderr,
                    "Error enviando dato: %s\n",
                    curl_easy_strerror(res)
                );
            } else {
                printf(
                    "Enviado exitosamente: %s\n",
                    jsonPayload
                );
            }

            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }

        numero++;

        if (numero > 100) {
            numero = 1;
        }

        sleep(1);
    }

    curl_global_cleanup();

    return NULL;
}

int main() {
    printf("Iniciando emisor...\n");

    pthread_t emisor;

    if (pthread_create(
            &emisor,
            NULL,
            enviarDatos,
            NULL
        ) != 0) {
        perror("Error creando hilo");
        return 1;
    }

    pthread_join(emisor, NULL);

    return 0;
}
