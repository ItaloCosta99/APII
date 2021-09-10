#include <stdio.h> 
#include <stdlib.h>
#define TAMANHO 10
  
  struct pilha
{
  
int top;
   
float itens[TAMANHO];
 
};

int
clean (struct pilha *p)
{
  
if (p->top == -1)
    {
      
return -1;
    
}
  
return 0;

}


float
pop (struct pilha *p)
{
  
if (clean (p))
    {
      
printf ("\nA pilha esta vazia");
      
exit (1);
    
}
  
return (p->itens[p->top--]);

}


void
push (struct pilha *p, float value)
{
  
if (p->top == (TAMANHO - 1))
    {
      
printf ("\nA pilha esta cheia!");
      
exit (1);
    
}
  
p->itens[++(p->top)] = value;
  
return;

}


int
size (struct pilha *p)
{
  
return p->top + 1;

}


float
topValue (struct pilha *p)
{
  
return p->itens[p->top];

}


int
main ()
{
  
struct pilha example;
  
example.top = -1;
  
push (&example, 3.6);
  
push (&example, 2.7);
  
push (&example, 2.3);
  
push (&example, 4.6);
  
push (&example, 5.0);
  
printf ("\nTamanho da pilha: %d", size (&example));
  
printf ("\nTopo da pilha: %f", topValue (&example));
  
printf ("\nFoi retirado: %f", pop (&example));
  
printf ("\nFoi retirado: %f", pop (&example));
  
printf ("\nFoi retirado: %f", pop (&example));
  
printf ("\nFoi retirado: %f", pop (&example));
  
printf ("\nFoi retirado: %f", pop (&example));
  
printf ("\nFoi retirado: %f", pop (&example));
  
return 0;

}


 
 
