#ifndef CELDAESPECIALIDADES_H_INCLUDED
#define CELDAESPECIALIDADES_H_INCLUDED

#include "especialidadMedica.h"
#include "nodoPaciente.h"

typedef struct{
    stEspecialidadMedica dato;
    nodoPaciente* listaPaciente;
}stCelda;

int buscarPos(stCelda adl[],int v,stEspecialidadMedica especialidad);
int alta(stCelda adl[], int v, stPaciente paciente, stEspecialidadMedica especialidad);
int agregarCelda(stCelda adl[],int v,stEspecialidadMedica especialidad);

#endif // CELDAESPECIALIDADES_H_INCLUDED
