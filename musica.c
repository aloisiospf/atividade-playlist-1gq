#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

struct musica {
    char titulo[100];
    char artista[100];
    int duracao;
};

Musica* musica_criar(const char* titulo, const char* artista, int duracao) {
    if (titulo == NULL || artista == NULL || duracao < 0)
        return NULL;

    Musica* musica = malloc(sizeof(Musica));

    if (musica == NULL)
        return NULL;

    strncpy(musica->titulo, titulo, sizeof(musica->titulo) - 1);
    musica->titulo[sizeof(musica->titulo) - 1] = '\0';

    strncpy(musica->artista, artista, sizeof(musica->artista) - 1);
    musica->artista[sizeof(musica->artista) - 1] = '\0';

    musica->duracao = duracao;

    return musica;
}

const char* musica_get_titulo(const Musica* musica) {
    if (musica == NULL)
        return NULL;

    return musica->titulo;
}

const char* musica_get_artista(const Musica* musica) {
    if (musica == NULL)
        return NULL;

    return musica->artista;
}

int musica_get_duracao(const Musica* musica) {
    if (musica == NULL)
        return 0;

    return musica->duracao;
}

void musica_imprimir(const Musica* musica) {
    if (musica == NULL)
        return;

    printf("Titulo: %s\n", musica->titulo);
    printf("Artista: %s\n", musica->artista);
    printf("Duracao: %d segundos\n", musica->duracao);
}

void musica_destruir(Musica* musica) {
    free(musica);
}