#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "functions.c"

void main() {
  int stock = 0, select;
  do {
    verOpciones(&select);
    switch (select) {
      case 1: 
        cargarStock(&stock);
      case 2:
        if (stock != 0) {
          verStock(); 
        } else {
          printf("\nPrimero cargar stock\n\n");
          cargarStock(&stock);
        }
      break;
      case 3:
        if (stock != 0) {
          hacerPedido(); 
        } else {
          printf("\nPrimero cargar stock\n\n");
          cargarStock(&stock);
        }
      break;
      case 0:
        printf("\n\n\tFINALIZACION DEL PROGRAMA");
      break;
    };

  } while (select != 0);
}