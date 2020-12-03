#ifndef ALDEANO_H
#define ALDEANO_H

#include<iostream>
#include<iomanip>
using namespace std;

class Aldeano{

public:
    Aldeano(){}
    Aldeano(const string &nombre, size_t edad, const string &genero, size_t salud)
    : nombre(nombre), edad(edad), genero(genero), salud(salud) {}

    void setNombre(const string &nombre);
    string getNombre() const;

    void setEdad(size_t edad);
    size_t getEdad() const;

    void setGenero(const string &genero);
    string getGenero();

    void setSalud(size_t salud);
    size_t getSalud() const;

    friend ostream& operator<<(ostream &out, const Aldeano &a){
        out << left;
        out << setw(14) << a.nombre;
        out << setw(8) << a.edad;
        out << setw(10) << a.genero;
        out << setw(6) << a.salud;

        return out;
    }

    bool operator<(const Aldeano &a){
        return nombre < a.getNombre();
    }

    bool operator==(const Aldeano& a){
        return nombre == a.nombre;
    }

    bool operator==(const Aldeano& a) const{
        return nombre == a.nombre;
    }

private:
    string nombre;
    size_t edad;
    string genero;
    size_t salud;

};

#endif