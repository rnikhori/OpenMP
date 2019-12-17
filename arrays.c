#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int N;
	printf("enter the number of iteration");
	scanf("%d",&N);
	clock_t start, end;
     double cpu_time_used;
     
     start = clock();

	int arr[N],i,min; 


for(i=0;i<N;i++)
{
	arr[i]=rand();
}
//for(i=0;i<50000;i++){
//printf("%d  ",arr[i]);
//}

 min = arr[0];
   
    for (i=1; i<N; i++)
    {
        if (arr[i] < min)
        {
           min = arr[i];
           
        }
    }
   
    //printf("Minimum element is  %d.\n",  min);
    	end = clock();
     	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("Time elasped is seconds%f\n",cpu_time_used);
	
}

