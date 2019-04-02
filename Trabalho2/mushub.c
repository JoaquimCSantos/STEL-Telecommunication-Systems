#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "ajuda_mushu.h"
	

// Pequeno exemplo de utilização
int main(void)
{
	double max_atraso_map = MAX_ATRASO_5;
	double tempo_simulacao = 0 ;
	double tempo_evento = 0, tempo_atual = 0;
	double atraso = 0.0, atraso_total = 0.0, max_atraso = 0.0 ,  min_atraso = 999.0 ;
	int tipo_evento, num_canais = 0, posicao_atraso = 0;
	int num_chamadas = 0;
	int num_chamadas_atrasadas = 0;
	lista *Eventos = NULL;

	lista *Fila = NULL;//agora temos fila
	int canal=0; 

	int index, histograma[HIST_SIZE] = {0};
	

	srand(time(NULL));
	printf(">>Qual o tempo de execucao em segundos? \n\n");
	scanf("%lf", &tempo_simulacao);
	printf(">>Qual o numero de canais? \n\n");
	scanf("%d", &num_canais);

	switch(num_canais){
		case 2:
			max_atraso_map = MAX_ATRASO_2;
			break;
		case 3:
			max_atraso_map = MAX_ATRASO_3;
			break;	
		case 4:
			max_atraso_map = MAX_ATRASO_4;
			break;	
		default:
			max_atraso_map = MAX_ATRASO_5;
			break;
	}									

	//Array com todos os canais 
	int chamadas_do_canal[num_canais];
	//Coloca as chamadas de todos os canais a zero
	for(int i=0; i<num_canais;i++){
		chamadas_do_canal[i]=0;
	}

	Eventos = adicionar(Eventos, CHEGADA_EVENTO, calculaC());



	while (tempo_evento < tempo_simulacao) {
		
		//vai buscar evento
		tempo_evento=Eventos->tempo;
		tipo_evento=Eventos->tipo;
		Eventos = remover(Eventos); //processar um evento


		switch(tipo_evento){

			case CHEGADA_EVENTO://se evento e de entrada
			

				Eventos=adicionar(Eventos, CHEGADA_EVENTO, (calculaC()+tempo_evento));
				if(canal < num_canais){    //se houver canais livres
					chamadas_do_canal[canal]++;
					num_chamadas++;
					canal++;
					Eventos = adicionar(Eventos, SAIDA_EVENTO, (calculaD() + tempo_evento));
				}

				else { //se os canais tiverem ocupados rejeita a chamada
				Fila = adicionar(Fila, CHEGADA_EVENTO, tempo_evento);
				//em vez de descartar, poe na fila
				num_chamadas++;
				num_chamadas_atrasadas++;

				}
			break;

			case SAIDA_EVENTO:// se evento e saida
			
				canal--; //liberta o canal e volta ao anterior
				if (Fila != NULL){      //tira da fila e poe no canal quando canal ta livre
					atraso = tempo_evento -Fila->tempo;
					atraso_total = atraso_total + atraso;
					Fila = remover(Fila);

					Eventos = adicionar(Eventos, SAIDA_EVENTO, (calculaD() + tempo_evento));
				
					chamadas_do_canal[canal]++; 
					canal++;

					//  AJUDA A TENTAR VER OS MELHORES
					if (max_atraso < atraso)
						max_atraso = atraso;

					if (min_atraso > atraso)
						min_atraso = atraso;					

					//Tentar Guardar todos os valores num array para depois fazer o map, no entanto muito comprido 70k
					// *(valores_atraso + posicao_atraso) = atraso;
					// posicao_atraso++;
					// valores_atraso = realloc(valores_atraso, posicao_atraso + 1 * sizeof(double));
					 index = map(atraso,max_atraso_map);
					 histograma[index]++;
			}
			break;
		}
	}

		// printf("Atraso: %d\n",posicao_atraso);
		// for (int i = 0; i <= posicao_atraso; ++i)
		// {
		// 	printf(" %lf\n", *(valores_atraso + i) );
		// }
		printf(">>Max_atraso:%lf  || Min_atraso: %lf  \n\n", max_atraso,min_atraso);
		printf("\n");
		printf(">>Atraso total:%lf\n\n", atraso_total);
		printf(">>Chamadas atrasadas:%d\n\n",num_chamadas_atrasadas );
		printf(">>Numero total de chamadas:%d\n\n",num_chamadas );
		printf(">>Probabilidade de atraso:%f.2\n\n", ((float)num_chamadas_atrasadas/num_chamadas) * 100);
		printf(">>Atraso Medio: %.2f\n\n",((float)atraso_total/num_chamadas));

		//imprimeHistograma(histograma);
		guardarCSV(histograma);

		system("python histograma.py");

		// limpar(arrivals);
}

