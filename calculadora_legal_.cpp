#include <iostream>
using namespace std;
//Calculadora de matrizes

/*	Nome: Estevão Augusto da Fonseca Santos
 * 	Data de criação: 30/07/2023
 * 	Data de ultima alteração: 30/07/2023
 *  Versao  1.0
 * 	
 */	

void subtrair(int **mat1, int **mat2){
	int **soma = NULL;
	soma = new int*[3];
	
	for(int i = 0; i < 3; i++){
		soma[i] = new int[3];
	}
	
	for(int l = 0; l < 3; l++){
		for(int c = 0; c < 3; c++){
			soma[l][c] = 0;
			soma[l][c] += mat1[l][c] - mat2[l][c];
			cout << soma[l][c] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void somar(int **mat1, int **mat2){
	int **soma = NULL;
	soma = new int*[3];
	
	for(int i = 0; i < 3; i++){
		soma[i] = new int[3];
	}
	
	for(int l = 0; l < 3; l++){
		for(int c = 0; c < 3; c++){
			soma[l][c] = 0;
			soma[l][c] += mat1[l][c] + mat2[l][c];
			cout << soma[l][c] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void preencher(int **mat1, int **mat2){
	cout << "======================================" << endl;
	cout << "Matriz 1" << endl << endl;
	
	for(int l = 0; l < 3; l++){
		for(int c = 0; c < 3; c++){
			cout << "Linha " << l << " Coluna " << c << ":";
			cin >> mat1[l][c];
		}
	}
	cout << "====================================" << endl;
	cout << "Matriz 2" << endl << endl;
	
	for(int l = 0; l < 3; l++){
		for(int c = 0; c < 3; c++){
			cout << "Linha " << l << " Coluna " << c << ":";
			cin >> mat2[l][c];
		}
	}
	cout << endl << endl;
}

int calculos(int **mat1, int **mat2, int c){
	
	return 0;
}

void multiplicar(int **mat1, int **mat2){
	int **soma = NULL;
	soma = new int*[3];
	
	for(int i = 0; i < 3; i++){
		soma[i] = new int[3];
	}
	
	for(int l = 0; l < 3; l++){
		for(int c = 0; c < 3; c++){
			soma[l][c] = 0;
		}
	}
	
	for(int c = 0; c < 3; c++){
		for(int l = 0; l < 3; l++){
			soma[l][c] = calculos(mat1, mat2, c);
		}
	}
	
	
	
}

int main(){
	
	int **mat1 = NULL;
	mat1 = new int*[3];
	
	for(int i = 0; i < 3; i++){
		mat1[i] = new int[3];
	}
	
	int **mat2 = NULL;
	mat2 = new int*[3];
	
	for(int i = 0; i < 3; i++){
		mat2[i] = new int[3];
	}
	
	preencher(mat1, mat2);
	
	bool saida = false;
	int opcao = 0;
	
	do{
		for(int l = 0; l < 3; l++){ 
			for(int c = 0; c < 3; c++){ 
				cout << mat1[l][c] << " ";
			}
			cout << "        ";
			for(int c = 0; c < 3; c++){ 
				cout << mat2[l][c] << " ";
			}
			cout << endl;
		}
		cout << endl;
		
		
		cout << "1)Somar" << endl;
		cout << "2)Subtrair" << endl;
		cout << "3)Multiplicar" << endl;
		cout << "4)Inverter" << endl;
		cout << "5)Editar matrizes" << endl;
		cout << "0)Sair" << endl;
		cout << "=============================" << endl;
		cout << "Resposta: ";
		
		
		cin >> opcao;
		
		switch(opcao){
			case 0:
				saida = true;
				break;
			case 1:
				somar(mat1, mat2);
				break;
			case 2:
				subtrair(mat1, mat2);
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			default:
				cout << "Opcao inexistente" << endl << endl;
		}
	}while(saida != true);
	
	return 0;
}
