#include<iostream>
#include "videogame.h"
#include "menucivilizacion.h"

using namespace std;

int main(){

    Videogame juego;
    string op;

    while (true){
        cout<<"Nombre de Usuario: "<< juego.getUsuario() <<endl;
        cout<<"1) Asignar Nombre de Usuario"<<endl;
        cout<<"2) Agregar Civilizacion"<<endl;
        cout<<"3) Insertar Civilizacion"<<endl;
        cout<<"4) Inicializar Civilizaciones"<<endl;
        cout<<"5) Primera Civilizacion"<<endl;
        cout<<"6) Ultima Civilizacion"<<endl;
        cout<<"7) Ordenar"<<endl;
        cout<<"8) Eliminar Civilizacion"<<endl;
        cout<<"9) Buscar"<<endl;
        cout<<"10) Modificar"<<endl;
        cout<<"11) Resumen"<<endl;

        cout<<"12) Respaldar Civilizaciones"<<endl;
        cout<<"13) Recuperar Civilizaciones"<<endl;

        cout<<"0) Salir"<<endl;
        getline(cin, op);

        if(op=="1"){
            string nu;

            cout <<"Escriba su nombre de usuario: ";
            getline(cin, nu);

            juego.setUsuario(nu);

        }else if(op=="2"){
            Civilizacion c;
            cin >> c;
            juego.agregar(c);

        }else if(op=="3"){
            Civilizacion c;
            size_t pos;

            cout <<"Posicion: ";
            cin >> pos; cin.ignore(); 

            if(pos >= juego.total()){
                cout <<"Posicion no valida"<<endl;
            }else{
                cin >> c;
                juego.insertar(c, pos);
            }

        }else if(op=="4"){
            Civilizacion c;
            size_t n;

            cin >> c;
            cout <<"n: ";
            cin >> n; cin.ignore();

            juego.inicializar(c, n);

        }else if(op=="5"){
            
            cout << juego.front();
            
        }else if(op=="6"){
            
            cout << juego.back();
            
        }else if(op=="7"){
            size_t opc;

            cout <<"Tipo de Orden:"<<endl;
            cout <<"1) Por Nombre"<<endl;
            cout <<"2) Por Pos. X"<<endl;
            cout <<"3) Por Pos. Y"<<endl;
            cout <<"4) Por Puntuacion"<<endl;

            cin >> opc; cin.ignore();

            switch (opc){
                case(1): juego.ordenarNombre();
                break;
                case(2): juego.ordenarXPOS();
                break;
                case(3): juego.ordenarYPOS();
                break;
                case(4): juego.ordenarPuntos();
                break;
                default: cout <<"Opcion invalida"<<endl;
                break;
            }
            
        }else if(op=="8"){
            string n;
            cout <<"Civilizacion a borrar: ";
            getline(cin, n);

            juego.erase(n);
            
        }else if(op=="9"){
            string n;
            cout <<"Civilizacion a buscar: ";
            getline(cin, n);

            Civilizacion c;
            c.setNombre(n);

            Civilizacion *ptr = juego.buscar(c);

            if(ptr == nullptr){
                cout <<"No encontrado"<<endl;
            }else{
                cout << left;
                cout << setw(16) << "Nombre.";
                cout << setw(12) << "Pos. X";
                cout << setw(12) << "Pos. Y";
                cout << setw(7) << "Puntuacion";
                cout << endl;
                cout << *ptr <<endl;
                menu(*ptr);
            }
            
        }else if(op=="10"){
            string n;
            cout <<"Civilizacion a buscar para modificar: ";
            getline(cin, n);

            Civilizacion c;
            c.setNombre(n);

            Civilizacion *ptr = juego.buscar(c);

            if(ptr == nullptr){
                cout <<"No encontrado"<<endl;
            }else{
                cout << left;
                cout << setw(16) << "Nombre.";
                cout << setw(12) << "Pos. X";
                cout << setw(12) << "Pos. Y";
                cout << setw(7) << "Puntuacion";
                cout << endl;
                cout << *ptr <<endl;
                juego.modificar(ptr);
            }
            
        }else if(op=="11"){
            
            juego.resumen();
            
        }else if(op=="12"){
            juego.respaldar();

        }else if(op=="13"){
            juego.recuperar();

        }else if(op=="0"){
            break;
        }

        cout << endl;
    }
    
    return 0;
}