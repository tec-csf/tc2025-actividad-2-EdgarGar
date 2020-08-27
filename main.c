//Edgar Adrian Garcia Villegas 
//A01021730
#include <stdio.h>
#include <stdlib.h>


typedef struct  Libro {
    char * titulo;
    int paginas;
} Libro;

typedef void (*t_imprime)(void*);
typedef void  (*t_iterator)(void*, size_t,t_imprime);


void* begin(void* datos){
    return datos;
}

void* next(void* datos, size_t size){
    return (datos+size);
}

void* prev(void* datos, size_t size){
    return (datos-size);
}

void* end(void* datos,size_t size, int len){
    return (datos+(size*len));
}

void forwardIt(void* datos, size_t size, int len, t_imprime imprime)
{
    void* temp = begin(datos);
    while(temp != end(datos,size,len)){
        imprime(temp);
        temp = next(temp,size);
    }
}

void prevIt(void* datos, size_t size, int len, t_imprime imprime)
{
    void* temp = end(datos,size,len);
    while(temp != begin(datos)){
        imprime(temp);
        temp = prev(temp,size);
    }
}

void bidIt(void* datos, size_t size, int len, t_imprime imprime)
{
    void* b = begin(datos);
    void* temp;
    if (datos = b){
        temp = begin(datos);
        while(temp != end(datos,size,len)){
            imprime(temp);
            temp = next(temp,size);
        }
    }
    else{
        temp = end(datos,size,len);
        while(temp != begin(datos)){
            imprime(temp);
            temp = prev(temp,size);
        }
    }
}

void imprimeChar(char* dato)
{
    printf("%c",*dato);
}

void imprimeLibro(Libro* libro)
{
    printf("%c\n",libro->titulo);
}

int main(int argc, const char * argv[])
{
    char* datos = "El principito ";
    forwardIt(datos,sizeof(char),10,&imprimeChar);
    printf("\n");
    prevIt(datos,sizeof(char),10,&imprimeChar);
    printf("\n");

    Libro* libros = (Libro*) malloc(3*sizeof(Libro));
    libros->titulo = "hOLI";
    (libros+1)->titulo = "hOLI2";
    (libros+2)->titulo = "hOLI3";
    bidIt(datos,sizeof(Libro),3,&imprimeLibro);
}
