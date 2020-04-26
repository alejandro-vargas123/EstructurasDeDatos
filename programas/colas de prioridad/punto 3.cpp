#include <iostream>
/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>*/
#include <bits/stdc++.h>

#define infinito 2147483647

using namespace std;

template<typename T>inline size_t Countof(const T (&)){ return 0; }
template<typename T,size_t S>inline size_t Countof(const T (&)[S]){return S;}



int largo(int q[]){
	//template<typename T>inline size_t Countof(const T (&)){ return 0; }
	//template<typename T,size_t S>inline size_t Countof(const T (&)[S]){return S;}
}

int parent(int n){
	return n/2;
}

int left(int n){
	return 2*n;
}

int right(int n){
	return 2*n+1;
}

void meanheapify(int q[],int i,int heapsize){
	int l=left(i);
	int r=right(i);
	//cout<<"izquierdo: "<<l<<endl;
	//cout<<"derecho: "<<r<<endl;
	int least;
	//cout<<"heapsize: "<<heapsize<<endl;
	
	if(l<=heapsize && q[l]<q[i]){
		least=l;
	}
	else{
		least=i;
		//cout<<"entro\n";
	}
	//cout<<"least: "<<least<<endl;
	
	if(r<=heapsize && q[r]<q[least]){
		least=r;
	}
	if(least!=i){
		int m=q[i];
		q[i]=q[least];
		q[least]=m;
		//cout<<"primer termino: "<<q[1]<<endl;
		meanheapify(q,least,heapsize);
	}
}

int minimun(int q[]){
	return q[1];
}

int extract(int q[],int heapsize){
	int min=-infinito;
	if(heapsize<1){
		cout<<"heapunderflow\n";
	}
	else{
		min=q[1];
		q[1]=q[heapsize];
		heapsize=heapsize-1;
		meanheapify(q,1,heapsize);
	}
	return min;
}

void decrease(int q[], int i, int key){
	if(key>q[i]){
		cout<<"new key is higher than current key\n";
	}
	q[i]=key;
	while((i>1) && (q[parent(i)]>q[i])){
		int m=q[i];
		q[i]=q[parent(i)];
		q[parent(i)]=m;
		i=parent(i);
	}
}

void insert(int q[],int key,int heapsize){
	heapsize++;
	q[heapsize]=infinito;
	decrease(q,heapsize,key);
}

int main() {
	/*int n;
	cin>>n;
	int k=n+1; //heapsize
	int vec[k];
	int a=1;
	while(a<k){
		cin>>vec[a];
		a++;
	}
	//cout<<Countof(vec)<<endl; Obtiene el largo del vector
	//cout<<Countof(a)<<endl;
	meanheapify(vec,1,k);
	a=1;
	int suma=0;
	cout<<"suma inicial: "<<suma<<endl;
	int respaldo=k;
	int b=0;
	while(a<=n){  //aqui se hacen las sumas necesarias
		sort(vec+1,vec+k);
		a++;
	}
	cout<<"suma: "<<suma<<endl;*/
	priority_queue <int, vector<int>, greater<int> > vec;
	int b;
	cin>>b;
	int a=0;
	while(a<b){
		int c;
		cin>>c;
		vec.push(c);
		a++;
	}
	/*while (vec.empty() == false) 
	{ 
		cout << vec.top() << " "; 
		vec.pop(); 
	}*/
	a=0;
	int suma=0;
	while(a<(b-1)){
		int x=vec.top();
		vec.pop();
		int y=vec.top();
		int termino=x+y;
		suma=suma+termino;
		vec.push(termino);
		a++;
	}
	cout<<suma<<endl;
	return 0;
}





