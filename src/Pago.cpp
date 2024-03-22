#include "Pago.h"

class Pago
{
private:

    Fecha *fechaPago;
    float montoPago;

public:
    Pago(Fecha *f, float mP){
       this->fechaPago = f;
       this->montoPago= mP;
    }

    Fecha *getFechaPago(){
        return this->fechaPago;
    }
    float getmontoPago(){
        return this->montoPago;
    }

};
