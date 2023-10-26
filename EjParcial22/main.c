#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registroMedico.h"
#include "celdaEspecialidades.h"
#define ARCHI_REGISTRO "registroMedico.dat"
#define DIM 50

void mostrarArchivoRegistro(char nombreArchi[]);
stEspecialidadMedica retornarEspecialidad(stRegistroMedico registro);
stPaciente retornasPaciente(stRegistroMedico registro);
int cargaAdl(char nombreArchi[],int v, int dim,stCelda adl[]);
void mostrarEstructuraCompleta(stCelda adl[],int v);
stEspecialidadMedica cargarEspe(char especialidad[]);
int agregarEspecialidadMedica(char especialidad[],stCelda adl[],int v, int dim);
int buscarEspecialidad(char espe[],stCelda adl[],int v);
int buscarRecursivoArbol(nodoPaciente* arbol,int flag, char nombre[], char apellido[]);
int buscarPaciente(stCelda adl[], int v,char nombre[],char apellido[],char espe[]);

int main()
{
    stCelda adl[DIM];
    int v=0;
    int flag=0;
    char espe[12];
    char nombre[30];
    char apellido[30];
    //mostrarArchivoRegistro(ARCHI_REGISTRO);
    v = cargaAdl(ARCHI_REGISTRO,v,DIM,adl);
    //printf("\n ingrese una nueva especialidad: ");
    //gets(espe);
    //v = agregarEspecialidadMedica(espe,adl,v,DIM);
    //printf("\n ingrese especialidad a buscar: ");
    //gets(espe);
    //flag=buscarEspecialidad(espe,adl,v);
    //if(flag==0){
    //    printf("\n Nose se encuentra %s", espe);
    //}else{
    //    printf("\n Se encontro la especialidad %s",espe);
    //}
    printf("\n ingrese nombre paciente: ");
    gets(nombre);
    printf("\n ingrese apellido paciente: ");
    gets(apellido);
    flag=buscarPaciente(adl,v,nombre,apellido,espe);
    if(flag==0){
        printf("\n Nose se encuentra el paciente %s %s", nombre, apellido);
    }else{
        printf("\n Se encontro el paciente %s %s en la especialidad %s",nombre,apellido,espe);
    }
    mostrarEstructuraCompleta(adl,v);
    return 0;
}

void mostrarArchivoRegistro(char nombreArchi[]){
    stRegistroMedico registro;
    FILE* archi = fopen(nombreArchi,"rb");
    if(archi){
        while(fread(&registro,sizeof(stRegistroMedico),1,archi)>0){
            mostrarRegistro(registro);
        }
    }
}

int cargaAdl(char nombreArchi[],int v, int dim,stCelda adl[]){
    stRegistroMedico registro;
    stEspecialidadMedica especialidad;
    stPaciente paciente;
    FILE* archi = fopen(nombreArchi,"rb");
    if(archi){
        while(v<dim && fread(&registro,sizeof(stRegistroMedico),1,archi)>0){
            especialidad = retornarEspecialidad(registro);
            paciente = retornasPaciente(registro);
            v = alta(adl,v,paciente,especialidad);
        }
        fclose(archi);
    }
    return v;
}

stEspecialidadMedica retornarEspecialidad(stRegistroMedico registro){
    stEspecialidadMedica especialidad;
    strcpy(especialidad.especialidadMedica,registro.especialidadMedica);
    especialidad.idEspecialidad = registro.idEspecialidad;
    return especialidad;
}

stPaciente retornasPaciente(stRegistroMedico registro){
    stPaciente paciente;
    strcpy(paciente.nombrePaciente,registro.nombrePaciente);
    strcpy(paciente.apellidoPaciente,registro.apellidoPaciente);
    strcpy(paciente.fechaAtencion,registro.fechaAtencion);
    strcpy(paciente.diagnostico,registro.diagnostico);
    strcpy(paciente.nombreDoctor,registro.nombreDoctor);
    paciente.idPaciente = registro.idPaciente;
    return paciente;
}

void mostrarEstructuraCompleta(stCelda adl[],int v){
    for(int i=0;i<v;i++){
        mostrarEspecialidad(adl[i].dato);
        inorder(adl[i].listaPaciente);
    }
}

int agregarEspecialidadMedica(char especialidad[],stCelda adl[],int v, int dim){
    stEspecialidadMedica espe;
    stPaciente paciente;
    espe = cargarEspe(especialidad);
    if(v-1<dim){
        v = alta(adl,v,paciente,espe);
    }
    return v;
}

stEspecialidadMedica cargarEspe(char especialidad[]){
    stEspecialidadMedica espe;
    strcpy(espe.especialidadMedica,especialidad);
    espe.idEspecialidad=rand()%100000;
    return espe;
}

int buscarEspecialidad(char espe[],stCelda adl[],int v){
    int j=0;
    for(int i=0;i<v;i++){
        if(strcmp(espe,adl[i].dato.especialidadMedica)==0){
            j=1;
        }
    }
    return j;
}

int buscarPaciente(stCelda adl[], int v,char nombre[],char apellido[],char espe[]){
    int i=0;
    int flag=0;
    while(i<v && flag == 0){
        flag=buscarRecursivoArbol(adl[i].listaPaciente,flag,nombre,apellido);
        strcpy(espe,adl[i].dato.especialidadMedica);
        i++;
    }
    return flag;
}

int buscarRecursivoArbol(nodoPaciente* arbol,int flag, char nombre[], char apellido[]){
    if(arbol){
        flag = buscarRecursivoArbol(arbol->izq,flag,nombre,apellido);
        flag = buscarRecursivoArbol(arbol->der,flag,nombre,apellido);
        if(strcmp(arbol->dato.nombrePaciente,nombre)==0 && strcmp(arbol->dato.apellidoPaciente,apellido)==0){
            flag=1;
        }
    }
    return flag;
}



