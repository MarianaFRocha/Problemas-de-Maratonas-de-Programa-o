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


        //DESCOBRIR COMO CRIAR O X !!!!!!!!!!!!!!
        int x=(k*v);
        if (x>n)
        {
            while (x>n)
            {
                x=x/n;
            }
            x++;
        }
        
        

        x--;
        printf("Case #%d:", i+1);
        if (k==1)
        {
            printf(" %s", atracoes[x]);
        }else
        {
            for (int j = 0; j < (k-1) && j!=x ; j++)
            {
                printf(" %s", atracoes[j]);

            }

            for (int j = x; j < k; j++)
            {
                printf(" %s", atracoes[j]);

            }
        }
        
        printf("\n");
        
    }
    

    return 0;

}