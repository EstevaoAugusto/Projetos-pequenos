/*
 * Feito por Estevao Augusto da Fonseca Santos
 * Criado em 04/01/2024
 * Ultima modificação: 04/01/2024
 */

#include <iostream>

using namespace std;

void piramide_inversa(int tamanho){
	int espacos = 0;
	int asteriscos = tamanho*2 - 1;
		
	for(int i = 1; i <= tamanho; i++){
		for(int a = 1; a <= asteriscos; a++){
			cout << "*"; 
	}
		cout << endl;
		asteriscos -= 2;
		espacos++;
		for(int a = 1; a <= espacos; a++){
			cout << " ";
		}
	}
	cout << endl;
}

int main(){
	int tamanho;
	
	do{
		cin >> tamanho;	
	}while(tamanho < 1);
	
	piramide_inversa(tamanho);	
	
	
	return 0;
}
