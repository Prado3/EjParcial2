#ifndef ESPECIALIDADMEDICA_H_INCLUDED
#define ESPECIALIDADMEDICA_H_INCLUDED

typedef struct {
    int idEspecialidad;
    char especialidadMedica[30];
}stEspecialidadMedica;

void mostrarEspecialidad(stEspecialidadMedica especialidad);

#endif // ESPECIALIDADMEDICA_H_INCLUDED
