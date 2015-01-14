#include <stdio.h>

typedef struct NODO {
    int id, nivel;
    struct NODO *nseg[10], *nant[10];
} Nodo;

Nodo *pesquisaListaSalto(Nodo *LS, int c);
Nodo *removeLS(Nodo **LS, int id);

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

Nodo *removeLS(Nodo **LS, int id) {
   Nodo *elem = pesquisaListaSalto(*LS, id);
   if (elem != NULL) {
        for (int i = 0; i < elem->nivel; i++) {
            if (elem->nant[i] != NULL)
                elem->nant[i]->nseg[i] = elem->nseg[i];
            elem->nseg[i] = NULL;
        }
        return elem;
   }
   return NULL;
}
