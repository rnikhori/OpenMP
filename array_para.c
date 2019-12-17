#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<omp.h>
# define CHUNKSIZE 500
int main()
{
int N;
printf("enter the length of array");
scanf("%d",&N);
int arr[N],i,chunk;
double my_min; 
chunk = CHUNKSIZE;

	clock_t start, end;
    double cpu_time_used;
	start = clock();
for(i=0;i<N;i++)
{
	arr[i]=rand();
}

my_min= arr[0];

#pragma omp parallel shared(arr) private(i) num_threads(2)
{
	
	

	#pragma omp for schedule(static,chunk)

	
	

    for (i=1; i<N; i++)
    {
        if (arr[i] < my_min)
        {
           my_min= arr[i];
           
        }
    }
   
 printf("Minimum element is  %lf.\n",  my_min);
	
}
	 

   


						end = clock();
     					cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
						printf("Time elasped is seconds%f\n",cpu_time_used);
}
