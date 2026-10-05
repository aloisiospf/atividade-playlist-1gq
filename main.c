#include <stdio.h>
#include "musica.h"
#include "lista.h"

void adiciona_musica(Lista* playlist, Musica* musica) {
    lista_inserir_final(playlist, musica);
}

void adiciona_musica_posicao(Lista* playlist, Musica* musica, int posicao) {
    lista_inserir_posicao(playlist, musica, posicao);
}

void remove_musica(Lista* playlist, int posicao) {
    Musica* musica = lista_remover_posicao(playlist, posicao);

    if (musica != NULL)
        musica_destruir(musica);
}

int tempo_restante(Lista* playlist, int proxima) {
    int total = 0;
    int quantidade = lista_quantidade(playlist);

    for (int i = proxima; i < quantidade; i++) {
        Musica* musica = lista_consultar_posicao(playlist, i);

        if (musica != NULL)
            total += musica_get_duracao(musica);
    }

    return total;
}

void play(Lista* playlist, int* proxima) {
    Musica* musica = lista_consultar_posicao(playlist, *proxima);

    if (musica == NULL) {
        printf("Fim da playlist.\n");
        return;
    }

    printf("\nTocando:\n");
    musica_imprimir(musica);

    (*proxima)++;
}

int musicas_reproduzidas(int proxima) {
    return proxima;
}

int main() {
    Lista* playlist = lista_criar();

    if (playlist == NULL) {
        printf("Erro ao criar a playlist.\n");
        return 1;
    }

    int proxima = 0;

    Musica* m1 = musica_criar("Through the Wire", "Kanye West", 221);
    Musica* m2 = musica_criar("No Church in the Wild", "Kanye West", 272);
    Musica* m3 = musica_criar("We Major", "Kanye West", 448);
    Musica* m4 = musica_criar("Paranoid", "Kanye West", 277);
    Musica* m5 = musica_criar("All Falls Down", "Kanye West", 223);
    Musica* m6 = musica_criar("Stronger", "Kanye West", 312);
    Musica* m7 = musica_criar("Last Call", "Kanye West", 760);
    Musica* m8 = musica_criar("Ghost Town", "Kanye West", 271);
    Musica* m9 = musica_criar("Good Life", "Kanye West", 207);
    Musica* m10 = musica_criar("I Wonder", "Kanye West", 243);

    adiciona_musica(playlist, m1);
    adiciona_musica(playlist, m2);
    adiciona_musica(playlist, m3);
    adiciona_musica(playlist, m4);
    adiciona_musica(playlist, m5);
    adiciona_musica(playlist, m6);
    adiciona_musica(playlist, m7);
    adiciona_musica(playlist, m8);
    adiciona_musica(playlist, m9);
    adiciona_musica(playlist, m10);

    printf("Quantidade inicial: %d\n", lista_quantidade(playlist));

    printf("Tempo restante: %d segundos\n",
           tempo_restante(playlist, proxima));

    play(playlist, &proxima);
    play(playlist, &proxima);
    play(playlist, &proxima);

    printf("\nMusicas reproduzidas: %d\n",
           musicas_reproduzidas(proxima));

    printf("Tempo restante: %d segundos\n",
           tempo_restante(playlist, proxima));

    Musica* nova = musica_criar(
        "Devil in a New Dress",
        "Kanye West",
        352
    );

    adiciona_musica_posicao(playlist, nova, 4);

    remove_musica(playlist, 7);

    printf("\nQuantidade de musicas presentes na playlist: %d\n",
           lista_quantidade(playlist));

    if (proxima < lista_quantidade(playlist)) {
        printf("Posicao da proxima musica a ser reproduzida: %d\n",
               proxima + 1);
    } else {
        printf("Nao ha proxima musica a ser reproduzida.\n");
    }

    lista_destruir(playlist);

    return 0;
}