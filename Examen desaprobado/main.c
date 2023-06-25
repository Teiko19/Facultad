#include <stdio.h>
#include <stdlib.h>

void main () {
  // DEFINIR VARIABLES
  int cantEstudiantes = 0 , notas[100], i = 1;
  int cantNota1 = 0, cantNota2 = 0, cantNota3 = 0, cantNota4 = 0, cantNota5 = 0;
  int frecCalAlta = 0, aux;
  char nombres[100][20], nombreAlumno[20];

  do {
    printf("Ingresar nombre de alumno\n");
    scanf("%s", nombreAlumno);
    for (int j = 0 ; j < 20 ; j++) {
      nombres[cantEstudiantes][j] = nombreAlumno[j];
    };

    printf("Ingresar nota de alumno entre 1 y 5\n");
    scanf("%d", &notas[cantEstudiantes]);

    cantEstudiantes = cantEstudiantes + 1;

    printf("seguir cargando alumnos? 0 = No\n");
    scanf("%d", &i);
  } while (i != 0);


  // MOSTRAR ARRAY NOTAS Y NOMRBES
  for (int t = 0 ; t < cantEstudiantes ; t++) {
    for (int j = 0 ; j < 20 ; j++) {
      printf("%c", nombres[t][j]);
    };
    printf("\t%d\n", notas[t]);
  }


  // FRECUENCIA DE NOTAS
  for (int j = 0 ; j < cantEstudiantes ; j++) {
    if (notas[j] == 1) cantNota1++;
    if (notas[j] == 2) cantNota2++;
    if (notas[j] == 3) cantNota3++;
    if (notas[j] == 4) cantNota4++;
    if (notas[j] == 5) cantNota5++;
  };
  
  printf("Cantidad de notas con 1:\t%d\n", cantNota1);
  printf("Cantidad de notas con 2:\t%d\n", cantNota2);
  printf("Cantidad de notas con 3:\t%d\n", cantNota3);
  printf("Cantidad de notas con 4:\t%d\n", cantNota4);
  printf("Cantidad de notas con 5:\t%d\n", cantNota5);


  // Nota con mayor frecuencia
  for (int j = 0 ; j < 5 ; j++){
    if (cantNota1 >= frecCalAlta) {
      frecCalAlta = cantNota1;
      aux = 1;
    }
    if (cantNota2 >= frecCalAlta) {
      frecCalAlta = cantNota2;
      aux = 2;
    }
    if (cantNota3 >= frecCalAlta) {
      frecCalAlta = cantNota3;
      aux = 3;
    }
    if (cantNota4 >= frecCalAlta) {
      frecCalAlta = cantNota4;
      aux = 4;
    }
    if (cantNota5 >= frecCalAlta) {
      frecCalAlta = cantNota5;
      aux = 5;
    }
  };

  printf("La nota con mayor frecuencia es %d", aux);
}