#include "civilizacion.h"

Aldeano capturar(){
    Aldeano a;
    string s;
    size_t n;

    cout<<"Nombre: ";
    getline(cin, s);
    a.setNombre(s);

    cout<<"Edad: ";
    cin >> n;
    a.setEdad(n); cin.ignore();

    cout<<"Genero: ";
    getline(cin, s);
    a.setGenero(s);

    cout<<"Salud: ";
    cin >> n;
    a.setSalud(n); cin.ignore();

    return a;
}

void menu(Civilizacion &c){
    string op, op2;

    while (true){
        cout<<"Menu de la Civilizacion: "<< c.getNombre() <<endl;
        cout<<"1) Agregar aldeano"<<endl;
        cout<<"2) Eliminar aldeano"<<endl;
        cout<<"3) Clasificar aldeanos"<<endl;
        cout<<"4) Buscar aldeano"<<endl;
        cout<<"5) Modificar aldeano"<<endl;
        cout<<"6) Mostrar aldeanos"<<endl;
        cout<<"0) Salir"<<endl;

        getline(cin, op);

        if(op=="1"){
            int p;
            cout<<"1) Agregar aldeano al inicio"<<endl;
            cout<<"2) Agregar aldeano al final"<<endl;
            getline(cin, op2);

            if(op2 == "1"){
                c.agregarInicio(capturar());

                p = c.getPuntuacion() + 100;
                c.setPuntuacion(p);
            }else if(op2 == "2"){
                c.agregarFinal(capturar());

                p = c.getPuntuacion() + 100;
                c.setPuntuacion(p);
            }
            cout<<endl;

        }else if(op=="2"){
            cout<<"1) Eliminar por nombre"<<endl;
            cout<<"2) Eliminar por salud minima(x)"<<endl;
            cout<<"3) Eliminar por edad maxima(60)"<<endl;
            getline(cin, op2);

            if(op2 == "1"){
                string ald;
                cout <<"Aldeano a borrar: ";
                getline(cin, ald);
                c.eliminarNombre(ald);

            }else if(op2 == "2"){
                size_t salud;
                cout <<"Salud minima aceptada: ";
                cin >>salud; cin.ignore();
                c.eliminarSaludMin(salud);

            }else if(op2 == "3"){
                c.eliminarEdad();
            }
            cout << endl;

        }else if(op=="3"){
            cout<<"1) Clasificar por nombre (ascendente)"<<endl;
            cout<<"2) Clasificar por edad (descendente)"<<endl;
            cout<<"3) Clasificar por salud (descendente)"<<endl;
            getline(cin, op2);

            if(op2 == "1"){
                c.ordenarNombre();

            }else if(op2 == "2"){
                c.ordenarEdad();

            }else if(op2 == "3"){
                c.ordenarSalud();
            }
            cout<<endl;

        }else if(op=="4"){
            string n;
            cout <<"Aldeano a buscar: ";
            getline(cin, n);

            Aldeano a;
            a.setNombre(n);

            Aldeano *ptr = c.buscarAldeano(a);

            if(ptr == nullptr){
                cout <<"No encontrado"<<endl;
            }else{
                cout << *ptr <<endl;
            }
            cout<<endl;

        }else if(op=="5"){
            string n;
            cout <<"Aldeano a buscar: ";
            getline(cin, n);

            Aldeano a;
            a.setNombre(n);

            Aldeano *ptr = c.buscarAldeano(a);

            if(ptr == nullptr){
                cout <<"No encontrado"<<endl;
            }else{
                cout << *ptr <<endl;
                c.modificarAldeano(ptr);
            }
            cout<<endl;

        }else if(op=="6"){
            cout << left;
            cout << setw(14) << "Nombre";
            cout << setw(8) << "Edad";
            cout << setw(10) << "Genero";
            cout << setw(6) << "Salud";
            cout << endl;

            c.mostrarAldeanos();
            cout<<endl;

        }else if(op=="0"){
            break;
        }
    }
    
}