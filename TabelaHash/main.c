#include <stdio.h>

#include "tabelaHash.h"

// gcc -Iinclude src/tabelaHash.c main.c -o tabelahash.o && ./tabelahash.o
int main(void){

    TabelaHash *tab = hsh_cria();

    hsh_set(tab,1001, "Ana", "ana@ifc.edu.br", 8.5);

    hsh_set(tab,1128, "Bruno", "bruno@ifc.edu.br", 7.9);

    hsh_set(tab,1255, "Carlos", "carlos@ifc.edu.br", 9.1);

    hsh_set(tab,1382, "Daniela", "daniela@ifc.edu.br", 8.2);

    hsh_set(tab,2002, "Eduardo", "edu@ifc.edu.br", 7.0);

    hsh_set(tab,2129, "Fernanda", "fer@ifc.edu.br", 8.0);

    hsh_set(tab,2256, "Gabriel", "gab@ifc.edu.br", 6.9);

    hsh_set(tab,3003, "Helena", "hel@ifc.edu.br", 9.5);

    hsh_set(tab,3130, "Igor", "igor@ifc.edu.br", 8.7);

    hsh_set(tab,4010, "Joao", "joao@ifc.edu.br", 7.3);

    hsh_set(tab,5020, "Karen", "karen@ifc.edu.br", 8.8);

    hsh_set(tab,6030, "Lucas", "lucas@ifc.edu.br", 6.5);

    hsh_set(tab,7040, "Maria", "maria@ifc.edu.br", 9.2);

    hsh_set(tab,8050, "Nicolas", "nico@ifc.edu.br", 8.1);

    hsh_set(tab,9060, "Olivia", "olivia@ifc.edu.br", 7.8);

    printf("Quantidade: %d\n", hsh_quantidade(tab));

    printf("Colisoes: %d\n", hsh_colisoes(tab));

    printf("Maior lista: %d\n", hsh_maior_lista(tab));

    printf("\n");

    printf("Busca 1001: %s\n", hsh_contem(tab,1001) ? "SIM" : "NAO");

    printf("Busca 5555: %s\n", hsh_contem(tab,5555) ? "SIM" : "NAO");

    printf("\nAtualizando aluno 1001\n\n");

    hsh_set(tab, 1001, "Ana Paula", "anapaula@ifc.edu.br", 9.7
    );

    printf("Removendo 1382\n");
    hsh_remove(tab,1382);

    printf("Removendo 1255\n");
    hsh_remove(tab,1255);

    printf("Tentando remover 9999\n");
    hsh_remove(tab,9999);

    printf("\n");

    hsh_imprime(tab);

    hsh_libera(tab);

    return 0;
}