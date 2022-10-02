#include "manejo.h"

manejo::manejo(){
    Lis = new lista;
}
int manejo::menu(){
    int respuesta;
    do{
        system("cls");
        cout<<"---------------------------------"<<endl;
        cout << "Por favor seleccione una opcion"<<endl;
        cout << "1: Ingresar un nuevo usuario"<<endl;
        cout << "2: Iniciar sesion"<<endl;
        cout << "3: Eliminar mi cuenta"<<endl;
        cout << "4: Mostrar todos los usuarios" <<endl;
        cout << "5: finalizar programa" << "\n";
        cout << "------------------------------"<<endl;
        cin >> respuesta;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n');
            cout<<"Profe el menu solo brinda valores numeros :'c"<<endl;Sleep(2000);
            respuesta = menu();
        }
        if(respuesta > 5 || respuesta < 1){
            cout<<"Profe, el menu solo acepta valores entre 1 y 5 -_-"<< endl;Sleep(2000);
            respuesta = menu();
        }
        switch(respuesta){
            case 1:agregarUsuarios();
                break;
            case 2:iniciarSesion();
                break;
            case 3:EliminarUsuario();
                break;
            case 4:verUsuarios();
                break;

        }
    }while(respuesta !=5);

    return respuesta;
}
void manejo::verUsuarios(){
    system("cls");
    cout<<Lis->toString()<<endl;
    system("pause");
}
void manejo::controlador(){
    Lis->cargarDatos();
    menu();
    Lis->guardaDatos();
}
void manejo::agregarUsuarios(){
    system("cls");
    string user, pw;
    Usuarios *Per;
    cout<<"Ingresa tu usuario: ";
    cin>>user;
    cout<<"Ingresa tu contrasena: ";
    cin>>pw;
    Per =Lis->nombreUsado(user);
    if(Per == NULL){
        Lis->ingresaUsuario(new Usuarios(user, pw));
    }else{
        cout<<"Opsi, alguien ya tiene este username :0"<<endl; Sleep(2000);
    }
}
void manejo::iniciarSesion(){
    system("cls");
    Usuarios *Per;
    string user;
    string pw;
    cout<<"Ingrese su nombre: "<<"\n";
    cin>>user;
    cout<<"Ingrese su contrasena: ";
    cin>>pw;
    Per = Lis->nombreUsado(user);
    if(Per != NULL){
        system("cls");
        cout<<Per->toString()<<endl;
        system("pause");
    }else{
        cout<<"Error al iniciar sesion... :c"<<endl;Sleep(1500);
    }
}
void manejo::EliminarUsuario(){
    system("cls");
    string user;
    string pw;
    Usuarios *Per;
    cout<<"Nombre de Usuario que quieres eliminar";
    cin>>user;
    cout<<"Ingrese la contrasena del usuario: ";
    cin>>pw;
    Per = Lis->eliminar(user);
    if(Per != NULL){
        delete Per;
        cout<<"Usuario Eliminado"<<endl;Sleep(1500);
    }else{
        cout<<"Usuario no encontrado!"<<endl;Sleep(1500);
    }
}
manejo::~manejo()
{
    //dtor
}