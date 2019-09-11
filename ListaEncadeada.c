#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
 
struct No
{
    int numero;
    struct No *prox;
};
 
void inserir(int numero, struct No **lista){
    struct No *novoNo = (struct No*) malloc(sizeof(struct No));
    novoNo->numero = numero;
    novoNo->prox = NULL;
   
    if(*lista == NULL)
        *lista = novoNo;
    else
	{
        struct No *noAtual = *lista;

        while(noAtual->prox != NULL)
			noAtual = noAtual->prox;
        
		noAtual->prox = novoNo;
    }
}
 
void listar(struct No *lista){
    struct No *noAtual = lista;
    
    if (noAtual == NULL)
		printf("Lista vazia\n ");
    else
	{
        while(noAtual != NULL){
            printf("%d\n", noAtual->numero);
            noAtual = noAtual->prox;
        }
    }
}
 
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    int opcao, valor;
    struct No *lista = NULL;
   
    do
	{
        printf("valor: ");
        scanf("%d", &valor);
       
        inserir(valor, &lista);
        printf("opção (0-SAIR): ");
        scanf("%d", &opcao);
    } while(opcao != 0);

    listar(lista);
    
    system("pause");
}
