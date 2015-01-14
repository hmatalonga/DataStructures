#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 4

typedef struct NODO {
    int index, nivel;
    struct NODO *next[NMAX];
} Nodo;

int randomNivel(int max);
Nodo *insert(Nodo *L, int index);
Nodo *lookup(Nodo *L, int index);
Nodo *remove(Nodo *L, int index);
int bemFormada(Nodo *L);

int main(void) {
    Nodo *L = NULL;
    return 0;
}

int randomNivel(int max) {
    int i = 0;
    float rd;
    while (1) {
        rd = (float) rand() / INIT_MAX;
        for (i = 1; i <= max; i++)
            if (rd > 1.0 / pow(2, i))
                return i;
    }
}
