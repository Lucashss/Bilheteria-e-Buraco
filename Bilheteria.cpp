#include <iostream>
#include <stdlib.h>
using namespace std;

/*
1. Projeto Bilheteria:

Um teatro possui 600 lugares dispostos em 15 fileiras com 40 poltronas cada.

Deseja-se um sistema de controle de ocupação que ofereça as seguintes opções, através de um seletor:

0.	Finalizar
1.	Reservar poltrona
2.	Mapa de ocupação
3.	Faturamento
A opção 1 deverá solicitar a informação da fileira e da poltrona. Os dados devem ser consistidos no sentido
da garantia de serem válidos. Caso o lugar esteja vago, efetuar a reserva e informar o usuário do sucesso da
operação. Caso o lugar já se encontre ocupado, alertar o usuário com uma mensagem.

A opção 2 deverá gerar na tela um “mapa” de ocupação do teatro com uma legenda onde:

‘.’ representa lugar vago
‘#’ representa lugar ocupado
A opção 3 deverá apresentar na tela as seguintes informações:

Qtde de lugares ocupados: 	999
Valor da bilheteria: 		R$ 9999,99
Sabendo-se que:

Fileiras 1 a 5:       R$ 50,00
Fileiras 6 a 10:     R$ 30,00
Fileiras 11 a 15:   R$ 15,00
*/

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	bool bk[15][40];
	int cont = 0;
	int cont1 = 0;
	int cont2 = 0;
	int cont3 = 0;
	int vt = 0;
	string imp;
	int opcao = 4;
	int fileira = 0;
	int poltrona = 0;

	for(int i = 0; i < 15; i++)
	{
		for(int x = 0; x < 40; x++)
		{
			bk[i][x] = 0;
		}
	}

	for (int x = 0; opcao != 0; x++)
	{
		system("cls");
		cout << "0. Finalizar." << endl;
		cout << "1. Reservar poltrona." << endl;
		cout << "2. Mapa de ocupação." << endl;
		cout << "3. Faturamento." << endl;
		cout << endl;
		cout << "Informe sua opção.: ";
		cin >> opcao;

		if (opcao == 1)
		{
			do
			{
				system("cls");
				cout << "Digite a fileira desejada (1 a 15)" << endl;
				cin >> fileira;
			}
			while(fileira < 1 || fileira > 15);
			do
			{
				system("cls");
				cout << "Digite a poltrona desejada (1 a 40)" << endl;
				cin >> poltrona;
			}
			while(poltrona < 1 || poltrona > 40);

			if(fileira > 0 && fileira < 6)
			{
				cont1++;
			}
			if(fileira > 5 && fileira  < 11)
			{
				cont2++;
			}
			if(fileira > 10 && fileira < 16)
			{
				cont3++;
			}

			if(bk[fileira - 1][poltrona - 1] != 1)
			{
				system("cls");
				bk[fileira - 1][poltrona - 1] = 1;
				cont++;
				cout << "Assento reservado com sucesso!" << endl;
				system("PAUSE");
			}
			else
			{
				cout << "Assento ocupado!" << endl;
				system("PAUSE");
			}
		}
		if (opcao == 2)
		{

			system("cls");
			cout << "|==================================================================================================================================================================|" << endl;
			cout << "|                                                                      MAPA DE OCUPAÇÃO                                                                            |" << endl;
			cout << "|==================================================================================================================================================================|" << endl;
			cout << "|                                                                         Poltronas                                                                                |" << endl;
			cout << "|------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;


			for(int i = 0; i < 15; i++)
			{

				if(i == 0)
				{
					for(int x = 0; x < 40; x++)
					{
						if(x < 9)
						{
							if(x == 0)
							{
								cout << "00 -";
							}
							cout << " 00" << x + 1;
						}
						else
						{
							cout << " 0" << x + 1;
						}
					}
					cout << endl;
				}

				if(i < 9)
				{
					cout << "0" << i + 1 << " -";
				}
				else
				{
					cout << i + 1 << " -";
				}

				for(int x = 0; x < 40; x++)
				{

					if(bk[i][x] == 0)
					{
						cout << " |.|";
					}
					else
					{
						cout << " |#|";
					}
				}
				cout << endl;
			}
			cout << endl;
			system("PAUSE");
		}

		if (opcao == 3)
		{
			system("cls");
			vt = (cont1 * 50) + (cont2 * 30) + (cont3 * 15);
			cout << "Quantidade de assentos ocupados: " << cont << endl;
			cout << "Valor total da bilheteria: R$ " << vt << ",00" << endl;
			system("PAUSE");
		}
	}
	return 0;
}

