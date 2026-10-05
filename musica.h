#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica Musica;

Musica* musica_criar(const char* titulo, const char* artista, int duracao);

const char* musica_get_titulo(const Musica* musica);
const char* musica_get_artista(const Musica* musica);
int musica_get_duracao(const Musica* musica);

void musica_imprimir(const Musica* musica);
void musica_destruir(Musica* musica);

#endif