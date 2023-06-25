#include <stdio.h>
#include <stdlib.h>
#define N 4

typedef struct iden{
  char name[40];
  int note[3];
} iden;

void leer(iden *R) {
  printf("\nIngresar datos de alumno\n\n");
  printf("Ingresar nombre\n");
  fflush(stdin);
  gets(R -> name);
  fflush(stdin);
  printf("Ingresar notas: \n");
  for (int i = 0; i < 3; i++) {
    fflush(stdin);
    scanf("%d", &R -> note[i]);
  };
}

void leerVector(iden curso[]) {
  iden x;
  printf("---------------------------------------------------------------");
  for (int i = 0; i < N; i++) {
    printf("\n\tCarga del estudiante n° %d\n", i + 1);
    fflush(stdin);
    leer(&x);
    curso[i] = x;
  }
}

void mostrar (iden v) {
  printf("\nLos datos del alumno ingresados son:\n");
  fflush(stdin);
  printf("Nombre: %s", v.name);
  printf("\t\tNotas: ");
  for (int i = 0; i < 3; i++) {
    printf("[%d]", v.note[i]);
  }
  printf("\n---------------------------------------------------------------");
}

void mostrarVector(iden curso[]) {
  printf("---------------------------------------------------------------\n");
  for (int i = 0; i < N; i++) {
    printf("\tMostrar estudiante n° %d", i + 1);
    mostrar(curso[i]);
    printf("\n");
  }
}

int main () {
  iden vector[N]; // array registers

  printf("\nInvocar funcion de carga\n");
  leerVector(vector);

  printf("\nInvocar la funcion de muestra\n");
  mostrarVector(vector);
};