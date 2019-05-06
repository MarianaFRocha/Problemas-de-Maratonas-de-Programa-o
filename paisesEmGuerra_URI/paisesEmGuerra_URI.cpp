#include <stdio.h>
#include <stdlib.h>

#define POST(L)  ((L)->posterior)
typedef struct acordo acordo, *listaAcordo;

struct acordo{

	int x;
	int y;
	int h;
	int vizinho; //0=vizinhos 1=nao eh
	listaAcordo posterior; 
};


void inserirAcordo(listaAcordo *p_L, int x, int y, int h)
{
	listaAcordo tmplista=*p_L;

	listaAcordo L = (listaAcordo) malloc(sizeof(acordo));
	
	if (*p_L == NULL)
	{

		
		L->x=x;
		printf(" \n\n %d \n\n", L->x);
		L->y=y;
		L->h=h;
		L->vizinho=0;
		L->posterior=NULL;
		//tmplista=*p_L;
		*p_L = L;
	}
	else
	{
		printf("\n\naqui\n");
		printf(" \n\n %d \n\n", tmplista->x);

		for(tmplista = *p_L; POST(tmplista)!=NULL; tmplista= POST(tmplista));
		printf("Passou\n");
		L->x=x;
		L->y=y;
		L->h=h;
		L->vizinho=1;
		L->posterior=NULL;
		POST(tmplista) = L;
	}
	return ;
}


void iniciar(listaAcordo *pais, int tamanho){
	for (int i = 0; i < tamanho; ++i)
	{
		pais[i]=NULL;
	}
}

int main(){

/*
	if(argc < 2)
  	{
		printf("\nErro: Digite o nome do arquivo !!!\n\n");
        	exit(1);
	}
	*/

	FILE *arq;

	arq = fopen("entrada.txt", "r");

	if (arq == NULL)
	{
	    printf("Problemas na CRIACAO do arquivo\n");
	    return 0;
	}

	int n, e, x, y, h, o, d,k;

	printf("Passou\n");

	while (fscanf(arq, "%d %d", &n , &e) != 1 && n!=0 && e!=0){

		printf("-------LOOP\n n %d e %d \n", n, e);


		listaAcordo pais[n];
		iniciar(pais,n);

		for (int i = 0; i < e; ++i)  // -----------------------------------------Leitura
		{
			fscanf(arq, "%d %d %d", &x , &y, &h);
			printf("x %d y %d h %d  loops %d \n", x, y, h, i);
			inserirAcordo(&pais[i], x, y, h); 
			printf("\nteste x %d i %d \n", pais[i]->x , i);/*
			if(pais[x].x!=x){

				pais[x].x=x;
				pais[x].y=y;
				pais[x].h=h;
				pais[x].vizinho=0;
				pais[x].proximo=NULL;


			}else{

				while(pais[x].proximo!=NULL){
					//pais[x].proximo->posterior;
				}

				if(pais[x].proximo==NULL){

					pais[x].x=x;
					pais[x].y=y;
					pais[x].h=h;
					pais[x].vizinho=1;
					pais[x].proximo=NULL;

				}
			}*/
		}


		fscanf(arq, "%d", &k);
		printf("d %d \n", k);

		for (int i = 0; i < k; ++i)
		{
			fscanf(arq, "%d %d", &o , &d);
			printf("o %d d %d \n", o, d);
/*
			while(pais[o].y!=d && pais[o].posterior==NULL){
				//pais[x].proximo->posterior;
			}
			*/

			if(pais[o]->y==d && pais[o]->vizinho==0){
				printf("\n------------------------------------->Saida:0\n");
			}
		}


	}

return 0;





}