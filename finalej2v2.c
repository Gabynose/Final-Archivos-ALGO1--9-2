/// EJERCICIO 2 FINAL COMPLETADO (BIEN) ///

#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>
#define LECTURA "%s"
#define ESCRITURA "%i;%i"
#define MAX_NOMBRE 100
#define MAX 50
const int PRIMER_LETRA = 0;
const int SEGUNDA_LETRA = 1;
const int TERCER_LETRA = 2;
const int CUARTA_LETRA = 3;
const int QUINTA_LETRA = 4;
int main(){
    FILE* entrada = fopen("entradaej2.txt", "r");
    if (entrada == NULL){
        perror("entrada.txt no disponible");
        return -1;
    }
    FILE* entrada_matriz = fopen("entradamatrizej2.txt", "r");
    if (entrada == NULL){
        perror("entrada.txt no disponible");
        fclose(entrada);
        return -1;
    }
    FILE* salida = fopen("salidaej2.txt", "w");
    if (entrada == NULL){
        perror("salida.txt no disponible");
        fclose(entrada);
        fclose(entrada_matriz);
        return -2;
    }
    char nombre[MAX_NOMBRE];
    char texto_sopa [MAX];
    int leidos_matriz = fscanf(entrada_matriz, LECTURA, texto_sopa);
    fscanf(entrada, LECTURA, nombre);
    int longitud_texto_sopa = (int)strlen(texto_sopa);
    bool palabra_encontrada = false;
    int fila_encontrada = 0;
    int columna_encontrada = 0;
    while (leidos_matriz == 1 && !palabra_encontrada){
        for (int i = 0; i < longitud_texto_sopa; i++){
            if (texto_sopa[i] == nombre[PRIMER_LETRA]){
                if (texto_sopa[i+1] == nombre[SEGUNDA_LETRA] &&
                texto_sopa[i+2] == nombre[TERCER_LETRA] &&
                texto_sopa[i+3] == nombre[CUARTA_LETRA] &&
                texto_sopa[i+4] == nombre[QUINTA_LETRA]){
                    palabra_encontrada = true;
                    columna_encontrada = i;
                }
            }
        }
        if (!palabra_encontrada){
            fila_encontrada++;
        }
        leidos_matriz = fscanf(entrada_matriz, LECTURA, texto_sopa);
    }
    fprintf(salida, ESCRITURA, fila_encontrada, columna_encontrada);
    fclose(entrada);
    fclose(entrada_matriz);
    fclose(salida);
    return 0;


}