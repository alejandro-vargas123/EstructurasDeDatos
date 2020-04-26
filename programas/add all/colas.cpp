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
	return (n+1)*2-1;
}

int right(int n){
	return (n+1)*2;
}

void meanheapify(int q[],int i){
	int l=left(i);
	int r=right(i);
	int least;
	int heapsize=Countof(q);
	
	if(l<=heapsize && q[l]<q[i]){
		least=l;
	}
	else least=i;
	
	if(r<=heapsize && q[r]<q[least]){
		least=r;
	}
	if(least!=i){
		int m=q[i];
		q[i]=q[least];
		q[least]=m;
		meanheapify(q,least);
	}
}

int minimun(int q[]){
	return q[1];
}

int extract(int q[]){
	int min=-infinito;
	int heapsize=Countof(q);
	if(heapsize<1){
		cout<<"heapunderflow\n";
	}
	else{
		min=q[1];
		q[1]=q[heapsize];
		heapsize=heapsize-1;
		meanheapify(q,1);
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

int main() {
	int vec[11]={5,8,10,12,13,15,16,20,21,30,40};
	//cout<<Countof(vec)<<endl; Obtiene el largo del vector
	//cout<<Countof(a)<<endl;
	cout<<extract(vec)<<endl;
	cout<<extract(vec)<<endl;
	
	return 0;
}





