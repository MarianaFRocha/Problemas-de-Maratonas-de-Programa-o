#include <stdlib.h>
#include <stdio.h>

int main(){

    //numero de campus - casos
    int t; 
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
         //n = numereo de atracoes k = numero de atracoes que ele vai visitar v = numero de visitas ja feitas
        int n, k;
        unsigned long v;  
        scanf("%d %d %lu", &n, &k, &v);
        
       // printf("%d %d %d %lu\n", t, n, k, v);

        char atracoes[n][20];

        for (int j = 0; j < n; j++)
        {
            scanf("%s", atracoes[j]);
            printf("%s \n", atracoes[j]);
        }
        printf("ok");

        printf("Case #%d:", i+1);
        if(k==n){
            for (int j = 0; j < n; j++)
            {
                printf(" %s", atracoes[j]);
            }
            
            
        }else
        {
            
            //otimizar calculo 
            int x=0, aux=n-k;
            for (unsigned long j = 0; j < v; j++)
            {
                if(x<=0){
                    x=n-aux;
                }
                else
                {
                    x-=aux;
                }           
            }
            
           // printf ("\n x: %d aux:%d \n", x, aux);


            if(k==1){
                printf(" %s", atracoes[x+1]);
            }else
            {
                for (int j = 0; j < n; j++)
                {
                    if(j<x || (x+aux)<=j){
                        printf(" %s", atracoes[j]);
                    }
                }
            }
            
        }
        printf("\n");       
       
    }
    

    return 0;

}