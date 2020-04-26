#include <iostream>

using namespace std;

int main() {
	int a=2;
	int suma=0;
	int b; //Rango de busqueda
	int veces=0;
	int mayor=0;
	int resto;
	//cout<<"Ingrese el rango de busqueda\n";
	cin>>b;
	while(a<=b){
		//cout<<"a es: "<<a<<endl;
		//cout<<"la suma de atras es: "<<
		int m=a+1;
		suma=0;
		int k=a-1;
		suma=(k*(k+1))/2;
		mayor=0;
		while(mayor<suma){
			mayor=mayor+m;
			m++;
		}
		if(suma==mayor){
			//cout<<"el numero es: "<<a<<endl;
			veces++;
		}
		a++;
	}
	cout<<veces<<endl;
	return 0;
}
