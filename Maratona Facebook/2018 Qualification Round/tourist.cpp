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
           // printf("%s \n", atracoes[j]);
        }

        int x=0;
        for (int j = 0; j < k; j++)
        {

            for (unsigned long y = 0; y < v; y++)
            {
                if (x>=n){
                    x=0;
                }
                x++;
            }
        }

        x--;
        printf("Case #%d:", i+1);
        int cont =0;
        for (int j = 0; j < (k-(n-x)); j++)
        {
            printf(" %s", atracoes[j]);
            cont++;
        }

        for (int j = x; j < n && cont<k; j++)
        {
            printf(" %s", atracoes[j]);
            cont++;
        }

        printf("\n");
        
    }
    

    return 0;

}