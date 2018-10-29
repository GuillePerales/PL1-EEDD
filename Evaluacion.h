#ifndef EVALUACION_H
#define EVALUACION_H
#include "Cola.h"
#include "Pila.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
class Evaluacion{
    public:
        Evaluacion();

        int evaluar_expresionInfija(char expresion[]);
        int evaluar_expresionInfija2(char expresion[]);
        Cola expresionInfija_a_expresionPostfija(char expresion[]);
        int evaluar_expresionPostfija(Cola expresion);
        bool es_correcta(char expresion[]);
};

#endif // EVALUACION_H
