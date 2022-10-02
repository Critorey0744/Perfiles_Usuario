#include "Usuarios.h"

using namespace std;

Usuarios::Usuarios()
{
    username = "";
    pwd = "";
}

Usuarios::Usuarios(string user, string pw){
    username = user;
    pwd = pw;
}
void Usuarios::guardaEnTxt(ofstream &Escribe){
    Escribe<< username <<"\n";
    Escribe<<pwd<<"\n";
}
Usuarios *Usuarios::leerEnTxt(ifstream &Leer){
    string user, pw;
    Leer>>user;
    Leer>>pw; //////////////////////////////////////////////////
    return (new Usuarios(user, pw));
}
string Usuarios::obtenerNombre(){
    return username;
}
string Usuarios::toString(){
    stringstream s;
    s<<"Nombre------: "<<username<<endl;
   // s<<"Contrasena--: "<<pwd<<endl;
    return s.str();
}
Usuarios::~Usuarios(){
}