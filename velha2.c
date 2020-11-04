#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
//FEITO POR K4NU1

void tabuleiro(char tabuleiro[3][3]){
	printf(" %c | %c | %c \n", tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);
}


int main(void){
	int linha,coluna,casas=0,vez;
	char velha[3][3] = {{'0','1','2'},{'3','4','5'},{'6','7','8'}};
	char res;
	
	do{
		int casas = 0;
		int vez = 0;
		printf("JOGO DA VELHA 0.1\nSEJA BEM VINDO!\n");
		for(int i = 0;i <= 2;i++)
			for(int j = 0;j<=2;j++)
				velha[i][j] = ' ';
		do{
			system("clear");
			tabuleiro(velha);
			if(vez % 2 == 0) printf("Jogador: X\n");
			else printf("Jogador: O");
			printf("\nLinha:");
			scanf("%i", &linha);
			printf("\nColuna:");
			scanf("%i", &coluna);
			if(linha > 3 || linha < 0 || coluna > 3 || coluna < 0){
				linha = 0;
				coluna = 0;
			}
			else if(velha[linha-1][coluna-1] != ' '){
				linha = 0;
				coluna = 0;
			}
			else{
				if(vez % 2 == 0)
					velha[linha-1][coluna-1] = 'X';
				else
					velha[linha-1][coluna-1] = 'O';
				
			casas++;
			vez++;
			}
			
			//VERIFICAÇAO X
			//Linhas
			if(velha[0][0] == 'X' && velha[0][1] == 'X' && velha[0][2] == 'X') casas = 11;
			if(velha[1][0] == 'X' && velha[1][1] == 'X' && velha[1][2] == 'X') casas = 11;
			if(velha[2][0] == 'X' && velha[2][1] == 'X' && velha[2][2] == 'X') casas = 11;

			//colunas
			if(velha[0][0] == 'X' && velha[1][0] == 'X' && velha[2][0] == 'X') casas = 11;
			if(velha[0][1] == 'X' && velha[1][1] == 'X' && velha[2][1] == 'X') casas = 11;
			if(velha[0][2] == 'X' && velha[1][2] == 'X' && velha[2][2] == 'X') casas = 11;

			//Diagonais
			if(velha[0][0] == 'X' && velha[1][1] == 'X' && velha[2][2] == 'X') casas = 11;
			if(velha[0][2] == 'X' && velha[1][1] == 'X' && velha[2][0] == 'X') casas = 11;

			//Verificaçao O
			//Linhas
			if(velha[0][0] == 'O' && velha[0][1] == 'O' && velha[0][2] == 'O') casas = 12;
	    		if(velha[1][0] == 'O' && velha[1][1] == 'O' && velha[1][2] == 'O') casas = 12;
			if(velha[2][0] == 'O' && velha[2][1] == 'O' && velha[2][2] == 'O') casas = 12;
			//colunas
		        if(velha[0][0] == 'O' && velha[1][0] == 'O' && velha[2][0] == 'O') casas = 12;
		        if(velha[0][1] == 'O' && velha[1][1] == 'O' && velha[2][1] == 'O') casas = 12;
		        if(velha[0][2] == 'O' && velha[1][2] == 'O' && velha[2][2] == 'O') casas = 12;

		         //Diagonais
		        if(velha[0][0] == 'O' && velha[1][1] == 'O' && velha[2][2] == 'O') casas = 12;
		        if(velha[0][2] == 'O' && velha[1][1] == 'O' && velha[2][0] == 'O') casas = 12;


		}while(casas < 9);
		system("clear");
		tabuleiro(velha);
		if(casas == 11){ system("clear"); printf("X venceu!"); }
		if(casas == 12){ system("clear"); printf("O venceu!"); }
		if(casas != 11 && casas != 12){
			printf("Velha!");
		}
		printf("\nDESEJA JOGAR NOVAMENTE? {s/n}\nDIGITE:");
		setbuf(stdin, NULL);
		scanf("%c", &res);
	}while(res == 's' || res == 'S');
	printf("Projeto feito em 1 hora por Kanui Matoi\n");
	return 0;
	
}
