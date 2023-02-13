#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>-
/// EJERCICIO 2 COMPLETADO (ESTA BIEN) /// <---- :D :D :D :D :D :D :D 
#define MAX_TEXTO 40
#define LECTURA "%s"
#define ESCRITURA_PERDER "%s - %i"
int main(){
    FILE* entrada = fopen("entradaej3.txt", "r");
    if (entrada == NULL){
        perror("Error no se abrio archivo de entrada.");
        return -1;
    }
    FILE* salida = fopen("salidaej3.txt", "w");
    if (salida == NULL){
        perror("Error no se abrio archivo de salida");
        fclose(entrada);
        return -2;
    }
    char texto [MAX_TEXTO];
    int longitud_texto = (int)strlen(texto);
    int comparacion_anterior = 0;
    int comparacion_posicion = 0;
    int leidos = fscanf (entrada, LECTURA, texto);
    for (int i = 0; i < longitud_texto; i++){
        if (texto[i] - 0 > comparacion_anterior){
            comparacion_anterior = texto[i] - 0;
            comparacion_posicion = i;
        }
    }
    bool continuar = true;
    int fila = 1;
    while (leidos == 1 && continuar){
        fila++;
        leidos = fscanf(entrada, LECTURA, texto);
        int comparacion_actual = 0;
        int comparacion_posicion_actual = 0;
        for (int i = 0; i < longitud_texto; i++){
            if (texto[i] - 0 >= comparacion_actual){
                comparacion_actual = texto[i] - 0;
                comparacion_posicion_actual = i;
            }
        }
        if (comparacion_actual >= comparacion_anterior && (comparacion_posicion_actual == comparacion_posicion ||
        comparacion_posicion_actual == comparacion_posicion + 1)){
            comparacion_anterior = comparacion_actual;
                
        } else if (comparacion_actual < comparacion_anterior){
            comparacion_anterior = comparacion_actual;
                
        } else if (comparacion_actual >= comparacion_anterior && (comparacion_posicion_actual != comparacion_posicion ||
         comparacion_posicion_actual != comparacion_posicion + 1)){
            continuar = false;
        }
    }

    if (continuar){
        fprintf(salida, LECTURA, "MATRIZ VALIDA");
    } else {
        fprintf(salida, ESCRITURA_PERDER, "ERROR", fila);
    }
    fclose(entrada);
    fclose(salida);
    return 0;
}
        


