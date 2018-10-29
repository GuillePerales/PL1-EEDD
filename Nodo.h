#ifndef NODO_H
#define NODO_H

#include <iostream> 
using namespace std;

class Nodo
{
public:
    Nodo(int v, Nodo *sig = NULL);
    ~Nodo();

private:
    int valor;
    Nodo* siguiente;
    
    friend class Pila;
    friend class Cola;
};

typedef Nodo* pNodo;

#endif // NODO_H
