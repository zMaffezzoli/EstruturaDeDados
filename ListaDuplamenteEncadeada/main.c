#include "listaDupla.h"
#include <stdio.h>

// gcc -Iinclude main.c src/listaDupla.c -o playlist.o && ./playlist
void main(){
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
}