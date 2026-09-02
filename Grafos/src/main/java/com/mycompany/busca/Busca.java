package com.mycompany.busca;
import com.mycompany.grafo.*;

import java.util.*;

public class Busca {

    public static Map<Vertice, InfoVertice> buscaEmLargura(
            Grafo grafo,
            Vertice r) {

        Map<Vertice, InfoVertice> info = new HashMap<>();

        for (Vertice v : grafo.vertices()) {
            info.put(v, new InfoVertice());
        }

        if (!info.containsKey(r)) {
            throw new IllegalArgumentException(
                    "Vértice não pertence ao grafo."
            );
        }

        InfoVertice infoR = info.get(r);

        infoR.setDistancia(0);
        infoR.setEstado(EstadoVertice.VISITADO);

        Queue<Vertice> fila = new LinkedList<>();
        fila.add(r);

        while (!fila.isEmpty()) {

            Vertice vi = fila.remove();

            for (Vertice vj : grafo.adj(vi)) {

                InfoVertice infoVj = info.get(vj);

                if (infoVj.getEstado() == EstadoVertice.NAO_VISITADO) {

                    fila.add(vj);

                    infoVj.setEstado(EstadoVertice.VISITADO);
                    infoVj.setPredecessor(vi);
                    infoVj.setDistancia(
                            info.get(vi).getDistancia() + 1
                    );
                }
            }

            info.get(vi).setEstado(EstadoVertice.ENCERRADO);
        }

        return info;
    }

    public static Map<Vertice, InfoVertice> buscaEmProfundidade(
            Grafo grafo,
            Vertice r) {

        Map<Vertice, InfoVertice> info = new HashMap<>();

        for (Vertice v : grafo.vertices()) {
            info.put(v, new InfoVertice());
        }

        if (!info.containsKey(r)) {
            throw new IllegalArgumentException(
                    "Vértice não pertence ao grafo."
            );
        }

        int[] tempo = {0};

        visitaVertice(grafo, r, info, tempo);

        return info;
    }

    private static void visitaVertice(
            Grafo grafo,
            Vertice vi,
            Map<Vertice, InfoVertice> info,
            int[] tempo) {

        InfoVertice infoVi = info.get(vi);

        infoVi.setEstado(EstadoVertice.VISITADO);

        tempo[0]++;
        infoVi.setTempoAbertura(tempo[0]);

        for (Vertice vj : grafo.adj(vi)) {

            InfoVertice infoVj = info.get(vj);

            if (infoVj.getEstado() == EstadoVertice.NAO_VISITADO) {

                infoVj.setPredecessor(vi);

                visitaVertice(grafo, vj, info, tempo);
            }
        }

        infoVi.setEstado(EstadoVertice.ENCERRADO);

        tempo[0]++;
        infoVi.setTempoEncerramento(tempo[0]);
    }

    public static List<Vertice> caminho(
            Vertice origem,
            Vertice destino,
            Map<Vertice, InfoVertice> info) {

        if (!info.containsKey(origem) || !info.containsKey(destino)) {
            throw new IllegalArgumentException(
                    "Vértice não pertence à busca."
            );
        }

        LinkedList<Vertice> caminho = new LinkedList<>();

        Vertice atual = destino;

        while (atual != null) {

            caminho.addFirst(atual);

            if (atual.equals(origem)) {
                return caminho;
            }

            atual = info.get(atual).getPredecessor();
        }

        return Collections.emptyList();
    }

    public static void imprimeCaminho(
            Vertice origem,
            Vertice destino,
            Map<Vertice, InfoVertice> info) {

        List<Vertice> caminho = caminho(origem, destino, info);

        if (caminho.isEmpty()) {
            System.out.println(
                    "Não existe caminho entre "
                            + origem + " e " + destino + "."
            );
            return;
        }

        for (int i = 0; i < caminho.size(); i++) {

            System.out.print(caminho.get(i));

            if (i < caminho.size() - 1) {
                System.out.print(" -> ");
            }
        }

        System.out.println();
    }

    public static void imprimeBFS(
            Grafo grafo,
            Map<Vertice, InfoVertice> info) {

        System.out.printf(
                "%-10s %-15s %-15s%n",
                "Vértice",
                "Distância",
                "Predecessor"
        );

        for (Vertice v : grafo.vertices()) {

            InfoVertice i = info.get(v);

            String predecessor = i.getPredecessor() == null
                    ? "nil"
                    : i.getPredecessor().toString();

            String distancia = i.getDistancia() == Integer.MAX_VALUE
                    ? "infinito"
                    : String.valueOf(i.getDistancia());

            System.out.printf(
                    "%-10s %-15s %-15s%n",
                    v,
                    distancia,
                    predecessor
            );
        }
    }

    public static void imprimeDFS(
            Grafo grafo,
            Map<Vertice, InfoVertice> info) {

        System.out.printf(
                "%-10s %-15s %-15s %-15s%n",
                "Vértice",
                "Predecessor",
                "Abertura",
                "Encerramento"
        );

        for (Vertice v : grafo.vertices()) {

            InfoVertice i = info.get(v);

            String predecessor = i.getPredecessor() == null
                    ? "nil"
                    : i.getPredecessor().toString();

            System.out.printf(
                    "%-10s %-15s %-15d %-15d%n",
                    v,
                    predecessor,
                    i.getTempoAbertura(),
                    i.getTempoEncerramento()
            );
        }
    }
}