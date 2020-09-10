#include <iostream>
#include <array>
#include <sstream>
#include <assert.h>
#include <math.h>
using namespace std;

 struct Color {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    };


     struct Punto {
        int x;
        int y;
    };


    struct Poligono{
        array<Punto,50> vertices;
        Color color;
        int cantidadVertices;
    };



Color Sumar(const Color, const Color);
Color Restar (const Color, const Color);
string getHtmlRgb(const Color);
string getHtmlHex(const Color);
bool isIgual(const Color, const Color);
Color getComplementario(const Color);
Color mezclarConProporciones(const Color,const Color, const array<int,3>);
void addVertice(Poligono &poligono, const Punto);
void setVertice(Poligono &poligono, const Punto,const int);
int getCantidadLados(const Poligono);
int getPerimetro(const Poligono);

Color red{255,0,0};

int main()
{

Punto a{0,0};
Punto b{1,0};
Punto c{0,1};
Punto d{1,1};

Poligono poligono{{a,b,c,d},red,4};

assert(getCantidadLados(poligono)==4);
assert(getPerimetro(poligono)==4);

addVertice(poligono,{5,5});
assert(getCantidadLados(poligono)==5);

setVertice(poligono,{3,0},1);
assert(getPerimetro(poligono)==7);
}

    string getHtmlRgb(const Color color) {
        int r = color.red;
        int g = color.green;
        int b = color.blue;
        return "rgb("+ to_string(r) + ","+to_string(g)+","+to_string(b)+")";
    }

     int getDistancia(Punto punto1, Punto punto2) {
        return sqrt(((punto2.x-punto1.x)^2) + ((punto2.y-punto1.y)^2));
    }

       void mover(Punto punto,array<int,2> values) {
        punto.x = punto.x+values.at(0);
        punto.y = punto.y+values.at(1);
    }

    void addVertice(Poligono &poligono,const Punto punto) {
        if (poligono.cantidadVertices<=50) {
        poligono.vertices.at(poligono.cantidadVertices) = punto;
        poligono.cantidadVertices = poligono.cantidadVertices +1;
        }
    }


    void setVertice(Poligono &poligono,const Punto punto, const int position) {
        if (poligono.cantidadVertices>position) {
        poligono.vertices.at(position) = punto;
        }
    }

    int getCantidadLados(const Poligono poligono) {
        return poligono.cantidadVertices;
    }


    int getPerimetro(const Poligono poligono) {
        int perimetro;
        for(int i = 0; i<poligono.cantidadVertices-1;i+=1) {
            perimetro = getDistancia(poligono.vertices.at(i),poligono.vertices.at(i+1))+perimetro;
        }
        return perimetro;
    }

