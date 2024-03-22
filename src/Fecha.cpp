#include "Fecha.h"

#include <iostream>
using namespace std;

class Fecha
{
        private:
    int dia;
    int mes;
    int anio;

        public:
    Fecha()
    {
        this->dia = 0;
        this->mes = 0;
        this->anio = 0;
    }
    Fecha(int d, int m, int a)
    {
        this->dia = d;
        this->mes = m;
        this->anio = a;
    }
    void mostrarFecha()
    {
        cout << this->dia << "/";
        cout << this->mes << "/";
        cout << this->anio << "/";
    }
    int getDia()
    {
        return this->dia;
    }
    int getMes()
    {
        return this->mes;
    }
    int getAnio()
    {
        return this->anio;
    }
};
