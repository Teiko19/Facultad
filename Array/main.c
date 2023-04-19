#include <stdio.h>
#include <stdlib.h>

int main () {
  int size_vect_par = 0,
      size_vect_impar = 0,
      size_vect_total = 0,
      vect_original[11], 
      vect_par[11], 
      vect_impar[11],
      vect_total[11], 
      i;

  printf("ingrese 10 valores aleatorios\n");

  // CARGAR VECTOR ORIGINAL

  for ( i=0 ; i<11 ; i++ ) {
    scanf("%d", &vect_original[i]);
  };

  printf("--------------------");

  printf("\n Vector Original = ");
  for ( i=0 ; i<11 ; i++ ) {
    printf("[%d]", vect_original[i]);
  };

  printf("\n--------------------");

  // CARGAR VECTORES PAR E IMPAR

  for ( i=0 ; i<11 ; i++ ) {
    vect_par[i] = 0;
    vect_impar[i] = 0;
    if ( vect_original[i] % 2 == 0) {
      vect_par[size_vect_par++] = vect_original[i];
    } else {
      vect_impar[size_vect_impar++] = vect_original[i];
    }
  };

  printf("\n Vector Pares = ");
  for ( i=0 ; i<size_vect_par ; i++ ) {
    printf("[%d]", vect_par[i]);
  };

    printf("\n--------------------");

  printf("\n Vector Impares = ");
  for ( i=0 ; i<size_vect_impar ; i++ ) {
    printf("[%d]", vect_impar[i]);
  };

  printf("\n--------------------");

  // CARGAR VECTOR TOTAL

  for (i=0 ; i<size_vect_par ; i++) {
    vect_total[i] = vect_par[i];
    size_vect_total++;
  }
  for (i=0 ; i<size_vect_impar ; i++) {
    vect_total[size_vect_total++] = vect_impar[i];
  }

  printf("\n Vector Total = ");
  for ( i=0 ; i<size_vect_total ; i++ ) {
    printf("[%d]", vect_total[i]);
  };

  printf("\n--------------------");

}