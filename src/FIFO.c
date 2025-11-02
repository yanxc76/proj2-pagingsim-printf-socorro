#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
} Node;

struct Queue {
    Node* inicio;
    Node* fim;
} Queue;

// Cria e inicializa uma nova fila vazia
Queue criarFila() {
    Queue* novaFila = (Queue*)malloc(sizeof(Queue));
    if (novaFila == NULL) {
        printf("Erro ao alocar memória para a fila!\n");// Facilitar depuração de erro na alocação (idealmente nunca aparecerá)
        exit(1);
    }
    novaFila->inicio = NULL;
    novaFila->fim = NULL;
    return novaFila;
}

// Verifica se a fila está vazia
boolean vazia(Queue* f) {
    return (f->inicio == NULL);
}


// Inserir valor na fila
void push(Queue* f, int dado) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o nó!\n");// Facilitar depuração de erro na alocação (idealmente nunca aparecerá)
        exit(1);
    }
    novoNo->data = dado;
    novoNo->next = NULL;

    if (vazia(f)) {
        f->inicio = novoNo;
        f->fim = novoNo;
    } else {
        f->fim->proximo = novoNo; // o próximo do último nó atual aponta para o novo nó
        f->fim = novoNo; // novo nó se torna o novo último nó
    }
}

// Remover valor da fila
void pop(Queue* f) {
    if (vazia(f)) {
        exit(1);
    }

    Node* noARemover = f->inicio;
    int dadoRemovido = noARemover->dado;
    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL) { // Se fila ficou vazia, altera fim para NULL
        f->fim = NULL;
    }

    free(noARemover);
    return dadoRemovido;
}

// Liberar memória da fila
void liberaFila(Queue* f) {
    while(!vazia(f)) {
        pop(f);
    }
    free(f);
}

int main() {
    Queue* f = criarFila();

    return 0;
}