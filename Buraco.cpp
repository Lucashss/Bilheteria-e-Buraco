#include <iostream>
#include <stdlib.h>
#include <string>
#include<time.h>

using namespace std;

int main()
{
	/*
	2. Projeto Buraco:

Objetivo: 

Criar em memória uma representação para cada uma das 52 cartas de um baralho (x 2 baralhos) para serem utilizadas em um jogo de Buraco.

O programa deverá "distribuir" aleatoriamente as cartas (11 cartas para cada um dos 4 jogadores participantes). Encerra a proposta com a apresentação das "mãos" de cada jogador.

Notação para a identificação da carta:

N-99-B = Onde:

N  -> Naipe (1-Copas / 2-Paus / 3-Ouro / 4-Espada)
99 -> Número da carta (01-Ás / 13-Rei)
B  -> Baralho (1 ou 2)
Exemplo:

4-10-2  ->  10 de espada do baralho 2
	*/
	
	int cartas[4][26];
	int naipe[4] = {26, 26, 26, 26};
	int baralho;
	int car;
	bool repetida = false;

	srand(time(NULL));

	for(int i = 0; i < 4; i++)
	{
		for(int x = 0; x < 26; x++)
		{
			cartas[i][x] = 0;
		}
	}

	for(int i = 0; i < 4; i++)
	{
		for(int x = 0; x < 11; x++)
		{

			do
			{
				repetida = false;
				baralho = rand() % (4 + 1 - 1) + 1;

				if(naipe[baralho - 1] == 0)
				{
					repetida = true;
				}
				else
				{

					car = rand() % (26 + 1 - 1) + 1;

					if(cartas[baralho - 1][car - 1] != 0)
					{
						repetida = true;
					}
					else
					{
						cartas[baralho - 1][car - 1] = i + 1;
						naipe[baralho - 1]--;
					}
				}
			}
			while(repetida);

		}
	}

	for(int i = 0; i < 4; i++)
	{
		cout << "Player " << i + 1 << endl;
		cout << endl;
		
		for(int y = 0; y < 4; y++)
		{
			for(int x = 0; x < 26; x++)
			{
				if(cartas[y][x] == i + 1)
				{

					if(x > 13)
					{
						if(x - 12 >= 10)
						{
							cout << y + 1 << "-" << x - 12 << "-2 / ";
						}
						else
						{
							cout << y + 1 << "-" << "0" << x - 12 << "-2 / ";
						}
					}
					else
					{
						if(x + 1 >= 10)
						{
							cout << y + 1 << "-" << x + 1 << "-1 / ";
						}
						else
						{
							cout << y + 1 << "-" << "0" << x + 1 << "-1 / ";
						}
					}
				}
			}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}

	return 0;
}
