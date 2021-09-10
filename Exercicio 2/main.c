#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_DA_FILA 100
/*
Estrutura de dados criada para representar uma fila que armazena valores inteiros.
Operações em Filas:
- Criação de uma fila vazia;
- Verificação para saber se a fila está vazia;
- Inserção de elementos na fila;
- Tamanho da fila;
- Consulta do próximo elemento que será atendido na fila;
- Remoção de elementos na fila;
- Liberar a fila;
*/
// Estrutura para representar a nossa fila
struct fila {
 int itens[TAMANHO_DA_FILA];
 int frente;
 int atras;
};
//Funcao responsavel por verificar se a fila esta vazia
int verificarFila (struct fila *p) {
 if ( p->frente != p->atras ) {
 return 0; // Fila com itens
 } else {
 return 1; // Fila vazia
 }
}
// Insere itens na fila
void inserirItem (struct fila *p, int x) {
 if (p->atras+1 >= TAMANHO_DA_FILA) {
 printf("\n Fila cheia!");
 exit(1);
 } else {
 p->itens[p->atras++] = x;
 }
}
// Retorna o tamanho da fila
int tamanhoFila (struct fila *p) {
 return p->atras;
}
// Retorna o próximo item da fila
int proximoItem (struct fila *p) {
 return p->itens[0];
}
// Remove itens da fila
int remover (struct fila *p) {
 int x, i;
 if ( verificarFila(p) ) {
 printf("\n A fila esta vazia.");
 exit(1);
 }
 x = proximoItem(p);
 for (i = 0; i < tamanhoFila(p); i++) {
 p->itens[i] = p->itens[i+1];
 }
 p->atras--;
 return x;
}
// Limpa a fila
void esvaziarFila (struct fila *p) {
 int tam = tamanhoFila(p);
 int i;
 printf("\n Processos de esvaziamento de fila");
 for (i = 0; i < tam; i++) {
 printf("\n Item %d retirado da fila.", remover(p));
 }
}
int main(){
 struct fila nossaFila;
 nossaFila.frente = 0; // Controla o início da fila
 nossaFila.atras = 0; // Controla o fim da fila
 if (verificarFila(&nossaFila) == 0) {
 printf("\n Fila com itens");
 } else {
 printf("\n Fila vazia");
 }
 inserirItem(&nossaFila,4);
 inserirItem(&nossaFila,2);
 inserirItem(&nossaFila,5);
 for (int i = 0; i < tamanhoFila(&nossaFila); i++) {
 printf("\n Valor resultante: %d", nossaFila.itens[i]);
 }
 printf("\n Tamanho da fila: %d", tamanhoFila(&nossaFila));
 printf("\n Proximo item: %d", proximoItem(&nossaFila));
 printf("\n O elemento removido: %d", remover(&nossaFila));
 for (int i = 0; i < tamanhoFila(&nossaFila); i++) {
 printf("\n Valor resultante: %d", nossaFila.itens[i]);
 }
 printf("\n Tamanho da fila: %d", tamanhoFila(&nossaFila));
 printf("\n Proximo item: %d", proximoItem(&nossaFila));
 esvaziarFila(&nossaFila);
 return 0;
}
