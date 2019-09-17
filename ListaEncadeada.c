#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
 
struct No {
    int numero;
    struct No *prox;
};
 
void inserir(int numero, struct No **lista) {
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
 
void listar(struct No *lista) {
    struct No *noAtual = lista;
    
    if (noAtual == NULL)
		printf("Lista vazia.\n");
    else
	{
        while(noAtual != NULL){
            printf("%d\n", noAtual->numero);
            noAtual = noAtual->prox;
        }
    }
}

bool remover(int numero, struct No **lista) {
    struct No *noAtual = *lista;
    struct No *noAnterior = NULL;
    bool removeu = false;

    while (noAtual != NULL) {
        if (noAtual->numero == numero) {
            if (noAnterior == NULL)
                *lista = NULL;
            else {
                removeu = true;
                noAnterior->prox = noAtual->prox;                
                free(noAtual);
            }
        }

        noAnterior = noAtual;
        noAtual = noAtual->prox;
    }

    return removeu;
}
 
int main() {
	setlocale(LC_ALL, "Portuguese");
	
    int opcao, valor;
    struct No *lista = NULL;
    bool removeu;

    do {
        printf("1) Inserir\n");
        printf("2) Remover\n");
        printf("3) Listar\n");
        printf("4) Sair\n\n");
        printf("opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: 
                printf("Inserir valor:");
                scanf("%d", &valor);
                inserir(valor, &lista);
                break;

            case 2: 
                printf("Remover valor:");
                scanf("%d", &valor);
                removeu = remover(valor, &lista);
                if (removeu == false)
                    printf("Não foi possível remover valor. Valor não encontrado.");
                break;

            case 3: 
                printf("\n--- Lista ---\n");
                listar(lista);
                break;
        }
    } while(opcao != 4);

    getchar();

    return 0;
}
