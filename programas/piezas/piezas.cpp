//#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int bina(int a[],int i,int j,int n){
	int m,result=-1;
	while(i<=j){
		if(n<=a[0]){
			result=0;
			break;
		}
		m=(i+j)>>1;
		if(a[m]==n){
			result=m;
			break;
		}
		else{
			if(n>a[m]) i=m+1;
			else j=m-1;
		}
	}
	if(result==-1){
		result=i;
	}
	return result;
}

int main() {
	int a;
	cin>>a;//abertura dada
	a=a*100000000;
	;
	int n;
	cin>>n;//numero de piezas
	int vec[n];//vector con valores
	int bin[n];//vector para corroborar
	int b=0;
	bool ban=false;
	while(b<n){
		cin>>vec[b];
		bin[b]=0;
		b++;//ingresar valores
	}
	b=0;
	sort(vec,vec+n);
	b=0;
	int mayor=0; //l2
	int menor=0; //l1
	int diferencia=0; //diferencia l2 - l1
	int l1,l2;
	while(b<n){
		if(bin[b]==0){//se puede analizar porque es cero
			//cout<<"Entro1\n";
			l1=vec[b];
			//cout<<"L1: "<<l1<<endl;
			//cout<<"mitad l1: "<<l1/2<<endl;
			if(l1!=a/2){//se da si no es la mitad de la abertura
				int z=bina(vec,0,(n-1),(a-l1));
				l2=vec[z];
				if(l2==(a-l1)){//si se da la condicion de que la segunda pieza se encuentre
					if((l2-l1)>diferencia){//aqui se define las piezas de mayor distancia
						ban=true;
						mayor=l2;
						menor=l1;
						diferencia=l2-l1;
						bin[b]=1;
						bin[z]=1;
					}
					else{ //si no se da la condicion 
						bin[b]=1;
						bin[z]=1;
					}
				}
				else{ //si no se da la condicion de encontrar la segunda pieza por lo cual no se encontro
					bin[b]=-1;
				}
			}
			else{//se da si la ficha es la mitad de la abertura
				l1=vec[b];
				//cout<<"entro\n";
				if(vec[b]==vec[b+1]){//si la posicion que estoy es la mitad y el siguiente tambien lo es
					cout<<vec[b]<<endl;
					if((mayor-menor)==0){//si se encuentra una pareja por primera vez
						l2=vec[b+1];
						mayor=l2;
						menor=l1;
						ban=true;
						b++;
						bin[b]=1;
						bin[b+1]=1;
					}
					else{ //si no es la primera vez que se encuentra
						bin[b]=1;
						bin[b+1]=1;
						b++;
					}
				}
			}/////////
		}
		//si no es uno en la lista binaria sigue avanzando
		b++;
	}
	if(ban==false){
		cout<<"danger\n";
	}
	else{
		cout<<"yes "<<menor<<" "<<mayor<<endl;
	}
	return 0;
}






