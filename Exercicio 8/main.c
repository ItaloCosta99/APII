#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10

struct pilha {
 int top;
 int itens[TAMANHO];
};
int clean (struct pilha *p) {
 if (p->top == -1) {
    return -1;
 }
 return 0;
}
int pop (struct pilha *p) {
 if (clean(p)) {
    printf("\nA pilha esta vazia");
    exit(1);
 }
 return (p->itens[p->top--]);
}
void push (struct pilha *p, int value) {
 if (p->top == (TAMANHO - 1)) {
    printf("\nA pilha esta cheia!");
    exit(1);
 }
 p->itens[++(p->top)] = value;
 return;
}
int size (struct pilha *p) {
 return p->top+1;
}
int topValue (struct pilha *p) {
 return p->itens[p->top];
}
void exibirItens(struct pilha *p) {
 for (int i = 0; i < 10; i++){
    printf("\nIndex[%d] Item: %d",i+1 ,p->itens[i]);
 }
}

int main() {
 int i = 0;
 struct pilha example;
 example.top = -1;
 printf("\nInsira 10 numeros inteiros:\n");
 for (i = 0; i < TAMANHO; i++) {
    int x;
    scanf("%d", &x);
    if (x % 2 == 0) {
    push(&example, x);
    } else {
        pop(&example);
    }
 }
 exibirItens(&example);
 size(&example);
 return 0;
}



 
 
