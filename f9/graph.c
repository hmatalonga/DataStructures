#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct NODO {
    int id, custo;
    struct NODO *next;
} Nodo;

Nodo **leGrafo(char *path, int *tv);
void mostraGrafo(Nodo **G, int tv);
Nodo **apagaGrafo(Nodo **G, int tv);
Nodo **prim(Nodo **G, int tv);
Nodo *append(Nodo *V, int vd, int custo);
int criterioParagem(int *x, int t);
void escolheAresta(Nodo **G, int tv, int *v, int *d, int *o);

int main(void) {
	int tv;
	Nodo **G = leGrafo("teste.txt", &tv), **P;
	mostraGrafo(G, tv);
	P = prim(G, tv);
	mostraGrafo(P, tv);
	G = apagaGrafo(G, tv);
	P = apagaGrafo(P, tv);
	return 0;
}

Nodo **leGrafo(char *path, int *tv) {
	int indexG = 1, ta, vo, vd, custo;
	FILE *fp = fopen(path, "r");
	Nodo **G;
	if (fp == NULL)
		exit(1);
	while (!feof(fp)) {
		if (indexG) {
			fscanf(fp, "%d\n", tv);
			fscanf(fp, "%d\n", &ta);
			G = (Nodo **) malloc(*tv*sizeof(Nodo*));
			indexG = 0;
		}
		fscanf(fp, "%d\n%d\n%d\n", &vo, &vd, &custo);
		G[vo] = append(G[vo], vd, custo);
	}
	return G;
}

void mostraGrafo(Nodo **G, int tv) {
    Nodo *V;
    int i;
    for (i = 0; i < tv; i++) {
		V = G[i];
		printf("[%d] ", i);
		while (V != NULL) {
			printf("-> %d(%d) ", V->id, V->custo);
			V = V->next;
		}
		printf("\n");
	}	
}

Nodo **apagaGrafo(Nodo **G, int tv) {
    Nodo *current = NULL, *temp = NULL;
	int i = 0;
	for (; i < tv; i++) {
		current = G[i];
    	while (current != NULL) {
			temp = current;current = current->next;
			free(temp);
		}
		//G[i] = NULL;
	}
	free(G);
    return NULL;
}

Nodo **prim(Nodo **G, int tv) {
	Nodo *V, **GN = NULL;
	int i, o, d;
	int *flag = (int *)calloc(sizeof(int), tv);
	flag[0] = 1;
	while (1) {
		escolheAresta(G, tv, flag, &o, &d);
		GN[o] = append(GN[o], d, 0);
		flag[d] = 1;
		if (criterioParagem(flag, tv))
			break;
	}
	// free flag
	return GN;
}

Nodo *append(Nodo *V, int vd, int custo) {
	Nodo *np = (Nodo *)malloc(sizeof(Nodo));
	if (np == NULL)
		exit(1);
	np->id = vd;
	np->custo = custo;
	np->next = V;
	return np;
}

int criterioParagem(int *x, int t) {
	int i = 0;
	for (; i < t; i++)
		if (!x[i]) // == 0
			return 0;
	return 1;
}

void escolheAresta(Nodo **G, int tv, int *v, int *d, int *o) {
	Nodo *V = NULL;
	int vmin = INT_MAX, i = 0;
	for (; i < tv; i++) {
		if (v[i]) { // Esta visitado
			V = G[i];
			while (V != NULL) {
				if (!v[V->id]) {
					if (V->custo < vmin) {
						vmin = V->custo;
						*d = V->id;
						*o = i;
					}
				}
				V = V->next;
			}
		}
	}
}
