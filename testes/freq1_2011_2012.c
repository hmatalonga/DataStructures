#include <stdio.h>

typedef struct NODO {
    int id;
    char nome[80];
    int nivel;
    struct NODO *nseg[10];
    struct NODO *nant[10];
} Nodo;

int bemFormada(Nodo *L);
void mostraEcran(Nodo *L, int inf, int sup);

int main(void) {
    return 0;
}

// 0 = Não, 1 = Sim
int bemFormada(Nodo *L) {
    int niveis[10], i = 0;
    for (i = 0; i < 10; i++)
        niveis[i] = 0;
    while (L != NULL) {
        ret[L->nivel-1]++;
        L = L->nseg[0];
    }
    for(; i < 9; i++)
        if (niveis[i] < niveis[i+1])
            return 0;
    return 1;
}

void mostraEcran(Nodo *L, int inf, int sup) {
    int n;
    while (L != NULL && L->id < inf) {
        n = L->nivel;
        while (n >= 1 && L) {
            if (L->nseg[n-1] != NULL) {
                if (L->nseg[n-1]->id <= inf) {
                    if (L->nseg[n-1]->id == inf)
                        continue;
                    L = L->nseg[n-1];
                    break; // reset nivel
                }
            }
            n--;
        }
    }
    while (L != NULL && L->id <= sup) {
        if (strcmp(L->nome, "João") == 0);
    }   
}
