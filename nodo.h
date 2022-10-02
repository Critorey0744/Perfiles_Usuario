#ifndef NODO_H
#define NODO_H
#include "Usuarios.h"

class nodo
{
public:
    nodo(Usuarios *, nodo *);
    void setUsuarios(Usuarios *);
    Usuarios *obtenerUsuarios();
    void setSiguiente(nodo *);
    nodo *obtenerSiguiente();
    virtual ~nodo();

private:
    Usuarios *usuarios;
    nodo *Sig;

};

#endif // NODO_H