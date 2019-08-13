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

int V, E;
using namespace std;

void bellmanFord(vector<CustoAresta> c, int *dist, int raiz){

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
			if( dist[(c.at(j)).v] != INFINITO && dist[(c.at(j)).w] > (dist[(c.at(j)).v] + (c.at(j)).peso)) 
			{
				//printf("v:%d w:%d  dist: %d\n\n", (c.at(j)).v, (c.at(j)).w, (dist[(c.at(j)).v] + (c.at(j)).peso));
				dist[(c.at(j)).w] = (dist[(c.at(j)).v] + (c.at(j)).peso);
			}
		}
	}

}


int main(){

	int i, j, k, casos, f, intersections, v=0, w, p, aux, posicao;

	//quantidade de casos
	scanf("%d", &casos); 

	for(j=0; j<casos; j++)
	{

		//quantidade de fire station e intersections
		scanf("%d %d", &f, &intersections);
		V=intersections;
	
		//Leitura da posicao dos fire station
		
		int *fireStation = (int*) calloc (f,sizeof(int));

		//Leitura das fireStation existentes
		for(i=0; i<f; i++){
			scanf("%d", &v);
			fireStation[i] = v-1;
			//printf("Fire Station - Arq:%d vetor:%d\n", v-1, fireStation[i]);
			//printf("%d\n", v);	
		}
		
		//Leitura das intersecoes
		vector<CustoAresta> custos;  
		CustoAresta c;

		int quantArestas = 0;

		//printf("f: %d intersections: %d\n", f, intersections);

		//caso so tem uma intersecao nao eh necessario calcular 
		//pois so tem um lugar para colocar a nova fireStation
		if(intersections == 1){
			printf("1\n\n");
		}else{

			//loop para leitura do input
			while(1)
			{

				//quebra de linha do final da linha anterior
				aux = getchar();  
				if(aux == 13) //13 = \r(retorno ao início da linha)
					aux = getchar(); 

				//primeiro valor da proxima linha
				v = getchar(); 

				//sai do loop ao encontrar uma quebra de linha ou ao chegar ao fim
				if(v == '\n' || v == EOF) 
					break;

				//converte para inteiro
				v = v - 48;  

				//le valores maiores que 9
				while(1){  
					//printf("aqui\n");
					aux = getchar();
					if(aux == ' ')
						break;
					v = (v*10)+(aux-48);

				}

				scanf("%d", &w);
				scanf("%d", &p);
				//printf("%d %d %d\n", v, w, p);

				//adiciona as intersecoes no vetor
				v--;
				w--;

				c.v=v;
				c.w=w;
				c.peso=p;
				custos.push_back(c);
			
				//printf("%d %d %d", (custos.at(i)).v, (custos.at(i)).w, (custos.at(i)).peso);
				c.w=v;
				c.v=w;
				c.peso=p;
				custos.push_back(c);

				quantArestas = quantArestas + 2;
			
			}

			//Inicio dos Calculos

			E=quantArestas; 

			//caso ja tenha fireStation em todas as intersecoes 
			if(intersections == f){
				posicao = 1;
			}else{

				//Vetor que fica armazenado as distancias das fireStation iniciais
				int *distFireStation = (int*) calloc (V,sizeof(int));  
				for(i=0; i<V; i++){
					distFireStation[i]=INFINITO; 	
				}

				int *dist = (int*) calloc (V,sizeof(int));
				posicao=0;
			
				//Calcula a distancia dos pontos a cada fire station já existente
				for(i=0; i<f; i++){
					bellmanFord(custos, dist, fireStation[i]);

					//printf("Vetor fire station existente %d: ", V);
					for(k = 0; k<V; k++){
						//atualiza o vetor com apenas os valores que ficam menores com a adicao de uma nova fire station
						if(dist[k]<distFireStation[k]){
							distFireStation[k] = dist[k]; 
						}
					//	printf("%d ", distFireStation[k]);
					}
					//printf("\n");
				}

				//Calculo para encontrar a posicao da nova fire station
				int melhor = INFINITO, novo;

				for(i = 0; i<V; i++){

					//Caso distFireStation == 0 ja existe um fire station
					if(distFireStation[i] != 0){

						bellmanFord(custos, dist, i);
						
						//printf("Vetor station %d: ", i);
						novo=-1;

						//O maior valor da menor distancia entre a nova fireStation e as fireStation que ja tinham 
						for(k = 0; k<V; k++){
							novo=max(novo, min(dist[k], distFireStation[k]));
						}
						//printf("\n");

						//Confere se a nova fireStation eh melhor que anterior
						if(novo<melhor){
							posicao = i+1;
							melhor = novo;
							//printf("Aqui: %d V: %d\n\n", posicao, V);  
						}
					}
				}
			}
			if(j!=casos-1)
				printf("%d\n\n", posicao);
		}
	}
	
	printf("%d\n", posicao);
       
	return 0;

}
