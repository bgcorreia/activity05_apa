#include <bits/stdc++.h>

using namespace std;

# define INF 0x3f3f3f3f

// Vertices -> par de valores (peso,vertice)
typedef par<int, int> Vertices;

// Classe que representa o Grafo
class Grafo
{
    int V;

// Lista de adjacencias
    list< par<int, int> > *adj;

public:
    // Metodo construtor
    Grafo(int V){

        this->V = V;
        adj = new list<Vertices> [V];

    }

    // Funcao que adiciona aresta ao grafo..
    void AdicionarAresta(int u, int v, int w){
    
        adj[u].push_back(make_par(v, w));
        adj[v].push_back(make_par(u, w));

    }

    void Prims(){

        priority_queue< Vertices, vector <Vertices> , greater<Vertices> > Heap_min;

        int A = 0; // Pegamos o vertice 0 como ponto de partida
        int MinimaArvore = 0;

        // Vetor com os pesos, inicialmente colocamos tudo como infinito
        vector<int> pesos(V, INF);


        // Vetor que armazena os pais dos vertices ( caminho da MST )
        vector<int> pais(V, -1);


        // Vetor booleano para saber se o vertice já foi incluso na MST, inicia todos falsos obviamente.
        vector<bool> NaMST(V, false);
        // Adiciona o A na lista de prioridade e inicia seu peso como zero..
        Heap_min.push(make_par(0, A));
        pesos[A] = 0;

        // Trazido do pseudocodigo, itera até a heap min não chegar em zero..
        while (!Heap_min.empty())
        {

            // Extrai o vertice da fila de prioridade,
            int atual = Heap_min.top().second;
            Heap_min.pop();
            NaMST[atual] = true;  // Include vertex in MST



            list< par<int, int> >::iterator i;
            for (i = adj[atual].begin(); i != adj[atual].end(); ++i)
            {

                int vertice = (*i).first;
                int peso = (*i).second;


                if (NaMST[vertice] == false && pesos[vertice] > peso)
                {

                    pesos[vertice] = peso;
                    Heap_min.push(make_par(pesos[vertice], vertice));
                    pais[vertice] = atual;
                }
            }
        }


        for (int i = 1; i < V; ++i)
            MinimaArvore += pesos[i];
            cout << "Peso Final da MST:" << endl << MinimaArvore << endl;

    }

};

int main(){

    int V = 9;
    Grafo grafo(V);

    grafo.AdicionarAresta(0, 1, 4);
    grafo.AdicionarAresta(0, 7, 8);
    grafo.AdicionarAresta(1, 2, 8);
    grafo.AdicionarAresta(1, 7, 11);
    grafo.AdicionarAresta(2, 3, 7);
    grafo.AdicionarAresta(2, 8, 2);
    grafo.AdicionarAresta(2, 5, 4);
    grafo.AdicionarAresta(3, 4, 9);
    grafo.AdicionarAresta(3, 5, 14);
    grafo.AdicionarAresta(4, 5, 10);
    grafo.AdicionarAresta(5, 6, 2);
    grafo.AdicionarAresta(6, 7, 1);
    grafo.AdicionarAresta(6, 8, 6);
    grafo.AdicionarAresta(7, 8, 7);

    grafo.Prims();

    return 0;
}
