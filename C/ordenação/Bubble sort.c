#include <stdio.h>
#define SIZE 5

int i,k;

void sort_bubble(int vetor[], int tamanho);

int main()
{
	int array[SIZE] = {5,2,4,3,-1};

	puts("BUBBLE SORT:");
	sort_bubble(array, SIZE);

	for (i = 0; i < SIZE; i++)
	{
		printf("[%d]", array[i]);
	}
	puts("\n");
	return 0;
}

void sort_bubble(int vetor[], int tamanho){
	int aux;
	for(i = 0; i < tamanho; i++){
		for (k = 0; k < tamanho; k++)
		{
			if( vetor[k] > vetor[k+1] ){
			aux = vetor[k];
			vetor[k] = vetor[k+1];
			vetor[k+1]= aux;
			}
		}
	}
}


/*-------------------*
ERILANDO CARVALHO 	*
------------------*/