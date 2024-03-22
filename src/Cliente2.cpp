#include "Cliente2.h"

Cliente2::Cliente2()
{
     private:
    int idCliente;
    string nombre;
    string apellido;
        public:
    Cliente(){
        this->idCliente= 0;
}

Cliente(int idc, string n, string a){
        this->idCliente= idc;
        this->nombre= n;
        this->apellido= a;
    }
    int getIdCliente(){
        return this->idCliente;
    }
    string getNombre(){
        return this->nombre;
    }
    string getApellido(){
        return this->apellido;
    }
};
