//Jhoao Alejandro Martinez y Alejandro Vargas Bernal

#include <bits/stdc++.h>

#define infinite 2147483647
#define negativeinfinite -2147483647

using namespace std;

struct node{
	char key;
	struct node *next;
};

struct node *push(struct node *top,char element){ //pilas
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->key=element;
	newnode->next=top;
	top=newnode;
	return top;
}

char pop(struct node **top){ //pilas
	struct node *q;
	//int element=negativeinfinite;
	char element;
	if(*top==NULL) cout<<"The stack is empty\n";
	else{
		q=*top;
		element=q->key;
		*top=(*top)->next;
		free(q);
	}
	return element;
}




struct node *enqueue(struct node *tail,char element){ //insertar en colas(modificado a caracteres)
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

char dequeue(struct node **tail){ //sacar de las colas(modificado para caracteres)
	struct node *q;
	//char element='a';
	char element;
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


int main() {
	/*struct node *top; //parte de las pilas(modificado a caracteres)
	int operation;
	char element;
	top=NULL;
	while(scanf("%d",&operation)!=EOF){
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
	
	
	
	
	/*struct node *tail; //parte de las colas(modificado a caracteres)
	int operation;
	char element;
	tail=NULL;
	while(scanf("%d",&operation)!=EOF){
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
	
	
	int n; //numero de torres
	cin>>n;
	int vec[n];
	for(int a=0;a<n;a++){ //Se reciben los nombres de las torres
		string cadena;
		cin>>cadena;
		struct node *top,*tail;
		top=NULL;
		tail=NULL;
		char element1,element2;
		int c=cadena.size();
		for(int b=0;b<c;b++){ //se llenan colas y pilas
			tail=enqueue(tail,cadena[b]); //ingresa en cola
			top=push(top,cadena[b]); //ingresa en pila
		}
		bool ban=true;
		for(int d=0;d<c;d++){ //se hacen las comparaciones
			//cout<<"elemento de la cola: \n";
			element1=dequeue(&tail); //saca de la cola
			//cout<<element1<<endl;
			//cout<<"elemento de la pila: \n";
			element2=pop(&top); //saca de la pila
			//cout<<element2<<endl;
			if(element1==element2){ //si ambos elementos son iguales el primero y el ultimo
				//cout<<element1<<endl;
				//cout<<"entro\n";
				if((element1=='A')||(element1=='H')||(element1=='I')||(element1=='M')||(element1=='O')||(element1=='T')||(element1=='U')||(element1=='V')||(element1=='X')||(element1=='Y')||(element1=='W')){      
					//cout<<"increible!!!"<<element1<<endl;
					if((element2=='A')||(element2=='H')||(element2=='I')||(element2=='M')||(element2=='O')||(element2=='T')||(element2=='U')||(element2=='V')||(element2=='X')||(element2=='Y')||(element2=='W')){
						//cout<<"entro verdadero\n";
						ban=true;
					} else {
						ban=false;
						break;
					}  
				}else {
					ban=false;
					break;
				}   
			}
			else{
				//cout<<"entro falso\n";
				ban=false;
				break;
			}
		}
		if(ban) vec[a]=1;
		else vec[a]=0;
		//cout<<endl;
	}
	for(int e=0;e<n;e++){
		if(vec[e]==1) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}














