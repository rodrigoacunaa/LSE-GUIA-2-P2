#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//en lib.h no incluimos nada!!


//estructura del nodo
typedef struct Nodo{
    //contenido del nodo
    int nums;

    //evolución del nodo
    struct Nodo * siguiente;
}TNodo;

TNodo * crearLista();
TNodo * crearNodo(int entrada);
void cargarEstructura(TNodo **cabeza);
void imprimirLista(TNodo * cabeza);
void inserFinal(TNodo **cabeza, int entrada);
void ordenarLista(TNodo **cabeza);




#endif // LIB_H_INCLUDED
