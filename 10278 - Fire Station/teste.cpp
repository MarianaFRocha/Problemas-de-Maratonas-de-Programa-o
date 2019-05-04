#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

	int i, j, casos, f, intersections, v, w, p;

	scanf("%d", &casos); 

	scanf("%d %d", &f, &intersections);

	int *fireStation = (int *)malloc(sizeof(int)*f);
		
		for(i=0; i<f; i++){
			scanf("%d", &v);
			fireStation[i] = v-1;		
		}

	int aux;
	int flag = 1;

	for(i=5; i<31; i++){

			//quebra de linha do final da linha anterior
			aux = getchar();  
			//primeiro valor da proxima linha
			v = getchar(); 

			//sai do loop ao encontrar uma quebra de linha
			if(v == '\n') 
				break;

			//converte para inteiro
			v = v - 48;  

			//le valores maiores que 9
			while(1){  
				aux = getchar();
				if(aux == ' ')
					break;
				v = (v*10)+(aux-48);

			}
			//scanf("%d", &v);
			scanf("%d", &w);
			scanf("%d", &p);
			printf("%d %d %d\n", v, w, p);

	}

	printf("fim!!\n");
	return 0;
}
