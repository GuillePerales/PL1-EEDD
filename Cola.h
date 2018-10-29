#ifndef COLA_H
#define COLA_H
#include "Nodo.h"

class Cola
{
    private:
        pNodo inicio,fin;
    
    public:
        Cola();
        ~Cola();

        void Encolar(int v);
        void Desencolar();
        int verPrimero();
        bool esVacia();
        void Mostrar();
        
};

#endif // COLA_H
