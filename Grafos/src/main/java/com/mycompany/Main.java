package com.mycompany;

import java.util.Collection;

public class Main {

    public static void main(String[] args) {

        testarGrafoNaoDirigido();
        testarGrafoDirigido();
    }

    // =========================================================
    // GRAFO NÃO DIRIGIDO
    // =========================================================

    private static void testarGrafoNaoDirigido() {

        System.out.println("========================================");
        System.out.println("       TESTE - GRAFO NAO DIRIGIDO");
        System.out.println("========================================");

        GrafoNaoDirigido grafo = new GrafoNaoDirigido();

        // -----------------------------------------------------
        // 1. insereV()
        // -----------------------------------------------------

        System.out.println("\n--- insereV() ---");

        Vertice v1 = grafo.insereV();
        Vertice v2 = grafo.insereV();
        Vertice v3 = grafo.insereV();
        Vertice v4 = grafo.insereV();

        System.out.println("Vértices criados:");
        System.out.println(v1);
        System.out.println(v2);
        System.out.println(v3);
        System.out.println(v4);

        // -----------------------------------------------------
        // 2. getOrdem()
        // -----------------------------------------------------

        System.out.println("\n--- getOrdem() ---");
        System.out.println("Ordem do grafo: " + grafo.getOrdem());

        // -----------------------------------------------------
        // 3. insereA()
        // -----------------------------------------------------

        System.out.println("\n--- insereA() ---");

        Aresta a1 = grafo.insereA(v1, v2);
        Aresta a2 = grafo.insereA(v1, v3);
        Aresta a3 = grafo.insereA(v2, v4);
        Aresta a4 = grafo.insereA(v3, v4);

        System.out.println("Aresta 1: " + a1);
        System.out.println("Aresta 2: " + a2);
        System.out.println("Aresta 3: " + a3);
        System.out.println("Aresta 4: " + a4);

        // -----------------------------------------------------
        // 4. getTamanho()
        // -----------------------------------------------------

        System.out.println("\n--- getTamanho() ---");
        System.out.println("Tamanho do grafo: " + grafo.getTamanho());

        // -----------------------------------------------------
        // 5. vertices()
        // -----------------------------------------------------

        System.out.println("\n--- vertices() ---");
        System.out.println("Vértices:");

        for (Vertice v : grafo.vertices()) {
            System.out.println("  " + v);
        }

        // -----------------------------------------------------
        // 6. arestas()
        // -----------------------------------------------------

        System.out.println("\n--- arestas() ---");
        System.out.println("Arestas:");

        for (Aresta e : grafo.arestas()) {
            System.out.println("  " + e);
        }

        // -----------------------------------------------------
        // 7. adj()
        // -----------------------------------------------------

        System.out.println("\n--- adj() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Adjacentes de " + v + ": " + grafo.adj(v)
            );
        }

        // -----------------------------------------------------
        // 8. getA()
        // -----------------------------------------------------

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

        // -----------------------------------------------------
        // 9. verticesA()
        // -----------------------------------------------------

        System.out.println("\n--- verticesA() ---");

        System.out.println(
                "Vértices de a1: "
                        + grafo.verticesA(a1)
        );

        // -----------------------------------------------------
        // 10. oposto()
        // -----------------------------------------------------

        System.out.println("\n--- oposto() ---");

        System.out.println(
                "Oposto de v1 em a1: "
                        + grafo.oposto(v1, a1)
        );

        System.out.println(
                "Oposto de v2 em a1: "
                        + grafo.oposto(v2, a1)
        );

        // -----------------------------------------------------
        // 11. grau()
        // -----------------------------------------------------

