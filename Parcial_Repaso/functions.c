#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int validator(int USER, int PASS) {
  int control = 4, valueUser, valuePass, valueAcces;
  do {
    printf("------------------------------------------------------------------------------");
    printf("\nIngresar usuario: ");
    fflush(stdin);
    scanf("%d", &valueUser);
    printf("ingresar contraseña: ");
    fflush(stdin);
    scanf("%d", &valuePass);
    if (valueUser != USER || valuePass != PASS) {
      if (valueUser != USER) printf("\nError de usuario, volver a intentar");
      if (valuePass != PASS) printf("\nError de contraseña, volvera intentar");
      control--;
      if (control != 0) printf("\n\n\tIntentos restantes: %d\n", control);
    }
    if (control == 0) {
      printf("\n------------------------------------------------------------------------------");
      printf("\n\tMaximo de intentos permitidos, finalizacion del sistema");
      printf("\n------------------------------------------------------------------------------");
      exit(-1);
    }
  } while (valueUser != USER || valuePass != PASS);
  printf("------------------------------------------------------------------------------");
  printf("\nIngreso al sistema exitoso\n");
  return 1;
}

void menu(int *option) {
  printf("------------------------------------------------------------------------------");
  do {
    printf("\nOpciones:\n");
    printf("\t1. Cargar y mostrar alumnos\n");
    printf("\t2. Calcular y mostrar nota final de alumnos\n");
    printf("\t3. Crear archivo con informacion de alumnos\n");
    printf("\t0. Para salir del sistema\n");
    printf("Seleccion: ");
    fflush(stdin);
    scanf("%d", &*option);
    if (*option < 0 || *option > 3) {
      printf("------------------------------------------------------------------------------");
      printf("\nOpcion incorrecta, seleccione una opcion correcta");
      printf("\n------------------------------------------------------------------------------");
    }
  } while (*option < 0 || *option > 3);
}

void cargarArr(alum v[6]) {
  FILE *data = fopen("C:\\Users\\tomib\\Desktop\\Facultad\\Programacion 1\\Parcial_Repaso\\alumnos.txt", "r");
  printf("------------------------------------------------------------------------------");
  int i = 0;
  if (data != NULL) {
    while(!feof(data)) {
      fflush(stdin);
      fscanf(data, "%d\t%d\t%f\t%f\t%f\t%s\t%s", &v[i].matricula, &v[i].asistencia , &v[i].notas[0], &v[i].notas[1], &v[i].notas[2], &v[i].apellido, &v[i].nombre);
      i++;
    };
    printf("\n\t\tALUMNOS Y NOTAS\nMatri\tAsist\tNota1\tNota2\tPract\tApellido Y Nombre");
    for (int j = 0; j < 6; j++) 
      printf("\n%d\t  %d\t%.2f\t%.2f\t%.2f\t%s %s", v[j].matricula, v[j].asistencia / 100, v[j].notas[0], v[j].notas[1], v[j].notas[2], v[j].apellido, v[j].nombre);
    fclose(data);
    printf("\n");
  } else {
    printf("\n\nError al abrir el archivo");
    exit(-1);
  }
}

void cargarFinal(alum v[6]) {
  float porcParc, porcPract, total;
  printf("------------------------------------------------------------------------------");
  printf("\n\t\tNOTAS FINALES\nApellido y Nombre\tNota Final Cursada\n");
  for (int i = 0; i < 6; i++) {
    porcPract = v[i].notas[2] * 0.4;
    porcParc = (v[i].notas[0] + v[i].notas[1]) * 0.6;
    total = porcParc + porcPract;
    v[i].notaFinal = porcParc + porcPract;
    printf("%s %s\t\t%.2f\n", v[i].apellido, v[i].nombre, total);
  }
}

void cargarArchivo(alum v[6]) {
  FILE *data = fopen("C:\\Users\\tomib\\Desktop\\Facultad\\Programacion 1\\Parcial_Repaso\\final.txt", "w+");
  printf("------------------------------------------------------------------------------");
  if (data != NULL) {
    for (int i = 0; i < 6; i++) {
      if (v[i].asistencia > 74 && v[i].notaFinal >= 7) fprintf(data, "%d\t%.2f\tpromociona\t %s %s\n", v[i].matricula, v[i].apellido, v[i].nombre);
      if (v[i].asistencia < 75 && v[i].asistencia > 59 && v[i].notaFinal) fprintf(data, "%d\t%.2f\tRinde Final\t %s %s\n", v[i].matricula, v[i].apellido, v[i].nombre);
      if (v[i].asistencia < 60 || v[i].notaFinal) fprintf(data, "%d\t%.2f\tRecursa\t %s %s\n", v[i].matricula, v[i].apellido, v[i].nombre);
    }
    printf("\n\tCarga exitosa\n");
    fclose(data);
  } else {
    printf("\n\nError al crear el archivo\n");
    exit(-1);
  }
}






