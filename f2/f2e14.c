#include <stdio.h>
#include <stdlib.h>

#define LSIZE 3

typedef struct TRABALHO{
    int numero; //número do aluno;
    int codTrabalho; //identificador do trabalho;
    float nota; //guarda nota do trabalho [0,20]
    struct TRABALHO *next;
} Trabalho;

Trabalho *makeNode();
Trabalho *insert(Trabalho *L, int num, int cod, float nota);
void trabalhoMaisRealizado(Trabalho *L);
void pautaTrabalhoDecrescente(Trabalho *L, int codTrabalho);

int main(int argc, char **argv) {
    Trabalho *L = NULL;
    
    L = insert(L, 10, 2, 15.6);
    L = insert(L, 11, 2, 14.3);
    L = insert(L, 12, 5, 12.1);
    
    return 0;
}

Trabalho *makeNode() {
    return (Trabalho *) malloc (sizeof(Trabalho));
}

Trabalho *insert(Trabalho *L, int num, int cod, float nota) {
    Trabalho *newp, *next, *previous, *ret;
    if ((newp = makeNode()) == NULL) {
        fprintf(stderr, "Error");
        exit(1);
    }
    if (L == NULL) {
        ret = newp;
        newp->next = NULL;
    } else {
        next = L;
        previous = NULL;
        while (next->codTrabalho < cod && next != NULL) {
            previous = next;
            next = next->next;
        }
        newp->next = next;
        if (previous == NULL)
            ret = newp;
        else {
            previous->next = newp;
            ret = L;
        }
    }
    newp->numero = num;
    newp->codTrabalho = cod;
    newp->nota = nota;
    return ret;
}

void trabalhoMaisRealizado(Trabalho *L) {
    int maxCount = 0, lastCount = 0, currTrab = 0;
    if (L == NULL)
        return;
    currTrab = L->codTrabalho;
    while (L->next != NULL) {
        if (L->codTrabalho == currTrab) {
            
            
            maxCount++;
            
        }
        L = L->next;
    }
}
