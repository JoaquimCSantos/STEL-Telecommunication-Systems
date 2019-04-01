
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "lista_ligada.h"

#define HIST_SIZE 25
#define LAMBDA 200
#define DELTA 2.0/(LAMBDA*5)
#define Dm 0.08

lista  * lista_eventos;

void imprimir (lista * apontador);


void guardarCSV(int histograma[]);

double calculaC();

double calculaD();

int map(double c_to_map);

int hardenMap(double c_to_map);

void imprimeHistograma(int histograma[]);

void limpar();
