#include <stdio.h>
#include <string.h> // Incluye la biblioteca para manipulación de cadenas


#define TL 140 // longitud máxima del texto del mensaje por SMS
#define IDir 200 // longitud máxima de texto para MMS
#define CantMensajes 100 // tabla de 100 mensajes para el buzón

// Definición de la estructura para los mensajes
struct buzon {
    char phone[10]; // Número de teléfono
    int datetime; // Fecha y hora del mensaje como un número entero
    char texto[TL]; // Texto del mensaje, máximo 140 caracteres
    char dirimage[IDir]; // Ruta  imagen, máximo 200 caracteres
    enum tipo { SMC, normal, MMS } tipoMensaje; // opciones: SMC, normal o MMS
};

int main(void) {
    struct buzon CD2[CantMensajes]; // Declara un arreglo de 100 mensajes para el buzon

    // Mensaje SMS
    strcpy(CD2[0].phone, "3128602756\t"); // número de teléfono
    CD2[0].datetime = 202409062111; // Asignacion de fecha y hora como un número entero en formato (AAAAMMDDHHMM)
    strcpy(CD2[0].texto, "Primer envio, por un mensaje SMS."); // texto menor a 140 letras
    CD2[0].tipoMensaje = normal; // Asigna el tipo de mensaje como "normal" al primer mensaje

    // Mensaje MMS
    strcpy(CD2[1].phone, "3215670096\t"); // número de teléfono
    CD2[1].datetime = 202409062112; // Asignacion de  fecha y hora como un número entero, en formato(AAAAMMDDHHMM)
    strcpy(CD2[1].texto, "Segundo envio,............................................................................................................................................................................................................................. por un mensaje MMS."); // texto menor a 200 letras
    strcpy(CD2[1].dirimage, "/ruta/a/la/imagen.jpg"); // Copia la ruta de la imagen al segundo mensaje
    CD2[1].tipoMensaje = MMS; // Asigna el tipo de mensaje como "MMS" al segundo mensaje


    printf("\tBUZON DE ENTRADA TELEFONO MOVIL\n");
    for (int i = 0; i < 2; i++) { // Itera sobre los mensajes inicializados

        switch (CD2[i].tipoMensaje) { // Verifica el tipo de mensaje

            case SMC: // Si el tipo de mensaje es SMC
                printf("SMS de numero %s: %s\n", CD2[i].phone, CD2[i].texto); // Imprime el numero celular y el texto del SMS
                break;
            case normal: // Si el tipo de mensaje es normal
                printf("Mensaje normal de numero %s: %s\n", CD2[i].phone, CD2[i].texto); // Imprime el numero celular y el texto del SMS
                break;
            case MMS: // Si el tipo de mensaje es MMS
                printf("MMS de numero %s: %s (Imagen: %s)\n", CD2[i].phone, CD2[i].texto, CD2[i].dirimage); // Imprime el numero celular, el texto y la ruta de la imagen del MMS
                break;
        }
    }

    return 0;
}
