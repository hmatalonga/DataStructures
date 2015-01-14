#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODOAB {
	int id;
	char dados[100];
	struct NODOAB *left, *right;
} NodoAB;

NodoAB *insert(NodoAB *A, int id, char dados[]);
int IDMaximo(NodoAB *A, char c);

int main(void) {
	NodoAB *tree = NULL;
	tree = insert(tree, 3, "Lorem six");
	tree = insert(tree, 6, "Khi venem");
	tree = insert(tree, 1, "Kapcz art");
	tree = insert(tree, 7, "pou NUgh");
	tree = insert(tree, 9, "Etp sklsm");
	tree = insert(tree, 8, "Lonn sasa");
	printf("%d\n", IDMaximo(tree, 'K'));
	return 0;
}

int IDMaximo(NodoAB *A, char c) {
    if (A == NULL)
        return -1;
    int a = IDMaximo(A->left, c);
    int b = IDMaximo(A->right, c);
    if (a > b) {
        if (A->id > a && strchr(A->dados, c) != NULL)
            return A->id;
        return a;
    }
    if (A->id > b && strchr(A->dados, c) != NULL)
        return A->id;
    return b;
}

NodoAB *insert(NodoAB *A, int id, char dados[]) {
    if (A == NULL) {
        NodoAB *novo = (NodoAB *) malloc(sizeof(NodoAB));
        if (novo == NULL)
            exit(1);
        novo->id = id;
        strcpy(novo->dados, dados);
        novo->left = NULL;
        novo->right = NULL;
        return novo;
    }
    if (id < A->id)
        A->left = insert(A->left, id, dados);
    else
        A->right = insert(A->right, id, dados);
    return A;
}
