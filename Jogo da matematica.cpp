/*
 * Feito por Estevao Augusto da Fonseca Santos
 * Criado em 19/12/2023
 */


#include <iostream>
#include <time.h>
#include <limits>
#include <cstdlib>
#include <locale.h>

using namespace std;

const int divisor = 10;

unsigned gerarNumeros(){ //ira retornar valores de 0 a ate divisor-1
	return rand()%divisor;
}

void verificarValor(int &resp){ //checara se o valor eh de fato um inteiro
	while (cin.fail() || cin.peek() != '\n') {
		cout << "Entrada inválida. Digite um número inteiro." << endl;
		cin.clear();  // Limpa o estado de erro
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta a entrada inválida
		cout << "Sua resposta: ";
		cin >> resp;
   }
}

void iniciarJogo(){
	
	int questao = 1;
	int vidas = 3;
	int pontos = 0, resp;
	int valor1 = gerarNumeros(), valor2 = gerarNumeros();
	
	while(vidas > 0){ //o jogo termina quando a quantidade de vidas acabar
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "Vidas: " << vidas << endl;
		cout << "Questao " << questao << ": " << valor1 << " + " << valor2 << " = ?" << endl;
		cout << "Sua resposta: ";
		cin >> resp;
		verificarValor(resp); 
		cout << endl;
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		
		if(resp != valor1 + valor2){ 
			//caso a resposta esteja incorreta, havera perda de uma vida
			cout << "Sua resposta esta incorreta. Tente novamente" << endl << endl;
			cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
			vidas--;
		} else {
			//caso a resposta esteja correta, havera ganho de pontos
			cout << "Sua resposta esta correta! " << endl;
			pontos += 10;
			valor1 = gerarNumeros();
			valor2 = gerarNumeros();
			questao++;
			if(pontos % 100 == 0){ vidas++;} //se pontos for multiplo de 100, entao havera um ganho de vida
		}
	}
	cout << "Fim de jogo" << endl;
	cout <<"Pontuacao: " << pontos << endl << endl;
	
}


int main(){
	char opcao;
	setlocale(LC_ALL, "");
	srand(time(0));
	    
	do{
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "      Jogo da Matematica" << endl;
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
