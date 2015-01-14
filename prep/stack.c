#include <stdio.h>
#include <stdlib.h>

typedef struct NODO {
    char *value;
    struct NODO *next;
} Nodo;

Nodo *push(Nodo *S, char value);
Nodo *pop(Nodo **S);
void print(Nodo *S);
int checkExp(char *exp);

int main(void) {
    char exp[128];
    fgets(exp, 128, stdin);
    if (checkExp(exp))
        printf("Expressão correcta.\n");
    else
        printf("Expressão incorrecta.\n");
    return 0;
}

Nodo *push(Nodo *S, char value) {
    Nodo *newp = (Nodo *) malloc(sizeof(Nodo));
    if (newp == NULL)
        exit(1);
    newp->value = value;
    newp->next = S;
    return newp;
}

Nodo *pop(Nodo **S) {
    Nodo *elem = NULL;
    if (*S == NULL)
        return NULL;
    elem = *S;
    *S = (*S)->next;
    elem->next = NULL;
    return elem;
}

void print(Nodo *S) {
    Nodo *aux = NULL, *temp = NULL;
    while (S != NULL) {
        temp = pop(&S);
        aux = push(aux, temp);
        printf("%c ", temp->value);
    }
    printf("\n");
    while (aux != NULL)
        S = push(S, pop(&aux));
}

int checkExp(char *exp) {
    Nodo *S = NULL, *temp = NULL;
    while (*exp != '\0') {
        if (*exp == '(')
            S = push(S, *exp);
        else if (*exp == ')') {
            temp = pop(&S);
            if (temp == NULL)
                return 0;
            if (temp->value != '(')
                return 0;
        }
        exp++;
    }
    return 1;
}
