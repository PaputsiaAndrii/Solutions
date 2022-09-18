/* buble_sort.c -- sipmle program, which can show how works buble sort algorithm.

Program will ask you to write down value N, and will use it for build 1D N-lenth array.
Then, program will fill this array by random integer values and show filled array.
By the next step will be bublle sort of values and printing sorted array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show_arr(const int * ptr, int n);
void fill_arr(int * ptr, int n);
void buble_sort(int ptr[], int n);


int main(void)
{
	int N;	
	int * ptr;

	//srand(time(NULL));				// setup grain for pseudo random
	
	printf("Write down N for filling array::\t");
	while(scanf("%d", &N) == 1 && N > 0)
	{
		ptr = malloc(N * sizeof(int));

		//puts("Init arr:");		
		//show_arr(ptr, N);				// show init arr

		fill_arr(ptr, N);
		puts("Filled arr:  (index ==> Value)");
		show_arr(ptr, N);				// show filled arr

		buble_sort(ptr, N);
		puts("Sorted arr:  (index ==> Value)");
		show_arr(ptr, N);				// show sorted arr
	
		free(ptr);				
		printf("Write down N for fill array::\t\n");
	}	

	return 0;
}

void show_arr(const int * ptr, int n)
{
	int i, j;
	for(i = 0, j = 1; i < n; i++, j++)
	{
		printf("%5d ==> %12d", i, *ptr++);
		//printf("%12d", *ptr++);
		if(j == 5)
		{
			putchar('\n');
			j = 0;
		}
	}
	puts("\n");
}

void fill_arr(int ptr[], int n)
{
	for(int i = 0; i < n; i++, ptr++)
	{	
		*ptr = rand(); 		
	}
}

void buble_sort(int ptr[], int n)
{
	int tmp;
			
	for(int i = 0; i < n; i++)
	{
		for(int j = n - 1; j > i; j--)
		{
			if(ptr[j - 1] > ptr[j])
			{
				tmp = ptr[j - 1];
				ptr[j - 1] = ptr[j];
				ptr[j] = tmp;
			}
		}
	} 

}
