#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <string>

// Mis recursos
#include "funciones.h"
#include "colores.h"


// std:: namespace global
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	// Variables locales
    int opcion;
    string entrada;
    bool salir = false;

    while (!salir)
    {

        // Variable mensaje
        string mensaje = "";

        // Imprime menú
        imprimirMenu();

        // Pide datos al usuario
        cout << YELLOW << "Ingrese el número de opción a ejecutar: " << RESET << endl;
        getline(cin, entrada); // Se utiliza std::getline para obtener la entrada del usuario como una cadena de texto en la variable entrada.

        try
        {
            opcion = stoi(entrada); // Se utiliza std::stoi para convertir esa cadena en un número entero en la variable opcion.

            switch (opcion)
            {
            case 1:
                // La opción es válida, hacer algo...
                cout << "Ha seleccionado la opción " << opcion << endl;
                reiniciarBluetooth();
                break;

            case 2:
                // La opción es válida, hacer algo...
                cout << "Ha seleccionado la opción " << opcion << endl;
                reiniciarWiFi();
                break;

            case 3:
                // La opción es válida, hacer algo...
                cout << "Ha seleccionado la opción " << opcion << endl;
                reiniciarExplorer();
                break;

            case 4:
                // La opción es válida, hacer algo...
                cout << "Ha seleccionado la opción " << opcion << endl;

                mensaje = "Saliendo";
                tiempoEspera(500, 3, 3, mensaje, RED);
                
                salir = true;
                break;

            default:
                // La opción no está en el rango válido
                mensaje = "Opción inválida. Por favor, ingrese un número entre 1 y 4.";
                imprimirMsjError(mensaje);
                break;
            }
        }
        catch (invalid_argument const &e)
        {
            // La entrada no es un número entero válido
            string mensaje = "Entrada inválida.\nPor favor, ingrese un número entero.";
            imprimirMsjError(mensaje);
        }
    }

    return 0;
}