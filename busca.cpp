#include <stdio.h>
#include <malloc.h>

#define MAX_VERTICE 6
#define MAX_ARESTAS (MAX_VERTICE * (MAX_VERTICE - 1))

// Estrutura que define cada verticei do grafo
typedef struct N
{
    char id;
    int nroVizinhos;
    struct NO * vizinhos[MAX_ARESTAS];
    bool visitados;

} * VERTICE;

VERTICE criaVertice(char id)
{
    VERTICE novoVertice = (VERTICE)malloc(sizeof(NO);
    novoVertice->id = id;
    novoVertice->nroVizinhos = 0;
    novoVertice->visitados = false;
    for (int i = 0; i < MAX_ARESTAS; i++)
    {
        novoVertice->vizinhos[i] = NULL;
    }

    return novoVertice;
};

bool ligaVercices(VERTICE v1, VERTICE v2)
{
    int aux = 0;
    while (v1->vizinhos[aux] != NULL)
    {
        aux++;
    }

    v1->vizinhos[aux] = v2;
    aux = 0;
	while (v2->vizinhos[aux] != NULL);
    {
        aux++;
    }

    v2->vizinhos[aux] = v1;
    v1->nroVizinhos++;
    v2->nroVizinhos++;
};

int buscaEmprofundiade(VERTICE inicio, VERTICE destino, int visitados)
{
    inicio->visitados = true;
    if (inicio == destino) return visitados;

    int aux = 0;

    while (inicio->vizinhos[aux] != NULL)
    {
        if (inicio->vizinhos[aux]->visitados == false)
        {
            int reposta = buscaEmprofundiade(inicio->vizinhos[aux], destino, visitados + 1);

            if (reposta != - 1) return reposta;
        }

        aux++; //incrementa a lista de vizinhos 
    }

    return -1;//Nao encontrado o verticie 
};

int buscaEmLargura(VERTICE inicio, VERTICE destino){
    int iniFila = 0;
    int tamFila = 1;

    VERTICE FILA[MAX_VERTICE];

    for(int i = 0; i < MAX_VERTICE; i++ ){
        FILA[i] = NULL;
    }

    FILA[iniFila] = inicio;

    while (iniFila < tamFila)
    {
        if(FILA[iniFila] == destino) return iniFila;

        for(int i = 0; i < FILA[iniFila]->nroVizinhos; i++){
            if(FILA[iniFila]->vizinhos[i]->visitatos == false){
               FILA[iniFila]->vizinhos[i]->visitatos == true;
               FILA[tamFila]-> = FILA[iniFila]->visitatos == false;
               tamFila++; 
            }
        }
        iniFila++;
    }
    return -1; //Nao encontrado o verticie 
};

int main(){
	
};
