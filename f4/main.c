#include <stdio.h>

typedef struct NODO {
    int id;
    struct NODO *nseg, *nant;
} Nodo;

int listaCircular(Nodo *L);
Nodo *ordenaOcorrencias(Nodo *L);

int main(void) {
    return 0;
}

int listaCircular(Nodo *L) {
    Nodo *head = L;
    if (L == NULL)
        return 1; // not circular
    while (L != NULL) {
        L = L->nseg;
        if (L == head)
            return 0; // circular
    }
    return 1; // not circular
}

Nodo *ordenaOcorrencias(Nodo *L) {
    int c, cm, im;
    Nodo *ln = NULL, *el, *aux;
    while (L != NULL) {
        aux = L;
        while (aux != NULL) {
            c = contaID(aux, aux->id);
            if (c > cm) {
                cm = c;
                im = aux->id;
            }
            aux = aux->nseg;
        }
        for (; cm > 0; cm--) {
            el = getID(&L, im);
            lm = insertLast(ln, el);
        }
    }
    return (ln);
}
