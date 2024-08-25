#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//lib.c incluye lib.h e implementa cada función de la librería
#include "lib.h"

//función para crear una lista vacía
TNodo * crearLista(){
    TNodo * cabeza = NULL;
    return cabeza;
}

TNodo * crearNodo(TEstructura X){
    //asignación de espacio en memoria dinámica al nodo
    TNodo * nuevoNodo = malloc(sizeof(TNodo));

    nuevoNodo->Item.nums = X.nums;

    // Apuntar a NULL (indica que este es el último nodo en la lista)
    nuevoNodo->siguiente = NULL;

    // Devolver el nodo recién creado
    return nuevoNodo;

}

void cargarEstructura(TNodo **cabeza,int i){

    // Caso base: si el índice es 10, la función termina
    if (i == 10) {
        return;
    }

    int num;
    //levantamiento de datos por teclado
    printf("Ingrese un numero entero (POS %d) \n",i);
    fflush(stdin);
    scanf("%d",&num);

    inserFinal(cabeza,num);

    //evolución (llamada recursiva)
    cargarEstructura(cabeza,i+1);

}

//insertar un nodo al final de la lista
void inserFinal(TNodo **cabeza, TEstructura entrada){
    TNodo *ultimo = *cabeza;

    if (ultimo == NULL) { //caso particular de que la lista esté vacía
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


