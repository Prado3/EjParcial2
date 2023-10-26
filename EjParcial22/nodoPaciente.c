#include "nodoPaciente.h"
#include <stdlib.h>
#include <stdio.h>

nodoPaciente* inicLista(){
    return NULL;
}

nodoPaciente* crearNodo(stPaciente paciente){
    nodoPaciente* nuevo = (nodoPaciente*) malloc(sizeof(nodoPaciente));
    nuevo->dato = paciente;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

nodoPaciente* agregarArbol(nodoPaciente* arbol, stPaciente paciente){
    if(!arbol){
        arbol = crearNodo(paciente);
    }else{
        if(arbol->dato.idPaciente<paciente.idPaciente){
            arbol->der = agregarArbol(arbol->der,paciente);
        }else{
            if(arbol->dato.idPaciente!=paciente.idPaciente){
                arbol->izq = agregarArbol(arbol->izq,paciente);
            }
        }
    }
    return arbol;
}

void inorder(nodoPaciente* arbol){
    if(arbol){
        inorder(arbol->izq);
        mostrarPaciente(arbol->dato);
        inorder(arbol->der);
    }
}

