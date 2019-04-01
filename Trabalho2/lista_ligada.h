#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>




// Definição da estrutura da lista
typedef struct{
	int tipo;
	double tempo;
	struct lista * proximo;
} lista;

lista * remover (lista * apontador);

lista * adicionar (lista * apontador, int n_tipo, double n_tempo);
