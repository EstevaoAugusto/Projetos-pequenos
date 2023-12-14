#include <iostream>

using namespace std;

const int hexBase = 16;
const int octBase = 8;
const int binBase = 2;


class noh{
	friend class pilha;
	private:
		int numero;
		noh* proximo;
	public:
		noh(int n);
};

noh::noh(int n){
	proximo = NULL;
	numero = n;
}

class pilha{
	private:
		int tamanho;
		noh* topo;
	public:
		pilha();
		~pilha();
		void empilhar(int n);
		int desempilhar();
		int verTopo() { return topo->numero;};
		void converterBinario(int &binario);
		void converterDecimal(int &decimal, int tipo);
		bool vazio() { return (topo == NULL);};
};

void pilha::converterBinario(int &binario){
	
	while(binario / 10 > 0){
		empilhar(binario % 10);
		binario = binario / 10;
	}
	empilhar(binario % 10);
	
}

void pilha::converterDecimal( int &decimal, int tipo){
	
	if(decimal / tipo > 0){
		empilhar(decimal % tipo);
		decimal = decimal / tipo;
		converterDecimal(decimal,tipo);
	} else {
		empilhar(decimal % tipo);
	}
}

pilha::~pilha(){
	while(!vazio()){
		desempilhar();
	}
	delete topo;
}

pilha::pilha(){
	tamanho = 0;
	topo = NULL;
}

void pilha::empilhar(int n){
	if(vazio()){
		noh* novo = new noh(n);
		topo = novo;
	} else {
		noh* novo = new noh(n);
		novo->proximo = topo;
		topo = novo;
	}
	tamanho++;
}

int pilha::desempilhar(){
	if(! vazio()){
		noh* aux = NULL;
		aux = topo;
		topo = topo->proximo;
		int num = aux->numero;
		delete aux;
		
		tamanho--;
		return num;
	}
	return -1;
}

void opcaoOctal(pilha& c){
	char opcao;
	
	do{
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "       Como deseja converter?" << endl;
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl<< endl;
	
		cout << "0) Sair" << endl;
		cout << "1) Converter Decimal para Octal" << endl;
		cout << "2) Converter Octal para Decimal" << endl << endl;
		
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "Sua resposta: ";
		cin >> opcao;
		cout << endl;
		switch(opcao){
			case '0':{
				break;
			}
			case '1':{
				int decimal;
				
				do{
					cin >> decimal;
				}while(decimal < 0);
				
				c.converterDecimal(decimal, octBase);
				
				int n;
				while(! c.vazio()){
					n = c.desempilhar();
					cout << n;
				}
				cout << endl << endl;;
				
				break;
			}
			case '2':{
				break;
			}
			default: {
				
			}
		}
	}while(opcao != '0');
}

void opcaoHex(pilha& c){
	char opcao;
	
	do{
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "       Como deseja converter?" << endl;
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl<< endl;
	
		cout << "0) Sair" << endl;
		cout << "1) Converter Decimal para Hexadecimal" << endl;
		cout << "2) Converter Hexadecimal para Decimal" << endl << endl;
		
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "Sua resposta: ";
		cin >> opcao;
		cout << endl;
		switch(opcao){
			case '0':{
				break;
			}
			case '1':{
				int decimal;
				do{
					cin >> decimal;
				}while(decimal < 0);
				c.converterDecimal(decimal, hexBase);
				
				int n;
				while(! c.vazio()){
					n = c.desempilhar();
					if(n == 10){ //10
						cout << "A";
					} else if(n == 11){ //11
						cout << "B";
					} else if(n == 12){ //12
						cout << "C";
					} else if(n == 13) { //13
						cout << "D";
					} else if(n == 14) {// 14
						cout << "E";
					} else if(n == 15) { //15
						cout << "F";
					} else {
						cout << n;
					}
				}
				cout << endl;
				
				break;
			}
			case '2':{
				break;
			}
			default: {
				cout << "Opcao inexistente" << endl;
			}
		}
	}while(opcao != '0');
}

void opcaoBin(pilha& c){
	char opcao;
	
	do{
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "       Como deseja converter?" << endl;
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl<< endl;
	
		cout << "0) Sair" << endl;
		cout << "1) Converter Decimal para Binario" << endl;
		cout << "2) Converter Binario para Decimal" << endl << endl;
		
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "Sua resposta: ";
		cin >> opcao;
		cout << endl;
		switch(opcao){
			case '0':{
				break;
			}
			case '1':{
				int decimal;
				do{
					cin >> decimal;
				}while(decimal < 0);
				c.converterDecimal(decimal, binBase);
				
				
				int n;
				while(! c.vazio()){
					n = c.desempilhar();
					cout << n;
				}
				cout << endl << endl;
				break;
			}
			case '2':{
				int bin;
				do{
					cin >> bin;
				}while(bin < 0);
				
				c.converterBinario(bin);
				
				while(! c.vazio()){
					cout << c.desempilhar();
				}
				cout << endl << endl;
				break;
			}
			default: {
				cout << "Opcao inexistente" << endl;
			}
		}
	}while(opcao != '0');
}

int main(){
	pilha controle;
	char opcao;
	
	do{
		
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "	  Conversor de valores" << endl;
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl << endl;
		
		cout << "0) Sair" << endl;
		cout << "1) Binario" << endl;
		cout << "2) Hexadecimal" << endl;
		cout << "3) Octal" << endl << endl;
		
		cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
		cout << "Sua resposta: ";
		cin >> opcao;
		cout << endl;
		
		switch(opcao){
			case '0':{
				break;
			}
			case '1':{
				opcaoBin(controle);
				break;
			}
			case '2':{
				opcaoHex(controle);
				break;
			}
			case '3':{
				opcaoOctal(controle);
				break;
			}
			default:{
				cout << "Opcao inexistente" << endl;
			}
		}
	}while(opcao != '0');
	
	return 0;
}
