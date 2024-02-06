/*
 * Feito por Estevao Augusto da Fonseca Santos
 * Criado em 19/12/2023
 * Ultima modificação: 22/12/2023
 */


#include <iostream>
#include <time.h>
#include <limits>
#include <cstdlib>
#include <locale.h>

using namespace std;


void verificarValor(int &resp){ //checara se o valor eh de fato um inteiro
	while (cin.fail() || cin.peek() != '\n') {
		cout << "Entrada invalida. Digite um numero inteiro." << endl;
		cin.clear();  // Limpa o estado de erro
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta a entrada inválida
		cout << "Sua resposta: ";
		cin >> resp;
   }
}

void iniciarJogo(){// o jogo sera iniciado aqui
	int escolha_player, escolha_cpu;
    int player = 0, cpu = 0;

    cout << "Melhor de 3!" << endl;

    do{
        cout << "Player: " << player << "         CPU: " << cpu << endl << endl;

        cout << "0) Pedra" << endl;
        cout << "1) Papel" << endl;
        cout << "2) Tesoura" << endl << endl;

        do{
            cout <<  "Sua escolha: ";
            cin >> escolha_player;
        }while(escolha_player < 0 || escolha_player > 2);
        escolha_cpu = rand()%3;

        if(escolha_cpu == escolha_player){
            cout << "Player escolheu " << escolha_player << endl;
			cout << "CPU escolheu " << escolha_cpu << endl;
			cout << "Deu empate!!" << endl << endl;
        } else {
            if(escolha_player == 0){
                cout << "Player escolheu " << escolha_player <<  " (Pedra)" << endl;
				if(escolha_cpu == 1){
					cout << "CPU escolheu " << escolha_cpu <<  " (Papel)" << endl;
					cout << "CPU venceu!"<< endl;
					cpu++;
                } else {
					cout << "CPU escolheu " << escolha_cpu <<  " (Tesoura)" << endl;
					cout << "Player venceu!" << endl;
					player++;
                }
            } else if(escolha_player == 1){
                cout << "Player escolheu " << escolha_player <<  " (Papel)" << endl;
                if(escolha_cpu == 0){
                    cout << "CPU escolheu " << escolha_cpu <<  " (Pedra)" << endl;
					cout << "Player venceu!" << endl;
					player++;
                } else {
					cout << "CPU escolheu " << escolha_cpu <<  " (Tesoura)" << endl;
					cout << "CPU venceu!"<< endl;
					cpu++;
                }
            } else if(escolha_player == 2){
				cout << "Player escolheu " << escolha_player <<  " (Tesoura)" << endl;
                if(escolha_cpu == 0){
                    cout << "CPU escolheu " << escolha_cpu <<  " (Pedra)" << endl;
					cout << "CPU venceu!" << endl;
					cpu++;
                } else {
					cout << "CPU escolheu " << escolha_cpu <<  " (Pedra)" << endl;
					cout << "Player venceu!" << endl;
					player++;
                }
            }
        }
	}while(cpu <= 3 && player <= 3);
	if(cpu == 4){
		cout << "cpu eh o ganhador! " << endl;
	} else {
		cout << "player eh o ganhador!" << endl;
	}
    
}


int main(){
	char opcao;
	setlocale(LC_ALL, "");
	srand(time(0));
	    
	do{
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "      Pedra-Papel-Tesoura!" << endl;
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl << endl;
		
		cout << "s - [Sair]       i - [iniciar]" << endl << endl;
		
		cout << "Resposta: ";
		cin >> opcao;
		
		switch(opcao){
			case 's':{
				break;
			}
			case 'i':{
				cout << endl;
                iniciarJogo();
				break;
			}
			default:{
				cout << "Opcao inexistente" << endl;
			}
		}
	}while(opcao != 's');
	
	return 0;
}