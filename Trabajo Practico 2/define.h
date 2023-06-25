#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

typedef struct main{
  char talle;
  int ID;
  int cantidad;
} data;

void verOpciones(int *option);
void cargarStock(int *stock);
void verStock();
void hacerPedido();
void mostrarPedido();
void actualizarInventory();
// void hacerPedido(int *object);

#endif
