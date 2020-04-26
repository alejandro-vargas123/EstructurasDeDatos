#include <bits/stdc++.h>

#define infinite 2147483647
#define negativeinfinite -2147483647

using namespace std;

struct node{
	int key;
	struct node *next;
};

struct node *push(struct node *top,int element){ //meter en pilas
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->key=element;
	newnode->next=top;
	top=newnode;
	return top;
}

int pop(struct node **top){ //sacar de pilas
	struct node *q;
	//int element=negativeinfinite;
	int element;
	if(*top==NULL) cout<<"The stack is empty\n";
	else{
		q=*top;
		element=q->key;
		*top=(*top)->next;
		free(q);
	}
	return element;
}




struct node *enqueue(struct node *tail,int element){ //insertar en colas(modificado a caracteres)
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->key=element;
	if(tail==NULL){
		newnode->next=newnode;
		tail=newnode;
	}
	else{
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
	}
	return tail;
}

int dequeue(struct node **tail){ //sacar de las colas(modificado para caracteres)
	struct node *q;
	//char element='a';
	int element;
	if(*tail==NULL) cout<<"The queue is empty\n";
	else{
		if(*tail==(*tail)->next){
			element=(*tail)->key;
			free(*tail);
			*tail=NULL;
		}
		else{
			q=(*tail)->next;
			element=q->key;
			(*tail)->next=q->next;
			free(q);
		}
	}
	return element;
}











int left(int x) { return 2 * x + 1; }
int right(int x) { return 2 * x + 2; }
int parent(int x) { return (x - 1) / 2; }

struct PQ {
	int n; //heapsize
	int heap[5010];
};

void max_heap(PQ &pq, int id) {
	int l = left(id);
	int r = right(id);
	int largest = id;
	if (l < pq.n && pq.heap[l] > pq.heap[largest])
		largest = l;
	if (r < pq.n && pq.heap[r] > pq.heap[largest])
		largest = r;
	if (largest != id) {
		int tmp = pq.heap[id];
		pq.heap[id] = pq.heap[largest];
		pq.heap[largest] = tmp;
		max_heap(pq, largest);
	}
}

void build(PQ &pq) {
	for (int i = pq.n - 1; i >= 0; i--)
		max_heap(pq, i);
}

int maximum(PQ &pq) {
	return pq.heap[0];
}

void extract(PQ &pq){
	if(pq.n==0) return;
	int max=pq.heap[0];
	pq.heap[0] = pq.heap[pq.n - 1];
	pq.n--;
	max_heap(pq, 0);
}


void insert(PQ &pq, int key) {
	pq.n++;
	pq.heap[pq.n - 1] = key;
	int i = pq.n - 1;
	while (i > 0 && pq.heap[parent(i)] < pq.heap[i]) {
		int tmp = pq.heap[parent(i)];
		pq.heap[parent(i)] = pq.heap[i];
		pq.heap[i] = tmp;
		i = parent(i);
	}
}



















int main() {
	//struct node *top; //parte de las pilas(modificado a caracteres)
	//int operation;
	//char element;
	//top=NULL;
	/*while(scanf("%d",&operation)!=EOF){
		if(operation==1){
			cin>>element;
			top=push(top,element);
		}
		else{
			if(operation==2){
				element=pop(&top);
				if(element!=negativeinfinite) cout<<element<<endl;
			}
			else{
				printf("Bad operation.\n");
			}
		}
	}*/
	
	
	
	
	//struct node *tail; //parte de las colas(modificado a caracteres)
	/*int operation;
	char element;*/
	//tail=NULL;
	/*while(scanf("%d",&operation)!=EOF){
		if(operation==1){
			cin>>element;
			tail=enqueue(tail,element);
		}
		else{
			if(operation==2){
				element=dequeue(&tail);
				cout<<element<<endl;
			}
			else{
				cout<<"Bad operatio\n";
			}
		}
	}*/
	
	
	
	//int n; //colas de maxima prioridad
	//struct PQ m;
	/*while(cin>>n && n>0){
		int element;
		if(n==1){
			//cout<<"entro a 1\n";
			cin>>element;
			insert(m,element);
		}
		if(n==2){
			//cout<<"entro a 2\n";
			int k=maximum(m);
			extract(m);
			//cout<<"salida: "<<k<<endl;
		}
	}*/
	int n;
	while(cin>>n && n!=EOF){
		struct node *top; //para pilas
		top=NULL;
		struct node *tail; //para colas comunes
		tail=NULL;
		struct PQ m; //para colas de maxima prioridad
		int operation;
		//int n;
		int vec[3]={1,1,1};
		//cin>>n;
		for(int a=0;a<n;a++){ //ciclo mas externo que controla entradas y salidas
			cin>>operation;
			int element;
			if(operation==1){
				cin>>element;
				insert(m,element); //inserta en colas de maxima prioridad
				tail=enqueue(tail,element); //inserta en colas comunes
				top=push(top,element); //inserta en pilas
			}
			if(operation==2){
				int z;
				cin>>z; //entrada por teclado que simula la salida
				int k=maximum(m); //variable de ////// MAXIMA ///// prioridad
				extract(m);
				//cout<<"salida para colas de prioridad: "<<k<<endl;
				
				int s=dequeue(&tail);//varible de ////// COLAS //// comunes
				//cout<<"salidad para colas comunes: "<<s<<endl;
				
				int r=pop(&top);//varibla para ////// PILAS //////
				//if(r!=negativeinfinite) cout<<"salida para pilas: "<<r<<endl;/////////////////////////////////////////////7
				
				
				
				if(z==r){ //compara la entrada con el valor de PILAS
					vec[0]=vec[0]*1;
				}
				else{
					vec[0]=vec[0]*0;
				}
				if(z==s){//compara la entrada con la parte de las COLAS
					vec[1]=vec[1]*1;
				}
				else{
					vec[1]=vec[1]*0;
				}
				if(z==k){//compara la entrada con la MAXIMA PRIORIDAD
					vec[2]=vec[2]*1;
				}
				else{
					vec[2]=vec[2]*0;
				}
			}
		}
		int suma=0;
		for(int d=0;d<3;d++){
			//cout<<vec[d]<<" ";
			suma=suma+vec[d];
		}
		if(suma==0) cout<<"imposible\n";
		if(suma>1) cout<<"not sure\n";
		else{
			if(suma==1){
				if(vec[0]==1) cout<<"stack\n";
				if(vec[1]==1) cout<<"queue\n";
				if(vec[2]==1) cout<<"priority queue\n";
			}
		}
	}
	return 0;
}














