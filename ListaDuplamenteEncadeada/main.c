#include "listaDupla.h"
#include <stdio.h>

// gcc -Iinclude main.c src/listaDupla.c -o playlist.out && ./playlist.out
int main(){
    printf("Criando playlist com 6 músicas padrões: \n");

    NoListaDupla *playlist = dllCria();
    playlist = dllInsere(playlist, "Welcome to the Jungle");
    playlist = dllInsereFim(playlist, "Thunderstruck");
    playlist = dllInsereFim(playlist, "Imagine");
    playlist = dllInsereFim(playlist, "Beautiful Boy");
    playlist = dllInsereFim(playlist, "Highway to Hell");
    playlist = dllInsereFim(playlist, "Back in Black");
    dllImprime(playlist);

    printf("\n");

    printf("Inserindo música \"Crazy Train\" na 3º posição da playlist: \n");
    playlist = dllInserePosicao(playlist, "Crazy Train", 3);
    dllImprime(playlist);

    printf("\n");

    printf("Inserindo música \"Paranoid\" na 1º posição da playlist: \n");
    playlist = dllInserePosicao(playlist, "Paranoid", 1);
    dllImprime(playlist);

    printf("\n");

    printf("Tentando inserir música \"No More Tears\" na 9º posição da playlist: \n");
    playlist = dllInserePosicao(playlist, "No More Tears", 9);
    dllImprime(playlist);

    printf("\n");

    printf("Inserindo música \"No More Tears\" na 8º posição da playlist: \n");
    playlist = dllInserePosicao(playlist, "No More Tears", 8);
    dllImprime(playlist);

    printf("\n");

    printf("Removendo música \"Imagine\" por título: \n");
    playlist = dllRetira(playlist, "Imagine");
    dllImprime(playlist);

    printf("\n");

    printf("Removendo 1º música por posição: \n");
    playlist = dllRetiraPosicao(playlist, 1);
    dllImprime(playlist);

    printf("\n");

    printf("Removendo 4º música por posição: \n");
    playlist = dllRetiraPosicao(playlist, 4);
    dllImprime(playlist);

    printf("\n");

    printf("Tentando remover 7º música por posição: \n");
    playlist = dllRetiraPosicao(playlist, 7);
    dllImprime(playlist);

    printf("\n");

    printf("Removendo 6º música por posição: \n");
    playlist = dllRetiraPosicao(playlist, 6);
    dllImprime(playlist);

    printf("\n");
    printf("Movendo música \"Welcome to the Jungle\" por título para a 4º posição: \n");
    playlist = dllmove(playlist, "Welcome to the Jungle", 4);
    dllImprime(playlist);

    printf("\n");
    printf("Movendo música 2º posição para a 4º posição: \n");
    playlist = dllmovePosicao(playlist, 2, 4);
    dllImprime(playlist);

    return 0;
}