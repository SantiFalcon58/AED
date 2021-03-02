#pragma once
#include <istream>
#include "Poligono.h"
#include <fstream>
#include <iostream>
#include "Punto.h"
#include <vector>
#include "Filtro.h"
#include <cassert>

using namespace std;

void CopiarPolígonosConPerímetrosMayoresA(double x, string nombreArchivoIn, string nombreArchivoOut) {
    vector<Poligono> poligonos;
    std::ifstream ifs(nombreArchivoIn, std::ifstream::in);
    extraerPoligono(ifs, poligonos);
    for (int i = 0; i < poligonos.size(); i++) {
        Poligono poligono = poligonos.at(i);
        if (getPerimetro(poligono) < x) {
            poligonos.erase(poligonos.begin() + i);
        }
    }
 
    std::ofstream ofs(nombreArchivoOut, std::ofstream::out);
    insertarPoligono(ofs, poligonos);

}




void extraerPoligono(ifstream&  in, vector<Poligono>& poligonos) {
    string line;
    bool gettingPoints;
    bool gettingColor = true;
    Color color = { 255,0,0 };
    vector<Punto> puntos;
     while (getline(in, line))
        {       
            if (gettingColor) {
                color = colorFromString(line);
                gettingColor = false;
                gettingPoints = true;
            }
            else if (gettingPoints and !line.empty()) {
                Punto punto = puntoFromString(line);
                puntos.push_back(punto);
            } else {
                Poligono poligono{color,NULL,NULL};
                for (int i = 0; i < puntos.size(); i++) {
                    addVertice(poligono,puntos.at(i));
                }
                poligonos.push_back(poligono);
                puntos.clear();
                gettingColor = true;
                gettingPoints = false;
            } 
    }

     Poligono poligono{ color,NULL,NULL };
     for (int i = 0; i < puntos.size(); i++) {
         addVertice(poligono, puntos.at(i));
     }

     poligonos.push_back(poligono);
        in.close();
}

void insertarPoligono(ofstream& out, const vector<Poligono> poligonos) {
    if (out.is_open())
    {
        for (int i = 0; i < poligonos.size(); i++) {
            Poligono poligono = poligonos.at(i);
            Color color = poligono.color;

            out << color.red << "," << color.green << "," << color.blue << "\n";
            for (int j = 0; j < getCantidadLados(poligono); j++) {
                Punto punto = getVertice(poligono, j);
                
                out << punto.x << "," << punto.y << "\n";
            }

            out <<"\n";

        }
    }
    out.close();

}

 
