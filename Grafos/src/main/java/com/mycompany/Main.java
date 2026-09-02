package com.mycompany;

import java.util.Map;
import com.mycompany.grafo.*;
import com.mycompany.busca.*;

public class Main {

    public static void main(String[] args) {

        testarGrafoNaoDirigido();
        testarGrafoDirigido();

        testarBuscasNaoDirigido();
        testarBuscasDirigido();
    }

    // =========================================================
    // ATIVIDADE 01 - GRAFO NÃO DIRIGIDO
    // =========================================================

    private static void testarGrafoNaoDirigido() {

        System.out.println("========================================");
        System.out.println("       TESTE - GRAFO NAO DIRIGIDO");
        System.out.println("========================================");

        GrafoNaoDirigido grafo = new GrafoNaoDirigido();

        Vertice v1 = grafo.insereV();
        Vertice v2 = grafo.insereV();
        Vertice v3 = grafo.insereV();
        Vertice v4 = grafo.insereV();

        System.out.println("\n--- insereV() ---");
        System.out.println("Vértices criados:");
        System.out.println(v1);
        System.out.println(v2);
        System.out.println(v3);
        System.out.println(v4);

        System.out.println("\n--- getOrdem() ---");
        System.out.println("Ordem do grafo: " + grafo.getOrdem());

        System.out.println("\n--- insereA() ---");

        Aresta a1 = grafo.insereA(v1, v2);
        Aresta a2 = grafo.insereA(v1, v3);
        Aresta a3 = grafo.insereA(v2, v4);
        Aresta a4 = grafo.insereA(v3, v4);

        System.out.println("Aresta 1: " + a1);
        System.out.println("Aresta 2: " + a2);
        System.out.println("Aresta 3: " + a3);
        System.out.println("Aresta 4: " + a4);

        System.out.println("\n--- getTamanho() ---");
        System.out.println("Tamanho do grafo: " + grafo.getTamanho());

        System.out.println("\n--- vertices() ---");
        System.out.println("Vértices:");

        for (Vertice v : grafo.vertices()) {
            System.out.println("  " + v);
        }

        System.out.println("\n--- arestas() ---");
        System.out.println("Arestas:");

        for (Aresta e : grafo.arestas()) {
            System.out.println("  " + e);
        }

        System.out.println("\n--- adj() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Adjacentes de " + v + ": " + grafo.adj(v)
            );
        }

        System.out.println("\n--- getA() ---");

        System.out.println(
                "Aresta entre v1 e v2: "
                        + grafo.getA(v1, v2)
        );

        System.out.println(
                "Aresta entre v2 e v1: "
                        + grafo.getA(v2, v1)
        );

        System.out.println(
                "Aresta entre v1 e v4: "
                        + grafo.getA(v1, v4)
        );

        System.out.println("\n--- verticesA() ---");

        System.out.println(
                "Vértices de a1: "
                        + grafo.verticesA(a1)
        );

        System.out.println("\n--- oposto() ---");

        System.out.println(
                "Oposto de v1 em a1: "
                        + grafo.oposto(v1, a1)
        );

        System.out.println(
                "Oposto de v2 em a1: "
                        + grafo.oposto(v2, a1)
        );

