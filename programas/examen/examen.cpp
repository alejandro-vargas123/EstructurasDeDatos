#include <bits/stdc++.h>

using namespace std;

struct paciente{
	string nombre;
	int llegada;
	int prioridad;
};

struct control{
	int heapsize;
	struct paciente vec[];
};


int left(int x) { return 2 * x + 1; }
int right(int x) { return 2 * x + 2; }
int parent(int x) { return (x - 1) / 2; }


void meanheap(struct control m,int pos){
	int l=left(pos);
	int r=right(pos);
	int smallest=pos;
	if(l<m.heapsize && m.vec[l].prioridad==m.vec[smallest].prioridad){ //cuando tienen igual prioridad en ambos nodos (left y pos)
		if(m.vec[l].llegada<m.vec[smallest].llegada){ //se desenpata por hora de llegada
			smallest=l;
		}
	}
	else{ //cuando se tiene distinta prioridad(Left y pos)
		if(l<m.heapsize && m.vec[l].prioridad < m.vec[smallest].prioridad){
			smallest=l;
		}
	}
	
	
	if(r<m.heapsize && m.vec[r].prioridad==m.vec[smallest].prioridad){ //cuando tienen igual prioridad en ambos nodos (left y pos)
		if(m.vec[r].llegada<m.vec[smallest].llegada){ //se desenpata por hora de llegada
			smallest=r;
		}
	}
	else{ //cuando se tiene distinta prioridad(Left y pos)
		if(r<m.heapsize && m.vec[r].prioridad < m.vec[smallest].prioridad){
			smallest=r;
		}
	}
	
	if(smallest!=pos){
		struct paciente tm;
		tm=m.vec[smallest];
		m.vec[smallest]=m.vec[pos];
		m.vec[pos]=tm;
		meanheap(m,smallest);
	}
}

void extract(struct control m){
	if (m.heapsize == 0) return;
	struct paciente smallest = m.vec[0];
	m.vec[0] = m.vec[m.heapsize - 1];
	m.heapsize--;
	meanheap(m,0);
}

struct paciente minimum(struct control m){ //retorna una posicion tipo paciente
	return m.vec[0];
}

void insert(struct control m, struct paciente key){
	cout<<"antes de el while\n";
	m.heapsize++;
	m.vec[m.heapsize-1]=key;
	int i=m.heapsize - 1;
	while(i>0 && m.vec[parent(i)].prioridad  >  m.vec[i].prioridad ){
		struct paciente tm= m.vec[parent(i)];
		m.vec[parent(i)]=m.vec[i];
		m.vec[i]=tm;
		i=parent(i);
	}
}



int main() {
	struct control m; //variable de control
	int n; //cantidad de transacciones
	int a=0;
	cin>>n;
	while(a<n){
		int operation;
		cin>>operation;
		if(operation==1){ //opcion de ingresar
			//cout<<"entro a 1\n";
			struct paciente k;
			cin>>k.llegada;
			cin>>k.prioridad;
			cin>>k.nombre;
			cout<<k.llegada<<endl;
			cout<<k.prioridad<<endl;
			cout<<k.nombre<<endl;
			//cout<<"antes de insert\n";
			insert(m,k);
			cout<<"despues de insert\n";
		}
		if(operation==2){ //opcion de sacar
			cout<<"entro a 2\n";
			int c; //hora de consulta
			struct paciente s=minimum(m);
			extract(m);
			cout<<s.llegada;
			cout<<" "<<c<<" ";
			cout<<(c-s.llegada)<<" "; //tiempo de llegada
			cout<<s.nombre;
		}
		n++;
	}
	return 0;
}





