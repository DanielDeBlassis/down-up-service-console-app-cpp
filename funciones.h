#ifndef FUNCIONES_H
#define FUNCIONES_H

// std:: namespace global
using namespace std;

// Prototipos de función
void imprimirLinea(int, char, string);
void imprimirMenu();
void imprimirMsjError(string);
void tiempoEspera(int tiempo, int repeticiones, int numeroPuntos, string mensaje, string colorMensaje);
void reiniciarBluetooth();
void reiniciarExplorer();
void reiniciarWiFi();

#endif