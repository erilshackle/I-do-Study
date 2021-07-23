#include <stdio.h>
#define SIZE 5

int i,k;

void sort_insersion(int vetor[], int tamanho);

int main()
{
	int array[SIZE] = {5,2,4,3,-1};

	puts("INSERTION SORT:");
	sort_insersion(array, SIZE);

	for (i = 0; i < SIZE; i++)
	{
		printf("[%d]", array[i]);
	}
	puts("\n");
	return 0;
}

void sort_insersion(int vetor[], int tamanho){
	int aux, pos;
	for(i = 0; i < tamanho; i++){
		pos = i;
		aux = vetor[i];
		while( (pos>0) && (vetor[pos-1]>aux) ) {
			vetor[pos] = vetor[pos-1];
			pos--;
		}
		vetor[pos] = aux;
	}
}


/*-------------------*
ERILANDO CARVALHO 	*
------------------*/