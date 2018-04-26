#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// represetar o peso da aresta no grafo
struct Aresta {

	int origem, destino, peso;

};

struct Grafo{

	// V-> n de vertices, A-> n de arestas
	int V, A;

	struct Aresta* aresta;

};

// cria grafo com V vertices e A arestas
struct Grafo* criaGrafo(int V, int A) {
	struct Grafo* grafo = new Grafo;
	grafo->V = V;
	grafo->A = A;

	grafo->aresta = new Aresta[A];

	return grafo;
}

// repesenta um subconjunto
struct subconjunto{
	int pai;
	int classificacao;
};

// busca no conjunto um elemento i
int buscaConjunto(struct subconjunto subconjuntos[], int i) {

	if (subconjuntos[i].pai != i)
		subconjuntos[i].pai = buscaConjunto(subconjuntos, subconjuntos[i].pai);

	return subconjuntos[i].pai;
}

// faz a uniao de x e y
void uniaoConjunto(struct subconjunto subconjuntos[], int x, int y) {

	int xroot = buscaConjunto(subconjuntos, x);
	int yroot = buscaConjunto(subconjuntos, y);

	if (subconjuntos[xroot].classificacao < subconjuntos[yroot].classificacao) {
		subconjuntos[xroot].pai = yroot;
	} else if (subconjuntos[xroot].classificacao > subconjuntos[yroot].classificacao) {
		subconjuntos[yroot].pai = xroot;
	} else {
		subconjuntos[yroot].pai = xroot;
		subconjuntos[xroot].classificacao++;
	}

}

// compara duas arestas baseado no peso
int comparaPesos(const void* a, const void* b) {

	struct Aresta* a1 = (struct Aresta*)a;
	struct Aresta* b1 = (struct Aresta*)b;
	return a1->peso > b1->peso;

}

// A função principal para construir o MST usando Kruskal
void Kruskal(struct Grafo* grafo) {

	int V = grafo->V;
	struct Aresta resultado[V]; // guarda o resultadoado do MST
	int a = 0; // usada para resultadoados
	int i = 0; // usada para classificar as arestas

	qsort(grafo->aresta, grafo->A, sizeof(grafo->aresta[0]), comparaPesos);

	struct subconjunto *subconjuntos =
		(struct subconjunto*) malloc( V * sizeof(struct subconjunto) );

	// cria V subconjuntos com elementos individuais
	for (int v = 0; v < V; ++v)
	{
		subconjuntos[v].pai = v;
		subconjuntos[v].classificacao = 0;
	}

	// teste do número de arestas
	while (a < V - 1) {

		struct Aresta next_aresta = grafo->aresta[i++];

		int x = buscaConjunto(subconjuntos, next_aresta.origem);
		int y = buscaConjunto(subconjuntos, next_aresta.destino);

		if (x != y) {

			resultado[a++] = next_aresta;
			uniaoConjunto(subconjuntos, x, y);

		}
	
	}

	printf("As seguintes arestas foram construídas com MST\n");
	
	for (i = 0; i < a; ++i){

		printf("%d -- %d == %d\n", resultado[i].origem, resultado[i].destino,
												resultado[i].peso);
	}
	return;

}

int main() {

	/* Let us create following pesoed grafo
		  10
		0-----1
		| \   |
	   6| 5\  |15
		|   \ |
		2-----3
		   4	 */

	int V = 4; // n de vértices no grafo
	int A = 5; // n de arestas no grafo
	struct Grafo* grafo = criaGrafo(V, A);


	// add aresta 0-1
	grafo->aresta[0].origem = 0;
	grafo->aresta[0].destino = 1;
	grafo->aresta[0].peso = 10;

	// add aresta 0-2
	grafo->aresta[1].origem = 0;
	grafo->aresta[1].destino = 2;
	grafo->aresta[1].peso = 6;

	// add aresta 0-3
	grafo->aresta[2].origem = 0;
	grafo->aresta[2].destino = 3;
	grafo->aresta[2].peso = 5;

	// add aresta 1-3
	grafo->aresta[3].origem = 1;
	grafo->aresta[3].destino = 3;
	grafo->aresta[3].peso = 15;

	// add aresta 2-3
	grafo->aresta[4].origem = 2;
	grafo->aresta[4].destino = 3;
	grafo->aresta[4].peso = 4;

	Kruskal(grafo);

	return 0;

}
