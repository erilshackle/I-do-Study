#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListaLigada {
	int codigo;
	struct ListaLigada *prox;
} Lista;

// inserir no fim
Lista* inserir_fim(Lista* H, int cod){
		Lista* novo = (Lista*)malloc(sizeof(Lista));
		if(novo!=NULL){
			novo->codigo = cod;
			novo->prox = NULL;
			if(H == NULL)return novo;
			Lista* aux = H;
			while(aux->prox!=NULL){
					aux=aux->prox;
			}
			aux->prox = novo;
		}
		return H;
}

// inserir no inicio
Lista* inserir_ini(Lista* H, int cod){
		Lista* novo = (Lista*)malloc(sizeof(Lista));
		if(novo!=NULL){
			novo->codigo = cod;
			novo->prox = NULL;

			if(H == NULL)return novo;
			
			novo->prox = H;
			H = novo;
		}
		return H;
}

// inserir em ordem
Lista* inserir_ord(Lista* H, int cod){
		Lista* novo = (Lista*)malloc(sizeof(Lista));
		if(novo!=NULL){
			novo->codigo = cod;
			novo->prox = NULL;
			
			if(H == NULL)return novo;
			
			Lista* aux = H;
			Lista* anterior = NULL;
			while(aux!=NULL){
				if(aux->codigo > cod) break;
					anterior = aux;
					aux=aux->prox;
			}

			novo->prox = aux;
			anterior->prox = novo;
		}
		return H;
}

// Imprimir Lista normal
void imprimir(Lista* H){
	Lista* aux = H;
	while(aux!=NULL){
		printf("|%d| -> ", aux->codigo);
		aux=aux->prox;
	}
	puts("NULL");
}

// Imprimir Lista do fim ao inicio
void imprimir_rev(Lista* H){
	if (H == NULL){
		puts("NULL");
		return;
	}
	imprimir_rev(H->prox);
	printf("<- |%d|", H->codigo);
}

// Pesquizar por código
bool buscar(Lista* H, int codigo){
	Lista* aux = H;
	while(aux!=NULL){
		if(aux->codigo == codigo)return true;
		aux = aux->prox;
	}
	return false;
}

int contar(Lista* H, int pesquiza){
	Lista* aux = H;
	int _c_ = 0;
	while (aux!=NULL) {
		if(aux->codigo == pesquiza)_c_++;
		aux = aux->prox;
	}
	return _c_;
}
int posicao(Lista* H, int pesquiza){
	Lista* aux = H;
	int pos = 0;
	while (aux!=NULL) {
		if(aux->codigo == pesquiza)return pos;
		pos++;
		aux = aux->prox;
	}
	return -1;
}

// Eliminar um codigo da lista
Lista* delete(Lista* H, int cod){
	Lista* aux = H;
	Lista* anterior = H;

	//Esse é o caso em que queremos eliminar o primeiro nó com o codigo:
	if(H->codigo == cod){	
		aux = aux->prox;			// aux é o mesmo que H, então aux vai ser igual ao seu proximo nó (H->prox)
		free(H);					// Limpamos o H porque ele é o que queremos eliminar (a consicão diz)
		return aux;					// retornamos o aux: pq contem o endereço do H-Prox, que daí passa a ser o inicio da lista
	}

	while(aux != NULL){
		
		if(aux->codigo == cod){
			anterior->prox = aux->prox;
			free(aux)	
			break;
		}

		anterior = aux;
		aux = aux->prox;
	}
	return H;
}

// Eliminar todos da lista
Lista* deleteAll(Lista* H){
	Lista* aux = H;
	Lista* anterior;
	while(aux->prox!=NULL){
		anterior = aux;
		aux = aux->prox;
		free(del);
	}
	free(aux);
	puts("A lista está Vazia!");
	return NULL;
}


int main()
{	

	/* Declarar um ponteiro que deve servir de referencia para o primeiro nó da lista
		Este ponteiro deve ser inicializado com NULL, o nome não importa (...) mas a < Lista* > sim!  */
	Lista* lista = NULL;

	
	/* são variáveis para scanf e printf
		num: numeros	i: loop for 	n:um número limite de quantos elemntos inserir cod: para pesquizar*/
	int num, i, n, cod;	


	printf("Quantos codigos quer inserir?: ");	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("%i* codigo: ", i+1);	scanf("%d", &num);

		lista = inserir_ord(lista, num);		// inserir na lista cada vez que introduzir um num..
	}

	// chamar a função imprimir enviando o nosso ponteiro que contem a referencia para o inicio da lista
	imprimir(lista);

	printf("Digite um codigo para avaliar: ");	scanf("%d", &cod);

	printf("buscando %d -> %s\n", cod, buscar(lista, cod)==true?"Encontrado":"Não Encontrado");
	printf("Posição  %d -> %d\n", cod,posicao(lista, cod));
	printf("contado  %d -> %dx\n", cod,contar(lista, cod));

	puts("Eliminadno a lista");	// é apenas para mostar na tela, puts() é a mesta coisa que printf("texto\n");

	lista = deleteAll(lista);	//	eliminar tudo da lista, e retornar NULL, 
	
	imprimir(lista);

	return 0;
}
