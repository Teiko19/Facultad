#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void menu(int *option) {
  printf("\n------------------------------------------------------------------------------");
  do {
    printf("\nOpciones:\n");
    // OPCIONES
    printf("Seleccion: ");
    fflush(stdin);
    scanf("%d", &*option);
    if (*option < 0 || *option > /* OPCION */) printf("\nOpcion incorrecta, seleccione una opcion correcta\n");
  } while (*option < 0 || *option > /* OPCION */);
}