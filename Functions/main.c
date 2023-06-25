#include <stdio.h>
#include <stdlib.h>

// MENU DE OPERACIONES
int menu() {
  int select = 0;
  printf("\nSelecciona una opcion de menu\n\n");
  printf("\t1. Cambiar de posicion los valores del array\n");
  printf("\t2. Crear arrays elementos de un array\n");
  printf("\t3. Mostrar elementos de un array\n");
  printf("\t0. Finalizar ejecucion\n");
  fflush(stdin);
  do {
    if (select < 0 || select > 3) 
      printf("\nIngresar un valor correcto\n");
    scanf("%d", &select);
  } while (select < 0 || select > 3);
  return(select);
};

// INTERCAMBIO ENTRE 2 VARIABLES
void Intercambio(int *x, int *y) {
  printf("\nX = %d\tY = %d\n", *x, *y);
  printf("\n\t------------ Intercambiar ------------\n");
  int aux = *x;
  *x = *y;
  *y = aux;
};

// CARGAR ELEMENTOS DEL ARRAY
void charge(int v[], int *x) {
  int size;
  printf("Ingrese la cantidad de elementos del array\n");
  scanf("%d", &size);
  printf("\n");
  for (int i = 0; i < size; i++) {
    printf("Elemento %d =\t", i + 1);
    fflush(stdin);
    scanf("%d", &v[i]);
  }
  *x = size;
};

// MOSTRAR ELEMENTOS DEL ARRAY
void view(int v[], int x) {
  printf("\nVector mostrado:\n");
  for (int i = 0; i < x; i++) {
    printf("[%d]", v[i]);
  }
  printf("\n\n");
}

void main () {
  int SelectMenu, x, y, T, chargeArray = 0;
  int array[20];
  int sizeArray = sizeof(array);

  do {
    SelectMenu = menu();
    switch (SelectMenu) {
      case 1: 
        printf("\nIngresar 2 valores enteros X e Y\n");
        fflush(stdin);
        scanf("%d%d", &x, &y);
        Intercambio(&x, &y);
        printf("\nX = %d\tY = %d\n", x, y); 
      break;
      case 2:
        charge(array, &T);
        chargeArray = 1;
        printf("\nElementos cargados\n"); 
      break;
      case 3:
        if (chargeArray == 1) 
          view(array, T); 
          else printf("\nPrimero cargar el array con sus elementos\n");
      break;
    }
  } while (SelectMenu != 0);

};