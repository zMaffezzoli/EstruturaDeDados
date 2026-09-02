package com.mycompany.busca;
import com.mycompany.grafo.*;

public class InfoVertice {

    private EstadoVertice estado;
    private Vertice predecessor;
    private int distancia;
    private int tempoAbertura;
    private int tempoEncerramento;

    public InfoVertice() {
        estado = EstadoVertice.NAO_VISITADO;
        predecessor = null;
        distancia = Integer.MAX_VALUE;
        tempoAbertura = 0;
        tempoEncerramento = 0;
    }

    public EstadoVertice getEstado() {
        return estado;
    }

    public void setEstado(EstadoVertice estado) {
        this.estado = estado;
    }

    public Vertice getPredecessor() {
        return predecessor;
    }

    public void setPredecessor(Vertice predecessor) {
        this.predecessor = predecessor;
    }

    public int getDistancia() {
        return distancia;
    }

    public void setDistancia(int distancia) {
        this.distancia = distancia;
    }

    public int getTempoAbertura() {
        return tempoAbertura;
    }

    public void setTempoAbertura(int tempoAbertura) {
        this.tempoAbertura = tempoAbertura;
    }

    public int getTempoEncerramento() {
        return tempoEncerramento;
    }

    public void setTempoEncerramento(int tempoEncerramento) {
        this.tempoEncerramento = tempoEncerramento;
    }
}