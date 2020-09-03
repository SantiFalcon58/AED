#include <iostream>
#include <array>
#include <cmath>
using namespace std;

 struct Punto {
        int x;
        int y;
    };

enum struct Cuadrante{PRIMER,SEGUNDO, TERCER, CUARTO};


int main() {
return 0;
}

    bool isIgual(Punto punto1, Punto punto2) {
        return (punto1.x==punto2.x) AND (punto2.y==punto2.y);
    }

    int getDistancia(Punto punto1, Punto punto2) {
        return sqrt(((punto2.x-punto1.x)^2) + ((punto2.y-punto1.y)^2);
    }

    int getDistanciaAlOrigen(Punto punto) {
        return sqrt((punto.x^2)+ (punto.y^2));
    }

    Cuadrante getCuadrante(Punto punto) {
    punto.x>0 ? punto.y > 0 ? return Cuadrante::PRIMER : return Cuadrante::CUARTO : punto.y>0 ? return Cuadrante::SEGUNDO : Cuadrante::TERCERO;
    }


    void mover(Punto punto,array<int,2> values) {
        punto.x = punto.x+values.at(0);
        punto.y = punto.y+values.at(1);
    }



