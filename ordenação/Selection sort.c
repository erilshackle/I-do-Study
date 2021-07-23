#include <stdio.h>
#define SIZE 5

int i,k;

void sort_selection(int vetor[], int tamanho);

int main()
{
	int array[SIZE] = {5,2,4,3,-1};

	puts("SELECTION SORT:");
	sort_selection(array, SIZE);

	for (i = 0; i < SIZE; i++)
	{
		printf("[%d]", array[i]);
	}
	puts("\n");
	return 0;
}

void sort_selection(int vetor[], int tamanho){
	int menor, aux;
	for(i = 0; i < tamanho; i++){
		menor = i;
		for (k = i+1; k < tamanho; k++)
		{
			if( vetor[k] < vetor[menor] ){
				menor = k;
			}
			aux = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor]= aux;
		}
	}
}


/*-------------------*
ERILANDO CARVALHO 	*
------------------*/