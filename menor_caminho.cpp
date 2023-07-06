#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int TIPOPESO;

typedef struct adjacencia {
    int vertice; 
    TIPOPESO peso; 
    struct adjacencia *prox; 
} ADJACENCIA;

typedef struct vertice {
    ADJACENCIA *cab; 
} VERTICE;

typedef struct grafo {
    int vertices; 
    int arestas; 
    VERTICE *adj;
} GRAFO;

GRAFO *criaGrafo(int v) {
    int i;
	
    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO)); 
    g->vertices = v; 
    g->arestas = 0;  
    g->adj = (VERTICE *)malloc(v * sizeof(VERTICE)); 
    for (i = 0; i < v; i++) {
        g->adj[i].cab = NULL;
    }
    return (g);
}

ADJACENCIA *criaAdj(int v, int peso) {
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA)); 
    temp->vertice = v; 
    temp->peso = peso;
    temp->prox = NULL;
    return (temp);
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p) {
    if (!gr) return (false);  
    if ((vf < 0) || (vf >= gr->vertices)) return (false); 
    if ((vi < 0) || (vi >= gr->vertices)) return (false); 

    ADJACENCIA *novo = criaAdj(vf, p); 
    novo->prox = gr->adj[vi].cab; 
    gr->adj[vi].cab = novo; 
    gr->arestas++; 
    return (true);
}

void imprime(GRAFO *gr) {
    if (!gr) return; 

    printf("Vertices: %d. Arestas: %d.\n", gr->vertices, gr->arestas); // imprime o número de vértices e arestas

    int i;

    for (i = 0; i < gr->vertices; i++) {
        printf("v%d: ", i); // imprime em qual aresta estamos
        ADJACENCIA *ad = gr->adj[i].cab;
        while (ad) { 
            printf("v%d(%d) ", ad->vertice, ad->peso); // imprime a adjacência e seu peso
            ad = ad->prox;
        }
        printf("\n");
    }
}

void dijkstra(GRAFO *gr, int origem, int destino) {
    if (!gr || origem < 0 || origem >= gr->vertices || destino < 0 || destino >= gr->vertices) {
        printf("Grafo invalido ou vertices invalidos.\n");
        return;
    }

    int *distancia = (int *)malloc(gr->vertices * sizeof(int));
    int *anterior = (int *)malloc(gr->vertices * sizeof(int));
    bool *visitado = (bool *)malloc(gr->vertices * sizeof(bool));

    int i, j, menorDistancia, proxVertice;

    for (i = 0; i < gr->vertices; i++) {
        distancia[i] = INT_MAX; 
        anterior[i] = -1; 
        visitado[i] = false; 
    }

    distancia[origem] = 0; 

    for (i = 0; i < gr->vertices; i++) {
        menorDistancia = INT_MAX;

        // Encontra o vértice com a menor distância não visitada
        for (j = 0; j < gr->vertices; j++) {
            if (!visitado[j] && distancia[j] < menorDistancia) {
                menorDistancia = distancia[j];
                proxVertice = j;
            }
        }

        visitado[proxVertice] = true;

        ADJACENCIA *ad = gr->adj[proxVertice].cab;
        while (ad) {
            int verticeAdj = ad->vertice;
            int pesoAresta = ad->peso;

            if (distancia[proxVertice] + pesoAresta < distancia[verticeAdj]) {
                distancia[verticeAdj] = distancia[proxVertice] + pesoAresta;
                anterior[verticeAdj] = proxVertice;
            }

            ad = ad->prox;
        }
    }

	// Mostra o menor caminho da origem ao destino
	printf("Menor caminho de v%d a v%d: ", origem, destino);
	int vertice = destino;
	int *caminho = (int *)malloc(gr->vertices * sizeof(int));
	int tamanhoCaminho = 0;
	
	while (vertice != -1) {
	    caminho[tamanhoCaminho++] = vertice;
	    vertice = anterior[vertice];
	}
	
	for (int i = tamanhoCaminho - 1; i >= 0; i--) {
	    printf("v%d", caminho[i]);
	    if (i != 0) {
	        printf(" -> ");
	    }
	}
	printf("\n");

}

int main() {
    GRAFO *gr = criaGrafo(5);
    //criarAresta(grafo, vertice_origem, vertice_destino, peso_aresta);
    criaAresta(gr, 0, 1, 2);
    criaAresta(gr, 1, 2, 4);
    criaAresta(gr, 2, 0, 12);
    criaAresta(gr, 2, 4, 40);
    criaAresta(gr, 3, 1, 3);
    criaAresta(gr, 4, 3, 8);

    imprime(gr);

    int origem, destino;
    printf("Digite o ponto A: v");
    scanf("%d", &origem);
    printf("Digite o ponto B: v");
    scanf("%d", &destino);

    dijkstra(gr, origem, destino);

    return 0;
}

