package com.mycompany.grafo;

import java.util.*;

public class GrafoNaoDirigido extends Grafo {

    @Override
    protected void adicionarAdjacencia(
            Vertice u,
            Vertice v,
            Aresta e) {

        adjacencias.get(u).put(v, e);
        adjacencias.get(v).put(u, e);
    }

    @Override
    protected void removerAdjacencia(
            Vertice u,
            Vertice v,
            Aresta e) {

        adjacencias.get(u).remove(v);
        adjacencias.get(v).remove(u);
    }

    @Override
    public Aresta insereA(Vertice u, Vertice v) {

        verificarVertice(u);
        verificarVertice(v);

        // Grafo não dirigido simples não permite laço.
        if (u.equals(v)) {
            throw new IllegalArgumentException(
                    "Não é permitido criar uma aresta de um vértice para ele mesmo."
            );
        }

        return super.insereA(u, v);
    }

    @Override
    public int grau(Vertice v) {
        return adj(v).size();
    }

    @Override
    public int grauE(Vertice v) {
        return grau(v);
    }

    @Override
    public int grauS(Vertice v) {
        return grau(v);
    }

    @Override
    public Collection<Aresta> arestasE(Vertice v) {

        verificarVertice(v);

        return Collections.unmodifiableCollection(
                adjacencias.get(v).values()
        );
    }

    @Override
    public Collection<Aresta> arestasS(Vertice v) {

        verificarVertice(v);

        return Collections.unmodifiableCollection(
                adjacencias.get(v).values()
        );
    }
}