#include "Pila.h"

Pila::Pila(){
    cima = NULL;
}

void Pila:: Apilar (int v){
    pNodo nuevo;
    nuevo = new Nodo (v, cima);
    cima = nuevo;
}

void Pila:: Desapilar (){
    pNodo nodo;
    int v;
    if(cima){
        nodo = cima;
        cima = nodo->siguiente;
        v = nodo ->valor;
        delete nodo;
    }
}
void Pila :: Mostrar(){
    pNodo aux = cima;
    cout << "Mi pila: ";
    while (aux){
        cout << "-> " << aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
}

int Pila :: Cima(){
    pNodo aux = cima;
    return aux->valor;
}

bool Pila:: esVacia(){
    return cima == NULL;
}

void Pila:: Vaciar(){
    pNodo aux;
    while(cima){
        aux = cima;
        cima = aux->siguiente;
        delete aux;
    }
}
bool Pila::hayMulDiv(){
    pNodo aux = cima;
    while(aux){
        if(aux->valor==40) return false;
        if(aux->valor==47 || aux->valor==42) return true;
        aux = aux->siguiente;
    }
    return false;
}



Pila::~Pila(){
    pNodo aux;
    while(cima){
        aux = cima;
        cima =cima->siguiente;
        delete aux;
    }
}
