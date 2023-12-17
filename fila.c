#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 10

typedef struct FILA {
    int dados[N];
    int fim;
} FILA;

void inicializar_fila(FILA *f) {
    for (int i = 0; i < N; i++) {
        f->dados[i] = 0;
    }
    f->fim = 0;
}

void inserir_na_fila(FILA *f, int elemento) {
    if (f->fim == N) {
        printf("A fila está cheia.\n");
        return;
    } else {
        f->dados[f->fim] = elemento;
        f->fim++;
    }
}

void inserirComPrioridade(FILA *f, int elemento) {
    if (f->fim == N) {
        printf("A fila está cheia.\n");
        return;
    }

    // Verifica se o elemento é maior que 69
    if (elemento > 69) {
        // Desloca os elementos existentes para a direita
        for (int i = f->fim; i > 0; i--) {
            f->dados[i] = f->dados[i - 1];
        }

        // Insere o elemento no início da fila
        f->dados[0] = elemento;
        f->fim++;
    } else {
        // Insere o elemento no final da fila
        f->dados[f->fim] = elemento;
        f->fim++;
    }
}

int remover_na_fila(FILA *f) {
    if (f->fim == 0) {
        printf("A fila está vazia.\n");
        return 1;
    } else {
        int removido = f->dados[0];
        for (int i = 0; i < f->fim; i++) {
            f->dados[i] = f->dados[i + 1];
        }
        f->fim--;
        return removido;
    }
}

void imprimir_fila(FILA *f) {
    for (int i = 0; i < f->fim; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

int main() {
    FILA fila1;

    inicializar_fila(&fila1);

    int opcao = -1, valor;
    while (opcao) {
        printf("Faça uma escolha: \n\t - 0 sair\n\t - 1 Inserir\n\t - 2 Remover\n\t - 3 InseriP\n\t - 4 Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número: ");
                scanf("%d", &valor);
                inserir_na_fila(&fila1, valor);
                break;
            case 2:
                remover_na_fila(&fila1);
                break;
            case 3:
                printf("Digite um número: ");
                scanf("%d", &valor);
                inserirComPrioridade(&fila1, valor);
                break;
            case 4:
                imprimir_fila(&fila1);
                break;
            default:
                if (opcao == 0)
                    exit(0);
        }
    }

    return 0;
}