        System.out.println("\n--- grau() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau de " + v + ": "
                            + grafo.grau(v)
            );
        }

        // -----------------------------------------------------
        // 12. grauE()
        // -----------------------------------------------------

        System.out.println("\n--- grauE() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau de entrada de " + v + ": "
                            + grafo.grauE(v)
            );
        }

        // -----------------------------------------------------
        // 13. grauS()
        // -----------------------------------------------------

        System.out.println("\n--- grauS() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau de saída de " + v + ": "
                            + grafo.grauS(v)
            );
        }

        // -----------------------------------------------------
        // 14. arestasE()
        // -----------------------------------------------------

        System.out.println("\n--- arestasE() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Arestas de entrada de " + v + ": "
                            + grafo.arestasE(v)
            );
        }

        // -----------------------------------------------------
        // 15. arestasS()
        // -----------------------------------------------------

        System.out.println("\n--- arestasS() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Arestas de saída de " + v + ": "
                            + grafo.arestasS(v)
            );
        }

        // -----------------------------------------------------
        // 16. toString()
        // -----------------------------------------------------

        System.out.println("\n--- toString() ---");
        System.out.println(grafo);

        // -----------------------------------------------------
        // 17. removeA()
        // -----------------------------------------------------

        System.out.println("\n--- removeA() ---");

        System.out.println("Removendo a aresta a1: " + a1);

        grafo.removeA(a1);

        System.out.println(
                "Tamanho após remoção: "
                        + grafo.getTamanho()
        );

        System.out.println("Grafo após remover a1:");
        System.out.println(grafo);

        // -----------------------------------------------------
        // 18. removeV()
        // -----------------------------------------------------

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
    // GRAFO DIRIGIDO
    // =========================================================

    private static void testarGrafoDirigido() {

        System.out.println("\n\n========================================");
        System.out.println("          TESTE - GRAFO DIRIGIDO");
        System.out.println("========================================");

        GrafoDirigido grafo = new GrafoDirigido();

        // -----------------------------------------------------
        // 1. insereV()
        // -----------------------------------------------------

        System.out.println("\n--- insereV() ---");

        Vertice v1 = grafo.insereV();
        Vertice v2 = grafo.insereV();
        Vertice v3 = grafo.insereV();
        Vertice v4 = grafo.insereV();

        System.out.println("Vértices criados:");
        System.out.println(v1);
        System.out.println(v2);
        System.out.println(v3);
        System.out.println(v4);

        // -----------------------------------------------------
        // 2. getOrdem()
        // -----------------------------------------------------

        System.out.println("\n--- getOrdem() ---");
        System.out.println(
                "Ordem do grafo: "
                        + grafo.getOrdem()
        );

        // -----------------------------------------------------
        // 3. insereA()
        // -----------------------------------------------------

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

        // -----------------------------------------------------
        // 4. getTamanho()
        // -----------------------------------------------------

        System.out.println("\n--- getTamanho() ---");
        System.out.println(
                "Tamanho do grafo: "
                        + grafo.getTamanho()
        );

        // -----------------------------------------------------
        // 5. vertices()
        // -----------------------------------------------------

        System.out.println("\n--- vertices() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println("  " + v);
        }

        // -----------------------------------------------------
        // 6. arestas()
        // -----------------------------------------------------

        System.out.println("\n--- arestas() ---");

        for (Aresta e : grafo.arestas()) {
            System.out.println("  " + e);
        }

        // -----------------------------------------------------
        // 7. adj()
        // -----------------------------------------------------

        System.out.println("\n--- adj() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Adjacentes de " + v + ": "
                            + grafo.adj(v)
            );
        }

        // -----------------------------------------------------
        // 8. getA()
        // -----------------------------------------------------

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

        // -----------------------------------------------------
        // 9. verticesA()
        // -----------------------------------------------------

        System.out.println("\n--- verticesA() ---");

        System.out.println(
                "Vértices de a1: "
                        + grafo.verticesA(a1)
        );

        // -----------------------------------------------------
        // 10. oposto()
        // -----------------------------------------------------

        System.out.println("\n--- oposto() ---");

        System.out.println(
                "Oposto de v1 em a1: "
                        + grafo.oposto(v1, a1)
        );

        System.out.println(
                "Oposto de v2 em a1: "
                        + grafo.oposto(v2, a1)
        );

        // -----------------------------------------------------
        // 11. grauE()
        // -----------------------------------------------------

        System.out.println("\n--- grauE() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau de entrada de " + v + ": "
                            + grafo.grauE(v)
            );
        }

        // -----------------------------------------------------
        // 12. grauS()
        // -----------------------------------------------------

        System.out.println("\n--- grauS() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau de saída de " + v + ": "
                            + grafo.grauS(v)
            );
        }

        // -----------------------------------------------------
        // 13. grau()
        // -----------------------------------------------------

        System.out.println("\n--- grau() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Grau total de " + v + ": "
                            + grafo.grau(v)
            );
        }

        // -----------------------------------------------------
        // 14. arestasE()
        // -----------------------------------------------------

        System.out.println("\n--- arestasE() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Arestas de entrada de " + v + ": "
                            + grafo.arestasE(v)
            );
        }

        // -----------------------------------------------------
        // 15. arestasS()
        // -----------------------------------------------------

        System.out.println("\n--- arestasS() ---");

        for (Vertice v : grafo.vertices()) {
            System.out.println(
                    "Arestas de saída de " + v + ": "
                            + grafo.arestasS(v)
            );
        }

        // -----------------------------------------------------
        // 16. toString()
        // -----------------------------------------------------

        System.out.println("\n--- toString() ---");
        System.out.println(grafo);

        // -----------------------------------------------------
        // 17. removeA()
        // -----------------------------------------------------

        System.out.println("\n--- removeA() ---");

        System.out.println("Removendo a aresta a1: " + a1);

        grafo.removeA(a1);

        System.out.println(
                "Tamanho após remoção: "
                        + grafo.getTamanho()
        );

        System.out.println("Grafo após remover a1:");
        System.out.println(grafo);

        // -----------------------------------------------------
        // 18. removeV()
        // -----------------------------------------------------

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
}