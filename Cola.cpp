#include "Cola.h"

Cola::Cola(){
    fin = NULL;
    inicio = NULL;
}

Cola::~Cola(){
    while(inicio) Desencolar();

}

bool Cola::esVacia(){
    return inicio == NULL;

}

void Cola::Encolar(int v){
    pNodo  nuevo;
    nuevo = new Nodo(v);
if(fin) fin->siguiente = nuevo;
    fin = nuevo;
    if(esVacia()) inicio = nuevo;
}

void Cola::Desencolar(){
    if(!esVacia()){
        pNodo aux;
        aux = inicio;
        inicio = aux->siguiente;
        aux->siguiente = NULL;
        delete aux;
        if(esVacia()) fin = NULL;
    }
}

int Cola::verPrimero(){
    if(!esVacia()) return inicio->valor;
}

void Cola::Mostrar(){
    pNodo aux;
    aux = inicio;
    cout<<"Cola:";
    while(aux){
        cout<<"-> "<<aux->valor;
        aux = aux->siguiente;
    }
    cout<<endl;
    

}

