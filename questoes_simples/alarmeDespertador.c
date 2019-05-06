#include <stdio.h>
#include <stdlib.h>

int main()
{
	int  h1, m1, h2, m2, tempo=0;

	while(1){
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if(h1==0 && m1==0 && h2==0 && m2==0){
            return 0;
        }

        if (h2==h1 && m2>m1)
        {
            tempo = m2-m1;
        }else{

            if(h1>=h2){
                tempo = 60-m1;
                h1++;

                while(h1!=h2){
                    if(h1!=24){
                        tempo+=60;
                        h1++;
                    }else{
                        h1=0;
                    }
                }
                tempo+=m2;
            }else{
                tempo = 60+m2;
                h2--;

                while(h1!=h2){
                    if(h2==24){
                        h2=0;
                    }else{
                        tempo+=60;
                        h2--;
                    }
                }

                tempo-=m1;
            }

        }

        printf("%d\n", tempo);
    }
}
