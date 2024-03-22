#include <iostream>
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"
#include "Prestamo.h"

#define TAM 5
using namespace std;

int menu() {
    int op;
    cout << "-------MENU DE OPCIONES-------" << endl;
    cout << "1. Agregar clientes a la lista." << endl;
    cout << "2. Agregar prestamo a la lista." << endl;
    cout << "3. Hacer pago de prestamos. " << endl;
    cout << "4. Mostrar lista de clientes." << endl;
    cout << "5. Mostrar lista de prestamos." << endl;
    cout << "6. Mostar detalles del prestamo." << endl;
    cout << "7. Salir." << endl;
    cin >> op;

    return op;
}

Cliente *agregarCliente() {
    Cliente *cliente;
    int idc = 0;
    string n;
    string a;
    cout << "Ingrese el ID del cliente." << endl;
    cin >> idc;
    cout << "Ingrese el nombre del cliente." << endl;
    cin >> n;
    cout << "Ingrese el apellido del cliente" << endl;
    cin >> a;

    cliente = new Cliente(idc, n, a);
    return cliente;
}

Cliente *buscarCliente(Cliente *list[], int cont, int idC){
    bool encontrado = false;
    int contador=0;
    Cliente *cliente = NULL;
    while (contador < cont && !encontrado){
        if (list[contador]->getIdCliente()== idC){
            encontrado = true;
            cliente = list[contador];
        }
        else
        {
            contador++;
        }
    }

    return cliente;
}

Prestamo *agregarPrestamos(Cliente *cliente){
    Prestamo  *prestamo;
    Fecha *fecha;

    int numeroPrestamo= 0;
    int dia = 0, mes = 0, anio = 0;
    float saldoPendiente;

    cout<<"ingrese el dia de la aprobacion"<<endl;
    cin>>dia;
    cout<<"ingrese el mes de la aprobacion"<<endl;
    cin>>mes;
    cout<<"ingrese el anio de la aprobacion"<<endl;
    cin>>anio;
    cout<<"ingrese el prestamo a realizar"<<endl;
    cin>>numeroPrestamo;
    cout<<"isaldo pendiente"<<endl;
    cin>>saldoPendiente;

    fecha = new Fecha(dia, mes, anio);
    prestamo = new Prestamo(numeroPrestamo, cliente, fecha, saldoPendiente);
    prestamo->setMontoAprobado(saldoPendiente);



}

Prestamo *buscarPrestamo(Prestamo *lstPrestamo[], int numeroPrestamo, int contadorPrestamo)
{
    Prestamo *prestamo = NULL;
    bool resultado = false;
    int cont=0;
    while(cont<contadorPrestamo && !resultado){
        if (lstPrestamo[cont]->getNumeroPrestamo()==numeroPrestamo){
            prestamo=lstPrestamo[cont];
            resultado= true;
        }else{
        cont++;
        }
    }
    return prestamo;
}

void realizarPago(Prestamo *prestamo){
    Fecha *fecha;
    Pago *pago;
    int dia=0, mes=0, anio=0;
    float p=0;
    cout<<"Ingrese el dia que realiza el pago"<<endl;
    cin>>dia;
    cout<<"Ingrese el mes que realiza el pago"<<endl;
    cin>>mes;
    cout<<"Ingrese el anio que realiza el pago"<<endl;
    cin>>anio;
    cout<<"Ingrese el monto del pago a realizar"<<endl;
    cin>>p;
    fecha = new Fecha(dia, mes, anio);
    pago = new Pago(fecha, p);
    prestamo->hacerPago(pago);



}

