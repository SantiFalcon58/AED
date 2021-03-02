#pragma once
#include "Punto.h"
#include <cmath>
#include <string>
#include <sstream> 
#include <vector>
#include <iostream>
using namespace std;



bool isPuntoIgual(Punto punto1, Punto punto2) {
    return (punto1.x == punto2.x) and (punto2.y == punto2.y);
}

float getDistancia(Punto punto1, Punto punto2) {
    float distancia = sqrt(pow(punto2.x - punto1.x, 2) + pow(punto2.y - punto1.y, 2) * 1.0);
        return distancia;
}

float getDistanciaAlOrigen(Punto punto) {
    return sqrt((pow(punto.x,2)) + (pow(punto.y,2) * 1.0));
}

Cuadrante getCuadrante(Punto punto) {
    return punto.x > 0 ? punto.y > 0 ? Cuadrante::PRIMER :  Cuadrante::CUARTO : punto.y > 0 ?  Cuadrante::SEGUNDO : Cuadrante::TERCER;   
}


void mover(Punto &punto, unsigned values[]) {
    punto.x = punto.x + values[0];
    punto.y = punto.y + values[1];
}
Punto puntoFromString(string s) {
        vector<int> coords;
        stringstream ss(s);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            coords.push_back(stoi(substr));
        }

        Punto punto{ coords[0],coords[1]};
        return punto;

   
}