        System.out.println("\n--- grau() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau de " + v + ": "
                            + grafo.grau(v)
            );
        }

        System.out.println("\n--- grauE() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau de entrada de " + v + ": "
                            + grafo.grauE(v)
            );
        }

        System.out.println("\n--- grauS() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau de saída de " + v + ": "
                            + grafo.grauS(v)
            );
        }

        System.out.println("\n--- arestasE() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Arestas de entrada de " + v + ": "
                            + grafo.arestasE(v)
            );
        }

        System.out.println("\n--- arestasS() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Arestas de saída de " + v + ": "
                            + grafo.arestasS(v)
            );
        }

        System.out.println("\n--- toString() ---");
        System.out.println(grafo);

        System.out.println("\n--- removeA() ---");

        System.out.println("Removendo a aresta a1: " + a1);

        grafo.removeA(a1);

        System.out.println(
                "Tamanho após remoção: "
                        + grafo.getTamanho()
        );

        System.out.println("Grafo após remover a1:");
        System.out.println(grafo);

        System.out.println("\n--- removeV() ---");

        System.out.println("Removendo o vértice v4: " + v4);

        grafo.removeV(v4);

        System.out.println(
                "Ordem após remoção: "
                        + grafo.getOrdem()
        );

        System.out.println(
                "Tamanho após remoção: "
                        + grafo.getTamanho()
        );

        System.out.println("Grafo após remover v4:");
        System.out.println(grafo);
    }


    // =========================================================
    // ATIVIDADE 01 - GRAFO DIRIGIDO
    // =========================================================

    private static void testarGrafoDirigido() {

        System.out.println("\n\n========================================");
        System.out.println("          TESTE - GRAFO DIRIGIDO");
        System.out.println("========================================");

        GrafoDirigido grafo = new GrafoDirigido();

        Vertice v1 = grafo.insereV();
        Vertice v2 = grafo.insereV();
        Vertice v3 = grafo.insereV();
        Vertice v4 = grafo.insereV();

        System.out.println("\n--- insereV() ---");
        System.out.println("Vértices criados:");
        System.out.println(v1);
        System.out.println(v2);
        System.out.println(v3);
        System.out.println(v4);

        System.out.println("\n--- getOrdem() ---");
        System.out.println("Ordem do grafo: " + grafo.getOrdem());

        System.out.println("\n--- insereA() ---");

        Aresta a1 = grafo.insereA(v1, v2);
        Aresta a2 = grafo.insereA(v1, v3);
        Aresta a3 = grafo.insereA(v2, v4);
        Aresta a4 = grafo.insereA(v3, v4);
        Aresta a5 = grafo.insereA(v4, v1);

        System.out.println("Aresta 1: " + a1);
        System.out.println("Aresta 2: " + a2);
        System.out.println("Aresta 3: " + a3);
        System.out.println("Aresta 4: " + a4);
        System.out.println("Aresta 5: " + a5);

        System.out.println("\n--- getTamanho() ---");
        System.out.println("Tamanho do grafo: " + grafo.getTamanho());

        System.out.println("\n--- vertices() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println("  " + v);
        }

        System.out.println("\n--- arestas() ---");

        for (Aresta e : grafo.arestas()) {
            System.out.println("  " + e);
        }

        System.out.println("\n--- adj() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Adjacentes de " + v + ": "
                            + grafo.adj(v)
            );
        }

        System.out.println("\n--- getA() ---");

        System.out.println(
                "Aresta de v1 para v2: "
                        + grafo.getA(v1, v2)
        );

        System.out.println(
                "Aresta de v2 para v1: "
                        + grafo.getA(v2, v1)
        );

        System.out.println(
                "Aresta de v1 para v4: "
                        + grafo.getA(v1, v4)
        );

        System.out.println("\n--- verticesA() ---");

        System.out.println(
                "Vértices de a1: "
                        + grafo.verticesA(a1)
        );

        System.out.println("\n--- oposto() ---");

        System.out.println(
                "Oposto de v1 em a1: "
                        + grafo.oposto(v1, a1)
        );

        System.out.println(
                "Oposto de v2 em a1: "
                        + grafo.oposto(v2, a1)
        );

        System.out.println("\n--- grauE() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau de entrada de " + v + ": "
                            + grafo.grauE(v)
            );
        }

        System.out.println("\n--- grauS() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau de saída de " + v + ": "
                            + grafo.grauS(v)
            );
        }

        System.out.println("\n--- grau() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau total de " + v + ": "
                            + grafo.grau(v)
            );
        }

        System.out.println("\n--- arestasE() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Arestas de entrada de " + v + ": "
                            + grafo.arestasE(v)
            );
        }

        System.out.println("\n--- arestasS() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Arestas de saída de " + v + ": "
                            + grafo.arestasS(v)
            );
        }

        System.out.println("\n--- toString() ---");
        System.out.println(grafo);

        System.out.println("\n--- removeA() ---");

        System.out.println("Removendo a aresta a1: " + a1);

        grafo.removeA(a1);

        System.out.println(
                "Tamanho após remoção: "
                        + grafo.getTamanho()
        );

        System.out.println("Grafo após remover a1:");
        System.out.println(grafo);

        System.out.println("\n--- removeV() ---");

        System.out.println("Removendo o vértice v4: " + v4);

        grafo.removeV(v4);

        System.out.println(
                "Ordem após remoção: "
                        + grafo.getOrdem()
        );

        System.out.println(
                "Tamanho após remoção: "
                        + grafo.getTamanho()
        );

        System.out.println("Grafo após remover v4:");
        System.out.println(grafo);
    }


    // =========================================================
    // ATIVIDADE 02 - BUSCAS NO GRAFO NÃO DIRIGIDO
    // =========================================================

    private static void testarBuscasNaoDirigido() {

        System.out.println("\n\n========================================");
        System.out.println("      BUSCAS - GRAFO NAO DIRIGIDO");
        System.out.println("========================================");

        GrafoNaoDirigido grafo = new GrafoNaoDirigido();

        Vertice v1 = grafo.insereV();
        Vertice v2 = grafo.insereV();
        Vertice v3 = grafo.insereV();
        Vertice v4 = grafo.insereV();
        Vertice v5 = grafo.insereV();
        Vertice v6 = grafo.insereV();

        grafo.insereA(v1, v2);
        grafo.insereA(v1, v3);
        grafo.insereA(v2, v4);
        grafo.insereA(v3, v4);
        grafo.insereA(v3, v5);
        grafo.insereA(v4, v6);
        grafo.insereA(v5, v6);

        System.out.println("\nGrafo:");
        System.out.println(grafo);

        System.out.println("--- BUSCA EM LARGURA ---");

        Map<Vertice, InfoVertice> bfs =
                Busca.buscaEmLargura(grafo, v1);

        Busca.imprimeBFS(grafo, bfs);

        System.out.println("\nCaminho de " + v1 + " até " + v6 + ":");
        Busca.imprimeCaminho(v1, v6, bfs);

        System.out.println("\nCaminho de " + v1 + " até " + v5 + ":");
        Busca.imprimeCaminho(v1, v5, bfs);

        System.out.println("\n--- BUSCA EM PROFUNDIDADE ---");

        Map<Vertice, InfoVertice> dfs =
                Busca.buscaEmProfundidade(grafo, v1);

        Busca.imprimeDFS(grafo, dfs);

        System.out.println("\nCaminho de " + v1 + " até " + v6 + ":");
        Busca.imprimeCaminho(v1, v6, dfs);

        System.out.println("\nCaminho de " + v1 + " até " + v5 + ":");
        Busca.imprimeCaminho(v1, v5, dfs);
    }


    // =========================================================
    // ATIVIDADE 02 - BUSCAS NO GRAFO DIRIGIDO
    // =========================================================

    private static void testarBuscasDirigido() {

        System.out.println("\n\n========================================");
        System.out.println("         BUSCAS - GRAFO DIRIGIDO");
        System.out.println("========================================");

        GrafoDirigido grafo = new GrafoDirigido();

        Vertice v1 = grafo.insereV();
        Vertice v2 = grafo.insereV();
        Vertice v3 = grafo.insereV();
        Vertice v4 = grafo.insereV();
        Vertice v5 = grafo.insereV();
        Vertice v6 = grafo.insereV();

        grafo.insereA(v1, v2);
        grafo.insereA(v1, v3);
        grafo.insereA(v2, v4);
        grafo.insereA(v3, v4);
        grafo.insereA(v3, v5);
        grafo.insereA(v4, v6);
        grafo.insereA(v5, v6);
        grafo.insereA(v6, v1);

        System.out.println("\nGrafo:");
        System.out.println(grafo);

        System.out.println("--- BUSCA EM LARGURA ---");

        Map<Vertice, InfoVertice> bfs =
                Busca.buscaEmLargura(grafo, v1);

        Busca.imprimeBFS(grafo, bfs);

        System.out.println("\nCaminho de " + v1 + " até " + v6 + ":");
        Busca.imprimeCaminho(v1, v6, bfs);

        System.out.println("\nCaminho de " + v1 + " até " + v5 + ":");
        Busca.imprimeCaminho(v1, v5, bfs);

        System.out.println("\n--- BUSCA EM PROFUNDIDADE ---");

        Map<Vertice, InfoVertice> dfs =
                Busca.buscaEmProfundidade(grafo, v1);

        Busca.imprimeDFS(grafo, dfs);

        System.out.println("\nCaminho de " + v1 + " até " + v6 + ":");
        Busca.imprimeCaminho(v1, v6, dfs);

        System.out.println("\nCaminho de " + v1 + " até " + v5 + ":");
        Busca.imprimeCaminho(v1, v5, dfs);
    }
}