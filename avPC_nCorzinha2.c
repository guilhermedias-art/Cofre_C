#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//padrão para alcançar a senha correta
/*
	1) 15
	2) 10
	3) 15
	4) 10
	5) 15
	6) 10
*/

int main(){
	int barra[25], count[7], verificador, pos_at, pos_nv, direcao, deslizes, chances = 3, i;
	const int senha[7] = {6,3,0,3,6,6,6};
	
	barra[0] = 0;
	for(i = 1; i < 25; i++){
		switch(barra[i - 1]){
			case 0:
				barra[i] = 1;
				break;

			case 1:
				barra[i] = 3;
				break;

			case 3:
				barra[i] = 4;
				break;

			case 4:
				barra[i] = 6;
				break;

			case 6:	
				barra[i] = 7;
				break;

			case 7:
				barra[i] = 9;
				break;

			case 9:
				barra[i] = 0;
				break;
		}
	}
	
	while(chances > 0){
		pos_at = 10;
		deslizes = 6;
		verificador = 0;
		
		count[0] = 0;
		count[1] = 0;
		count[2] = 0;
		count[3] = 0;
		count[4] = 0;
		count[5] = 0;
		count[6] = 0;
		
		system("cls");
		printf("\033[0;36m");
		printf("~ CHANCES: %d ~", chances);
		printf("\033[0m");
		
		while(deslizes > 0){
			printf("\n+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+");
			printf("\n|");
			for(i = 1; i <= 25; i++){
				if(i == pos_at){
					printf("\033[0;33m");
					printf(" [%2d]", i);
					printf("\033[0m");
					printf(" |");
				}else{
					printf("  %2d  |", i);
				}
			}
			printf("\n+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+");
			printf("\n|");
			for(i = 0; i < 25; i++){
				if(i == pos_at - 1){
					printf("\033[0;33m");
					printf(" [%2d]", barra[i]);
					printf("\033[0m");
					printf(" |");
				}else{
					printf("  %2d  |", barra[i]);
				}
			}
			printf("\n+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
			
			printf("\033[0;36m");
			printf("~ DESLIZES RESTANTES: %d ~\n", deslizes);
			printf("\033[0m");
			
			printf("Insira a proxima posicao na barra (entre 1 e 25): ");
			scanf("%d", &pos_nv);
			
			while(pos_nv < 1 || pos_nv > 25 || pos_nv == pos_at){
				printf("\033[1;31m");
				printf("Valor invalido. Insira novamente: ");
				printf("\033[0m");
				scanf("%d", &pos_nv);
			}
			
			if(pos_at > pos_nv){
				direcao = -1;
			}else{
				direcao = 1;
			}
			
			for(i = pos_at; i != (pos_nv + direcao); i += direcao){
				if(i!=pos_at){
					switch(barra[i]){
						case 0:
							count[0]++;
							break;
						case 1:
							count[1]++;
							break;
						case 3:
							count[2]++;
							break;
						case 4:
							count[3]++;
							break;
						case 6:
							count[4]++;
							break;
						case 7:
							count[5]++;
							break;
						case 9:
							count[6]++;
							break;
					}
				}
			}
			
			pos_at = pos_nv;
			deslizes--;
		}
		chances--;
		
		for(i = 0; i < 7; i++){
			if(count[i] == senha[i]){
				verificador++;
			}
		}
		
		if(verificador == 7){
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
			printf("\n|");
			for(i = 1; i <= 25; i++){
				if(i == pos_at){
					printf("\033[0;33m");
					printf(" [%2d]", i);
					printf("\033[0m");
					printf(" |", i);
				}else{
					printf("  %2d  |", i);
				}
			}
			
			printf("\n|");
			for(i = 0; i < 25; i++){
				if(i == pos_at - 1){
					printf("\033[0;33m");
					printf(" [%2d]", barra[i]);
					printf("\033[0m");
					printf(" |");
				}else{
					printf("  %2d  |", barra[i]);
				}
			}
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			chances = -1;
		}
	}
	
	if(verificador == 7){
		printf("\033[1;32m");
		printf("\n -------------------------------------------");
		printf("\n | SUCESSO - SENHA CORRETA!: %d-%d-%d-%d-%d-%d-%d |", count[0], count[1], count[2], count[3], count[4], count[5], count[6]);
		printf("\n -------------------------------------------");
		printf("\033[0m");
	}else{
		printf("\033[1;31m");
		printf("\n ----------------------------");
		printf("\n | FALHA - SENHA INCORRETA! |");
		printf("\n ----------------------------");
		printf("\033[0m");
		exit(0);
	}
}
