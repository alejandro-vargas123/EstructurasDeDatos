#include <iostream>

using namespace std;

int bina(long long a[],long long i,long long j,long long n){
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
	cin>>a;
	long long vec[a];
	int b=0;
	while(b<a){
		cin>>vec[b];
		b++;
	}
	int c;
	cin>>c;
	long long sar[c];
	b=0;
	while(b<c){
		cin>>sar[b];
		b++;
	}
	b=0;
	while(b<c){
		if(sar[b]<=vec[0]){//////////////////
			if(sar[b]<vec[0]) cout<<"X "<<vec[0]<<endl; //Parte de altura menor al primer termino
			else{ //parte de la altura igual al primer termino
				
				int k=1;
				int mayor=vec[k];
				while(sar[b]==mayor){
					k++;
					mayor=vec[k];
				}
				cout<<"X "<<mayor<<endl;
			}
		}
		if(sar[b]>=vec[a-1]){////////////////// pendiente
			if(sar[b]>vec[a-1]) cout<<"X "<<vec[a-1]<<endl;
			else{
				int k=2;
				int menor=vec[a-k];
				menor=vec[a-k-1];
				//cout<<"menor primero: "<<menor<<endl;
				while(sar[b]==menor){
					k++;
					//int t=a-k-1;
					menor=vec[a-k];
				}
				cout<<menor<<" X\n";
			}
		}
		if((sar[b]>vec[0]) && (sar[b]<vec[a-1])){ //Cuando es en cualquier posicion que no son los extremos
			int m=bina(vec,0,(a-1),sar[b]); //Se hace la busqueda binaria para saber la posicion que se esta o en la que deberia estar
			if(sar[b]!=vec[m]){
				int mayor=vec[m];
				int menor=vec[m-1];
				cout<<menor<<" "<<mayor<<endl;
			}
			else{
				int l=1;
				int mayor=vec[m+l];
				int menor=vec[m-l];
				int cant=0;
				while((sar[b]==menor) && (cant<(m-1))){
					l++;
					menor=vec[m-l];
				}
				cant=0;
				l=1;
				while((sar[b]==mayor) && (cant<(a-m-2))){
					l++;
					mayor=vec[m+l];
				}
				cout<<menor<<" "<<mayor<<endl;
			}
		}
		b++;
	}
	return 0;
}
