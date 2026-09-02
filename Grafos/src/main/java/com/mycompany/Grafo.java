package com.mycompany;

import java.util.*;

public abstract class Grafo {

    protected Map<Integer, Vertice> vertices;
    protected Map<Vertice, Map<Vertice, Aresta>> adjacencias;
    protected Set<Aresta> arestas;

    public Grafo() {
        vertices = new HashMap<>();
        adjacencias = new HashMap<>();
        arestas = new HashSet<>();
    }

    public int getOrdem() {
        return vertices.size();
    }

    public int getTamanho() {
        return arestas.size();
    }

    public Collection<Vertice> vertices() {
        return Collections.unmodifiableCollection(vertices.values());
    }

    public Collection<Aresta> arestas() {
        return Collections.unmodifiableCollection(arestas);
    }

    public Vertice insereV() {
        Vertice v = new Vertice();

        vertices.put(v.getId(), v);
        adjacencias.put(v, new HashMap<>());

        return v;
    }

    public void removeV(Vertice v) {

        verificarVertice(v);

        Set<Aresta> incidentes = new HashSet<>();

        for (Aresta e : arestas) {
            if (e.getU().equals(v) || e.getV().equals(v)) {
                incidentes.add(e);
            }
        }

        for (Aresta e : incidentes) {
            removeA(e);
        }

        adjacencias.remove(v);
        vertices.remove(v.getId());
    }

    public Aresta insereA(Vertice u, Vertice v) {

        verificarVertice(u);
        verificarVertice(v);

        if (getA(u, v) != null) {
            throw new IllegalArgumentException(
                    "Já existe uma aresta entre esses vértices."
            );
        }

        Aresta e = new Aresta(u, v);

        arestas.add(e);

        adicionarAdjacencia(u, v, e);

        return e;
    }

    public void removeA(Aresta e) {

        verificarAresta(e);

        Vertice u = e.getU();
        Vertice v = e.getV();

        removerAdjacencia(u, v, e);

        arestas.remove(e);
    }

    public Collection<Vertice> adj(Vertice v) {

        verificarVertice(v);

        return Collections.unmodifiableCollection(
                adjacencias.get(v).keySet()
        );
    }

    public Aresta getA(Vertice u, Vertice v) {

        verificarVertice(u);
        verificarVertice(v);

        return adjacencias.get(u).get(v);
    }

    public abstract int grauE(Vertice v);

    public abstract int grauS(Vertice v);

    public int grau(Vertice v) {
        return grauE(v) + grauS(v);
    }

    public List<Vertice> verticesA(Aresta e) {

        verificarAresta(e);

        return List.of(
                e.getU(),
                e.getV()
        );
    }

    public Vertice oposto(Vertice v, Aresta e) {

        verificarVertice(v);
        verificarAresta(e);

        if (e.getU().equals(v)) {
            return e.getV();
        }

        if (e.getV().equals(v)) {
            return e.getU();
        }

        throw new IllegalArgumentException(
                "O vértice não é incidente à aresta."
        );
    }

    public abstract Collection<Aresta> arestasE(Vertice v);

    public abstract Collection<Aresta> arestasS(Vertice v);

    @Override
    public String toString() {

        StringBuilder sb = new StringBuilder();

        for (Vertice v : vertices.values()) {

            sb.append(v)
                    .append(" -> ")
                    .append(adjacencias.get(v).keySet())
                    .append("\n");
        }

        return sb.toString();
    }

    protected abstract void adicionarAdjacencia(
            Vertice u,
            Vertice v,
            Aresta e
    );

    protected abstract void removerAdjacencia(
            Vertice u,
            Vertice v,
            Aresta e
    );

    protected void verificarVertice(Vertice v) {

        if (v == null || vertices.get(v.getId()) != v) {
            throw new IllegalArgumentException(
                    "Vértice não pertence ao grafo."
            );
        }
    }

    protected void verificarAresta(Aresta e) {

        if (e == null || !arestas.contains(e)) {
            throw new IllegalArgumentException(
                    "Aresta não pertence ao grafo."
            );
        }
    }
}