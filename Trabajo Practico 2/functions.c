#include <stdio.h>
#include <stdlib.h>
#include "define.h"

void verOpciones(int *option) {
  do {
    printf("\t\nSeleccionar opcion:\n");
    printf("\n1. Cargar stock");
    printf("\n2. Ver stock");
    printf("\n3. Realizar el pedido");
    printf("\n0. Finalizar programa\n");
    fflush(stdin);
    scanf("%d", &*option);
  } while (*option < 0 || *option > 3);
}

void cargarStock(int *stock) {
  int carga = 1, i = 0, existe;
  data Object;
  // PARA QUE TOME EL ARCHIVO HAY QUE PONER LA RUTA DONDE SE QUIERE QUE ESTE, SINO SALTA ERROR AL CARGAR ARCHIVO
  FILE *Inventory = fopen("Inventory.txt", "a+");
  if (Inventory != NULL) {
    do {
      existe = 0;

      // verifica codigo de articulo
      do {
        printf("\n\tIngresar codigo de articulo:\n");
        scanf("%d", &Object.ID);
        if (Object.ID < 0) printf("\nError de codigo ingresado, intente nuevamente\n");
      } while (Object.ID < 0);

      // verifica cantidad de articulo
      do {
        printf("\n\tIngresar cantidad de articulo\n");
        scanf("%d", &Object.cantidad);
        if (Object.cantidad < 0) printf("\nError de cantidad ingresadas, intente nuevamente\n");
      } while(Object.cantidad < 0);

      // verifica talle de articulo
      do {
        printf("\n\tIngresar talle de articulo\n");
        fflush(stdin);
        Object.talle = getchar();
        if (Object.talle != 'S' && Object.talle != 'M' && Object.talle != 'L' && Object.talle != 'X') printf("\nError de talle ingresado, intente nuevamente");
      } while (Object.talle != 'S' && Object.talle != 'M' && Object.talle != 'L' && Object.talle != 'X');

      fprintf(Inventory, "%d\t%c\t%d\n", Object.ID, Object.talle, Object.cantidad);
      printf("\nArticulo cargado\b");

      // verifica si seguir escribiendo en el archivo o no
      do {
        printf("\n\n\tSeguir cargando? Si = 1 | No = 0\n");
        fflush(stdin);
        scanf("%d", &carga);
        if (carga != 1 && carga != 0) printf("\nIngresar valor correcto");
      } while(carga != 1 && carga != 0);

      *stock = 1;
      if (carga == 1) i++; 
    } while (carga != 0);
    fclose(Inventory);
  } else {
    printf("\n\nError al abrir el archivo");
    exit(-1);
  }
}

void verStock() {
  data Object;

  FILE *Inventory = fopen("Inventory.txt", "r+");

  // muestra el stock disponible
  if (Inventory != NULL) {
    while (!feof(Inventory)) {
      fscanf(Inventory, "%d %c %d", Object.ID, Object.talle, Object.cantidad);
      printf("\nCodigo: %d\tTalle: %c\tCantidad: %d\n\n\n", Object.ID, Object.talle, Object.cantidad);
    };
  } else {
    printf("\n\nError al abrir el archivo");
    exit(-1);
  }

  fclose(Inventory);
};

void mostrarPedido() {
  FILE *Pedidos = fopen("Pedidos.txt", "r");
  data Object;

 // muestra los pedidos a realizar
  if (Pedidos != NULL) {
    while(!feof(Pedidos)) {
      fscanf(Pedidos, "%d %c %d", Object.ID, Object.talle, Object.cantidad);
      printf("\nCodigo: %d\tTalle: %c\tCantidad: %d", Object.ID, Object.talle, Object.cantidad);
    };
  } else {
    printf("\nError al abrir el archivo");
    exit(-1);
  };

  fclose(Pedidos);
}

void actualizarInventory() {
  FILE *Inventory = fopen("Inventory.txt", "a+");
  FILE *Pedidos = fopen("Pedidos.txt", "r");
  data ObjectInventory[1000] = {0};
  data ObjectPedidos;
  int i = 0;

  // primero guarda todos los articulos como objetos dentro de un array
  if (Inventory != NULL) {
    while (!feof(Inventory)) {
      fscanf(Inventory, "%d %c %d", ObjectInventory[i].ID, ObjectInventory[i].talle, ObjectInventory[i].cantidad);
      i++;
    };
  } else {
    printf("\nError al abrir el archivo\n");
  };

  // verifica que el segundo objeto sea igual al mismo objeto guardado en el array y ademas que el del objeto en el array su cantidad sea mayor o igual
  // en caso de ser iguales pero no mayor que en el array, entonces muestra el articulo y la cantidad faltante
  for (int j = 0; j < i; j++) {
    if (ObjectInventory[j].ID != 0) {
      fscanf(Pedidos, "%d %c %d", ObjectPedidos.ID, ObjectPedidos.talle, ObjectPedidos.cantidad);
      if (ObjectInventory[j].ID == ObjectPedidos.ID && ObjectInventory[j].talle == ObjectPedidos.talle && (ObjectInventory[j].cantidad >= ObjectPedidos.cantidad))
        fprintf(Inventory, "%d %c %d", ObjectInventory[j].ID, ObjectInventory[j].talle, (ObjectInventory[j].cantidad - ObjectPedidos.cantidad)); 
      if (ObjectInventory[j].ID == ObjectPedidos.ID && ObjectInventory[j].talle == ObjectPedidos.talle && (ObjectInventory[j].cantidad < ObjectPedidos.cantidad))
        printf("\n\nEl codigo: %d\tcon talle: %c\tno pudo realizar con exito el pedido, falta de stock de: %d", ObjectPedidos.ID, ObjectPedidos.talle, (ObjectPedidos.cantidad - ObjectInventory[j].cantidad));
    }
  }

  fclose(Inventory);
  fclose(Pedidos);
}

void hacerPedido() {
  mostrarPedido();
  actualizarInventory();
}