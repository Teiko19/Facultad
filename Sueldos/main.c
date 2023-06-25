#include <stdio.h>
#include <stdlib.h>

int main() {

  // DEFINIR VARIABLES
  int total, num, total_sueldo = 0;
  char seller[10][30], nombre[30];
  float ventas[10], sueldo[10];
  float mayor = 0;

  // CARGAR VECTORES
  for (int i = 0; i < 10; i++) {

    // Generar el nombre del vendedor
    printf("Nombre de vendedor %d: \n", i + 1);
    scanf("%s", nombre);
    nombre[29] = '\0';

    // Almacenar el nombre del vendedor en el array seller
    for (int j = 0 ; j < 30 ; j++) {
      seller[i][j] = nombre[j];
    }
    seller[i][29] = '\0';

    // carga las ventas del vendedor
    printf("Ingresa el total de ventas de vendedor %d \n", i + 1);
    scanf("%g", &ventas[i]);

    // carga el sueldo del vendedor
    total = 0;
    if (ventas[i] > 14999 && ventas[i] < 25001) {
      total = 3000;
    }
    if (ventas[i] > 25000 && ventas[i] < 35001) {
      total = 6000;
    }
    if (ventas[i] > 35000) {
      total = 9000;
    }
    sueldo[i] = total + ventas[i]*0.04;

  };

  printf("\n");

  // IMPRIMIR VENDEDORES, VENTAS, SUELDOS
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 30; j++) {
      printf("%c", seller[i][j]);
    }
    printf("\t ventas: $%g\t", ventas[i]);
    printf("\t sueldo: $%g\t", sueldo[i]);
    printf("\n");
  };

  // MAYOR IMPORTE DE VENTAS
  for (int i = 0 ; i < 10 ; i++) {
    if (ventas[i] > mayor) {
      mayor = ventas[i];
      num = i;
    } 
  };
  printf("\n Vendedor %d mayores ventas con un total de: %g \n", num, mayor);

  // Cantidad de billetes
  for (int i = 0 ; i < 10 ; i++) {
    total_sueldo = total_sueldo + ventas[i];
  };

  printf(" suma de todos los sueldos: %d", total_sueldo);
  int billetes_1000 = total_sueldo / 1000;
  total_sueldo = total_sueldo % 1000;
  int billetes_500 = total_sueldo / 500;
  total_sueldo = total_sueldo % 500;
  int billetes_200 = total_sueldo / 200;
  total_sueldo = total_sueldo % 200;
  int billetes_100 = total_sueldo / 100;
  total_sueldo = total_sueldo % 100;
  int billetes_50 = total_sueldo / 50;
  total_sueldo = total_sueldo % 50;
  int billetes_20 = total_sueldo / 20;
  total_sueldo = total_sueldo % 20;
  int billetes_10 = total_sueldo / 10;
  total_sueldo = total_sueldo % 10;
  printf("\n cantidad de billetes de 1000: %d", billetes_1000);
  printf("\n cantidad de billetes de 500: %d", billetes_500);
  printf("\n cantidad de billetes de 200: %d", billetes_200);
  printf("\n cantidad de billetes de 100: %d", billetes_100);
  printf("\n cantidad de billetes de 50: %d", billetes_50);
  printf("\n cantidad de billetes de 20: %d", billetes_20);
  printf("\n cantidad de billetes de 10: %d", billetes_10);

};