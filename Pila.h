#ifndef PILA_H
#define PILA_H
#include "Nodo.h"

class Pila
{
    private:
    	pNodo cima;
    
    public:
        Pila();
        ~Pila();

        void Mostrar();
        void Apilar(int v);
        void Desapilar();
        int Cima();
        bool esVacia();
        bool hayMulDiv();
        void Vaciar();
};

#endif // PILA_H
