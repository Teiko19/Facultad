#include <stdio.h>
#include <stdlib.h>

int main () {
  int size_vect_par = 0,
      size_vect_impar = 0,
      size_vect_total = 0,
      vect_original[11], 
      vect_par[size_vect_par], 
      vect_impar[size_vect_impar],
      vect_total[size_vect_total], 
      i,
      t;

  printf("ingrese 10 valores aleatorios\n");

  // CARGAR VECTOR ORIGINAL

  for ( i=0 ; i<11 ; i++ ) {
    scanf("%d", &vect_original[i]);
  };

  printf("\n Vector Original = ");
  for ( i=0 ; i<11 ; i++ ) {
    printf("[%d]", vect_original[i]);
  };

  // CARGAR VECTOR PAR

  for ( i=0 ; i<11 ; i++ ) {
    vect_par[i] = 0;
    if ( vect_original[i] % 2 == 0) {
      vect_par[size_vect_par++] = vect_original[i];
    }
  };

  printf("\n Vector Pares = ");
  for ( i=0 ; i<size_vect_par ; i++ ) {
    printf("[%d]", vect_par[i]);
  };

  // CARGAR VECTOR IMPAR

  for ( i=0 ; i<11 ; i++ ) {
    vect_impar[i] = 0;
    if ( vect_original[i] % 2 == 1) {
      vect_impar[size_vect_impar++] = vect_original[i];
    }
  };

  printf("\n Vector Impares = ");
  for ( i=0 ; i<size_vect_impar ; i++ ) {
    printf("[%d]", vect_impar[i]);
  };

  // CARGAR VECTOR TOTAL

  for ( i=0 ; i<2 ; i++) {
    if ( i == 0 ) {
      for ( t=0 ; t<size_vect_par ; t++) {
        printf("\n valor del vector par: %d", vect_par[t]);
        vect_total[size_vect_total++] = vect_par[t];
        printf("\n valor t: %d", t);
      };
      printf("\n termina carga par");
    } else {
      for ( t ; t<11 ; t++) {
        vect_total[size_vect_total++] = vect_par[t];
        printf("\n valor t: %d", t);
      };
    }
  };

  printf("\n Vector Total = ");
  for ( i=0 ; i<size_vect_total ; i++ ) {
    printf("[%d]", vect_total[i]);
  };

}