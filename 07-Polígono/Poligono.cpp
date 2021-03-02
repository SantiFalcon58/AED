//#if 0
#pragma once
#include "Poligono.h"
#include "Nodo.h"
#include "Punto.h"
#include <cstddef>
#include <iostream>

using namespace std;



void addVertice(Poligono& poligono, const Punto punto) {
    NodoPunto* nuevo = new NodoPunto();
    nuevo->punto = punto;

    if (poligono.primerPunto == NULL) {
        poligono.primerPunto = nuevo;
        poligono.primerPunto->siguiente = NULL;
        poligono.ultimoPunto = nuevo;
    }
    else {
        poligono.ultimoPunto->siguiente = nuevo;
        nuevo->siguiente = NULL;
        poligono.ultimoPunto = nuevo;
    }
}


void imprimir(const Poligono poligono) {
    NodoPunto* actual = new NodoPunto();
    actual = poligono.primerPunto;
    int pos = 0;
    if (poligono.primerPunto != NULL) {
        while (actual != NULL) {
                 Punto punto = actual->punto;
                 cout << "vertices[" << pos << "]: " << punto.x << "," << punto.y << "\n";

                 pos++;
            actual = actual->siguiente;
        }
    }
}


Punto getVertice(const Poligono poligono, unsigned i) {
    NodoPunto* actual = new NodoPunto();
    actual = poligono.primerPunto;
    int pos = 0;
    if (poligono.primerPunto != NULL) {
        while (actual != NULL) {
            if (pos == i) {
                return actual->punto;
            }
            else {
                pos = pos + 1;
            }
            actual = actual->siguiente;
        }
    }    
}


int getCantidadLados(const Poligono poligono) {
    NodoPunto* actual = new NodoPunto();
    actual = poligono.primerPunto;
    int amount = 0;
    if (poligono.primerPunto != NULL) {
        while (actual != NULL) {
            amount = amount + 1;
            actual = actual->siguiente;
        }
    }
    
    return amount;
}


float getPerimetro(const Poligono poligono) {
    NodoPunto* anterior = NULL;
    NodoPunto* actual = new NodoPunto();
    NodoPunto* ultimo = new NodoPunto();
    actual = poligono.primerPunto;
    float perimetro = 0;
    if (poligono.primerPunto != NULL) {
        while (actual != NULL) {  
                if (anterior == NULL) {
                    anterior = new NodoPunto();
                }
                else {
                    perimetro = perimetro + getDistancia(anterior->punto, actual->punto);
                }
                anterior = actual; 
                ultimo = actual;
                actual = actual->siguiente;
            }

        perimetro = perimetro + getDistancia(poligono.primerPunto->punto, ultimo->punto);
    }
    return perimetro;
}

void setVertice(Poligono& poligono, Punto& punto, unsigned index) {

    NodoPunto* actual = new NodoPunto();
    actual = poligono.primerPunto;
    int pos = 0;
    if (poligono.primerPunto != NULL) {
        while (actual != NULL) {
            if (pos = index) {
                actual->siguiente->punto = punto;
                return;
            }
            else {
                pos++;
            }

            actual = actual->siguiente;
        }
    }
    
}

void removeVertice(Poligono& poligono, Punto& punto) {
   NodoPunto* actual = new NodoPunto();
    actual = poligono.primerPunto;
    if (poligono.primerPunto != NULL) {
        while (actual != NULL) {
            if (isPuntoIgual(actual->punto, punto)) {
                actual->punto = actual->siguiente->punto;
                actual->siguiente = actual->siguiente->siguiente;
            }

            actual = actual->siguiente;
        }
    }
    
}



void removeVertice(Poligono& poligono, int index) {
    NodoPunto* actual = new NodoPunto();
    actual = poligono.primerPunto;
    int pos = 0;
    if (poligono.primerPunto != NULL) {
        while (actual != NULL) {
            if (pos == index) {
                actual->punto = actual->siguiente->punto;
                actual->siguiente = actual->siguiente->siguiente;
                return;
            }
            else {
                actual = actual->siguiente;
                pos++;
            }
        }
    }
    
}
//#endif
