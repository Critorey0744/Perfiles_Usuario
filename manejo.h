#ifndef MANEJO_H
#define MANEJO_H
#include "lista.h"
#include <cstdlib>
#include <windows.h>

class manejo
{
public:
    manejo();
    int menu();
    void verUsuarios();
    void agregarUsuarios();
    void iniciarSesion();
    void controlador();
    void EliminarUsuario();
    virtual ~manejo();

private:
    lista *Lis;
};

#endif // MANEJO_H