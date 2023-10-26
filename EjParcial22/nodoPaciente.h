#ifndef NODOPACIENTE_H_INCLUDED
#define NODOPACIENTE_H_INCLUDED

#include "paciente.h"

typedef struct _nodoPaciente{
    stPaciente dato;
    struct _nodoPaciente* izq;
    struct _nodoPaciente* der;
}nodoPaciente;

nodoPaciente* inicLista();
nodoPaciente* crearNodo(stPaciente paciente);
nodoPaciente* agregarArbol(nodoPaciente* arbol, stPaciente paciente);
void inorder(nodoPaciente* arbol);

#endif // NODOPACIENTE_H_INCLUDED
