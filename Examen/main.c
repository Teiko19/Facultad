#include <stdio.h>
#include <stdlib.h>

int main () {
  // DEFINIR VARIABLES
  int maxVec = 1000, notas[maxVec], frecNota[5] = {0}, frecCalAlta = 0, cantEstudiantes = 0, cargAlum, aux = 0;
  char nombres[maxVec][50];

  // CARGA DE ARRAYS DE ALUMNOS Y NOTAS
  do {
    // Ingresar el nombre del alumno al array
    printf("Ingresar nombre de alumno\n");
    fflush(stdin);
    gets(nombres[cantEstudiantes]);

    // Verificar y guardar la nota del alumno en el array
    do {
      printf("Ingresar nota de alumno entre 1 y 5\n");
      fflush(stdin);
      scanf("%d", &notas[cantEstudiantes]);
      if (notas[cantEstudiantes] > 5 || notas[cantEstudiantes] < 1) printf("Error al ingresar nota\n");
    } while (notas[cantEstudiantes] > 5 || notas[cantEstudiantes] < 1);

    // Verificar y analizar si seguir cargando alumnos o no
    do {
      printf("Seguir cargando alumnos? 0 = No || 1 = Si\n");
      fflush(stdin);
      scanf("%d", &cargAlum);
      if (cargAlum > 1 || cargAlum < 0) puts("Error de decisión");
    } while (cargAlum > 1 || cargAlum < 0);

    // Si se sigue cargando alumnos se agrega 1 a la cantidad de estudiantes
    if (cargAlum == 1) cantEstudiantes++;
  } while (cargAlum != 0 && cantEstudiantes < maxVec);

  // MOSTRAR ARRAYS Y FRECUENCIA DE CADA NOTA
  printf("\nCantidad de estudiantes = %d\n", cantEstudiantes + 1);
  for (int i = 0 ; i < cantEstudiantes + 1; i++) {
    printf("%s\tNota = %d\n", nombres[i], notas[i]);
    if (notas[i] > 0 && notas[i] < 6) frecNota[notas[i] - 1]++;
  };

  printf("\n");

  // MOSTRAR LA FRECUENCIA DE CADA NOTA
  for (int i = 0 ; i < 5 ; i++){
    printf("Cantidad de notas con %d = %d\n", i + 1, frecNota[i]);
  };

  // NOTA CON MAYOR FRECUENCIA
  for (int i = 0 ; i < 5 ; i++) {
    if (frecNota[i] >= aux) {
      frecCalAlta = i + 1;
      aux = frecNota[i];
    };
  };
  printf("\nLa nota mas alta con mayor frecuencia es la %d\n", frecCalAlta);

  // ALUMNOS CON LA NOTA CON MAS FRECUENCIA
  printf("Alumnos con la nota con mas freciencia:\n");
  for (int i = 0 ; i < cantEstudiantes ; i++) {
    if (notas[i] == frecCalAlta) {
      printf("\t");
      puts(nombres[i]);
    }
  };
  return 0;
};