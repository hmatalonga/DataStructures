#include <stdio.h>
#include <stdlib.h>

#define MAX_NIVEIS 4

typedef struct m {
    int id, dia, mes, ano;
    char nome[80];
    struct m *next;
} Membro;

typedef struct pa {
    Membro *elem;
    struct pa *next;
} Participante;

typedef struct e {
    int dia, mes, ano;
    Membro *organizador;
    char tema[100];
    Participante *lista;
    struct e *next;
} Evento;

typedef struct NODO {
    int ID;
    int nivel;
    struct NODO *nseg[MAX_NIVEIS];
} Nodo;

float mediaPresentes(Evento *E, int BIOrganizador) {
    int totEventos = 0, totMembros = 0;
    while (E != NULL) {
        if (E->organizador->id == BIOrganizador) {
            totEventos++;
            while (E->lista != NULL) {
                totMembros++;
                E->lista = E->lista->next;
            }
        }
        E = E->next;
    }
    return totMembros / totEventos;
}

void mostraInactivos(Membro *M, Evento *E) {
    Evento *aux;
    while (M != NULL) {
        aux = E;
        while (aux != NULL) {
            if (aux->organizador == M)
                break;
            aux = aux->next;
        }
        if (aux == NULL)
            printf("%s\n", M->nome);
        M = M->next;
    }
}

int totalAno(Evento *E, int ano) {
    int tot = 0;
    while (E != NULL) {
        if (E->ano == ano)
            tot++;
        E = E->next;
    }
    return tot;
}

int bemOrdenada(Nodo *L) {
    while (L != NULL) {
        if (L->nseg[0] != NULL && L->ID > L->nseg[0]->ID)
            return 0;
        L = L->nseg[0];
    }
    return 1;
}

int bemFormada(Nodo *L, float p) {
    int niveis[MAX_NIVEIS], int i = 0;
    for (; i < MAX_NIVEIS; i++)
        niveis[i] = 0;
    while (L != NULL) {
        niveis[L->nivel]++;
        L = L->next;
    }
    for (i = 0; i < MAX_NIVEIS-1; i++)
        if (niveis[i] <= p*niveis[i+1])
            return 0;
    return 1;
}

// Função auxiliar
int pesquisaListaSalto(Nodo *LS, int c) {
    int n, tot = 0;
    while (LS != NULL) {
        n = LS->nivel;
        while (n >= 1) {
            if (LS->nseg[n-1] != NULL) {
                if (LS->nseg[n-1]->id <= c) {
                    if (LS->nseg[n-1]->id == c)
                        return tot;
                    LS = LS->nseg[n-1];
                    tot++;
                    break; // reset nivel
                }
            }
            n--;
        }
        return -1;
    }
}

void IDMaisVantajoso(Nodo *L) {
    Nodo *head = L;
    int maxC = 0, maxID = 0, linear = 0, temp;
    while (head != NULL) {
        temp = linear - pesquisaListaSalto(L, head->ID);
        if (temp > maxC) {
            maxC = temp;
            maxID = head->ID;
        }
        head = head->next;
        linear++;
    }
    printf("%d\n", maxID);
}
