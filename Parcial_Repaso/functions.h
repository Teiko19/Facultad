#ifndef functions
#define functions

typedef struct main{
  int matricula;
  char nombre[30];
  char apellido[30];
  float asistencia;
  int notas[3];
  float notaFinal;
} alum;

int validator(int USER, int PASS);
void menu(int *option);
void cargarArr(alum v[6]);
void cargarFinal(alum v[6]);
void cargarArchivo(alum v[6]);


#endif