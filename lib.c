#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//lib.c incluye lib.h e implementa cada función de la librería
#include "lib.h"

//función para crear una lista vacía
TNodo * crearLista(){
    return NULL;
}

TNodo * crearNodo(int entrada){
    //asignación de espacio en memoria dinámica al nodo
    TNodo * nuevoNodo = malloc(sizeof(TNodo));

    nuevoNodo->nums = entrada;

    // Apuntar a NULL (indica que este es el último nodo en la lista)
    nuevoNodo->siguiente = NULL;

    // Devolver el nodo recién creado
    return nuevoNodo;
}

void cargarEstructura(TNodo **cabeza){

    int num;
    for(int i=0; i<10; i++){
        printf("Ingrese un numero entero (POS %d) \n",i);
        scanf("%d",&num);
        inserFinal(cabeza,num);
    }

}

//insertar un nodo al final de la lista
void inserFinal(TNodo **cabeza, int entrada){
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
        printf("%d  ",actual->nums);

    }
    printf("\n");

}

void ordenarLista(TNodo **cabeza){

    if (*cabeza == NULL || (*cabeza)->siguiente == NULL) {
        // Si la lista está vacía o tiene un solo nodo, no hay nada que ordenar
        return;
    }

    // Inicialmente, la lista ordenada está vacía
    TNodo *cab_ordenada = NULL;

    // Puntero para recorrer la parte desordenada de la lista
    TNodo *actual_desordenado = *cabeza;

    //puntero que apunta al nodo de la parte desordenada: TNodo * actual_desordenado

    //recorremos la parte desordenada
     while(actual_desordenado!=NULL){

        //guardar el siguiente nodo antes de modificar los punteros
        TNodo *siguiente_desordenado=actual_desordenado->siguiente;

        //Si la lista ordenada está vacía o el nodo actual debe ir al inicio...
        if(cab_ordenada == NULL || actual_desordenado->nums <= cab_ordenada->nums){
            //actual_desordenado->siguiente apunta a cab_ordenada (es decir que va para el inicio)
            actual_desordenado->siguiente=cab_ordenada;
            cab_ordenada=actual_desordenado;

        }else{

            //sino, buscamos la posición correcta en la lista ordenada
            TNodo *ordenado_actual = cab_ordenada;

            while(ordenado_actual->siguiente!=NULL && ordenado_actual->siguiente->nums < actual_desordenado->nums){
                //pasa al siguiente nodo hasta encontrar el que no sea menor que actual_desordenado->nums
                //o hasta que ordenado_actual->siguiente==NULL (es decir, hasta que llegue al fin de la lista)
                ordenado_actual=ordenado_actual->siguiente;
            }
            actual_desordenado->siguiente=ordenado_actual->siguiente;
            ordenado_actual->siguiente = actual_desordenado;
        }

        actual_desordenado=siguiente_desordenado;
    }
    //despues de que todos los nodos fueron insertados en su lugar, la lista estará ordenada
    *cabeza=cab_ordenada;
}


