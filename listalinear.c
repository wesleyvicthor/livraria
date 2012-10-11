#include <stdio.h>

int elemento[100];
int ultimo;

void inserir() {
    int num, i, posicao;
    if (ultimo == 99) {
        printf("Lista Cheia");
        return;
    }

    printf("Digite o numero a ser inserido\n");
    scanf("%d", &num);
    printf("Digite a posicao\n");
    scanf("%d", &posicao);

    printf("%d\n", ultimo);
    for (i = ultimo; i>= posicao; i--) {
        printf("%d\n", i);
        elemento[i+1] = elemento[i];
    }
    elemento[posicao] = num;
    ultimo = ultimo + 1;
    return;
};
void remover() {
    
};
void pesquisar() {};
void listar() {};

void main ()
{
    int opcao;
    ultimo = -1;
    while(opcao != 5) {
        printf("Digite uma opção: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir();
            break;
            case 2:
                remover();
            break;
            case 3:
                pesquisar();
            break;
            case 4:
                listar();
            break;
        }
    }
}