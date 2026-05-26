#include "arvoreNaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -Iinclude src/arvoreNaria.c main.c -o campis.out && ./campis.out
int main(void){
    /*
        IFC
        ├── Campus Blumenau
        │   ├── BCC
        │   │   ├── Estruturas de Dados I
        │   │   ├── Programacao II
        │   │   └── Banco de Dados
        │   └── Biblioteca
        │
        ├── Campus Camboriu
        │   ├── Pedagogia
        │   └── Coordenacao de Ensino
        │
        └── Campus Araquari
            └── Administracao
    */

    ArvoreNaria *a1 = an_cria();
    ArvoreNaria *a2 = an_cria();

    NoArvoreNaria *ifc = an_cria_no("IFC");
    NoArvoreNaria *ifsc = an_cria_no("IFSC");

    NoArvoreNaria *blumenau = an_cria_no("Campus Blumenau");
    NoArvoreNaria *camboriu = an_cria_no("Campus Camboriu");
    NoArvoreNaria *araquari = an_cria_no("Campus Araquari");

    NoArvoreNaria *bcc = an_cria_no("BCC");
    NoArvoreNaria *pedagogia = an_cria_no("Pedagogia");
    NoArvoreNaria *administracao = an_cria_no("Administracao");
    NoArvoreNaria *biblioteca = an_cria_no("Biblioteca");
    NoArvoreNaria *coord = an_cria_no("Coordenacao de Ensino");

    NoArvoreNaria *ed1 = an_cria_no("Estruturas de Dados I");
    NoArvoreNaria *prog2 = an_cria_no("Programacao II");
    NoArvoreNaria *bd = an_cria_no("Banco de Dados");

    an_define_raiz(a1, ifc);
    an_define_raiz(a2, ifsc);

    an_insere_filho(ifc, araquari);
    an_insere_filho(ifc, camboriu);
    an_insere_filho(ifc, blumenau);

    an_insere_filho(blumenau, biblioteca);
    an_insere_filho(blumenau, bcc);

    an_insere_filho(bcc, bd);
    an_insere_filho(bcc, prog2);
    an_insere_filho(bcc, ed1);

    an_insere_filho(camboriu, coord);
    an_insere_filho(camboriu, pedagogia);

    an_insere_filho(araquari, administracao);

    printf("Arvore:\n");
    an_imprime(a1);

    printf("\nNumero total de nos: %d\n", an_num_nos(a1));

    printf("Quantidade de folhas: %d\n", an_folhas(a1));

    printf("Altura da arvore: %d\n", an_altura(a1));

    printf("\nBCC pertence? %d\n", an_pertence(a1, "BCC"));

    printf("Matematica pertence? %d\n", an_pertence(a1, "Matematica"));

    printf("IFC é igual a IFSC? %d\n", an_igual(a1, a2));

    an_libera(a1);

    printf("A árvore está vazia? %d\n", an_vazia(a1));

    return 0;
}