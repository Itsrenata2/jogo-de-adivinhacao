#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// descritiva em C
// #define TENTATIVAS 3

int main() {
	printf("\n");
	printf("**********************\n");
	printf("* Bem vindo ao GUESS *\n");
	printf("**********************\n");
	printf("O jogo de adivinhação!\n");
	printf("\n");

	// segundos desde 1970, sempre vai estar mudando
	int segundos = time(0);
	// semente
	srand(segundos);

	int numero_secreto = rand() % 100;
	// int numero_secreto = 42;
	int chute;
	// int ganhou = 0;
	int tentativas = 1;
	double pontos = 1000;
	int numero_de_tentativas = 5;

	// níveis de dificuldade
	int nivel = 0;
	printf("Qual o nível de dificuldade?\n");
	printf("(1) Fácil\n");
	printf("(2) Médio\n");
	printf("(3) Difícil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	switch(nivel) {
		case 1: 
			numero_de_tentativas = 20;
			break;

		case 2:
			numero_de_tentativas = 15;
			break;

		default:
			numero_de_tentativas = 6;
			break;
	}
	/*if (nivel == 1) {
		numero_de_tentativas = 20;
	} else if (nivel == 2) {
		numero_de_tentativas = 15;
	} else {
		numero_de_tentativas = 6;
	}*/

	int historico_chutes[numero_de_tentativas];
    	for (int i = 0; i < numero_de_tentativas; i++) {
        	historico_chutes[i] = -1; 
    }

	// while 1, sempre infinito, sempre verdadeiro, apenas irá quebrar no if do chute correto
	// while (1) {
	for (int i = 1; i <= numero_de_tentativas; i++) {
		printf("\n");
		printf("* Tentativa %d *\n", tentativas);
		printf("\n");

		printf("Qual é o seu chute? ");
		scanf("%d", &chute);
		printf("Seu chute foi %d!\n", chute); 

		int repetido = 0;
	        for (int i = 0; i < numero_de_tentativas; i++) {
	            if (historico_chutes[i] == chute) {
	                printf("Você já chutou esse número. Tente outro!\n");
	                repetido = 1;
	                break;
	            }
        }

        if (repetido) {
            continue;
        }

        historico_chutes[tentativas - 1] = chute;

		if (chute < 0) {

			printf("Você não pode chutar números negativos!\n");
			printf("Relax, você não perdeu nenhuma tentativa :)\n");
			// i--;

			// o for loop continua sem executar o resto do bloco, também funciona no while
			continue;

		} else if (chute == numero_secreto) {

			// printf("Parabéns, você acertou! :)\n");

			// parar de executar o for loop
			break;
			// ganhou = 1;

		} else if (chute > numero_secreto) {

			printf("Você disse um número maior.\n");
			printf("Tente de novo :|\n");

		} else if (chute < numero_secreto) {

			printf("Você disse um número menor.\n");
			printf("Tente de novo :|\n");

		} else {

			printf("Você errou :(\n");

		}
		tentativas++;

		// abs função para converter número negativo para positivo
		double diferenca = abs((chute - numero_secreto)) / (double) 2;
		pontos = pontos - diferenca;
	}

	printf("\n");
	printf("FIM DE JOGO!\n");

	if (chute == numero_secreto) {

		printf("\n");
		printf("********** VOCÊ GANHOU ********\n");
		printf("* Você acertou em %d tentativas *\n", tentativas);
		printf("********* Pontos: %.1f ********\n", pontos);
		printf("\n");

	} else {

		printf("\n");
		printf("Você perdeu\n");
		printf("Tente de novo :|\n");
		printf("O número secreto era %i.\n", numero_secreto);
		printf("\n");

	}
}