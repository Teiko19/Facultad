#include <stdio.h>
#include <stdlib.h>

int main () {
  // DEFINIR VARIABLES
  char noVacunados[50][30], tipoVacuna[50], nombre[30];
  int edad[50], respuesta[50], encuestado = 0, cantSputnik = 0, cantSinopharm = 0, cantCoveshield = 0, cantSinVacunar = 0, etareo_1 = 0, etareo_2 = 0, etareo_3 = 0;

  // ENCUESTA X PERSONA
  do {
    int i = 1;
    encuestado = encuestado + 1;

    // edad
    printf(" Edad:\n");
    scanf("%d", edad[encuestado]);

    // si aplico vacuna
    printf(" Se aplico alguna vacuna? 1 = Si o 2 = No\n");
    scanf("%d", respuesta[encuestado]);

    // tipo de vacuna
    if (respuesta[encuestado] == 1) {

      printf(" Que tipo de vacuna se aplico?\n")
      printf("\tS = Sinopharm\n");
      printf("\tV = Sputnik\n");
      printf("\tC = Covishield\n");
      scanf("%s", tipoVacuna[encuestado]);

      if (tipoVacuna[encuestado] == "V") {
        cantSputnik = cantSputnik + 1;

        // rango etareo
        if(edad[encuestado] > 59 && edad[encuestado] < 70) {
          etareo_1 = etareo_1 + 1;
        };
        if(edad[encuestado] > 69 && edad[encuestado] < 80) {
          etareo_2 = etareo_2 + 1;
        };
        if(edad[encuestado] > 79) {
          etareo_31 = etareo_3 + 1;
        };
      };

      if (tipoVacuna[encuestado] == "S") {
        cantSinopharm = cantSinopharm + 1;
      };

      if (tipoVacuna[encuestado] == "C") {
        cantCoveshield = cantCoveshield + 1;
      };

    };

    // sin vacunar
    if (respuesta[encuestado] == 2) {
      // nombre y apellido
      printf(" Ingresar nombre y apellido:\n");
      scanf("%s", nombre);
      for (int j = 0 ; j < 30 ; j++ ) {
        noVacunados[encuestado][j] = nombre[j];
      };
      // mayor a 75 años
      if (edad[encuestado] > 75) {
        cantSinVacunar = cantSinVacunar + 1;
      }
    }

    printf("\n")

    printf(" Encuestar otra persona? 1 = Si o 0 = No\n");
    scanf("%d", i);
  } while (i = 0);

}

