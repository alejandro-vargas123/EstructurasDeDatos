#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct node{
	int key;
	struct node *next;
};

void print(struct node *head){
	struct node *q;
	q=head;
	while(q!=NULL){
		printf("%d -> ",q->key);
		q=q->next;
	}
}

struct node *crear(int n){ //funcion para crear continuo
	struct node *head;
	struct node *q=NULL;
	while(n>0){
		q=(struct node *)malloc(sizeof(struct node));
		q->key=n;
		q->next=head;
		head=q;
		n--;
	}
	return head;
}

struct node *llenar(int n){ //funcion para llenar unos numeros pedidos
	struct node *head;
	struct node *q=NULL;
	int a=0;
	while(a<n){
		q=(struct node *)malloc(sizeof(struct node));
		int m;
		cin>>m;
		q->key=m;
		q->next=head;
		head=q;
	}
	return head;
}

struct node *insertar(int m,struct node *head){
	struct node *nodo,*p,*q;
	if(head=NULL){
		nodo->next=head;
		head=nodo;
	}
	else{
		if(m<=head->key){
			nodo->next=head;
			head=nodo;
		}
		else{
			p=NULL;
			q=head;
			while((q!=NULL) && (m > q->key)){
				p=q;
				q=q->next;
			}
			p->next=nodo;
			nodo->next=q;
		}
	}
	return head;
	
}






struct node *eliminar(int m,struct node *head){
	struct node *nodo,*p,*q;
	if(head=NULL){
		cout<<"no se puede\n";
	}
	else{
		if(m == head->key){
			q=head;
			head=head->next;
			free(head);
		}
		else{
			p=NULL;
			q=head;
			while((q!=NULL) && (m > q->key)){
				p=q;
				q=q->next;
			}
			
			if(q!=NULL){
				p->next=q->next;
				free(q);
			}
			else{
				printf("no esta en la lista\n");
			}
			p->next=nodo;
			nodo->next=q;
		}
	}
	return head;
	
}











void imprimir(struct node *head){
	struct node *q;
	q=head;
	while(q!=NULL){
		printf("%d\n",q->key);
		q=q->next;
	}
}

void limpiar(struct node *head){
	struct node *q;
	q=head;
	while(q!=NULL){
		head=q;
		q=q->next;
		free(head);
	}
}


/*int main() { //pone los numeros del 1 al 1000 con listas y sin funcioes
	struct node *head,*q;
	int n=1000;
	head=NULL;
	while(n>0){
		q=(struct node *)malloc(sizeof(struct node));
		q->key=n;
		q->next=head;
		head=q;
		n--;
	}
	q=head;
	while(q!=NULL){
		printf("%d\n",q->key);
		q=q->next;
	}
	q=head;
	while(q!=NULL){
		head=q;
		q=q->next;
		free(head);
	}
	return 0;
}*/



/*int main(){ //pone los numeros del 1 al 1000 con funciones
	int n;
	scanf("%d",&n);
	struct node *head=crear(n);
	imprimir(head);
	limpiar(head);
	return 0;
}*/


/*int main(){
	int n;
	cin>>n;
	struct node *head=llenar(n);
	system("CLS");
	imprimir(head);
	limpiar(head);
	return 0;
}*/



/*int main(){
	int n;
	cin>>n;
	struct node *head=llenar(n);
	print(head);
	int m;
	cin>>m;
	insertar(m,head);
	imprimir(head);
	return 0;
}*/


int main(){
	struct node *head;
	int element;
	head=NULL;
	while((scanf("%d",&element)) !=EOF){
		head=insertar(element,head);
		print(head);
	}
	return 0;
}







