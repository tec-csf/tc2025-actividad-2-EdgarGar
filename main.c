//Edgar Adrian Garcia Villegas 
//A01021730

#include <stdio.h>
#include <stdlib.h>

struct  Libro {
    
    char * titulo;
    int paginas;
    
};
struct Libro * libros;

typedef void (*t_direction)(void *, size_t, int);

void* begin(void* vector){
    return vector;
}

void* next(void* vector, size_t size){
    return (vector+size);
}

void* prev(void* vector, size_t size){
    return (vector-size);
}

void* end(void* vector,size_t size, int len){
    return (vector+(size*len));
}

void print(char* elem)
{
    printf("%c \n",*elem);
}

void forward(void * vector, size_t size, int len)
{
    void* aux = begin(vector);
    while(aux != end(vector,size,len)){
        print(aux);
        aux = next(aux,size);
    }
    
}

void backward(void * vector, size_t size, int len)
{
    void* aux = end(vector, size, len);
    while(aux != begin(vector)){
        print(aux);
        aux = prev(aux,size);
    }
}

void iterate(t_direction option, void * vector, size_t size, int len)
{
    (*option)(vector, size, len);
}

void recorre(void * vector, int n, int len)
{
    if(n == 0)
    {
        iterate(forward, vector, sizeof(*vector),len);
    } else if (n == 1) {
        iterate(backward, vector, sizeof(*vector),len);
    }
}

int main(int argc, const char * argv[]) { 
    
    char * arreglo = "ESTA FRASE ES PEGAJOSA";
    recorre(arreglo, 1, 22);
    
    return 0;
}

