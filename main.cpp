#include <iostream>
#include "manejo.h"

using namespace std;

int main(){
    manejo *Man = new manejo;
    Man->controlador();
    delete Man;
    return 0;
}