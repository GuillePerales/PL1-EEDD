#include "Evaluacion.h"

Evaluacion::Evaluacion(){

}

int Evaluacion::evaluar_expresionInfija(char expresion[]){
    Pila pilaNum;
    Pila pilaOp;
    int i,x,y,res,a,b;
    char op;
    bool anteriorNum;
    bool anteriorSim;
    bool siguienteNeg;
    size_t size;
    size = strlen(expresion);
    for(i=0;i<size;i++){
        if(expresion[i]==41 && !pilaOp.esVacia() && !pilaNum.esVacia()){
            res=0;
            x = pilaNum.Cima();
            pilaNum.Desapilar();
            y = pilaNum.Cima();
            pilaNum.Desapilar();
            op = pilaOp.Cima();
            pilaOp.Desapilar();
            if(op=='+'){res=y+x;}
            if(op=='-'){res=y-x;}
            if(op=='*'){res=y*x;}
            if(op=='/'){res=y/x;}
            pilaNum.Apilar(res);
            if(pilaOp.Cima()==40){pilaOp.Desapilar();}
        }
        else{ 
            if(isdigit(expresion[i])){
                if(anteriorNum){
                    a = pilaNum.Cima();
                    if(a>=0){
                        pilaNum.Desapilar();
                        b = a*10+(expresion[i]-48);
                    }
                    else{
                        pilaNum.Desapilar();
                        b = a*10-(expresion[i]-48);
                   }
                }
                else{
                    b = expresion[i]-48;
                }
                if(siguienteNeg){
                    pilaNum.Apilar(-b);
                }
                else{
                    pilaNum.Apilar(b);
                }
                anteriorNum = true;
                anteriorSim = false;
                siguienteNeg= false;
            }
            else{
                if(expresion[i]==45 && anteriorSim){
                    siguienteNeg = true;
                }
                else{
                    pilaOp.Apilar(expresion[i]);
                }
                anteriorNum = false;
                anteriorSim = true;
            }    
        }
    } 
    return pilaNum.Cima();
}

