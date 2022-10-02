#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
class lista
{
public:
    lista();
    void ingresaUsuario(Usuarios *);
    void guardaDatos();
    void cargarDatos();
    Usuarios *nombreUsado(string);
    string toString();
    Usuarios *eliminar(string);
    void eliminarNodo(nodo *, nodo *);
    virtual ~lista();
private:
    nodo *Ppr;

};

#endif