
#ifndef UNTITLED3_USUARIOS_H
#define UNTITLED3_USUARIOS_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Usuarios
{
public:
    Usuarios();
    Usuarios(string, string);
    void guardaEnTxt(ofstream &);
    string obtenerNombre();
    Usuarios *leerEnTxt(ifstream &);
    string toString();
    virtual ~Usuarios();
private:
    string username;
    string pwd;

};


#endif
