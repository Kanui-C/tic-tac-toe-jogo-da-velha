#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void imprime(char velha[3][3]){
		system("clear");
	printf(" %c  | %c  | %c \n", velha[0][0], velha[0][1], velha[0][2]);
	printf("----|----|---\n");
	printf(" %c  | %c  | %c \n", velha[1][0], velha[1][1], velha[1][2]);
	printf("----|----|---\n");
	printf(" %c  | %c  | %c \n",velha[2][0], velha[2][1], velha[2][2]);
}
void verifica();
void ganhador();
void ascii(){
printf("       ______  __________     ____  ___       _    __________    __  _____ \n");
printf("      / / __ \\/ ____/ __ \\   / __ \\/   |     | |  / / ____/ /   / / / /   |\n");
printf(" __  / / / / / / __/ / / /  / / / / /| |     | | / / __/ / /   / /_/ / /| |\n");
printf("/ /_/ / /_/ / /_/ / /_/ /  / /_/ / ___ |     | |/ / /___/ /___/ __  / ___ |\n");
printf("\\____/\\____/\\____/\\____/  /_____/_/  |_|     |___/_____/_____/_/ /_/_/  |_|\n");
                                                                           
}
int main(){

	char velha[3][3] = { {'1','2','3'},
						 {'4','5','6'},
						 {'7','8','9'}, };
	char res;
	int casas=1,l,c,vez,vencedor;

	do{
		for(int i = 0;i<3;i++)
			for(int x = 0; x < 3; x++){
				velha[i][x] = ' ';
			}
		do{
			imprime(velha);
			if(vez%2==0)
				printf("Jogador X\n");
			else
				printf("Jogador O\n");
			printf("Digite a linha: ");
			scanf("%i", &l);
			printf("Digite a coluna: ");
			scanf("%i", &c);
			if(l < 1 || c < 1 || l > 3 || c > 3){
				l = 0;
				c = 0;
			}else if(velha[l-1][c-1] != ' '){
				l = 0;
				c = 0;
			}else{
				if(vez%2==0){
					velha[l-1][c-1] = 'X';
				}else
					velha[l-1][c-1] = 'O';
				vez++;
				casas++;
			}
			ganhador();
			verifica();

		}while(casas<=9);
		ganhador();
	}while(res == 's' || res == 'S');
}
void ganhador(){
			if(casas == 11){
			system("clear");
			imprime(velha);
			printf("\nX venceu !\n");
		}
		if(casas == 12){
			system("clear");
			imprime(velha);
			printf("\nO venceu !\n");
		}
		printf("Jogar Novamente?[S-N]:");
		setbuf(stdin,NULL);
		scanf("%c", &res);
}


void verifica(){
			// X 

			//linhas
			if(velha[0][0] == 'X' && velha[0][1] == 'X' && velha[0][2] == 'X'){ casas = 11;}
			if(velha[1][0] == 'X' && velha[1][1] == 'X' && velha[1][2] == 'X'){ casas = 11;}
			if(velha[2][0] == 'X' && velha[2][1] == 'X' && velha[2][2] == 'X'){ casas = 11;}
			//colunas
			if(velha[0][0] == 'X' && velha[1][0] == 'X' && velha[2][0] == 'X'){ casas = 11;}
			if(velha[0][1] == 'X' && velha[1][1] == 'X' && velha[2][1] == 'X'){ casas = 11;}
			if(velha[0][2] == 'X' && velha[1][2] == 'X' && velha[2][2] == 'X'){ casas = 11;}
			//diagonais
			if(velha[0][0] == 'X' && velha[1][1] == 'X' && velha[2][2] == 'X'){ casas = 11;}
			if(velha[0][2] == 'X' && velha[1][1] == 'X' && velha[2][0] == 'X'){ casas = 11;}

			//BOLINHA

			//linhas
			if(velha[0][0] == 'O' && velha[0][1] == 'O' && velha[0][2] == 'O'){ casas = 12;}
			if(velha[1][0] == 'O' && velha[1][1] == 'O' && velha[1][2] == 'O'){ casas = 12;}
			if(velha[2][0] == 'O' && velha[2][1] == 'O' && velha[2][2] == 'O'){ casas = 12;}
			//colunas
			if(velha[0][0] == 'O' && velha[1][0] == 'O' && velha[2][0] == 'O'){ casas = 12;}
			if(velha[0][1] == 'O' && velha[1][1] == 'O' && velha[2][1] == 'O'){ casas = 12;}
			if(velha[0][2] == 'O' && velha[1][2] == 'O' && velha[2][2] == 'O'){ casas = 12;}
			//diagonais
			if(velha[0][0] == 'O' && velha[1][1] == 'O' && velha[2][2] == 'O'){ casas = 12;}
			if(velha[0][2] == 'O' && velha[1][1] == 'O' && velha[2][0] == 'O'){ casas = 12;}
}