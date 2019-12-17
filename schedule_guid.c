#include<stdio.h>
#include<math.h>
#include<time.h>
#include<omp.h>
#define chunk 100
int  main()
{float t1,t2;

t1= omp_get_wtime();
int N;
scanf("%d",&N);

#pragma omp parallel num_threads(32)
#pragma omp   for schedule(guided,chunk)
for(int i=0;i<N;i++)
{
        int flag=1;
        for(int j=2;j<=sqrt(i);j++)
        {
          if(i%j==0)
         {
          flag = 0;
          break;
        }
   }

        if(flag==1)
        printf("%d  \n",i);

}
t2 =omp_get_wtime();
printf("TIme elapsed is %lf seconds",(double)(t2-t1));


return 0;
}

