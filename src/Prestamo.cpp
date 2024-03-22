#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED

#include "cliente.h"
#include "fecha.h"
#include "pago.h"

#define TAM 5

class Prestamo {
private:
    int numeroPrestamo;
    Cliente *cliente;
    Fecha *fechaAprobacion;
    float montoAprobado;
    Pago *lstPagos[TAM];
    float saldoPendiente;
    int contadorPagos;

public:
    Prestamo(){
    }

    Prestamo(int nP, Cliente *cli, Fecha *f, float sP){
        this->numeroPrestamo= nP;
        this->cliente=cli;
        this->fechaAprobacion=f;
        this->saldoPendiente=sP;

    }

    int getNumeroPrestamo() {
        return this->numeroPrestamo;
    }

    void setNumeroPrestamo(int num) {
        this->numeroPrestamo = num;
    }

    Cliente *getCliente() {
        return this->cliente;
    }

    void setCliente(Cliente *cli) {
        this->cliente = cli;
    }

    void setFechaAprobacion(Fecha *f) {
        this->fechaAprobacion = f;
    }

    Fecha *getFechaAprobacion() {
        return this->fechaAprobacion;
    }

    void setMontoAprobado(float mA) {
        this->montoAprobado = mA;
    }

    float getMontoAprobado() {
        return this->montoAprobado;
    }

    bool hacerPago(Pago *p) {
        bool resultado=false;
            if(this->saldoPendiente>0){
                lstPagos[contadorPagos]= p;
                saldoPendiente-= p ->getmontoPago();
                contadorPagos++;
                resultado=true;
            }else{
                cout << "El prestamo ya ha terminado"<<endl;
            }
            return resultado;
    }

    Pago **getLstPago() {
        return this->lstPagos;
    }

    float getSaldoPendiente() {
        return this->saldoPendiente;
    }
    int getContadorPagos(){
        return this->contadorPagos;
    }
};

#endif // PRESTAMO_H_INCLUDED

