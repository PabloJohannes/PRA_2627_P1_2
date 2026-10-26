#ifndef DYV_H
#define DYV_H

#include<iostream>
#include<vector>
#include<chrono>

using namespace std;

template<typename T>
int busquedaBinaria(T X, const vector<T>& V, int ini, int fin) {
	if(ini > fin) {		
		return -1;
	}
	int medio = (ini+fin) / 2;
	if(V[medio] == X) {
		return medio;
	}
	if(V[medio] > X) {
		return busquedaBinaria(X,V,ini,medio-1);
	}else {
		return busquedaBinaria(X,V,medio+1,fin);
	}
}


template<typename T>
int partition(vector<T>& V, int ini, int fin) {
	T x = V[fin];
	int i = ini;
	for(int j=ini;j<fin;j++){
		if(V[j] <= x){
			T aux=V[i];
			V[i]=V[j];
			V[j]=aux;
			i = i + 1;
		}
	}
	V[fin]=V[i];
	V[i]=x;
	return i;
}

template<typename T>
void quicksort(vector<T>& V, int ini, int fin) {
	if(ini < fin) {
		int pivot = partition(V, ini, fin);
		quicksort(V, ini, pivot -1);
		quicksort(V, pivot + 1, fin);
	}
}


#endif
