#ifndef LISTADUPLA_H
#define LISTADUPLA_H

struct NoListaDupla {
    char info[100];
    struct NoListaDupla *ant;
    struct NoListaDupla *prox;
};

typedef struct NoListaDupla NoListaDupla;

NoListaDupla *dllCria(void);
NoListaDupla *dllInsere(NoListaDupla *head, char *v);
void dllImprime(NoListaDupla *head);
int dllVazia(NoListaDupla *head);
NoListaDupla *dllBusca(NoListaDupla *head, char *v);
int dllComprimento(NoListaDupla *head);
NoListaDupla *dllUltimo(NoListaDupla *head);
NoListaDupla *dllRetira(NoListaDupla *head, char *v);
void dllLibera(NoListaDupla *head);
NoListaDupla *dllInsereFim(NoListaDupla *head, char *v);
NoListaDupla *dllInserePosicao(NoListaDupla *head, char *v, int posicao);

#endif