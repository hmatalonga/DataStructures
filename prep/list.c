#include <stdio.h>
#include <stdlib.h>

typedef struct NODO {
    int index;
    struct NODO *next;
} Nodo;

Nodo *append(Nodo *L, int index);
Nodo *find(Nodo *L, int index);
void print(Nodo *L);
Nodo *getLast(Nodo *L);
int countByIndex(Nodo *L, int index);
int totalElementos(Nodo *L);
int totalElementosDiferentes(Nodo *L);
Nodo *insereFim(Nodo *L, int index);
int listaOrdenada(Nodo *L);
Nodo *inverteLista(Nodo *L);
Nodo *intercalaLista(Nodo *L1, Nodo *L2);
int countRecursivo(Nodo *L);
int maxIterativo(Nodo *L);
int maxRecursivo(Nodo *L);
Nodo *removeElemento(Nodo *L, int index);
Nodo *compactLista(Nodo *L);

int main(void) {
    Nodo *L = NULL, *A = NULL, *R = NULL;
    
    L = append(L, 5);
    L = append(L, 3);
    L = append(L, 8);
    L = append(L, 1);
    L = append(L, 9);
    L = append(L, 3);
    L = append(L, 6);
    L = append(L, 1);
    
    A = append(A, 7);
    A = append(A, 4);
    A = append(A, 2);
    
    R = intercalaLista(L, A);
    
    print(L);
    L = compactLista(L);
    print(L);
    
    return 0;
}

Nodo *append(Nodo *L, int index) {
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));
    if (novo == NULL)
        exit(1);
    novo->index = index;
    novo->next = L;
    return novo;
}

Nodo *find(Nodo *L, int index) {
    while (L != NULL) {
        if (L->index == index)
            return L;
        L = L->next;
    }
    return NULL;
}

void print(Nodo *L) {
    while (L != NULL) {
        printf("%d ", L->index);
        L = L->next;
    }
    printf("\n");
}

Nodo *getLast(Nodo *L) {
    if (L == NULL)
        return NULL;
    for(; L->next != NULL; L = L->next);
    return L;
}

int countByIndex(Nodo *L, int index) {
    int c = 0;
    while (L != NULL) {
        if (L->index == index)
            c++;
        L = L->next;
    }
    return c;
}

int totalElementos(Nodo *L) {
    int c = 0;
    while (L != NULL) {
        c++;
        L = L->next;
    }
    return c;
}

int totalElementosDiferentes(Nodo *L) {
    int c = 0;
    Nodo *aux = NULL;
    while (L != NULL) {
        if (find(aux, L->index) == NULL) {
            c++;
            aux = append(aux, L->index);
        }
        L = L->next;
    }
    return c;
}

Nodo *insereFim(Nodo *L, int index) {
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo)), *fim = L;
    if (novo == NULL)
        exit(1);
    novo->index = index;
    novo->next = NULL;
    if (fim == NULL)
        return novo;
    while (fim->next != NULL)
        fim = fim->next;
    fim->next = novo;
    return L;
}

int listaOrdenada(Nodo *L) {
    while (L != NULL) {
        if (L->next != NULL && L->index > L->next->index)
            return 0;
        L = L->next;
    }
    return 1;
}

Nodo *inverteLista(Nodo *L) {
    Nodo *nova = NULL;
    while (L != NULL) {
        nova = append(nova, L->index);
        L = L->next;
    }
    return nova;
}

Nodo *intercalaLista(Nodo *L1, Nodo *L2) {
    Nodo *nova = NULL;
    while (L1 != NULL && L2 != NULL) {
        nova = insereFim(nova, L1->index);
        nova = insereFim(nova, L2->index);
        L1 = L1->next;
        L2 = L2->next;
    }
    if (L1 == NULL)
        while (L2 != NULL) {
            nova = insereFim(nova, L2->index);
            L2 = L2->next;
        }
    else
        while (L1 != NULL) {
            nova = insereFim(nova, L1->index);
            L1 = L1->next;            
        }
    return nova;
}

void imprimeMaisFrequente(Nodo *L) {
    int max = -1, curr;
    Nodo *aux = L, *elem = NULL;
    while (aux != NULL) {
        curr = countByIndex(L, aux->index);
        if (curr > max) {
            max = curr;
            elem = aux;
        }
        aux = aux->next;
    }
    if (elem != NULL)
        printf("%d\n", elem->index);
    else
        printf("Lista vazia\n");
}

int countRecursivo(Nodo *L) {
    if (L == NULL)
        return 0;
    return (1 + countRecursivo(L->next));
}

int maxIterativo(Nodo *L) {
    int max = -1, curr;
    Nodo *aux = L;
    while (aux != NULL) {
        curr = countByIndex(L, aux->index);
        if (curr > max)
            max = curr;
        aux = aux->next;
    }
    return max;
}

Nodo *removeElemento(Nodo *L, int index) {
    Nodo *aux = NULL, *ret = L;
    if (L == NULL)
        return NULL;
    if (L->index == index) {
        aux = L;
        L = L->next;
        free(aux);
        return L;
    }
    while (ret->next != NULL) {
        if (ret->next->index == index) {
            aux = ret->next;
            ret->next = aux->next;
            aux->next = NULL;
            free(aux);
            break;
        }
        ret = ret->next;
    }
    return L;
}

Nodo *compactLista(Nodo *L) {
    Nodo *nova = NULL;
    while (L != NULL) {
        if (find(nova, L->index) == NULL)
            nova = insereFim(nova, L->index);
        L = L->next;
    }
    return nova;
}
