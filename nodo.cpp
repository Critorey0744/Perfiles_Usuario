#include "nodo.h"

nodo::nodo(Usuarios *per, nodo *sig){
    usuarios = per;
    Sig = sig;
}
void nodo::setUsuarios(Usuarios *per){
    usuarios = per;
}
Usuarios *nodo::obtenerUsuarios(){
    return usuarios;
}
void nodo::setSiguiente(nodo *sig){
    Sig = sig;
}
nodo *nodo::obtenerSiguiente(){
    return Sig;
}

nodo::~nodo()
{
    //dtor
}