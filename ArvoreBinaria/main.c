#include "arvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -Iinclude src/arvoreBinaria.c main.c -o campeonato.o && ./campeonato.o
int main(){
    ArvoreBinaria *campeonato = ab_cria();
    
    NoArvoreBinaria *brasil = ab_cria_no("Brasil", NULL, NULL);
    NoArvoreBinaria *argentina = ab_cria_no("Argentina", NULL, NULL);
    NoArvoreBinaria *alemanha = ab_cria_no("Alemanha", NULL, NULL);
    NoArvoreBinaria *franca = ab_cria_no("França", NULL, NULL);
    
    NoArvoreBinaria *semifinal1 = ab_cria_no("Semifinal 1", brasil, argentina);
    NoArvoreBinaria *semifinal2 = ab_cria_no("Semifinal 2", alemanha, franca);

    NoArvoreBinaria *final = ab_cria_no("Final", semifinal1, semifinal2);
    
    ab_define_raiz(campeonato, final);
    
    printf("Pré-ordem:\n");
    ab_imprime_pre(campeonato);

    printf("Ordem simétrica:\n");
    ab_imprime_sim(campeonato);

    printf("Pos-ordem:\n");
    ab_imprime_pos(campeonato);

    printf("Quantidade de folhas: %d\n", ab_num_folhas(campeonato));
    printf("Quantidade de nós: %d\n", ab_num_nos(campeonato));

    printf("Altura da árvore %d\n", ab_altura(campeonato));

    printf("A seleção brasileira pertence ao chaveamento do campeonato? %d\n", ab_pertence(campeonato, "Brasil"));
    printf("A seleção belga pertence ao chaveamento do campeonato? %d\n", ab_pertence(campeonato, "Bélgica"));

    ArvoreBinaria *campeonato2 = ab_cria();
    NoArvoreBinaria *final2 = ab_cria_no("Final", franca, alemanha);
    ab_define_raiz(campeonato2, final2);

    printf("Pré-ordem:\n");
    ab_imprime_pre(campeonato2);
    printf("Os dois campeonatos são iguais? %d\n", ab_igual(campeonato, campeonato2));
    return 0;
}