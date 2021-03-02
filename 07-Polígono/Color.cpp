#pragma once
#include "Color.h"
#include <string>
#include <sstream> 
#include <iostream>
#include <vector>
using namespace std;

int promedio(int, int);


Color Sumar(const Color color1, const Color color2) {
    int r = color1.red + color2.red >= 255 ? 255 : color1.red + color2.red;
    int g = color1.green + color2.green >= 255 ? 255 : color1.green + color2.green;
    int b = color1.blue + color2.blue >= 255 ? 255 : color1.blue + color2.blue;
    Color nuevoColor{ r,g,b };
    return nuevoColor;
}


Color Restar(const Color color1, const Color color2) {
    int r = color1.red - color2.red <= 0 ? 0 : color1.red - color2.red;
    int g = color1.green - color2.green <= 0 ? 0 : color1.green - color2.green;
    int b = color1.blue - color2.blue <= 0 ? 0 : color1.blue - color2.blue;
    Color nuevoColor{ r,g,b };
    return nuevoColor;
}

string getHtmlHex(const Color color) {
    stringstream s1, s2, s3;
    string R,G,B,hex;
    s1 << std::hex << color.red;
    R = s1.str();
    if (R.length() == 1) R = "0" + R;
    s2 << std::hex << color.green;
    G = s2.str();
    if (G.length() == 1)   G = "0" + G;
    
    s3 << std::hex << color.blue;

    B = s3.str();
    if (B.length() == 1) B = "0" + B;
    
    hex  = "#" + R + G + B;
    return hex;
}

string getHtmlRgb(const Color color) {
    int r = color.red;
    int g = color.green;
    int b = color.blue;
    return "rgb(" + to_string(r) + "," + to_string(g) + "," + to_string(b) + ")";
}


bool isColorIgual(const Color color1, const Color color2) {
    return (color1.red == color2.red) and (color1.green == color2.green) and (color1.blue == color2.blue);
}

Color getComplementario(const Color color) {
    int r = 255 - color.red;
    int g = 255 - color.green;
    int b = 255 - color.blue;
    Color nuevoColor{ r,g,b };
    return nuevoColor;
}


Color mezclarColores(const Color color1, const Color color2) {
    int red = promedio(color1.red, color2.red);
    int green = promedio(color1.green, color2.green);
    int blue = promedio(color1.blue, color2.blue);
    Color nuevoColor{ red,green,blue };
    return nuevoColor;
}


int promedio(int a, int b) {
    return (a + b) / 2;
}


Color colorFromString(string s) {
    vector<int> rgb;
    //cout << "Entrada: "<<s <<"\n";
    stringstream ss(s);

    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        rgb.push_back(stoi(substr));
    }
    Color color{rgb[0],rgb[1],rgb[2]};
    //cout << "Salida: " << color.red << " " << color.green << " " << color.blue << "\n";
    return color;

}