#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct binary_tree{
	int codigo;
	struct binary_tree *esq;
	struct binary_tree *dir;
	// poderia tambem escrever: struct binary_tree *esq, *dir;
}Arvore;

/* FUNÇÃO CRIAR
	essa função tem três obrigações: 
		1. criar uma nova variavel da estrutura usando malloc
		2. definir que os filhos dessa 'nova' variavel (esq,dir) sejam NULL
		3. retornar a variável criada
	Inicializar os dados da variável é basicamente atribuir os dados do parametro ado novo->....
*/
Arvore* criarNo(int cdg){
	Arvore* novo = (Arvore*)malloc(sizeof(Arvore));		// só isso, sem inventar nada ok?!
		novo->codigo = cdg;								// inicializar os dados
	novo->esq = novo->dir = NULL;						// definir esq e dir como null
	return novo;										// retornar
}

/*	Função INSERIR
	verificamos se a raiz é null, se for então alí devemos criar o novo nó
	caso a raíz não for NULL criamos duas condições:
	1. O código que veio no parametro é menor que o código da ráiz?
		• se sim, chamos essa mesma função agora enviando o filho esquerdo da raíz como argumento
	2. O código que veio no parametro é maior que o código da ráiz?
		• se sim, chamos essa mesma função agora enviando o filho direito da raíz como argumento
	caso nenhuma dessas condições sejam satisfeita isso significa que o Código já existe
*/
void inserir(Arvore* *raiz, int codigo){
	if( *raiz == NULL ){
		*raiz = criarNo(codigo);
	} else {
		if ( codigo < (*raiz)->codigo )		inserir(&(*raiz)->esq, codigo);
		else if (codigo > (*raiz)->codigo)	inserir(&(*raiz)->dir, codigo);
		else 								puts("Codigo ja existe");
	}
}


/* FUNÇÃO PESQUIZAR
	retorna verdadeiro ou falso..
	sinceramente, é a mesma coisa que a função inserir:
	Só que, se for NULL:
		retornamos falso
	Mas se não satisfazer nenhuma condição (é menor? é maior?)
	ou satisfazer a condição de igualdade (raiz->codigo == codigo )
		retornamos verdadeiro
*/
bool pesquisar(Arvore* raiz, int codigo){
	if(raiz == NULL){								// verificar se é null
		return false;
	}
	if(codigo == raiz->codigo){						//	condição de igualdade
		return true;
	}
	else if(codigo < raiz->codigo ){				// é menor?t
			return pesquisar(raiz->esq, codigo);	// got to the left
	}
	else{											// se não for null, nem igual nem menor, é pq é maior
			return pesquisar(raiz->dir, codigo);	// go to the right
	}
	// as ordem de condição podem mudar, mas lembrase, if NULL é sempre primeiro
	
	return false;									// isso nem se não estivesse aqui
}

/*  Funções de percorer uma arvore 
	uma dica é que, se queremos operar (soma total, calcular, etc.)
	com todos os elementos da arvore, esse é metodo recorrido
*/

void preordem(Arvore* raiz){		// IED
	if(raiz == NULL)return;
	
	printf(" {%d} ", raiz->codigo);
	preordem(raiz->esq);
	preordem(raiz->dir);
}

void inordem(Arvore* raiz){			// EID
	if(raiz == NULL)return;
	
	inordem(raiz->esq);
	printf(" {%d} ", raiz->codigo);
	inordem(raiz->dir);
}

void posordem(Arvore* raiz){		// EDI
	if(raiz == NULL)return;
	
	posordem(raiz->esq);
	posordem(raiz->dir);
	printf(" {%d} ", raiz->codigo);
}

/* I - Imprimir		E - Esquerda	D - Direita */

// Sério... só copia, 
void eliminar(Arvore* *raiz, int codigo){
	if(*raiz == NULL)return;
	else if( codigo < (*raiz)->codigo )		eliminar( &(*raiz)->esq, codigo );
	else if( codigo > (*raiz)->codigo )		eliminar( &(*raiz)->dir, codigo );
	/* 	Encontrado!*/
	else {
		// Caso 1: sem filhos
		if( (*raiz)->esq == NULL && (*raiz)->dir == NULL ){
			free(*raiz);
			*raiz = NULL;
		}//caso 2: com apenas 1 filho
		else if ( (*raiz)->esq == NULL){
			Arvore* aux = *raiz;
			*raiz = (*raiz)->dir;
			free(aux);
		}
		else if ( (*raiz)->dir == NULL){
			Arvore* aux = *raiz;
			*raiz = (*raiz)->esq;
			free(aux);
		}// Caso 3: com ambos os filhos
		else {
			Arvore* aux = (*raiz)->dir; //= maior_menor((*raiz)->dir, 'e');
			while(aux->esq!=NULL){
				aux = aux->esq;
			}
			(*raiz)->codigo = aux->codigo;
			eliminar( &(*raiz)->dir, aux->codigo );
		}
	}
}
// to zuando, se querer entender, é só chamar, mas isso leva tempo

void modificar(Arvore* *raiz, int codigo);

int main()
{

	Arvore* raiz = NULL;	// Menino do céu, se vc não colocar isso, tu ta frito!
	
	inserir(&raiz, 17);
	inordem(raiz);
	preordem(raiz);
	posordem(raiz);
	eliminar(&raiz, 17);
	if( pesquisar(raiz, 17) == true ){
		puts("Encontrado");
	} else {
		puts("Não encontrado");
	}

	return 0;
}
// Mostrei o MAIN() com a intenção de terem uma noção
// de como chamar cada função, e cuidado com &


// Por curiosidade, o output será:  {17}  {17}  {17} Não encontrado


