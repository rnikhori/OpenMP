#include<stdio.h>
#include<math.h>
#include<time.h>
#include<omp.h>
int  main()
{
double time_spent = 0;
clock_t begin = clock();
int N;

scanf("%d",&N);
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
clock_t end =clock();
time_spent +=(double)(end-begin)/CLOCKS_PER_SEC;
printf("TIme elapsed is %f seconds",time_spent);
return 0;
}

