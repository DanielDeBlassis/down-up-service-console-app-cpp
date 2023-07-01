#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include <chrono> //Simular salida
#include <thread> //Simular salida

// Mis recursos
#include "colores.h"
#include "funciones.h"

// std:: namespace global
using namespace std;

/**
 * @brief Imprimir línea
 *
 * Imprime una línea con caracteres de relleno y color personalizados.
 *
 * @param ancho     Ancho de la línea.
 * @param caracter  Carácter de relleno de la línea.
 * @param color     Color de la línea.
 */
void imprimirLinea(int ancho, char caracter, string color)
{
    // Rellenar una línea con el carácter del menú
    string linea(ancho, caracter);

    cout << color << linea << RESET << endl;
}

/**
 *
 * @brief Imprimir menú
 *
 */
void imprimirMenu()
{
    int ancho = 40;      // Ancho del menú
    int centro = 25;     // Centro
    char caracter = '='; // Carácter del menú

    // Imprimir línea superior del menú
    imprimirLinea(ancho, caracter, LIGHT_MAGENTA);

    cout << setw(centro) << "MENÚ" << endl;

    // Imprimir línea intermedia del menú
    imprimirLinea(ancho, caracter, LIGHT_MAGENTA);

    // Imprimir contenido del menú
    cout << GREEN << " (1) " << LIGHT_CYAN << "Reiniciar Bluetooth" << endl;
    cout << GREEN << " (2) " << LIGHT_CYAN << "Reiniciar Wi-Fi" << endl;
    cout << GREEN << " (3) " << LIGHT_CYAN << "Reiniciar Explorador" << endl;
    cout << GREEN << " (4) " << LIGHT_CYAN << "Salir" << RESET << endl;

    // Imprimir línea inferior del menú
    imprimirLinea(ancho, caracter, LIGHT_MAGENTA);
}

/**
 * @brief Imprimir mensaje de error
 *
 * Personaliza mensaje de error al pasarlo por parámetro.
 *
 * @param mensaje Mensaje a imprimir.
 *
 */
void imprimirMsjError(string mensaje)
{
    int ancho = 40;      // Ancho del menú
    int centro = 25;     // Centro
    char caracter = '='; // Carácter del menú

    // Imprimir línea superior del menú
    imprimirLinea(ancho, caracter, RED);

    cout << RED << setw(centro) << "ERROR!" << RESET << endl;

    // Imprimir línea intermedia del menú
    imprimirLinea(ancho, caracter, RED);

    cout << RED << mensaje << RESET << endl;

    // Imprimir línea intermedia del menú
    imprimirLinea(ancho, caracter, RED);
}

/**
 * @brief Tiempo de espera
 *
 * Genera un período de espera personalizable manteniendo al usuario informado.
 *
 * @param tiempo        Retraso en milisegundos.
 * @param repeticiones  Veces que se repetirá el proceso de impresión del mensaje.
 * @param numeroPuntos  Veces que se repetirán los puntos suspensivos.
 * @param mensaje       Mensaje a imprimir en pantalla.
 * @param colorMensaje  Color del mensaje a imprimir.
 */
void tiempoEspera(int tiempo, int repeticiones, int numeroPuntos, string mensaje, string colorMensaje)
{

    // Se declaran constantes
    const int numPuntosSuspensivos = numeroPuntos;
    const int numRepeticiones = repeticiones;
    const int retrasoMilisegundos = tiempo;

    for (int j = 0; j < numRepeticiones; ++j)
    {

        cout << colorMensaje << mensaje;
        cout.flush(); // Asegurar que el texto se imprima de inmediato

        for (int i = 0; i < numPuntosSuspensivos; ++i)
        {
            this_thread::sleep_for(chrono::milliseconds(retrasoMilisegundos));
            cout << ".";
            cout.flush(); // Asegurar que el punto se imprima de inmediato
        }

        // Volver al inicio de la línea utilizando secuencias de escape ANSI
        cout << RESET << "\r";
        cout.flush();
    }

    cout << endl; // Saltar una línea después de los puntos suspensivos
}

/**
 *
 * @brief Reinicia servicio bluetooth.
 *
 * Opción 1 del menú.
 * 
 */
void reiniciarBluetooth()
{
    try
    {
        // Ejecuta comando para reiniciar el servicio bluetooth
        system("net stop bthserv");
        // tiempoEspera(500, 5, 4, "Reiniciando servicio bluetooth", GREEN);
        system("net start bthserv");
        cout << GREEN << "Servicio Bluetooth reiniciado exitosamente." << RESET << endl;
    }
    catch (const int error)
    {
        imprimirMsjError("Error al detener servicio bluetooth");
    }
}

/**
 *
 * @brief Reinicia servicio Wi-Fi.
 *
 * Opción 2 del menú.
 * 
 */
void reiniciarWiFi()
{
    try
    {
        // // Ejecuta comando para reiniciar el servicio wifi
        system("netsh interface set interface 'Wi-Fi' admin=disable");
        // tiempoEspera(500, 5, 4, "Reiniciando servicio Wi-Fi", GREEN);
        system("netsh interface set interface 'Wi-Fi' admin=enable");
        cout << GREEN << "Servicio Wi-Fi reiniciado exitosamente." << RESET << endl;
    }
    catch (const int error)
    {
        imprimirMsjError("Error al detener servicio Wi-Fi");
    }
}

/**
 *
 * @brief Reinicia servicio explorer.
 *
 * Opción 3 del menú.
 * 
 */
void reiniciarExplorer()
{
    try
    {
        // // Ejecuta el comando para reiniciar el servicio explorer.exe
        system("taskkill /f /im explorer.exe");
        // tiempoEspera(500, 5, 2, "Reiniciando servicio explorer.exe", GREEN);
        system("start explorer.exe");
        cout << GREEN << "Servicio Explorer reiniciado exitosamente." << RESET << endl;
    }
    catch (const int error)
    {
        imprimirMsjError("Error al detener servicio explorer");
    }
}
