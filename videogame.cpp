#include "videogame.h"
#include<fstream>
#include<algorithm>

Videogame::Videogame(){
    
}

size_t Videogame::total(){
    return civilizaciones.size();
}

void Videogame::agregar(const Civilizacion &c){
    civilizaciones.push_back(c);
}

void Videogame::insertar(const Civilizacion &c, size_t pos){
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

void Videogame::inicializar(const Civilizacion &c, size_t n){
    civilizaciones = vector<Civilizacion>(n, c);
}

Civilizacion Videogame::front(){
    return civilizaciones[0];
}

Civilizacion Videogame::back(){
    return civilizaciones[total()-1];
}

void Videogame::ordenarNombre(){
    sort(civilizaciones.begin(), civilizaciones.end());
}
void Videogame::ordenarXPOS(){
    sort(civilizaciones.begin(), civilizaciones.end(),
    [] (Civilizacion c1, Civilizacion c2) {return c1.getXpos() < c2.getXpos();});
}
void Videogame::ordenarYPOS(){
    sort(civilizaciones.begin(), civilizaciones.end(),
    [] (Civilizacion c1, Civilizacion c2) {return c1.getYpos() < c2.getYpos();});
}
void Videogame::ordenarPuntos(){
    sort(civilizaciones.begin(), civilizaciones.end(),
    [] (Civilizacion c1, Civilizacion c2) {return c1.getPuntuacion() > c2.getPuntuacion();});
}

void Videogame::erase(string n){
    int pos;

    for(size_t i=0; i<civilizaciones.size(); i++){
        if(civilizaciones[i].getNombre() == n){
            pos = i;
            civilizaciones.erase(civilizaciones.begin()+pos);
            break;
        }
        if(i==civilizaciones.size()){
            cout<<"Civilizacion no encontrada."<<endl;
        }
    }
}

Civilizacion* Videogame::buscar(const Civilizacion &c){
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return nullptr;
    }else{
        return &(*it);
    }
}

void Videogame::modificar(Civilizacion *c){

    int opp=1, m;
    string n;

    while(opp != 0){
        cout <<"Dato a modificar:"<<endl;
        cout <<"1) Nombre"<<endl;
        cout <<"2) Posicion X"<<endl;
        cout <<"3) Posicion Y"<<endl;
        cout <<"4) Puntuacion"<<endl;
        cout <<"0) Terminar Modificaciones"<<endl;

        cin >> opp;

        switch (opp){
            case(1): cout<<"Nuevo Nombre: "; cin >> n; c->setNombre(n);
            break;
            case(2): cout<<"Nueva Posicion en X: "; cin >> m; c->setXpos(m);
            break;
            case(3): cout<<"Nueva Posicion en Y: "; cin >> m; c->setYpos(m);
            break;
            case(4): cout<<"Nueva Puntuacion: "; cin >> m; c->setPuntuacion(m);
            break;
            case(0): cin.ignore();
            break;
            default: cout<<"Opcion invalida"<<endl;
            break;
        }
    }
}

void Videogame::resumen(){
    cout << left;
    cout << setw(16) << "Nombre.";
    cout << setw(12) << "Pos. X";
    cout << setw(12) << "Pos. Y";
    cout << setw(7) << "Puntuacion";
    cout << endl;

    for(size_t i=0; i<civilizaciones.size(); i++){
        Civilizacion &c = civilizaciones[i];
        cout << c;
    }
}

void Videogame::respaldar(){
    ofstream archivo("civilizaciones.txt", ios::out);

    for (int i = 0; i < civilizaciones.size(); ++i) {
        Civilizacion &cv = civilizaciones[i];
        archivo << cv.getNombre() << endl;
        archivo << cv.getXpos() <<endl;
        archivo << cv.getYpos() <<endl;
        archivo << cv.getPuntuacion()<<endl;

        cv.respaldarAldeanos();
    }
    archivo.close();
}

void Videogame::recuperar(){
    ifstream archivo("civilizaciones.txt");
    Civilizacion c;
    int actual = civilizaciones.size();

    if(archivo.is_open()){
        
        string s;
        int n;

        while(true){
            getline(archivo, s);
            if(archivo.eof()){
                break;
            }
            c.setNombre(s);

            getline(archivo, s);
            n = stoi(s);
            c.setXpos(n);

            getline(archivo, s);
            n = stoi(s);
            c.setYpos(n);

            getline(archivo, s);
            n = stoi(s);
            c.setPuntuacion(n);

            agregar(c);
        }
    }
    archivo.close();
    c.recuperarAldeanos(civilizaciones, actual);
}