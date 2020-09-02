#include <iostream>
#include <array>

using namespace std;

 struct Color {
        int red;
        int green;
        int blue;
    };


Color Sumar(Color, Color);
Color Restar (Color,Color);

int main()
{
    Color rojo{255,0,0};
     Color verde{0,255,0};
    Color azul{0,0,255};

      // Color cyan{0,255,255};
    Color cyan = Sumar(verde,azul);

   // Color magenta{255,0,255};
   Color magenta = Sumar(rojo,azul);

    //Color amarillo{255,255,0};
   Color amarillo = Sumar(rojo,verde);

   // Color negro{0,0,0};
   Color negro = Restar(rojo,rojo);

   // Color blanco{255,255,255};
   Color blanco = Sumar(Sumar(rojo,verde),azul);
}


int promedio(int x, int y) {
        return (x+y)/2;
    }

    Color mezclarColores(Color color1, Color color2) {
        int red = promedio(color1.red,color2.red);
        int green = promedio(color1.green,color2.green);
        int blue = promedio(color1.blue,color2.blue);
        Color nuevoColor{red,green,blue};
        return nuevoColor;
     }

    Color getComplementario(Color color) {
         int r = 255-color.red;
         int g = 255-color.green;
         int b = 255-color.blue;
         Color nuevoColor{r,g,b};
         return nuevoColor;
     }

 Color Sumar(Color color1, Color color2) {
         int r = color1.red+color2.red>=255 ? 255 : color1.red+color2.red;
        int g = color1.green+color2.green>=255 ? 255 : color1.green+color2.green;
        int b = color1.blue+color2.blue>=255 ? 255 : color1.blue+color2.blue;
        Color nuevoColor{r,g,b};
        return nuevoColor;
    }




    Color Restar(Color color1, Color color2) {
         int r = color1.red-color2.red<=0 ? 0 : color1.red-color2.red;
        int g = color1.green-color2.green<=0 ? 0 : color1.green-color2.green;
        int b = color1.blue-color2.blue<=0 ? 0 : color1.blue-color2.blue;
        Color nuevoColor{r,g,b};
        return nuevoColor;
    }


    Color mezclarConProporciones(Color color1, Color color2,array<int,3> porcentajes) {

        int porcentaje_red = porcentajes.at(0)/100;
        int porcentaje_green = porcentajes.at(1)/100;
        int porcentaje_blue = porcentajes.at(2)/100;

        int red = promedio(color1.red*porcentaje_red,color2.red*(1-porcentaje_red));
        int green = promedio(color1.green*porcentaje_green,color2.green*(1-porcentaje_green));
        int blue = promedio(color1.blue*porcentaje_blue,color2.blue*(1-porcentaje_blue));
        Color nuevoColor{red,green,blue};
        return nuevoColor;
    }

