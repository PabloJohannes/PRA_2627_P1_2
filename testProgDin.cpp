#include <iostream>
#include <vector>
#include "ProgDin.h"

using namespace std;


int main (void){
	
	//testear función monedas:
	cout << "TEST FUNCIÓN MONEDAS" << "\n\n";
	int d = 8;
	vector<int> monedas = {1,4,6};
	vector<int> salida = {};
	cout << "La cantidad de dinero a devolver es: " << d << endl; 
	cout << "Y los tipos de moneda que hay son: ";
	for (int i= 0; i < monedas.size(); i++){
		cout << monedas[i] << " ";
	}
	cout << endl;
	cout << "Tras llamar a la función cambioMonedas, ésta ha calculado la siguiente tabla: \n";
	int c = cambioMonedas(d,monedas,salida);
	cout << "Ha calculado que la cantidad mínima de monedas que se necesitan es: " << c << endl;
	cout << "Usando la siguiente combinación de monedas: \n";
	for(int j= 0; j < salida.size(); j++){
		if(salida[j] != 0){
			cout << "  " << salida[j] << " monedas de " << monedas[j] << endl;
		}
	}






	cout << "\n\n\n\n";


	//testear función mochila
	cout << "TEST FUNCIÓN MOCHILA" << "\n\n";
	vector<int> pesos = {9,6,5};
	vector<int> beneficios = {38,40,24};
	int M = 15;
	vector<int> eleccion(pesos.size(),0);
	cout << "La capacidad máxima que tiene la mochila es: " << M << endl;
	cout << "Los objetos disponibles son: \n";
	for(int i=0; i<pesos.size(); i++){
		cout << "Objeto " << (i+1) << ": peso: " << pesos[i] << " beneficio: " << beneficios[i] << endl;
	}
	cout << "Tras llamar a la función mochila, ésta ha calculado la siguiente tabla: \n";
	int benef = mochila(pesos,beneficios,M,eleccion);
	cout << "Ha calculado que el máximo beneficio possible es: " << benef << endl;
	cout << "Usando la siguiente combinación de objetos: \n";
	for(int j=0; j<eleccion.size(); j++){
		if(eleccion[j]){
			cout << "  Objeto " << (j+1) << endl;
		}
	}







	return 0;
}
