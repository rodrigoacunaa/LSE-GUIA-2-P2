#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//lib.c incluye lib.h e implementa cada funci�n de la librer�a
#include "lib.h"

//funci�n para crear una lista vac�a
TNodo * crearLista(){
    TNodo * cabeza = NULL;
    return cabeza;
}

TNodo * crearNodo(TEstructura X){
    //asignaci�n de espacio en memoria din�mica al nodo
    TNodo * nuevoNodo = malloc(sizeof(TNodo));

    nuevoNodo->Item.nums = X.nums;

    // Apuntar a NULL (indica que este es el �ltimo nodo en la lista)
    nuevoNodo->siguiente = NULL;

    // Devolver el nodo reci�n creado
    return nuevoNodo;

}

void cargarEstructura(TNodo **cabeza,int i){

    // Caso base: si el �ndice es 10, la funci�n termina
    if (i == 10) {
        return;
    }

    int num;
    //levantamiento de datos por teclado
    printf("Ingrese un numero entero (POS %d) \n",i);
    fflush(stdin);
    scanf("%d",&num);

    inserFinal(cabeza,num);

    //evoluci�n (llamada recursiva)
    cargarEstructura(cabeza,i+1);

}

//insertar un nodo al final de la lista
void inserFinal(TNodo **cabeza, TEstructura entrada){
    TNodo *ultimo = *cabeza;

    if (ultimo == NULL) { //caso particular de que la lista est� vac�a
        *cabeza = crearNodo(entrada);
    } else {
        while (ultimo->siguiente != NULL) {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = crearNodo(entrada);
    }
}


//imprimir lista
void imprimirLista(TNodo * cabeza){
    TNodo * actual;
    printf("La lista es:\n");
    for(actual=cabeza; actual!=NULL; actual=actual->siguiente){
        printf("%d",&actual->Item.nums);
        printf("\n\n");
    }

}


