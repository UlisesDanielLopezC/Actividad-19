#include "civilizacion.h"
#include<algorithm>
#include<fstream>

Civilizacion::Civilizacion(){

}

Civilizacion::Civilizacion(const string &nombre, int xpos, int ypos, int puntuacion){
                            this->nombre = nombre;
                            this->xpos = xpos;
                            this->ypos = ypos;
                            this->puntuacion = puntuacion;
                        }

void Civilizacion::setNombre(const string &v){
    nombre = v;
}
string Civilizacion::getNombre(){
    return nombre;
}

void Civilizacion::setXpos(int v){
    xpos = v;
}
int Civilizacion::getXpos(){
    return xpos;
}

void Civilizacion::setYpos(int v){
    ypos = v;
}
int Civilizacion::getYpos(){
    return ypos;
}

void Civilizacion::setPuntuacion(int v){
    puntuacion = v;
}
int Civilizacion::getPuntuacion(){
    return puntuacion;
}

void Civilizacion::agregarFinal(const Aldeano &a){
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a){
    aldeanos.push_front(a);
}

void Civilizacion::eliminarNombre(const string &n){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(n == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarSaludMin(size_t s){
    aldeanos.remove_if([s](const Aldeano &a){return a.getSalud() <= s;});
}

bool comparadorE(const Aldeano &a){
    return a.getEdad() >= 60;
}
void Civilizacion::eliminarEdad(){
    aldeanos.remove_if(comparadorE);
}

void Civilizacion::ordenarNombre(){
    aldeanos.sort();
}

bool comparaEdad(const Aldeano &a1, const Aldeano &a2){
    return a1.getEdad() > a2.getEdad();
}
void Civilizacion::ordenarEdad(){
    aldeanos.sort(comparaEdad);
}

bool comparaSalud(const Aldeano &a1, const Aldeano &a2){
    return a1.getSalud() > a2.getSalud();
}
void Civilizacion::ordenarSalud(){
    aldeanos.sort(comparaSalud);
}

Aldeano* Civilizacion::buscarAldeano(const Aldeano &a){
    auto it = find(aldeanos.begin(), aldeanos.end(), a);

    if(it == aldeanos.end()){
        return nullptr;
    }else{
        return &(*it);
    }
}

void Civilizacion::modificarAldeano(Aldeano *a){
    int opp=1, m;
    string n;

    while(opp != 0){
        cout <<"Dato a modificar:"<<endl;
        cout <<"1) Nombre"<<endl;
        cout <<"2) Edad"<<endl;
        cout <<"3) Genero"<<endl;
        cout <<"4) Salud"<<endl;
        cout <<"0) Terminar Modificaciones"<<endl;

        cin >> opp;

        switch (opp){
            case(1): cout<<"Nuevo Nombre: "; cin >> n; a->setNombre(n);
            break;
            case(2): cout<<"Nueva Edad: "; cin >> m; a->setEdad(m);
            break;
            case(3): cout<<"Nuevo Genero: "; cin >> n; a->setGenero(n);
            break;
            case(4): cout<<"Nueva Salud: "; cin >> m; a->setSalud(m);
            break;
            case(0): cin.ignore();
            break;
            default: cout<<"Opcion invalida"<<endl;
            break;
        }
    }
}

void Civilizacion::mostrarAldeanos(){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it <<endl;
    }
}

void Civilizacion::respaldarAldeanos(){
    ofstream a(getNombre() + ".txt", ios::out);
    
    for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        a << aldeano.getNombre() << endl;
        a << aldeano.getEdad() << endl;
        a << aldeano.getGenero() << endl;
        a << aldeano.getSalud() << endl;
    }
    a.close();
}

void Civilizacion::recuperarAldeanos(vector<Civilizacion> &civ, int actual){

    for(size_t i=actual; i<civ.size(); i++){
        ifstream archivo(civ[i].getNombre() + ".txt");

        if(archivo.is_open()){
            Aldeano a;
            string s;
            int n;

            while(true){
                getline(archivo, s);
                if(archivo.eof()){
                    break;
                }
                a.setNombre(s);

                getline(archivo, s);
                n = stoi(s);
                a.setEdad(n);

                getline(archivo, s);
                a.setGenero(s);

                getline(archivo, s);
                n = stoi(s);
                a.setSalud(n);

                civ[i].agregarFinal(a);
            }
        }
    archivo.close();
    }
}