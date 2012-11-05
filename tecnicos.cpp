#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filaPedidos {
    char nomeCliente[20];
    char descServico[20];
    char endereco[20];
    char bairro[15];
    struct filaPedidos *proximo;
} *inicio, *fim;

struct tecnico {
    char nomeTecnico[20];
    bool liberado;
    int qtdAtendimentos;
} tecnicos[5];


void inserirPedido() {
    struct filaPedidos *cliente;
    cliente = (struct filaPedidos *) malloc(sizeof(struct filaPedidos));    

    printf("Inserir pedido\n");
    printf("Nome do cliente:\n");
    scanf("%s", cliente->nomeCliente);
    printf("Descrição do serviço:\n");
    scanf("%s", cliente->descServico);
    printf("Endereco:\n");
    scanf("%s", cliente->endereco);
    printf("Bairro:\n");
    scanf("%s", cliente->bairro);

    if (NULL == inicio) {
        inicio = cliente;
    } else {
        fim->proximo = cliente;
        fim = cliente;
    }
}

void atenderPedido() {
    printf("Atender pedido\n");
    if (inicio == NULL) {
        printf("Fila de pedidos vazia\n");
        return;
    }
    char nome[20];
    printf("Digite o nome do técnico para atender: \n");
    scanf("%s", nome);

    int exist = -1;
    int tecId = 0;
    while (tecId != 5){
        if (strcmp(tecnicos[tecId].nomeTecnico, nome) == 0) {
            if (!tecnicos[tecId].liberado) {
                printf("Técnico não liberado para atendimento\n");
                return;
            }
            exist = tecId;
        }
        tecId++;
    }
    if (exist == -1) {
        printf("Técnico não existe!\n");
        return;
    }
    struct filaPedidos *aux;
    aux = inicio;
    printf("Dados a serem atendidos: \n");
    printf("Nome cliente: %s\n", aux->nomeCliente);
    printf("Descrição serviço: %s\n", aux->descServico);
    printf("Endereço: %s\n", aux->endereco);
    printf("Bairro: %s\n", aux->bairro);
    printf("Técnico responsável: %s\n", tecnicos[exist].nomeTecnico);
    tecnicos[exist].liberado = false;
    tecnicos[exist].qtdAtendimentos += 1;
    inicio = inicio->proximo;
    free(aux);
}

void liberarTecnico() {
    char nome[20];
    printf("Liberar Técnico\n");
    printf("Digite o nome do técnico: \n");

    int exist = -1;
    int tecId = 0;
    while (tecId != 5){
        if (strcmp(tecnicos[tecId].nomeTecnico, nome) == 0) {
            if (!tecnicos[tecId].liberado) {
                tecnicos[tecId].liberado = true;
                return;
            }
            exist = tecId;
        }
        tecId++;
    }
    if (exist == -1) {
        printf("Técnico não existe!\n");
        return;
    }
    printf("Técnico liberado para atendimento!\n");
}
void relacionarNomes() {
    printf("Técnicos liberados: \n");
    int tecId = 0;
    while (tecId != 5){
        if (tecnicos[tecId].liberado) {
            printf("%s\n", tecnicos[tecId].nomeTecnico);
        }
        tecId++;
    }
}
void qtdPedidosSemAtentimento () {
    struct filaPedidos *aux;
    aux = inicio;
    int qtd = 0;
    while(aux != NULL) {
        qtd = qtd + 1;
        aux = aux->proximo;
    }
    printf("Total de %d pedidos na fila\n", qtd);
}
void qtdPedidosPorTecnico() {
    int tecId = 0;
    while(tecId != 5) {
        printf("Técnico %s, atendeu %d pedidos.\n", tecnicos[tecId].nomeTecnico, tecnicos[tecId].qtdAtendimentos);
    }
}
int pesquisar() {
    int opcao = 0;
    while (opcao != 5) {
        printf("[1] Quantidade de pedidos sem atendimento\n");
        printf("[2] Quantidade de pedidos atendidos por técnico\n");
        printf("[3] Relação de pedidos por bairro\n");
        printf("[4] Dados dos pedidos\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                qtdPedidosSemAtentimento();
            break;
            case 2:
                qtdPedidosPorTecnico();
            break;
            case 3:
                char bairro[15];
                printf("Digite o nome do bairro: \n");
                struct filaPedidos *auxx;
                auxx = inicio;
                while(auxx != NULL) {
                    if (strcmp(auxx->bairro, bairro) == 0) {
                        printf("Nome cliente, %s\n", auxx->nomeCliente);
                        printf("Descrição serviço, %s\n", auxx->descServico);
                        printf("Endereço, %s\n", auxx->endereco);
                        printf("Bairro, %s\n", auxx->bairro);
                        printf("-\n");
                    }
                    auxx = auxx->proximo;
                }
            break;
            case 4:
                struct filaPedidos *aux;
                aux = inicio;
                while(aux != NULL) {
                    printf("Nome cliente, %s\n", aux->nomeCliente);
                    printf("Descrição serviço, %s\n", aux->descServico);
                    printf("Endereço, %s\n", aux->endereco);
                    printf("Bairro, %s\n", aux->bairro);
                    printf("-\n");
                    aux = aux->proximo;
                }
            break;
            case 5:
                return 0;
            break;
        }
    }
}

int main ()
{
    int tecId = 0;
    int opcao = 0;
    printf("Assistência Técnica - Fila de Atendimento de Pedidos");
    printf("\n-\n");
    printf("Cadastro de Técnicos\n");
    while (tecId != 5){
        printf("Digite o nome do %dº técnico: ", (tecId+1));
        scanf("%s", tecnicos[tecId].nomeTecnico);
        tecnicos[tecId].liberado = true;
        tecnicos[tecId].qtdAtendimentos = 0;
        tecId++;
    }

    while (opcao != 6) {
        printf("O que deseja fazer ?\n");
        printf("[1] Inserir pedido na fila\n");
        printf("[2] Atender um pedido\n");
        printf("[3] Liberar um técnico para novo atendimento\n");
        printf("[4] Relacionar nomes dos técnicos liberados\n");
        printf("[5] Pesquisas\n");
        printf("[6] Sair\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                inserirPedido();
            break;
            case 2:
                atenderPedido();
            break;
            case 3:
                liberarTecnico();
            break;
            case 4:
                relacionarNomes();
            break;
            case 5:
                pesquisar();
            break;
            case 6:
                return 0;
            break;
        }
    }
}
