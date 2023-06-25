#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"

void main () {
  int option;
  do{
    menu(&option);
    switch(option) {
      case 0: 
        printf("------------------------------------------------------------------------------\n");
        printf("\tFinalizacion del sistema");
        printf("\n-----------------------------------------------------------------------------");
        exit(-1);
      break;
      /* CASE DE OPCIONES */
    }
  } while (option != 0);
}