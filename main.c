#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//aquí solo incluimos lib.h
#include "lib.h"


int main()
{
    int op;
    TNodo * elemento = crearLista();

    do{
    printf("BIENVENIDO! Seleccione una opcion\n");

    printf("1) Cargar lista (10 numeros enteros)\n");
    printf("2) Ordenar lista de mayor a menor (NO IMPLEMENTADA AUN)\n");
    printf("3) Imprimir lista\n");
    fflush(stdin);
    scanf("%d",&op);
    switch(op){
        case 1: cargarEstructura(&elemento);
            break;

        case 2:
            ordenarLista(&elemento);
            break;

        case 3: imprimirLista(elemento);
            break;
    }
    }while(op!=0);




}
