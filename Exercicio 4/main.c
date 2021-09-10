#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_DA_FILA 100
/*
Estrutura de dados criada para representar uma fila que armazena valores inteiros.
OperaC'C5es em Filas:
- CriaC'C#o de uma fila vazia;
- VerificaC'C#o para saber se a fila estC! vazia;
- InserC'C#o de elementos na fila;
- Tamanho da fila;
- Consulta do prC3ximo elemento que serC! atendido na fila;
- RemoC'C#o de elementos na fila;
- Liberar a fila;
*/
// Estrutura para representar a nossa fila
struct fila
{
  int itens[TAMANHO_DA_FILA];
  int frente;
  int atras;
};
//Funcao responsavel por verificar se a fila esta vazia
int
verificarFila (struct fila *p)
{
  if (p->frente != p->atras)
    {
      return 0;			// Fila com itens
    }
  else
    {
      return 1;			// Fila vazia
    }
}

// Insere itens na fila
void
inserirItem (struct fila *p, int x)
{
  if (p->atras + 1 >= TAMANHO_DA_FILA)
    {
      printf ("\n Fila cheia!");
      exit (1);
    }
  else
    {
      p->itens[p->atras++] = x;
    }
}

// Retorna o tamanho da fila
int
tamanhoFila (struct fila *p)
{
  return p->atras;
}

// Retorna o proximo item da fila
int
proximoItem (struct fila *p)
{
  return p->itens[0];
}

// Remove itens da fila
int
remover (struct fila *p)
{
  int x, i;
  if (verificarFila (p))
    {
      printf ("\n A fila esta vazia.");
      exit (1);
    }
  x = proximoItem (p);
  for (i = 0; i < tamanhoFila (p); i++)
    {
      p->itens[i] = p->itens[i + 1];
    }
  p->atras--;
  return x;
}

// Limpa a fila
void
esvaziarFila (struct fila *p)
{
  int tam = tamanhoFila (p);
  int i;
  printf ("\n Processos de esvaziamento de fila");
  for (i = 0; i < tam; i++)
    {
      printf ("\n Item %d retirado da fila.", remover (p));
    }
}

// Funcao que calcula fatorial
int fatorial (int x){
 int n = x;
 int fat;
 for (fat = 1; n > 1; n = n - 1) {
 fat = fat * n;
 }
 printf("\n Fatorial = %d", fat);
 return fat;
}

// mostra os numeros inteiros presentes na fila
void exibirItem (struct fila *p) {
 for (int i = 0; i < tamanhoFila(p); i++) {
 printf("\n [%d] Item na fila: %d", i+1, p->itens[i]);
 }
}

int main () { 
 int x, aux;
 struct fila nossaFila;
 nossaFila.frente = 0; // Controla o início da fila
 nossaFila.atras = 0; // Controla o fim da fila

 printf("\n Insira um valor inteiro para calcular seu fatorial: ");
 scanf("%d", &x);
 aux = fatorial(x);
 inserirItem(&nossaFila,aux);
 exibirItem(&nossaFila);
 
 return 0;
}