int main() {

    Cliente *cliente;
    Cliente *lstCliente[TAM];
    Prestamo *prestamo;
    Prestamo *lstPrestamo[TAM];
    Pago *pago;
    Pago *lstPago[TAM];

    int op=0;
    int idCliente=0;
    int contCliente=0;
    int numeroPrestamo=0;
    int contPrestamo=0;
    int contAbono=0;
    int numeroAbono=0;

    do{
        op=menu();
        switch (op){
        case 1: /*agregar clientes*/

            if(contCliente<TAM){
                lstCliente[contCliente]= agregarCliente();
                cout<<"el cliente se agrego correctamente."<<endl;
                contCliente++;

            }else{
                cout<<"la lista esta llena."<<endl;
            }
            break;

        case 2: /*agregar prestamo*/

            if(contAbono<TAM){
                if(contCliente==0){
                    cout<<"la lista esta vacia."<<endl;
                }else{

                cout<<"ingrese el ID del cliente."<<endl;
                cin>>idCliente;

                cliente = buscarCliente(lstCliente, idCliente, contCliente);
                if(cliente){
                    lstPrestamo[contPrestamo]= agregarPrestamos(cliente);
                    cout<<"el prestamo fue realizado exitosamente."<<endl;
                    contPrestamo++;
                    }else{
                        cout<<"el cliente no fue encontrado en la lista, intente nuevamente."<<endl;
                    }
                }
                }else{
                cout<<"la lista de prestamos esta llena."<<endl;
                }
                break;

        case 3: /*pago de prestamo*/

            if(contPrestamo==0){
                cout<<"la lista de prestamos esta vacia."<<endl;
            }else{
                cout<<"ingrese el numero de prestamo a abonar."<<endl;
                cin>>numeroPrestamo;

                prestamo = buscarPrestamo(lstPrestamo, numeroPrestamo, contPrestamo);

                if(prestamo){
                    if(prestamo->getSaldoPendiente()==0){
                        cout<<"termino de pago el prestamo satisfactoriamente."<<endl;
                    }else{
                        realizarPago(prestamo);
                        cout<<"el pago se realizo corectamente."<<endl;
                    }

                }else{
                    cout<<"el numero de prestamo no fue econtrado en la lista, intente nuevamente."<<endl;
                }
            }
            break;

        case 4:
                /*mostrar cliente*/

            if(contCliente==0){
                cout<<"la lista esta vacia."<<endl;
            }else{
                cout<<"ID \t NOMBRE \t APELLIDO \t"<<endl;
                for(int i=0; i< contCliente; i++){
                    cout<< lstCliente[i]->getIdCliente()<< "\t";
                    cout<< lstCliente[i]->getNombre()<< "\t";
                    cout<< lstCliente[i]->getApellido()<< "\t"<<endl;
                }

            }
            break;

        case 5:
            /*lista de prestamos*/

            if(contPrestamo==0){
                cout << "La lista esta vacia, intente nuevamente."<<endl;
            }else{
                cout<<"N� \t NOMBRE \t APELLIDO \t FECHA APROBACION \t MONTO APROVADO \t SALDO PENDIENTE"<<endl;
                for(int i = 0; i<contPrestamo; i++){
                  cout<< lstPrestamo[i]->getNumeroPrestamo()<< "\t";
                  cout<< lstPrestamo[i]->getCliente()->getNombre()<< "\t \t";
                  cout<< lstPrestamo[i]->getCliente()->getApellido()<< "\t \t";
                  lstPrestamo [i]->getFechaAprobacion()->mostrarFecha();
                  cout<< "\t \t"<< lstPrestamo[i]->getMontoAprobado() <<"\t \t";
                  cout<< lstPrestamo[i]->getSaldoPendiente()<< endl;

                }
            }
            break;

        case 6:
            /*detalles de prestamo*/

            if(contPrestamo==0){
                cout << "La lista esta vacia, intente nuevamente."<<endl;
            }else{
                cout<<"ingrese el numero de prestamo para visualizar los detalles"<<endl;
                cin>>numeroPrestamo;

                prestamo=buscarPrestamo(lstPrestamo, numeroPrestamo, contPrestamo);
                if(prestamo){
                    cout<<"el numero de prestamo es: " << prestamo->getNumeroPrestamo()<< "\t";
                    cout<<"nombre del cliente: " << prestamo->getCliente()->getNombre()<< "\t \t";
                    cout<<"apellido del cliente: " << prestamo->getCliente()->getApellido()<< "\t \t";
                    cout<<"saldo pendiente: " << prestamo->getSaldoPendiente()<< "\t \t";
                    cout<<"monsto aprobado: " <<prestamo ->getMontoAprobado()<< endl;
                    Pago **lst=prestamo->getLstPago();

                    cout<< "N� \t FECHA ABONO \t MONTO PAGADO \t"<<endl;
                    for(int i=0; prestamo->getContadorPagos(); i++){
                            cout<< (i+1) << endl;
                            lst[i]->getFechaPago()->mostrarFecha();
                            cout << "\t \t" <<lst[i]->getmontoPago() << endl;
                    }

                } else{
                    cout<< "el numero de prestamo no fue encontrado" << endl;
                }
            }
                break;
        case 7:
            cout << "saliendo del sistema......"<<endl;
            break;
        default:
            cout<< "opcion invalida, ingrese una opcion nuevamente."<<endl;
            break;
    }
    system("pause");
    }while(op!=7);

    return 0;
}

