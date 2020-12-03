#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class Videogame{

    string nusuario;
    vector<Civilizacion> civilizaciones;  
    
public:
    Videogame();

    void agregar(const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t pos);
    void inicializar(const Civilizacion &c, size_t n);
    Civilizacion front();
    Civilizacion back();

    void ordenarNombre();
    void ordenarXPOS();
    void ordenarYPOS();
    void ordenarPuntos();

    void erase(string n);
    Civilizacion* buscar(const Civilizacion &c);

    void modificar(Civilizacion *c);

    void resumen();

    void respaldar();
    void recuperar();

    size_t total();

    void setUsuario(const string &nu){
        nusuario = nu;
    }
    string getUsuario(){
        return nusuario;
    }

    friend Videogame& operator<<(Videogame &v, const Civilizacion &c){
        v.agregar(c);
        return v;
    }

};

#endif