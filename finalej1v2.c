#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TEXTO 30
#define LECTURA "%s"
#define ESCRITURA "%s"
const char TRIGO [MAX_TEXTO] = "trigo";
const char ARCILLA [MAX_TEXTO] = "arcilla";
const char MADERA [MAX_TEXTO] = "madera";
const char LANA [MAX_TEXTO] = "lana";
const char PIEDRA [MAX_TEXTO] = "piedra";

int main(){
    FILE* entrada = fopen("entradaej1.txt", "r");
    if (entrada == NULL){
        perror("Archivo de entrada error.");
        return -1;
    }

    FILE* salida = fopen("salidaej1.txt", "w");
    if (salida == NULL){
        perror("Archivo de salida error XDDDDD");
        fclose(entrada);
        return -2;
    }
    char palabra [MAX_TEXTO];
    int trigo_cantidad = 0;
    int arcilla_cantidad = 0;
    int madera_cantidad = 0;
    int lana_cantidad = 0;
    int piedra_cantidad = 0;
    
    int leidos = fscanf (entrada, LECTURA, palabra);
    while (leidos == 1){
        if (strcmp (palabra, TRIGO) == 0){
            trigo_cantidad++;
        } else if (strcmp(palabra, ARCILLA) == 0){
            arcilla_cantidad++;
        } else if (strcmp(palabra, MADERA) == 0){
            madera_cantidad++;
        } else if (strcmp(palabra, LANA) == 0){
            lana_cantidad ++;
        } else if (strcmp(palabra, PIEDRA) == 0){
            piedra_cantidad ++;
        }
        leidos = fscanf(entrada, LECTURA, palabra);
    }
    if (arcilla_cantidad >= 1 && madera_cantidad >= 1){
        fprintf(salida, ESCRITURA, "camino\n");
    }
    if (arcilla_cantidad >= 1 && madera_cantidad >= 1 && lana_cantidad >= 1 && trigo_cantidad >= 1){
        fprintf(salida, ESCRITURA, "poblado\n");
    }
    if (trigo_cantidad >= 2 && piedra_cantidad >= 3){
        fprintf(salida, ESCRITURA, "ciudad\n");
    }
    if (lana_cantidad >= 1 && trigo_cantidad >= 1 && piedra_cantidad >= 1){
        fprintf(salida, ESCRITURA, "carta de desarrollo\n");
    }
    fclose(entrada);
    fclose(salida);

}