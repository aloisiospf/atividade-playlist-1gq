#ifndef LISTA_H
#define LISTA_H

#include "musica.h"

typedef struct lista Lista;

Lista* lista_criar(void);

int lista_inserir_inicio(Lista* lista, Musica* musica);
int lista_inserir_final(Lista* lista, Musica* musica);
int lista_inserir_posicao(Lista* lista, Musica* musica, int posicao);

Musica* lista_remover_primeira(Lista* lista);
Musica* lista_remover_ultima(Lista* lista);
Musica* lista_remover_posicao(Lista* lista, int posicao);

Musica* lista_primeira(const Lista* lista);
Musica* lista_consultar_posicao(const Lista* lista, int posicao);

int lista_quantidade(const Lista* lista);

void lista_destruir(Lista* lista);

#endif