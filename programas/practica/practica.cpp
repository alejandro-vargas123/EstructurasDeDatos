#include <iostream>

using namespace std;

/*void merge(int a[],int p,int q,int r){
	int n1=q-p+1;
	int n2=r-q;
	int l[n1+1];
	int r[n2+1];
	for(int i=0,i<=n1,i++){
		l[i]=a[p+i-1];
	}
	for(int j=0;j<=n2,j++){
		r[j]=a[q+j];
	}
	
}*/

int bina(long long a[],long long i,long long j,double n){
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
	double a;//Abertura del vector
	cin>>a;
	int conversion= int(a*(1000.));
	cout<<"conversion desde fuera: "<<conversion<<endl;
	int n; //variable del largo de el vector
	cin>>n;
	int vec[n];
	int b=0;
	while(b<n){
		cin>>vec[b]; //Ingreso de las medidas del vector
		b++;
	}
	b=0;
	int l1,l2;
	while(b<n){
		l1=vec[b];
		int k=conversion-l1;
		cout<<"conversion "<<conversion<<endl;
		int z=bina(vec,0,(n-1),(conversion-l1));
		l2=vec[z];
		cout<<"l1 "<<l1<<endl;
		cout<<"l2 "<<l2<<endl;
		if(((l1+l2)==conversion) && l1<=l2){
			cout<<"yes "<<l1<<" "<<l2<<endl;
			break;
		}
		b++;
	}
	/*double a;
	cin>>a;
	int conversion= int((100000000.)*a);
	cout<<conversion<<endl;*/
	return 0;
}






