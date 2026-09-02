package com.mycompany;

public class Vertice {

    private static int contador = 1;

    private final int id;

    public Vertice() {
        this.id = contador++;
    }

    public int getId() {
        return id;
    }

    @Override
    public String toString() {
        return String.valueOf(id);
    }
}