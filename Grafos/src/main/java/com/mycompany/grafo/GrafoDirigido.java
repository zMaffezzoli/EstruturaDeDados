package com.mycompany.grafo;

import java.util.*;

public class GrafoDirigido extends Grafo {

    @Override
    protected void adicionarAdjacencia(
            Vertice u,
            Vertice v,
            Aresta e) {

        // Aresta de u para v
        adjacencias.get(u).put(v, e);
    }

    @Override
    protected void removerAdjacencia(
            Vertice u,
            Vertice v,
            Aresta e) {

        adjacencias.get(u).remove(v);
    }

    @Override
    public int grauS(Vertice v) {
        return adj(v).size();
    }

    @Override
    public int grauE(Vertice v) {

        verificarVertice(v);

        int grau = 0;

        for (Vertice u : vertices.values()) {
            if (adjacencias.get(u).containsKey(v)) {
                grau++;
            }
        }

        return grau;
    }

    @Override
    public Collection<Aresta> arestasE(Vertice v) {

        verificarVertice(v);

        Collection<Aresta> resultado = new ArrayList<>();

        for (Vertice u : vertices.values()) {

            Aresta e = adjacencias.get(u).get(v);

            if (e != null) {
                resultado.add(e);
            }
        }

        return resultado;
    }

    @Override
    public Collection<Aresta> arestasS(Vertice v) {

        verificarVertice(v);

        return Collections.unmodifiableCollection(
                adjacencias.get(v).values()
        );
    }
}