#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "ajuda_mushu.h"


// Pequeno exemplo de utilização
int main(void)
{

	double tempo_simulacao = 0;
	double tempo_evento = 0, tempo_atual = 0;
	double atraso = 0.0, atraso_total = 0.0;
	int tipo_evento, num_canais = 0;
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

	//Array com todos os canais 
	int chamadas_do_canal[num_canais];
	//Coloca as chamadas de todos os canais a zero
	for(int i=0; i<num_canais;i++){
		chamadas_do_canal[i]=0;
	}

	Eventos = adicionar(Eventos, 1, calculaC());



	while (tempo_evento < tempo_simulacao) {
		
		//vai buscar evento
		tempo_evento=Eventos->tempo;
		tipo_evento=Eventos->tipo;
		Eventos = remover(Eventos); //processar um evento


		switch(tipo_evento){

			case 1://se evento e de entrada
			

			Eventos=adicionar(Eventos, 1, (calculaC()+tempo_evento));
				if(canal < num_canais){    //se houver canais livres
					chamadas_do_canal[canal]++;
					num_chamadas++;
					canal++;
					Eventos = adicionar(Eventos, 0, (calculaD() + tempo_evento));
				}

				else { //se os canais tiverem ocupados rejeita a chamada
				Fila = adicionar(Fila, 1, tempo_evento);
				//em vez de descartar, poe na fila
				num_chamadas++;
				num_chamadas_atrasadas++;

				}
			break;

			case 0:// se evento e saida
			
				canal--; //liberta o canal e volta ao anterior
				if (Fila != NULL){      //tira da fila e poe no canal quando canal ta livre
					atraso = tempo_evento -Fila->tempo;
					atraso_total = atraso_total + atraso;
					Fila = remover(Fila);




					Eventos = adicionar(Eventos, 0, (calculaD() + tempo_evento));
				
					chamadas_do_canal[canal]++; 
					canal++;


				//timoteo, o gajo aqui faz umas merdas com indexes para
				// o histograma, ve isso pf
			}
			break;
		}
	}





		printf("\n");
		printf(">>Atraso total:%lf\n\n", atraso_total);
		printf(">>Chamadas atrasadas:%d\n\n",num_chamadas_atrasadas );
		printf(">>Numero total de chamadas:%d\n\n",num_chamadas );
		printf(">>Probabilidade de atraso:%f.2\n\n", ((float)num_chamadas_atrasadas/num_chamadas) * 100);
		printf(">>Atraso Medio: %.2f\n\n",((float)atraso_total/num_chamadas));
		//index = hardenMap(c_atual);

		//histograma[index]++;
		// lista_eventos = adicionar(lista_eventos, 0,c_atual);
	

	//tempo_espera = tempo_espera/arrivals;
	//printf("Total de chegadas: %d\n",arrivals);
	//printf("Tempo médio de espera: %lf \n",tempo_espera);
	// printf("Maximo de index %d  | Minimo de c: %lf | Max de c: %lf \n", max_ind,min_c,max_c);
	// printf("Minimo de u: %lf | Max de u: %lf \n", max_u,min_u);
	//imprimeHistograma(histograma);
	//guardarCSV(histograma);

	//system("python histograma.py");

	// limpar(arrivals);
}

