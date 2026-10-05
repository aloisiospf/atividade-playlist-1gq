#include <stdlib.h>
#include "lista.h"

typedef struct no {
    Musica* musica;
    struct no* proximo;
} No;

struct lista {
    No* inicio;
    int quantidade;
};

Lista* lista_criar(void) {
    Lista* lista = malloc(sizeof(Lista));

    if (lista == NULL)
        return NULL;

    lista->inicio = NULL;
    lista->quantidade = 0;

    return lista;
}

int lista_inserir_inicio(Lista* lista, Musica* musica) {
    if (lista == NULL || musica == NULL)
        return 0;

    No* novo = malloc(sizeof(No));

    if (novo == NULL)
        return 0;

    novo->musica = musica;
    novo->proximo = lista->inicio;

    lista->inicio = novo;
    lista->quantidade++;

    return 1;
}

int lista_inserir_final(Lista* lista, Musica* musica) {
    if (lista == NULL || musica == NULL)
        return 0;

    No* novo = malloc(sizeof(No));

    if (novo == NULL)
        return 0;

    novo->musica = musica;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;

        while (atual->proximo != NULL)
            atual = atual->proximo;

        atual->proximo = novo;
    }

    lista->quantidade++;

    return 1;
}

int lista_inserir_posicao(Lista* lista, Musica* musica, int posicao) {
    if (lista == NULL || musica == NULL)
        return 0;

    if (posicao < 0 || posicao > lista->quantidade)
        return 0;

    if (posicao == 0)
        return lista_inserir_inicio(lista, musica);

    if (posicao == lista->quantidade)
        return lista_inserir_final(lista, musica);

    No* novo = malloc(sizeof(No));

    if (novo == NULL)
        return 0;

    No* atual = lista->inicio;

    for (int i = 0; i < posicao - 1; i++)
        atual = atual->proximo;

    novo->musica = musica;
    novo->proximo = atual->proximo;
    atual->proximo = novo;

    lista->quantidade++;

    return 1;
}

Musica* lista_remover_primeira(Lista* lista) {
    if (lista == NULL || lista->inicio == NULL)
        return NULL;

    No* remover = lista->inicio;
    Musica* musica = remover->musica;

    lista->inicio = remover->proximo;

    free(remover);
    lista->quantidade--;

    return musica;
}

Musica* lista_remover_ultima(Lista* lista) {
    if (lista == NULL || lista->inicio == NULL)
        return NULL;

    if (lista->inicio->proximo == NULL)
        return lista_remover_primeira(lista);

    No* atual = lista->inicio;

    while (atual->proximo->proximo != NULL)
        atual = atual->proximo;

    No* remover = atual->proximo;
    Musica* musica = remover->musica;

    atual->proximo = NULL;

    free(remover);
    lista->quantidade--;

    return musica;
}

Musica* lista_remover_posicao(Lista* lista, int posicao) {
    if (lista == NULL)
        return NULL;

    if (posicao < 0 || posicao >= lista->quantidade)
        return NULL;

    if (posicao == 0)
        return lista_remover_primeira(lista);

    if (posicao == lista->quantidade - 1)
        return lista_remover_ultima(lista);

    No* atual = lista->inicio;

    for (int i = 0; i < posicao - 1; i++)
        atual = atual->proximo;

    No* remover = atual->proximo;
    Musica* musica = remover->musica;

    atual->proximo = remover->proximo;

    free(remover);
    lista->quantidade--;

    return musica;
}

Musica* lista_primeira(const Lista* lista) {
    if (lista == NULL || lista->inicio == NULL)
        return NULL;

    return lista->inicio->musica;
}

Musica* lista_consultar_posicao(const Lista* lista, int posicao) {
    if (lista == NULL)
        return NULL;

    if (posicao < 0 || posicao >= lista->quantidade)
        return NULL;

    No* atual = lista->inicio;

    for (int i = 0; i < posicao; i++)
        atual = atual->proximo;

    return atual->musica;
}

int lista_quantidade(const Lista* lista) {
    if (lista == NULL)
        return 0;

    return lista->quantidade;
}

void lista_destruir(Lista* lista) {
    if (lista == NULL)
        return;

    No* atual = lista->inicio;

    while (atual != NULL) {
        No* proximo = atual->proximo;

        musica_destruir(atual->musica);
        free(atual);

        atual = proximo;
    }

    free(lista);
}