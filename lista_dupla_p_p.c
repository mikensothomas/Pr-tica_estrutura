#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct no {
    int valor;
    struct no *proximo;
    struct no *anterior;
} No;

void inserirNoInicio(No **lista, int num) {
    No *novo = (No *)malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        novo->proximo = *lista;
        novo->anterior = NULL;
        if(*lista){
            (*lista)->anterior = novo;
        }
        *lista = novo;
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void inserirNoFinal(No **lista, int num) {
    No *auxi, *novo = (No *)malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;

        if (*lista == NULL) {
            *lista = novo;
            novo->anterior = NULL;
        } else {
            auxi = *lista;
            while (auxi->proximo) {
                auxi = auxi->proximo;
            }
            auxi->proximo = novo;
            novo->anterior = auxi;
        }

    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void inserirNoMeio(No **lista, int num, int ant) {
    No *aux, *novo = (No *)malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        if (*lista == NULL) {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->valor != ant && aux->proximo) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void inserir_ordrnado(No **lista, int num){
    No *aux, *novo = (No*) malloc(sizeof(No));
    if(novo){
        novo->valor = num;

        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        } else {
            if(novo->valor < (*lista)->valor){
                novo->proximo = *lista;
                (*lista)->anterior = novo;
                *lista = novo;
            } else {
                aux = *lista;
                while (aux->proximo && novo->valor > aux->proximo->valor){
                    aux = aux->proximo;
                }
                novo->proximo = aux->proximo;
                if(aux->proximo){
                    aux->proximo->anterior = novo;
                }
                novo->anterior = aux;
                aux->proximo = novo;
                
            }
        }
    } else {
        printf("Erro ao alocar memória");
    }
}

No* remove_na_lista(No **lista, int num){
    No *aux, *remover = NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
            if(*lista){
                (*lista)->anterior = NULL;
            }
        } else {
            aux = *lista;
            while (aux->proximo && aux->proximo->valor != num){
                aux = aux->proximo;
            }
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo){
                    aux->proximo->anterior = aux;
                }
            }
        }
    }

    return remover;
}

No* buscar_na_lisla(No **lista, int num){
    No *auxi, *no = NULL;
    auxi = *lista;
    while (auxi && auxi->valor != num){
        auxi = auxi->proximo;
    }
    if (auxi){
        no = auxi;
    }
    
    return no;
}

void imprimirLista(No *no) {
    printf("\n\tLista:");
    while (no) {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

No* ultimoNo(No **lista){
    No *auxi = *lista;
    while (auxi->proximo){
        auxi = auxi->proximo;
    }
    return auxi;
}

void imprimirContrario(No *no){
    printf("\n\tLista:");
    while (no) {
        printf("%d ", no->valor);
        no = no->anterior;
    }
    printf("\n\n");
}

int main() {

    int opcao, valor, anterior;
    No *remover, *lista = NULL;

    do {
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - InserirF\n\t3 - InserirM\n\t4 - InserirOrdenado\n\t5 - Remover\n\t6 - Buscar\n\t7 - Imprimir\n\t8 - ImprimirC\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 0:
            exit (0);
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserirNoInicio(&lista, valor);
            break;
        case 2:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserirNoFinal(&lista, valor);
            break;
        case 3:
            printf("Digite o valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserirNoMeio(&lista, valor, anterior);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordrnado(&lista, valor);
            break;
        case 5:
            printf("Digite o valor a ser remvido: ");
            scanf("%d", &valor);
            remover = remove_na_lista(&lista, valor);
            if(remover){
                printf("Elemento a ser removido: %d\n", remover->valor);
                free(remover);
            } else{
                printf("Este elemento não existe na lista.");
            }
            break;
        case 6:
            printf("Digite o valor a ser buscado ");
            scanf("%d", &valor);
            remover = buscar_na_lisla(&lista, valor);
            if(remover){
                printf("Elemento encontrado: %d\n", remover->valor);   
            } else {
                printf("Elemento não encontrado.");
            }
            break;
        case 7:
            imprimirLista(lista);
            break;
        case 8:
            imprimirContrario(ultimoNo(&lista));
            break;
        default:
            printf("Valor não encontrado.\n");
            exit(0);
        }
        
    } while (opcao != 0);

    return 0;
}