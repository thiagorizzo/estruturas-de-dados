#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int TAMANHO_PILHA = 100;
int pilha[100];
int topo = -1;

struct intNullable {
	bool hasValor;
	int valor;
};

bool isPilhaVazia() {
	return topo == -1;
}

bool isPilhaCheia() {
	return topo + 1 == TAMANHO_PILHA;
}

bool push(int numero) {
	if (isPilhaCheia())
		return false;

	pilha[++topo] = numero;
	return true;
}

struct intNullable pop() {
	struct intNullable valorRetorno;
	
	if (isPilhaVazia())
		valorRetorno.hasValor = false;
	else {
		valorRetorno.hasValor = true;
		valorRetorno.valor = pilha[topo--];
	}
		
	return valorRetorno;	
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int opcao;
	int valor;
	struct intNullable valorRetorno;
	
	do {
		printf("1) Push\n");
		printf("2) Pop\n");
		printf("3) Sair\n");		
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1:
				printf("Valor:");
				scanf("%d", &valor);
				if (push(valor) == false)
					printf("Pilha cheia.\n\n");
				break;
				
			case 2:
				valorRetorno = pop();
				if (!valorRetorno.hasValor)
					printf("Pilha vazia.\n\n");
				else
					printf("Valor Pop: %d\n\n", valorRetorno.valor);
				break;
		}
	} while(opcao != 3);
	
	getch();
}
