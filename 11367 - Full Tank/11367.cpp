#include <stdio.h>
#include <stdlib.h>
#include <vector> 
#include <string.h>

#define INFINITO 2147483646

typedef struct custoAresta{
	int v;
	int w;
	int peso;
}CustoAresta; 


int V, E, tanqueMax, saida, destino;

void bellmanFord(CustoAresta *c, int *p, int *dist, int raiz){
	printf("entrou\n");

	int i, j, v, cont=0;

	for(i=0; i<V; i++){
		dist[i]=INFINITO; 	
	}

    //vertice inicial
    dist[raiz]=0;   

	for(i=0; i<V-1; i++)
	{
		//printf("Interacao %d: \n", i+1);
		for (j = 0; j < E; j++)
		{
			if( dist[c[j].v]*p[j] != INFINITO && dist[(c[j]).w]*p[j] > (dist[c[j].v]*p[j] + ((c[j].peso)*p[j]))) 
			{
				printf("v:%d w:%d  dist: %d\n\n", c[j].v, c[j].w, (dist[c[j].v] + (c[j].peso)*p[j]));
				dist[c[j].w] = (dist[c[j].v] + (c[j].peso)*p[j]);
			}
		}
	}

}

void imprimeCusto(CustoAresta *c, int e){
	printf("\nPeso das Arestas do Grafo\n\n");
	for(int i=0; i<e; i++){
		printf("v:%d - w:%d p:%d \n", (c[i].v), (c[i].w), c[i].peso);
	}

	printf("\n");
}


int main(){

	int i, j, k, v, w, peso, cidades, estradas;

	scanf("%d %d", &cidades, &estradas);

	int *postos = (int*) calloc (cidades,sizeof(int));

	for (i = 0; i < cidades; ++i)
	{
		scanf("%d", &postos[i]);
		printf("%d ", postos[i]);
	}
	printf("\n");

	CustoAresta *c = (CustoAresta *)malloc(sizeof(CustoAresta));

	int aux = estradas*2;
	printf("\n%d\n", aux);
	for(i = 0; i < aux; i++)
	{
		scanf("%d %d %d", &v, &w, &peso);
		c[i].v = v;
		c[i].w = w;
		c[i].peso = peso;
		
		i++;

		c[i].w = v;
		c[i].v = w;
		c[i].peso = peso;
	}

	imprimeCusto(c, aux);

	int casos;
	scanf("%d", &casos);
	printf("casos %d\n", casos);

	int *dist = (int*) calloc (V,sizeof(int));

	for (i = 0; i < casos; ++i)
	{
		scanf("%d %d %d", &tanqueMax, &saida, &destino);
		printf("%d %d %d", tanqueMax, saida, destino);

		bellmanFord(c, dist, postos, 0);
		for (int j = 0; j < V; ++j)
		{
			printf("%d \n", dist[j]);
		}



	}
	printf("\n");





	return 0;

}
