#if 0
#pragma once
#include "Poligono.h"
#include "Nodo.h"
#include "Punto.h"
#include <cstddef>
#include <iostream>

using namespace std;



void addVertice(Poligono& poligono, const Punto punto) {
    poligono.vertices[poligono.lados] = punto;
    poligono.lados++;
    //imprimir(poligono);
}

void imprimir(const Poligono poligono) {
    for (int i = 0; i < getCantidadLados(poligono); i++) {
        Punto p = poligono.vertices[i];
    cout << "vertices[" << i << "]: " << p.x << "," << p.y << "\n";
    cout << "Color[" << i << "]: " << poligono.color.red << "," << poligono.color.green <<"," << poligono.color.blue << "\n";
}
}


Punto getVertice(const Poligono poligono, unsigned i) {
    //imprimir(poligono);
    Punto p = poligono.vertices[i];
        return p;  
}


int getCantidadLados(const Poligono poligono) {
    return poligono.lados;
}


float getPerimetro(const Poligono poligono) {
    float perimetro = 0;
    if (getCantidadLados(poligono) >2) {
        for (int i = 0; i < getCantidadLados(poligono)-1; i++) {     
            Punto a = poligono.vertices[i];
            Punto b = poligono.vertices[i+1];
            perimetro = perimetro + getDistancia(a, b);
        }

        Punto primero = poligono.vertices[0];
        Punto ultimo = poligono.vertices[getCantidadLados(poligono) - 1];
        perimetro = perimetro + getDistancia(primero, ultimo);
    }
    return perimetro;
}

void setVertice(Poligono& poligono, Punto& punto, const unsigned index) {
    poligono.vertices[index] = punto;
}



void removeVertice(Poligono& poligono, unsigned index) {
    poligono.lados--;

}

#endif