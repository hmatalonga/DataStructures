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
int escolheAresta(Nodo **G, int tv, int **R);
int **dijkstra(Nodo **G, int tv, int v);
int *caminhoMaisCurto(Nodo **G, int tv, int vo, int vd, int *tc);

int main(void) {
}

int escolheAresta(Nodo **G, int tv, int **R) {
	Nodo *V = NULL;
	int cmin = INT_MAX, imin = -1, i = 0;
	for (; i < tv; i++) {
		if (!R[i][2]) { // Esta visitado
			V = G[i];
			while (V != NULL) {
				if (V->custo < cmin) {
					cmin = V->custo;
					imin = i;
				}
				V = V->next;
			}
		}
	}
	return imin;
}

int **dijkstra(Nodo **G, int tv, int v) {
	int **R = (int **)malloc(tv*sizeof(int *));
	int i, j, va;
	Nodo *V;
	for (i = 0; i < tv; i++)
		R[i] = (int *)malloc(3*sizeof(int));
	for (i = 0; i < tv; i++) {
		R[i][0] = INT_MAX;
		R[i][1] = 0;
		R[i][2] = -1;
	}
	R[v][0] = 0;
	while (1) {
		for (i = 0; i < tv; i++)
			if (!R[i][1])
				break;
		va = escolheAresta(G, tv, R);
		V = G[va];
		while (V != NULL) {
			if (R[va][0] + V->custo < R[V->id][0]) {
				R[V->id][2] = va;
				R[V->id][0] = R[va][0] + V->custo;
			}
			V = V->next;
		}
		R[v][1] = 1;
	}
	return R;
}

int *caminhoMaisCurto(Nodo **G, int tv, int vo, int vd, int *tc) {
	int **R = dijkstra(G, tv, vd);
	int *cam = NULL;
	int v;
	cam = (int *)realloc(cam, ++(*tc)*sizeof(int));
	cam[*tc-1] = vd;
	v = vd;
	while (v != vo) {
		cam = (int *)realloc(cam, ++(*tc)*sizeof(int));
		cam[*tc-1] = R[v][2];
		v = R[v][2];
	}
	return cam;
}
