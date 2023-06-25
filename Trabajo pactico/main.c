#include <stdio.h>
#include <stdlib.h>
#define passAdmin 190302

typedef struct main{
  int access, 
      DNI, 
      department;
} users;

// MENU DE OPCIONES
void menu(int *init) {
  printf("\n\tOptions\n\n");
  printf("1. Enter into sistem\n");
  printf("2. Charge user (need pass of admin)\n");
  printf("0. Finish program\n\n");
  fflush(stdin);
  scanf("%d", &*init);
};

// VERIFICACION DE CONTRASEÑA DE ADMINISTRADOR
void adminVerification(int *admin) {
  printf("\n------------------------------------------");
  printf("\n\tEnter admin password\n");
  printf("password: ");
  fflush(stdin);
  scanf("%d", &*admin);
};

// CARGA DE USUARIOS
void chargeUsers(users saveUsers[]) {
  printf("------------------------------------------");
  printf("\n\t\tUsers load\n");
  for (int i = 0; i < 9 ; i ++) {
    printf("------------------------------------------");
    printf("\nUser N°%d\n", i + 1);
    printf("---------------------\n");

    // validador de DNI
    do {
      printf("DNI:\t");
      fflush(stdin);
      scanf("%d", &saveUsers[i].DNI);
      (saveUsers[i].DNI < 0 || saveUsers[i].DNI > 99999999) && printf("-> Error DNI, try again\n");
    } while (saveUsers[i].DNI < 0 || saveUsers[i].DNI > 99999999);

    // validador de acceso de nivel
    printf("---------------------\n");
    do {
      printf("Access level:\n");
      printf("\t1. Total\n");
      printf("\t2. Partial\n");
      printf("\t3. Visitor\n");
      fflush(stdin);
      scanf("%d", &saveUsers[i].access);
      (saveUsers[i].access < 1 || saveUsers[i].access > 3) && printf("-> Error access level, try again\n");
    } while(saveUsers[i].access < 1 || saveUsers[i].access > 3);

    // validador de departamentos
    printf("---------------------\n");
    do {
      printf("Departments:\n");
      printf("\t1. RRHH\n");
      printf("\t2. Marketing\n");
      printf("\t3. Sistems\n");
      fflush(stdin);
      scanf("%d", &saveUsers[i].department);
      (saveUsers[i].department < 0 || saveUsers[i].department > 3) && printf("-> Error department, try again\n");
    } while(saveUsers[i].department < 0 || saveUsers[i].department > 3);
  }
};

// VALIDADOR DE ACCESO
int access(int password[3][3][8], users saveUsers[]) {
  char pass[8];
  int DNI, aux1, aux2, acumWhile = 0, caractValue = 0;
  printf("------------------------------------------");
  printf("\nEnter DNI\n");
  fflush(stdin);
  do {
      scanf("%d", &DNI);
      (DNI < 0 || DNI > 99999999) && printf("-> Error DNI, try again\n");
  } while (DNI < 0 || DNI > 99999999);

  do {
    // Valida la existencia de dni
    if (DNI == saveUsers[acumWhile].DNI) { 
      aux1 = saveUsers[acumWhile].access - 1;
      aux2 = saveUsers[acumWhile].department - 1;

      // Si la contraseña almacenada existe la empieza a validar
      if (password[aux1][aux2] != 0) {
        for (int i = 0; i < 4; i++) {
          if (i < 3) {
            printf("\nEnter password:\t");
            fflush(stdin);
            gets(pass);
            for (int j = 0; j < 8; j++) {
              (pass[j] == password[aux1][aux2][j]) && caractValue++;
              if (caractValue = 8) { 
                printf("\nAccess accepted\n");
                exit(-1);
              } else {
                printf("\nError password\n");
                caractValue = 0;
              }
            }
            if (i = 3) {
              printf("\nPast max attempts\n");
              exit(-1);
            }
          }
        }
      } else {
        printf("\nDNI exists, but you don't have a password, enter it below\n");
        return acumWhile;
      }

    }
    acumWhile++;
  } while(acumWhile < 8);

  // Si no existe el dni
  (acumWhile = 8) && printf("\nAccess denied, DNI dont exists");
  exit(-1);
};

// CREAR NUEVA CONTRASEÑA
void newPassword(int x, int password[3][3][8], users saveUsers[]) {
  int acumWhile = 1;
  char pass[8];

  do {
    printf("\nEnter new password (4 characters & 4 digits)\n");
    fflush(stdin);
    gets(pass);
    // Si la primera letra es mayuscula valida los siguientes caracteres
    if (pass[0] >= 'A' && pass[0]<='Z') {
      for (int i = 0; i < 8; i++) {
        (pass[i] > 47 && pass[i] < 58) && acumWhile++;
      }
      if (acumWhile > 3) {
        printf("\nPassword Saved");
        for (int i = 0; i < 8; i++) 
          password[saveUsers[x].access][saveUsers[x].department][i] = pass[i];
        acumWhile = 0;
      } else {
        printf("\nPassword must contain at least 4 digits\n");
      }
    } else {
      printf("\nThe first character of the password must be a capital letter, try again\n");
    }
  } while (acumWhile != 0);
}

void main () {
  users saveUsers[9];
  int password[3][3][8] = {0}, init = 0, aux, admin;
  printf("\nWELCOME TO SISTEM\n");
  do {
    menu(&init);
    switch (init) {
      case 0: 
        printf("\nFinished Program"); 
      break;
      case 1: 
        aux = access(password, saveUsers);
        newPassword(aux, password, saveUsers);
      break;
      case 2: 
        adminVerification(&admin);
        if (admin == passAdmin) { 
          chargeUsers(saveUsers);
        } else { 
          printf("\n\nAccess denied");
          exit(-1);
        }
      break;
      default:
        printf("Invalid option, try again\n");
      break;
    };
  } while(init != 0);
};