#include <iostream>
#include <array>
#include <cmath>
using namespace std;

 struct Punto {
        int x;
        int y;
    };

    struct Triangulo {
        Punto p1;
        Punto p2;
        Punto p3;
    };

    bool isIgual(Punto,Punto);
    int getDistancia(Punto,Punto);
    int getDistanciaAlOrigen(Punto);



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


    getPerimetro(Triangulo triangulo) {
        int lado1 = getDistancia(triangulo.p1,triangulo.p2);
        int lado2 = getDistancia(triangulo.p2,triangulo.p3);
        int lado3 = getDistancia(triangulo.p3,triangulo.p1);
        return lado1+lado2+lado3;
    }

    getArea(Triangulo triangulo) {
         Punto a = triangulo.p1;
         Punto b = triangulo.p2;
         Punto c = triangulo.p3;

        int vector_ab_x = b.x-a.x;
        int vector_ab_y = b.y-a.x;

         modulo_ab = sqrt(vector_ab_x^2 + vector_ab_y^2);

        int distancia()
    }


    int distanciaPuntoARecta(Punto punto, array<int,2> vector) {

    }
