#include <iostream>
#include <array>
#include <sstream>
#include <assert.h>
using namespace std;

 struct Color {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    };


Color Sumar(const Color, const Color);
Color Restar (const Color, const Color);
string getHtmlRgb(const Color);
string getHtmlHex(const Color);
bool isIgual(const Color, const Color);
int promedio(const int,const int);
Color mezclarColores(const Color, const Color);
Color getComplementario(const Color);
Color mezclarConProporciones(const Color,const Color, const array<int,3>);


    const Color rojo{255,0,0};
    const Color verde{0,255,0};
    const Color azul{0,0,255};

      // Color cyan{0,255,255};
    const Color cyan = Sumar(verde,azul);

   // Color magenta{255,0,255};
   const Color magenta = Sumar(rojo,azul);

    //Color amarillo{255,255,0};
   const Color amarillo = Sumar(rojo,verde);

   // Color negro{0,0,0};
   const Color negro = Restar(rojo,rojo);

   // Color blanco{255,255,255};
   const Color blanco = Sumar(Sumar(rojo,verde),azul);


int main()
{
    assert(getHtmlRgb(rojo)=="rgb(255,0,0)");
    assert(getHtmlRgb(mezclarColores(rojo,azul))=="rgb(127,0,127)");
    assert(getHtmlRgb(getComplementario(rojo))=="rgb(0,255,255)");
}


    int promedio(const int x, const int y) {
        return (x+y)/2;
    }

    Color mezclarColores(const Color color1, const Color color2) {
        int red = promedio(color1.red,color2.red);
        int green = promedio(color1.green,color2.green);
        int blue = promedio(color1.blue,color2.blue);
        Color nuevoColor{red,green,blue};
        return nuevoColor;
     }

    Color getComplementario(const Color color) {
         int r = 255-color.red;
         int g = 255-color.green;
         int b = 255-color.blue;
         Color nuevoColor{r,g,b};
         return nuevoColor;
     }

 Color Sumar(const Color color1, const Color color2) {
         int r = color1.red+color2.red>=255 ? 255 : color1.red+color2.red;
        int g = color1.green+color2.green>=255 ? 255 : color1.green+color2.green;
        int b = color1.blue+color2.blue>=255 ? 255 : color1.blue+color2.blue;
        Color nuevoColor{r,g,b};
        return nuevoColor;
    }

bool isIgual(const Color color1, const Color color2) {
    return (color1.red==color2.red) and (color1.green==color2.green) and (color1.blue==color2.blue);
}


    Color Restar(const Color color1, const Color color2) {
         int r = color1.red-color2.red<=0 ? 0 : color1.red-color2.red;
        int g = color1.green-color2.green<=0 ? 0 : color1.green-color2.green;
        int b = color1.blue-color2.blue<=0 ? 0 : color1.blue-color2.blue;
        Color nuevoColor{r,g,b};
        return nuevoColor;
    }


    Color mezclarConProporciones(const Color color1, const Color color2,const array<int,3> porcentajes) {

        int porcentaje_red = porcentajes.at(0)/100;
        int porcentaje_green = porcentajes.at(1)/100;
        int porcentaje_blue = porcentajes.at(2)/100;

        int red = promedio(color1.red*porcentaje_red,color2.red*(1-porcentaje_red));
        int green = promedio(color1.green*porcentaje_green,color2.green*(1-porcentaje_green));
        int blue = promedio(color1.blue*porcentaje_blue,color2.blue*(1-porcentaje_blue));
        Color nuevoColor{red,green,blue};
        return nuevoColor;
    }

    string getHtmlHex(const Color color) {
        long html = ((color.red & 0xff) << 16) + ((color.green & 0xff) << 8) + (color.blue & 0xff);
        std::ostringstream ss;
        ss << html;
        return ss.str();
    }

    string getHtmlRgb(const Color color) {
        int r = color.red;
        int g = color.green;
        int b = color.blue;
        return "rgb("+ to_string(r) + ","+to_string(g)+","+to_string(b)+")";
    }

