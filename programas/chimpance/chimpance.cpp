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
	long long a;
	cin>>a;
	long long vec[a];
	long long b=0;
	while(b<a){
		cin>>vec[b];
		b++;
	}
	long long c;
	cin>>c;
	long long sar[c];
	b=0;
	while(b<c){
		cin>>sar[b];
		b++;
	}
	b=0;
	while(b<c){
		if(sar[b]>vec[a-1]) cout<<vec[a-1]<<" X"<<endl;
		else{
			if(sar[b]<vec[0]) cout<<"X "<<vec[0]<<endl;
			else{ //parte de analisis de las posiciones
				int k=bina(vec,0,(a-1),sar[b]);
				//cout<<k<<endl; //se verifica que se este analizandl la posicion correcta
				if(sar[b]<vec[k] && sar[b]>vec[k-1]) cout<<vec[k-1]<<" "<<vec[k]<<endl;
				if(vec[k]==sar[b]){
					int m=k+1;
					int n=k-1;
					int mayor=vec[m];
					int menor=vec[n];
					while(vec[n]==sar[b]){
						menor=vec[n];
						n--;
					}
					while(vec[m]==sar[b]){
						mayor=vec[m];
						m++;
					}
					cout<<menor<<" "<<mayor<<endl;
				}
			}
		}
		b++;
	}
	return 0;
}
