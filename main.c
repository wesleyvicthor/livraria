#include <stdio.h>
#include <stdlib.h>

struct lista {
	int codigo;
	char titulo[50];
	char autor[50];
	float preco;
	int qtdEstoque;
	struct lista *proximo;
} *inicio;

void cadastrarLivro() {
	int end;
	struct lista *livro;

	printf("\nCadastrar Livro: \n");
	printf("Digite o endereço para armazenar: \n");
	scanf("%d", &end);

	livro = (struct lista*) malloc (sizeof(struct lista)*end);

	printf("Digite o código: \n");
	scanf("%d", &livro->codigo);
	printf("Digite o título: \n");
	scanf("%s", livro->titulo);
	printf("Digite o autor: \n");
	scanf("%s", livro->autor);
	printf("Digite o preco: \n");
	scanf("%f", &livro->preco);
	printf("Digite a quantidade no estoque: \n");
	scanf("%d", &livro->qtdEstoque);

	if (!inicio) {
		livro->proximo = NULL;
		inicio = livro;
	} else {
		inicio->proximo = livro;
	}

	printf("Livro inserido com sucesso\n");
	return;
}
void comprarLivro() {}
void venderLivro() {}
void listarLivros() {
	struct lista *aux;
	aux = inicio;
	printf("|\tCódigo\t|\tTítulo\t|\tAutor\t|\tPreço\t|\tEstoque\t|\n");
	printf("---------------------------------------------------------------------\n");
	while(aux) {
		printf(
			"|\t%d\t|\t%s\t|\t%s\t|\t%.2f\t|\t%d\t|\n",
			aux->codigo,
			aux->titulo,
			aux->autor,
			aux->preco,
			aux->qtdEstoque
		);
		aux = aux->proximo;
	}
}
void pesquisarPorTitulo() {}
void pesquisarPorAutor() {}
void removerLivro() {}

int main () 
{
	int opcao;
	printf("Bem Vindo a Livraria\n");
	while (opcao != 8) {
		printf("O que deseja fazer?\n\n");

		printf("[1] Cadastrar um livro novo\n");
		printf("[2] Comprar exemplares de um livro de uma editora\n");
		printf("[3] Vender livro para cliente\n");
		printf("[4] Listar livros existentes no estoque\n");
		printf("[5] Pesquisar livro por título\n");
		printf("[6] Pesquisar livro por autor\n");
		printf("[7] Remover livro da lista\n");
		printf("[8] Fim\n");

		scanf("%d", &opcao);


		switch (opcao) {
			case 1:
				cadastrarLivro();
			break;
			case 2:
				comprarLivro();
			break;
			case 3:
				venderLivro();
			break;
			case 4:
				listarLivros();
			break;
			case 5:
				pesquisarPorTitulo();
			break;
			case 6:
				pesquisarPorAutor();
			break;
			case 7:
				removerLivro();
			break;
		}
	}
	return 0;
}