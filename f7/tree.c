#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct AB {
    int id, n;
    struct AB *left, *right;
} NodoAB;

NodoAB *insert(NodoAB *A, int value);

void visitarArvore(NodoAB *A);
int contaNos(NodoAB *A);
int contaFolhas(NodoAB *A);
int altura(NodoAB *A);
int maximoChave(NodoAB *A);
int maximoNaoChave(NodoAB *A);
int bemFormada(NodoAB *A);
int bemFormadaMax(NodoAB *A);

int cheia(NodoAB *A);
int completa(NodoAB *A);
int balanceada(NodoAB *A);
NodoAB *espelho(NodoAB *A);
int maximoCaminho(NodoAB *A);
int repetidos(NodoAB *A, NodoAB *root);

int main(void) {
    NodoAB *root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 0);
    root = insert(root, 6);
    
    visitarArvore(root);
    printf ("\n%d\n", cheia(root));
    
    return 0;
}

NodoAB *insert(NodoAB *A, int value) {
    if (A == NULL) {
        NodoAB *novo = (NodoAB *) malloc(sizeof(NodoAB));
        if (novo == NULL)
            exit(1);
        novo->id = value;
        novo->left = NULL;
        novo->right = NULL;
        return novo;
    }
    if (value < A->id)
        A->left = insert(A->left, value);
    else
        A->right = insert(A->right, value);
    return A;
}

void visitarArvore(NodoAB *A) {
    if (A == NULL)
        return;
    /*
    // Asc order
    visitarArvore(A->left);
    printf("%d", A->id);
    visitarArvore(A->right);
    // Desc order
    printf("%d", A->id);
    visitarArvore(A->left);
    visitarArvore(A->right);
    */
    // Curr order
    visitarArvore(A->left);
    visitarArvore(A->right);
    printf("%d ", A->id);
}

int contaNos(NodoAB *A) {
    if (A == NULL)
        return 0;
    return (1 + contaNos(A->left) + contaNos(A->right));
}

int contaFolhas(NodoAB *A) {
    if (A == NULL)
        return 0;
    if (A->left == NULL && A->right == NULL)
        return 1;
    return (contaFolhas(A->left) + contaFolhas(A->right));
}

int altura(NodoAB *A) {
    if (A == NULL)
        return 0;
    int a = altura(A->left);
    int b = altura(A->right); 
    return (1 + (a > b ? a : b));
}

int maximoChave(NodoAB *A) {
    if (A == NULL)
        return -1;
    if (A->right == NULL)
        return A->id;
    return (maximoChave(A->right));
}

int maximoNaoChave(NodoAB *A) {
    if (A == NULL)
        return -1;
    int a = maximoNaoChave(A->left);
    int b = maximoNaoChave(A->right);
    if (a > b) {
        if (A->id > a)
            return A->id;
        return a;
    }
    if (A->id > b)
        return A->id;
    return b;
}

// 1 = Sim, 0 = Nao
int bemFormada(NodoAB *A) {
    if (A == NULL)
        return 1;
    if (A->left != NULL)
        if (A->left->id > A->id)
            return 0;
    if (A->right != NULL)
        if (A->right->id < A->id)
            return 0;
    if (bemFormada(A->left) && bemFormada(A->right))
        return 1;
}

int cheia(NodoAB *A) {
    if (A == NULL)
        return 1;
    if (A->left == NULL && A->right != NULL || A->left != NULL && A->right == NULL)
        return 0;
    return (cheia(A->left) && cheia(A->right));
}

int completa(NodoAB *A) {
    if (A == NULL)
        return 1;
    if (altura(A->left) != altura(A->right))
        return 0;
    return (completa(A->left) && completa(A->right));
}

int balanceada(NodoAB *A) {
    if (A == NULL)
        return 1;
    if (abs(contaNos(A->left) - contaNos(A->right)) > 1)
        return 0;
    return (balanceada(A->left) && balanceada(A->right));
}

NodoAB *espelho(NodoAB *A) {
    if (A == NULL)
        return NULL;
    NodoAB *swap = A->left;
    A->left = espelho(A->right);
    A->right = espelho(swap);
    return A;
}

int maximoCaminho(NodoAB *A) {
    if (A == NULL)
        return 0;
    if (A->left == NULL && A->right == NULL)
        return A->id;
    int left = maximoCaminho(A->left);
    int right = maximoCaminho(A->right);
    return (A->id + (left > right ? left : right));
}

/*
int repetidos(NodoAB *A, NodoAB *root) {
    if (A == NULL)
        return 0;
    if (conta(root, A->n) > 1)
        return 1;
    return (repetidos(A->left, root) || repetidos(A->right, root));
}
*/
