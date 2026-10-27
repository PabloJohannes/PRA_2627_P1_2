#ifndef PROGDIN_H
#define PROGDIN_H

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int cambioMonedas(const int d,const vector<int>& m, vector<int>& s){
    int n = m.size();
    vector<vector<int>> T(n, vector<int>(d+1,-1)); //podría usar infinito, pero prefiero -1
    T[0][0] = 0;

    for(int j = 1; j <= d; j++) { //se rellena primero la primera fila(solo usando la moneda mas pequeña)
        if(j>=m[0] && T[0][j-m[0]]!=-1) {//si el tamaño de la moneda es mayor que el dinero a devolver o el dinero a devolver menos el tamaño de la moneda da un dinero que no se puede hacer con la moneda, la casilla se queda con -1
            T[0][j]=1+T[0][j-m[0]]; //si es que si que es possible, calcula las monedas que se necesita, haciendo uso de lo calculado para cantidades de dinero menores
        }
    }

    for(int i = 1; i < n; i++){ //para rellenar todas las demás filas(todos los demás tipos de moneda)
        T[i][0]=0;
        for(int j=1; j <= d; j++) {//para cada cantidad de dinero después de 0 hasta el dienro máximo(d)
            if(j<m[i] || T[i][j-m[i]] == -1){ //si el tamaño de la moneda es mayor que el dinero a devolver o el dinero a devolver menos el tamaño de la moneda da un dinero que no se puede hacer, se usa al valor calculado con las monedas de tamaños menores
                T[i][j] = T[i-1][j];
            } else {
                if(T[i-1][j]!= -1){//si para la misma cantidad de dinero hay un resultado váido usando monedas menores se compara ese valor con el que usa la moneda actual
                    T[i][j] = min(T[i-1][j],1+T[i][j-m[i]]);
                } else { //si no hay, pues se utiliza directamente la solución usando la moneda actual
                    T[i][j] = 1+T[i][j-m[i]];
                }
            }
        }
    }

    //rellenar vector de solución:

    vector<int> Sol(n,0);
    int i= n-1; //poscición del vector de la moneda mas grande
    int j=d; //dinero total
    while(j!=0){ //mientras todavía haya dinero que devolver:
        if(i==0 || T[i][j] != T[i-1][j]){ //si la cantidad de monedas usando la moneda i es differente a la cantidad sin usarla, es mejor usarla y por tanto se le resta su valor y se le suma al contador para apuntar que se ha usado esa moneda
            j = j-m[i];
            Sol[i]++;
        } else { //y si no, es que la moneda i no aporta y se puede pasar de fila
            i--;
        }
    }
    s=Sol;

	//manera para mí para ver si funciona lo que he hecho:
    cout << "\n";
    for(int f=0;f<m.size();f++){
        for(int c=0; c<=d; c++){
            cout << T[f][c] << " ";
        }
        cout << "\n";
    }

    return T[n-1][d];
}

int mochila(const vector<int>& p, const vector<int>& b, int m, vector<int>& s){
    int numObj = p.size();
    vector<vector<int>> g(numObj+1,vector<int>(m+1,0));

    for(int i=1;i<=numObj;i++){
        for(int j=1; j<=m; j++){
            if(p[i-1]>j){ //si el objeto 1 no cabe: devolver el beneficio que se calculó sin tener en cuenta al objeto i
                g[i][j]=g[i-1][j];
            } else{ //si si cabe, se devuelve el mayor beneficio entre la solución sin tener encueta el objeto i y la solución que usa el objeto i(sumando su beneficio y el máximo beneficio que se ha sacado con el tamanyo restante)
                g[i][j]=max(g[i-1][j],g[i-1][j-p[i-1]]+b[i-1]);
            }
        }
    }

    //rellenar vector de solución:
    int capacidad = m; //capacidad total
    int obj = numObj; //posición del último objeto de la lista en la tabla (obj-1 es su posición en la lista)
    while(obj>0 && capacidad > 0){
        if(g[obj][capacidad] != g[obj-1][capacidad]){ //si ésto se cumple se anota que el obj se ha usado para obtener el beneficio máximo y por tanto se anota en el vector de salida y se reduce la capacidad
            s[obj-1]=1;
            capacidad -= p[obj-1];
        }
        obj--; //independientemente si se ha utilizado un objeto o no se pasa de objeto en cada ciclo del bucle (sólo hay un objeto de cada)
    }
    
    
    
	//manera para mí para ver si funciona lo que he hecho:
    cout << "\n";
    for(int f=0;f<=numObj;f++){
        for(int c=0; c<=m; c++){
            cout << g[f][c] << " ";
        }
        cout << "\n";
    }


    return g[numObj][m];
}






#endif