int Evaluacion::evaluar_expresionInfija2(char expresion[]){
    Pila pilaNum;
    Pila pilaOp;
    int i,x,y,res,a,b,naux;
    char op;
    bool anteriorNum;
    bool anteriorSim;
    bool siguienteNeg;
    size_t size;
    size = strlen(expresion);
    for(i=0;i<size;i++){
        std::cout<<"\n---Numero: "<<i<<"---\n";
        std::cout<<"Antes de nada\n";
        pilaOp.Mostrar();
        pilaNum.Mostrar();
        if(expresion[i]==41 && !pilaOp.esVacia() && !pilaNum.esVacia()){
            Pila pilaNumAux;
            Pila pilaOpAux;
            while(pilaOp.Cima()!=40){
                std::cout<<"\n---Numero(while): "<<i<<"---\n";
                res=0; 
            	op = pilaOp.Cima();
                std::cout<<"Operacion:\t\n"<<op;
                pilaOp.Desapilar();
                if(op==43 || op==45 && (pilaOp.Cima()==47 || pilaOp.Cima()==42)){
                    std::cout<<"1\n";
                    pilaOpAux.Apilar(op);
                    std::cout<<"2\n";
                    naux = pilaNum.Cima();
                    std::cout<<"Numero: "<<naux<<"\n";
                    pilaNumAux.Apilar(naux);
                    std::cout<<"4\n";
                    pilaNum.Desapilar();
                    std::cout<<"5\n";
                    pilaNumAux.Mostrar();
                    pilaOpAux.Mostrar();
                }
                else{
                    std::cout<<"El siguiente no es multiplicacion\n";
                    x = pilaNum.Cima();
            	    pilaNum.Desapilar();
            	    y = pilaNum.Cima();
             	    pilaNum.Desapilar();
                	std::cout<<"Antes de operar\n";
                	pilaOp.Mostrar();
                	pilaNum.Mostrar();         	
                     if(op=='*'){res=y*x;}
                     if(op=='/'){res=y/x;}             
                    if(op=='+'){res=y+x;}
                     if(op=='-'){res=y-x;}   
                	std::cout<<"\nResultado"<<res<<"\n";
                	pilaNum.Apilar(res);
                	std::cout<<"Despues de operar\n";
                	pilaOp.Mostrar();
                	pilaNum.Mostrar();
	            }
             }

             if(!pilaOpAux.esVacia()){
                while(!pilaOpAux.esVacia()){
                        pilaNumAux.Mostrar();
                        pilaOpAux.Mostrar();
                        std::cout<<"operaciones Aux\n";
                        op = pilaOpAux.Cima();
                        pilaOpAux.Desapilar();
                        y = pilaNum.Cima();
                        pilaNum.Desapilar();
                        x = pilaNumAux.Cima();
                        pilaNumAux.Desapilar();
                        if(op=='+')res=y+x;
                        if(op=='-')res=y-x;
                        pilaNum.Apilar(res);
                    	std::cout<<"\nResultado"<<res<<"\n";
                     }
                }
            
            if(pilaOp.Cima()==40)pilaOp.Desapilar();
        }
	
        else{
            std::cout<<"Metiendo: "<<expresion[i]<<"\n";
            if(isdigit(expresion[i])){
                if(anteriorNum){
                    a = pilaNum.Cima();
                    if(a>=0){
                        pilaNum.Desapilar();
                        b = a*10+(expresion[i]-48);
                    }
                    else{
                        pilaNum.Desapilar();
                        b = a*10-(expresion[i]-48);
                   }
                }
                else{
                    b = expresion[i]-48;
                }
                
                if(siguienteNeg){
                    pilaNum.Apilar(-b);
                }
                else{
                    pilaNum.Apilar(b);
                }
                anteriorNum = true;
                anteriorSim = false;
                siguienteNeg= false;
            }
            else{
                if(expresion[i]==45 && anteriorSim){
                    siguienteNeg = true;
                }
                else{
                    pilaOp.Apilar(expresion[i]);
                }
                anteriorNum = false;
                anteriorSim = true;
            }    
        } 
    }
    if(!pilaOp.esVacia()){
        if(pilaOp.Cima()==41 ||pilaOp.Cima()==40)pilaOp.Desapilar();
        else{
            op = pilaOp.Cima();
            pilaOp.Desapilar();
            x = pilaNum.Cima();
            pilaNum.Desapilar();
            y = pilaNum.Cima();
            pilaNum.Desapilar();
            if(op=='+')res=y+x;
            if(op=='-')res=y-x;
            if(op=='*')res=y*x;
            if(op=='/')res=y/x;
            pilaNum.Apilar(res);
        }

    }
    return pilaNum.Cima();
}
Cola Evaluacion::expresionInfija_a_expresionPostfija(char expresion[]){
    Pila pilaNum;
    Pila pilaOp;
    Cola colaRes;
    int i,a,b,x,y;
    char op;
    bool anteriorNum;
    bool anteriorSim;
    bool siguienteNeg;
    size_t size;
    size = strlen(expresion);
    for(i=0;i<size;i++){
        std::cout<<"\n--- "<<i<<" ---\n";
        colaRes.Mostrar();
        if(expresion[i]==41){
            if(!pilaNum.esVacia()){
                x=pilaNum.Cima();
                pilaNum.Desapilar();
                y=pilaNum.Cima();
                pilaNum.Desapilar();
                op = pilaOp.Cima();
                pilaOp.Desapilar();
                colaRes.Encolar(y);
                colaRes.Encolar(x);
                colaRes.Encolar(op);
            }
            else{
                //if(pilaOp.Cima()!=41){
                    op = pilaOp.Cima();
                    pilaOp.Desapilar();
                    colaRes.Encolar(op);
                
            }

            if(pilaOp.Cima()==40)pilaOp.Desapilar();
        }

        else{

            if(isdigit(expresion[i])){
                if(anteriorNum){
                    a = pilaNum.Cima();
                    if(a>=0){
                        pilaNum.Desapilar();
                        b = a*10+(expresion[i]-48);
                    }
                    else{
                        pilaNum.Desapilar();
                        b = a*10-(expresion[i]-48);
                   }
                }
                else{
                    b = expresion[i]-48;
                }
                if(siguienteNeg){
                    pilaNum.Apilar(-b);
                }
                else{
                    pilaNum.Apilar(b);
                }
                anteriorNum = true;
                anteriorSim = false;
                siguienteNeg= false;
            }
            else{
                if(expresion[i]==45 && anteriorSim){
                    siguienteNeg = true;
                }
                else{
                    pilaOp.Apilar(expresion[i]);
                }
                anteriorNum = false;
                anteriorSim = true;
            }    
        }
    }
    std::cout<<"Cola final: ";
    colaRes.Mostrar();
    std::cout<<"\n";
    return colaRes;
}

int Evaluacion::evaluar_expresionPostfija(Cola expresion){
    Pila pilaNumAux;
    int x,y,res;
    char op;
    while(!expresion.esVacia()){
        if(expresion.verPrimero()<40 || expresion.verPrimero()>47){
            pilaNumAux.Apilar(expresion.verPrimero());
            pilaNumAux.Mostrar();
        }
        else{
            pilaNumAux.Mostrar();
            x = pilaNumAux.Cima();
            pilaNumAux.Desapilar();
            y = pilaNumAux.Cima();
            pilaNumAux.Desapilar();
            op = expresion.verPrimero();
            if(op=='+'){res=y+x;}
            if(op=='-'){res=y-x;}
            if(op=='*'){res=y*x;}
            if(op=='/'){res=y/x;}
            pilaNumAux.Apilar(res);
        }
        expresion.Desencolar();
    }
    return pilaNumAux.Cima();
}

bool Evaluacion::es_correcta(char expresion[]){



}
