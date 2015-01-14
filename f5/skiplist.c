#include <stdio.h>

typedef struct NODO {
    int id, nivel;
    struct NODO *nseg[10];
} Nodo;

Nodo *pesquisaListaSalto(Nodo *LS, int c);

int main(void) {
    return 0;
}

Nodo *pesquisaListaSalto(Nodo *LS, int c) {
    int n;
    while (LS != NULL) {
        n = LS->nivel;
        while (n >= 1) {
            if (LS->nseg[n-1] != NULL) {
                if (LS->nseg[n-1]->id <= c) {
                    if (LS->nseg[n-1]->id == c)
                        return LS->nseg[n-1];
                    LS = LS->nseg[n-1];
                    break; // reset nivel
                }
            }
            n--;
        }
        return NULL;
    }
}
