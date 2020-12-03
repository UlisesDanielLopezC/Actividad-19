#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include<list>
#include<vector>
#include "aldeano.h"

class Civilizacion{

    string nombre;
    int xpos;
    int ypos;
    int puntuacion;

    list<Aldeano> aldeanos;

public:
    Civilizacion();
    Civilizacion(const string &nombre, int xpos, int ypos, int puntuacion);

    void setNombre(const string &nombre);
    string getNombre();

    void setXpos(int xpos);
    int getXpos();

    void setYpos(int ypos);
    int getYpos();

    void setPuntuacion(int puntuacion);
    int getPuntuacion();

    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);

    void eliminarNombre(const string &n);
    void eliminarSaludMin(size_t s);
    void eliminarEdad();

    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    Aldeano* buscarAldeano(const Aldeano &a);
    void modificarAldeano(Aldeano *a);
    void mostrarAldeanos();

    void respaldarAldeanos();
    void recuperarAldeanos(vector<Civilizacion> &civ, int actual);

    friend ostream& operator<<(ostream &out, const Civilizacion &c){

        out << left;
        out << setw(16) << c.nombre;
        out << setw(12) << c.xpos;
        out << setw(12) << c.ypos;
        out << setw(7) << c.puntuacion;
        out << endl;

        return out;
    }

    friend istream& operator>>(istream &in, Civilizacion &c){

        cout <<"Nombre: ";
        getline(cin, c.nombre);
        
        cout <<"Posicion en X: ";
        cin >> c.xpos;

        cout <<"Posicion en Y: ";
        cin >> c.ypos; 

        cout <<"Puntuacion: ";
        cin >> c.puntuacion; cin.ignore();

        return in;
    }

    bool operator==(const Civilizacion& c){
        return nombre == c.nombre;
    }

    bool operator==(const Civilizacion& c) const{
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion& c){
        return nombre < c.nombre;
    }

};

#endif