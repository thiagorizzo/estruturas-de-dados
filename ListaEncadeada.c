#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h> 
 
struct No {
    int numero;
    struct No *prox;
    struct No *ant;
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

		novoNo->ant = noAtual;
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
				noAtual->prox->ant = noAnterior;              
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
	
    int opcao, valor, opcaoPercorrer;
    struct No *lista = NULL;
    struct No *noPercorrer = NULL;
    bool removeu;

    do {
        printf("1) Inserir\n");
        printf("2) Remover\n");
        printf("3) Listar\n");
        printf("4) Percorrer Lista\n");
        printf("5) Sair\n\n");
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
                
            case 4:
        		noPercorrer = lista;
            	do {
			        printf("1) Proximo\n");
			        printf("2) Anterior\n");
			        printf("3) Apresentar Atual\n");
			        printf("4) Sair\n\n");
			        printf("opcao: ");
			        scanf("%d", &opcaoPercorrer);
            		
            		switch(opcaoPercorrer) {
						case 1:
							if (noPercorrer->prox == NULL)
								printf("Não há nó próximo. Último nó da lista.\n\n");
							else
								noPercorrer = noPercorrer->prox;
							break;
							
						case 2:
							if (noPercorrer->ant == NULL)
								printf("Não há nó anterior. Primeiro nó da lista.\n\n");
							else
								noPercorrer = noPercorrer->ant;
							break;
							
						case 3:
							printf("Atual: %d\n", noPercorrer->numero);
							break;	
					}
				} while(opcaoPercorrer != 4);
				break;
        }
    } while(opcao != 5);

    getchar();

    return 0;
}
