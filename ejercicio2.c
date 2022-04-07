#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct 
{
   char *nombre;
}nombre;


int main(int argc, char const *argv[])
{
    int t=1;
char **nombres;
char *Buff;
Buff= (char *) malloc(100*sizeof(char));
for ( int i = 0; i < 5; i++)
{
    printf("Ingrese sus nombres: ");
    gets(Buff);
    nombres[i]=(char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(nombres[i], Buff);    
}
printf("Los nombres cargados son: \n");
for ( int i = 0; i < 5; i++)
{
    printf("%s\n", nombres[i]);
}

free(Buff);
for (int i = 0; i < 5; i++)
{
    free(nombres[i]);
}
    return 0;
}
