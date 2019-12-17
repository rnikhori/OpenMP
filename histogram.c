#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define SIZE 1000000
#define NUMRANGE 50 

int main(){
int i;
int index;
int *arr = (int *)malloc(sizeof(int) * SIZE);
int *hTable = (int *)malloc(sizeof(int) * NUMRANGE);
double start,end;
srand(0);

#pragma omp parallel
{
#pragma omp for 
for(i =0;i< SIZE;i++)
	arr[i] = rand() % NUMRANGE;
}

start = omp_get_wtime();
omp_lock_t writelock;
omp_init_lock(&writelock);
#pragma omp parallel
{
#pragma omp for
for(i = 0; i<SIZE; i++){
	index = arr[i];
	omp_set_lock(&writelock);
	hTable[index] = hTable[index] + 1; 
	omp_unset_lock(&writelock);
}
	omp_destroy_lock(&writelock);
}
end = omp_get_wtime();
printf("%lf", (end-start));

return 0;

}
		


