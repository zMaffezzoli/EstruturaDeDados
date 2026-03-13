#ifndef LISTASIMPLES_H
#define LISTASIMPLES_H

struct noLista {
    int info;
    struct noLista *prox;
};

typedef struct noLista NoLista;
NoLista *sllInsere(NoLista *head, int v);
NoLista *sllInsereFim(NoLista *head, int v);

NoLista *sllCria(void);
int sllVazia(NoLista *head);
NoLista *sllBusca(NoLista *head, int v);
NoLista *sllUltimo(NoLista *head);

void sllImprime(NoLista *head);
void sllImprimeRecursivo(NoLista *head);

int sllComprimento(NoLista *head);
int sllComprimentoRecursivo(NoLista *head);

NoLista *sllRetira(NoLista *head, int v);
NoLista *sllRetiraRecursivo(NoLista *head, int v);

void sllLibera(NoLista *head);
void sllLiberaRecursivo(NoLista *head);

int sllIgual(NoLista *head1, NoLista *head2);
int sllIgualRecursivo(NoLista *head1, NoLista *head2);

#endif