#include "Evaluacion.h"
#include <iostream>
int main(){
    Evaluacion e;
    Cola res;
    int resultado;
    res.Encolar(2); 
    res.Encolar(5); 
    res.Encolar('*'); 
    res.Encolar(1); 
    res.Encolar(2); 
    res.Encolar('*'); 
    res.Encolar('-'); 
    res.Encolar(9); 
    res.Encolar(7); 
    res.Encolar('-'); 
    res.Encolar('/'); 
    res.Mostrar();
    resultado = e.evaluar_expresionPostfija(res);
    cout<<resultado;
    resultado = e.evaluar_expresionInfija2("(3+2-3)");
    cout<<resultado;
}   
