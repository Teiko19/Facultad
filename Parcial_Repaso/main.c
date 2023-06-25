#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"
#define USER 2021
#define PASS 123

void main() {
  int value = validator(USER, PASS), option;
  alum arrAlum[6];
  if (value == 1) {
    do{
      menu(&option);
      switch(option) {
        case 0: 
          printf("------------------------------------------------------------------------------\n");
          printf("\tFinalizacion del sistema");
          printf("\n-----------------------------------------------------------------------------");
          exit(-1);
        break;
        case 1: cargarArr(arrAlum); break;
        case 2: cargarFinal(arrAlum); break;
        case 3: cargarArchivo(arrAlum); break;
      }
    } while (option != 0);
  };
}