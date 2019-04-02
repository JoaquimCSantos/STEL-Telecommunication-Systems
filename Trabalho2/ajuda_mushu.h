
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "lista_ligada.h"

#define HIST_SIZE 25

#define MAX_ATRASO_2 0.15
#define MAX_ATRASO_3 0.050
#define MAX_ATRASO_4 0.030
#define MAX_ATRASO_5 0.016

#define LAMBDA 200
#define DELTA 2.0/(5)
#define Dm 0.008

#define CHEGADA_EVENTO 1
#define SAIDA_EVENTO 0

lista  * lista_eventos;

void guardarCSV(int histograma[]);

double calculaC();

double calculaD();

int map(double c_to_map, double max_atraso);

int hardenMap(double c_to_map);

void imprimeHistograma(int histograma[]);

void limpar();
