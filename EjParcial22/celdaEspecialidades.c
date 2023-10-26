#include "celdaEspecialidades.h"
#include "nodoPaciente.h"

int alta(stCelda adl[], int v, stPaciente paciente, stEspecialidadMedica especialidad){
    int pos = buscarPos(adl,v,especialidad);
    if(pos == -1){
        v = agregarCelda(adl,v,especialidad);
        pos = v-1;
    }
    adl[pos].listaPaciente = agregarArbol(adl[pos].listaPaciente,paciente);
    return v;
}

int buscarPos(stCelda adl[],int v,stEspecialidadMedica especialidad){
    int pos = -1;
    int i=0;

    while(i<v && pos==-1){
        if(adl[i].dato.idEspecialidad==especialidad.idEspecialidad){
            pos = i;
        }
        i++;
    }
    return pos;
}

int agregarCelda(stCelda adl[],int v,stEspecialidadMedica especialidad){
    adl[v].dato = especialidad;
    adl[v].listaPaciente = inicLista();
    return v+1;
}
