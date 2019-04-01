
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "ajuda_mushu.h"




// Pequeno exemplo de utilização
int main(void)
{

	double tempo_simulacao, tempo_evento = 0; 
	double tempo_espera, tempo_atual = 0;
	int tipo_evento, num_canais = 0;
	int num_chamadas, num_chamadas_perdidas = 0;
	lista *Eventos = NULL;
	int canal = 0; 
	int index, histograma[HIST_SIZE] = {0};

	num_chamadas = 0;
		

	srand(time(NULL));
	printf("Qual o tempo de execucao em segundos? \n");
	scanf("%lf", &tempo_simulacao);
	printf("Qual o numero de canais? \n");
	scanf("%d", &num_canais);

	//Array com todos os canais 
	int chamadas_do_canal[num_canais];
	//Coloca as chamadas de todos os canais a zero
	for(int i=0; i<num_canais;i++){
		chamadas_do_canal[i]=0;
	}

	Eventos = adicionar(Eventos, 1, calculaC() );



	while (tempo_evento < tempo_simulacao) {
		tempo_evento=Eventos->tempo;
		tipo_evento=Eventos->tipo;
		Eventos = remover(Eventos); //processar um evento


		if(tipo_evento==1){

		Eventos=adicionar(Eventos, 1, (calculaC()+tempo_evento));//chegada do proximo
			if(canal < num_canais){    //se houver canais livres
				chamadas_do_canal[canal]++;
				num_chamadas++;
				canal++;
				Eventos = adicionar(Eventos, 0, (calculaD() + tempo_evento));//partida deste
			}

			else { //se os canais tiverem ocupados rejeita a chamada
				num_chamadas++;
				num_chamadas_perdidas++;
			}
		}

		else if(tipo_evento == 0) {
			canal--; //liberta o canal e volta ao anterior
		}
	}



	imprimir(Eventos);
	printf("%d\n", num_chamadas_perdidas);
	printf("%d\n",num_chamadas);
	printf("Probabilidade de bloqueio:%f.2\n", ((float)num_chamadas_perdidas/num_chamadas) * 100);
	// index = hardenMap(c_atual);
	// histograma[index]++;
	// lista_eventos = adicionar(lista_eventos, 0,c_atual);
	

	// printf("Maximo de index %d  | Minimo de c: %lf | Max de c: %lf \n", max_ind,min_c,max_c);
	// printf("Minimo de u: %lf | Max de u: %lf \n", max_u,min_u);

	// imprimeHistograma(histograma);
	// guardarCSV(histograma);

	// system("python histograma.py");

	// limpar(arrivals);

}
