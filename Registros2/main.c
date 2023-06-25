#include <stdio.h>
#include <stdlib.h>
#define PERSONAS 10

typedef struct main{
  int peso;
  int cantidad;
} data;

void VectorPeso(int vectorPeso[PERSONAS]);
void VectorCantidad(data arrCant[],int vectorPeso[PERSONAS]);
void MostrarCantidad(data arrCant[]);

void main() {
  data arrCant[PERSONAS];
  int vectorPeso[PERSONAS];
  VectorPeso(vectorPeso);
  VectorCantidad(arrCant, vectorPeso);
  MostrarCantidad(arrCant);
}

void VectorPeso(int vectorPeso[PERSONAS]) {
  for (int i = 0; i < PERSONAS; i++) {
    printf("cargar peso de la persona %d:\t", i + 1);
    fflush(stdin);
    scanf("%d", &vectorPeso[i]);
  }
  printf("V1: ");
  for (int i = 0; i < PERSONAS; i++)
    printf("[%d]", vectorPeso[i]);
  printf("\n");
}

void VectorCantidad(data arrCant[], int vectorPeso[PERSONAS]) {
  int auxPeso;
  int index = 0;
  // RECORRE EL VECTOR 1 PARA GENERAR EL VECTOR 2
  for (int i = 0; i < PERSONAS; i++) {
    auxPeso = vectorPeso[i];
    int encontrado = 0; // VUELVE A HACERLO CON OTRO PESO DEL VECTOR 1 Y LO ANALIZA
    // BUSCA SI YA EXISTE EN EL VECTOR CANTIDAD
    for (int j = 0; j < index; j++)
      if (auxPeso == arrCant[j].peso) {
        arrCant[j].cantidad++;
        encontrado = 1; // DICE QUE SE ENCONTRO
      };
    // SI NO SE ENCONTRO ENTONCES LO AGREGA COMO NUEVO
    if (!encontrado) {
      arrCant[index].peso = auxPeso;
      arrCant[index].cantidad = 1;
      index++;
    }
  }
}

void MostrarCantidad(data arrCant[]) {
  printf("Peso\tCantidad de Personas\n");
  for (int i = 0; i < PERSONAS; i++) {
    printf("%d\t", arrCant[i].peso);
    for (int j = 0; j < arrCant[i].cantidad; j++) printf("*");
    printf("\n");
  }
  exit(-1);
}