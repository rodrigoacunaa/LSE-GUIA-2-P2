#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//en lib.h no incluimos nada!!

typedef struct Estructura{
    int nums;
}TEstructura;

//estructura del nodo
typedef struct Nodo{
    //contenido del nodo
    TEstructura Item;

    //evolución del nodo
    struct Nodo * siguiente;
}TNodo;

TNodo * crearLista();
TNodo * crearNodo(TEstructura X);
void cargarEstructura(TNodo **cabeza , int i);
void imprimirLista(TNodo * cabeza);




#endif // LIB_H_INCLUDED
