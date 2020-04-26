#include <bits/stdc++.h>

using namespace std;

struct paciente{ //estructura paciente que almacena la informacion de los pacientes
	string nombre;
	int llegada;
	int prioridad;
};

struct control{ //estructura de control en la cual se lleva el control de la informacion en las funciones
	int heapsize; //cantidad de pacientes que hay en el momento
	struct paciente vec[100]; //vector tipo estructura paciente donde se almacena la informacion de todos los pacientes permitiendo hacer la cola de prioridad
}m;


int left(int x) { return 2 * x + 1; } //hijo de un nodo por la izquierda
int right(int x) { return 2 * x + 2; } //hijo de un nodo por la derecha
int parent(int x) { return (x - 1) / 2; } //padre de un nodo


void meanheap(struct control *m,int pos){ //funcion que sirve para poder garantizar la propiedad de monton minimo
	int l=left(pos);
	int r=right(pos);
	int smallest=pos; //con las tres variables se busca el menor de los 3 en un subarbol
	if(l<(*m).heapsize && (*m).vec[l].prioridad==(*m).vec[smallest].prioridad){ //cuando tienen igual prioridad en ambos nodos (left y pos)
		if((*m).vec[l].llegada<(*m).vec[smallest].llegada){ //se desenpata por hora de llegada
			smallest=l; //se define el hujo izquierdo como el mas pequeño
		}
	}
	else{ //cuando se tiene distinta prioridad(Left y pos)
		if(l<(*m).heapsize && (*m).vec[l].prioridad < (*m).vec[smallest].prioridad){
			smallest=l; //se define el hijo izquierdo como el mas pequeño
		}
	}
	
	
	if(r<(*m).heapsize && (*m).vec[r].prioridad==(*m).vec[smallest].prioridad){ //cuando tienen igual prioridad en ambos nodos (right y pos)
		if((*m).vec[r].llegada<(*m).vec[smallest].llegada){ //se desenpata por hora de llegada
			smallest=r; //se define el hijo derecho como el mas pequeño
		}
	}
	else{ //cuando se tiene distinta prioridad(right y pos)
		if(r<(*m).heapsize && (*m).vec[r].prioridad < (*m).vec[smallest].prioridad){
			smallest=r; //se define el hijo derecho como el mas pequeño
		}
	}
	
	if(smallest!=pos){ //se verifica que el mas pequeño y la posicion de inicio no sean la misma
		struct paciente tm; //variable temporal para poder hacer un intercambio en las posiciones
		tm=(*m).vec[smallest];
		(*m).vec[smallest]=(*m).vec[pos];
		(*m).vec[pos]=tm;
		meanheap(m,smallest); //se llama recursivamente la funcion meanhep que garantiza el monton minnimo
	}
}

void extract(struct control *m){ //funcion que extrae un elemento de una cola
	if ((*m).heapsize == 0) return; //se mira si la cantidad de pacientes es mayor a cero
	struct paciente smallest = (*m).vec[0];
	(*m).vec[0] = (*m).vec[(*m).heapsize - 1];
	(*m).heapsize--; //se reduce en uno el numero que indica la cantidad de pacientes que hay en total
	meanheap(m,0); //se llama recursivamente la funcion meanheap
}

struct paciente minimum(struct control m){ //retorna una posicion tipo paciente que es el de mayor prioridad en TRIAGE
	return m.vec[0];
}

void insert(struct control *m, struct paciente key){ //funcion que inserta un paciente en el vectos donde estos se almacenan
	//cout<<"Heapsize antes: "<<(*m).heapsize<<endl;
	(*m).heapsize++;//se aunmenta la variable en uno de lo que lleva la cuenta de los pacientes
	//cout<<"heapsize despues: "<<(*m).heapsize<<endl;
	//cout<<"antes de el while\n";
	(*m).vec[(*m).heapsize-1]=key;
	int i=(*m).heapsize - 1;
	//cout<<"heapsize: "<<m.heapsize<<endl;
	//cout<<"i : "<<i<<endl;
	while(i>0 && (*m).vec[parent(i)].prioridad  >  (*m).vec[i].prioridad ){ //su busca hasta que se encuentra la posicion adecuada por monton minimo
		struct paciente tm= (*m).vec[parent(i)];
		(*m).vec[parent(i)]=(*m).vec[i];
		(*m).vec[i]=tm;
		i=parent(i);
	}
}



int main() {
	//struct control m; //variable de control
	int n; //cantidad de transacciones
	int a=0; //variable que hace conteo
	cin>>n; //ingreso de la cantidad de transacciones
	while(a<n){
		int operation; //variable que dice la operacion que se va a hacer(ingreso o salida de paciente)
		cin>>operation;
		if(operation==1){ //opcion de ingresar
			//cout<<"entro a 1\n";
			struct paciente k;
			cin>>k.llegada;
			cin>>k.prioridad; //se pide la informacion del paciente
			cin>>k.nombre;
			
			//cout<<"antes de insert\n";
			insert(&m,k); //se inserta en la cola el nuevo paciente siguiendo el monton minimo
			/*cout<<"Llegada: "<<m.vec[0].llegada<<endl;
			cout<<"prioridad: "<<m.vec[0].prioridad<<endl;
			cout<<"Nombre: "<<m.vec[0].nombre<<endl;
			cout<<"Heapsize: "<<m.heapsize<<endl;*/
			//cout<<"despues de insert\n";
		}
		if(operation==2){ //opcion de sacar
			//cout<<"entro a 2\n";
			int c; //hora de consulta
			cin>>c;
			//cout<<"hora de consulta: "<<c<<endl;
			struct paciente s=minimum(m);//se consigue la informacion de el paciente de maxima prioridad por TRIAGE
			extract(&m);
			cout<<s.llegada; //se muestra toda la informacion del paciente segun la especificacion de salida
			cout<<" "<<c<<" ";
			cout<<(c-s.llegada)<<" "; //tiempo de llegada
			cout<<s.nombre<<endl;
		}
		a++;
	}
	return 0;
}





