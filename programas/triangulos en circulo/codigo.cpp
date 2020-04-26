#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	//cout<<"Ingrese le cantidad de puntos para el vector\n";
	int n;
	cin>>n;
	int vec[n];
	int sar[n];
	int i=0;
	while(i<n){
		sar[i]=-1;
		i++;
	}
	i=0;
	int suma=0;
	while(i<n){
		//cout<<"Ingrese la distancia del punto "<<i<<endl;
		cin>>vec[i];
		suma=suma+vec[i];
		i++;
	}
	int lado=suma/3;
	i=0;
	int veces=0;
	int h=0;
	while(h<n){
		i=h;
		int posicion=i;
		suma=0;
		if(sar[i]==-1){
			while(suma<lado){
				suma=suma+vec[i];
				i++;
			}
			if(suma==lado){
				sar[i]=2;
				suma=0;
				while(suma<lado){
					suma=suma+vec[i];
					i++;
				}
				if(suma==lado){
					sar[i]=2;
					sar[posicion]=1;
					veces++;
				}
				i++;
			}
			else sar[i]=0;
		}
		if(sar[i]==0||sar[i]==2) i++;
		h++;
	}
	i=0;
	int coincidencia=0;
	while(i<n){
		if(sar[i]==1) coincidencia++;
		i++;
	}
	cout<<coincidencia<<endl;;
	return 0;
}






