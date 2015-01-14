#include <stdio.h>
#include <stdlib.h>

typedef struct NODO {
    int id, custo;
    struct NODO *next;
} Nodo;

void print(Nodo **G, int tv);
Nodo *append(Nodo *V, int id, int c);
int existeAresta(Nodo **G, int a, int b);
int grafoCompleto(Nodo **G, int tv);
int grafoDirigido(Nodo **G, int tv);
int caminhoValidoIT(Nodo **G, int *cam, int tc); 
int caminhoValidoRec(Nodo **G, int *cam, int tc);

int main(void) {
    Nodo *G[4];
    G[0] = NULL;
    G[1] = NULL;
    G[2] = NULL;
    G[3] = NULL;
    G[0] = append(G[0], 2, 4);
    G[0] = append(G[0], 3, 1);
    G[1] = append(G[1], 3, 7);
    G[1] = append(G[1], 2, 3);
    G[1] = append(G[1], 0, 6);
    G[2] = append(G[2], 1, 4);
    G[3] = append(G[3], 2, 2);
    print(G, 4);
    return 0;
}

Nodo *append(Nodo *V, int id, int c) {
    Nodo *A = (Nodo *)malloc(sizeof(Nodo));
    if (A == NULL)
        exit(1);
    A->id = id;
    A->custo = c;
    A->next = V;
    return A;
}

void print(Nodo **G, int tv) {
    Nodo *V;
    int i;
    for (i = 0; i < tv; i++) {
        V = G[i];
        printf("[%d] ", i);
        while (V != NULL) {
            printf("-> %d ", V->id);
            V = V->next;
        }
        printf("\n");
    }
}

int existeAresta(Nodo **G, int a, int b) {
    Nodo *V = G[a];
    while (V != NULL) {
        if (V->id == b)
            return 1;
        V = V->next;
    }
    return 0;
}

int grafoCompleto(Nodo **G, int tv) {
    int i = 0, j = 0, a = 1;
    for (; i < tv; i++) {
        for (j = 0; j < tv; j++) {
            if (i == j)
                continue;
            if (!existeAresta(G, i, j))
                return 0;
        }
    }
    return 1;
}

int grafoDirigido(Nodo **G, int tv) {
    Nodo *V;
    int i = 0;
    for (; i < tv; i++) {
        V = G[i];
        while (V != NULL) {
            if (!existeAresta(G, V->id, i))
                return 0;
            V = V->next;
        }
    }
    return 1;
}

int caminhoValidoIT(Nodo **G, int *cam, int tc) {
    int i = 0;
    for (; i < tc-1; i++) {
        if (!existeAresta(G, cam[i], cam[i+1]))
            return 0;
    }
    return 1;
}

int caminhoValidoRec(Nodo **G, int *cam, int tc) {
    if (tc < 2)
        return 1;
    if (!existeAresta(G, cam[0], cam[1]))
        return 0;
    return (caminhoValidoRec(G, cam+1, tc-1));
}

int totalHubs(Nodo **G, int tv, int lim) {
    Nodo *V; 
    int i = 0, hubs = 0, c;
    for (; i < tv; i++) {
        V = G[i];
        c = 0;
        while (V != NULL) {
            c++;
            V = V->next;
        }
        if (c > lim)
            hubs++;
    }
    return hubs;
}

int totalAutoridades(Nodo **G, int tv, int lim) {
    Nodo *V;
    int i = 0, auth = 0, c;
    for (; i < tv; i++) {
        V = G[i];

    }
}


