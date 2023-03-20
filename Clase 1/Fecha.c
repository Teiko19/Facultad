#include <stdio.h>
#include <stdlib.h>

void main(){
    char d[2], m[2], a[4];
    printf("Ingresar el dia\n");
    scanf("%s",&d);
    printf("Ingresar el mes\n");
    scanf("%s",&m);
    printf("ingresar el año\n");
    scanf("%s",&a);
    printf("La fecha es: %s/%s/%s",a,m,d);
}
