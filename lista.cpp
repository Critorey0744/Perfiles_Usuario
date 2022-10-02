#include "lista.h"

lista::lista()
{
    Ppr = NULL;
}
void lista::ingresaUsuario(Usuarios *per){
    Ppr = new nodo(per, Ppr);
}
string lista::toString(){
    stringstream s;
    nodo *p = Ppr;
    Usuarios *Per;
    while(p != NULL){
        Per = p->obtenerUsuarios();
        s<<Per->toString();
        p = p->obtenerSiguiente();
    }
    return s.str();
}
void lista::guardaDatos(){
    nodo *p = Ppr;
    Usuarios *Per;
    ofstream Escribe("usuarios.txt", ios::out);
    while(p != NULL){
        Per = p->obtenerUsuarios();
        Per->guardaEnTxt(Escribe);
        p = p->obtenerSiguiente();
    }
    Escribe.close();
}
void lista::cargarDatos(){
    ifstream Leer("usuarios.txt", ios::in);
    Usuarios *Per;
    Usuarios aux;
    Per = aux.leerEnTxt(Leer);
    while(!Leer.eof()){ //eof significa que mientras no termine de leer todo el archivo
        ingresaUsuario(Per);
        Per = aux.leerEnTxt(Leer);
    }
    Leer.close();
}
Usuarios *lista::nombreUsado(string user){
    Usuarios *aux;
    nodo *p = Ppr;
    while(p != NULL){
        aux = p->obtenerUsuarios();
        if(aux->obtenerNombre() == user){
            return aux;
        }
        p = p->obtenerSiguiente();
    }
    return NULL;
}
Usuarios *lista::eliminar(string user){
    nodo *p = Ppr;
    nodo *aux = NULL;
    bool encontrar = false;
    Usuarios *Per;
    while(p != NULL && !encontrar){ //el signo de admiracion significa que encontrado = falso
        Per = p->obtenerUsuarios();
        if(Per->obtenerNombre() == user){
            encontrar == true;
            eliminarNodo(aux, p);
            return Per;
        }
        aux = p;
        p = p->obtenerSiguiente();
    }
    return NULL;
}
void lista::eliminarNodo(nodo *aux, nodo *p){
    if(aux == NULL){
        Ppr = p->obtenerSiguiente();
    }else{
        aux->setSiguiente(p->obtenerSiguiente());
    }
    delete p;
}
lista::~lista(){
    nodo *p = Ppr;
    nodo *aux;
    while(p != NULL){
        aux = p->obtenerSiguiente();
        delete p;
        p = aux;
    }
    Ppr = NULL;
}