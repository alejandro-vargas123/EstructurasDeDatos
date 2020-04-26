#include <bits/stdc++.h>

using namespace std;


struct node{
	int key;
	struct node *prev;
	struct node *next;
};

struct node *insertincircularlist(struct node *tail,int element){
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->key=element;
	if(tail==NULL){
		newnode->next=newnode;
		newnode->prev=newnode;
		tail=newnode;
	}
	else{
		newnode->next=tail->next;
		tail->next->prev=newnode;
		newnode->prev=tail;
		tail->next=newnode;
		tail=newnode;
	}
	return tail;
}

void printcircularlist(struct node *tail){ //imprime de derecha a izquierda
	struct node *p,*q;
	if(tail==NULL) printf("Empty list\n");
	else{
		q=NULL;
		p=tail;
		while(q!=tail->next){
			printf("%d ->",p->key);
			q=p;
			p=p->prev;
		}
		printf("...\n");
	}
}

struct node *deleteincircularlist(struct node *tail,int element){
	struct node *p,*q;
	if(tail==NULL) cout<<"Imposible delete\n";
	else{
		if(tail==tail->prev){ //si solo hay un elemento
			if(element==tail->key){
				free(tail);
				tail=NULL;
			}
			else cout<<"Element is not in list\n";
		}
		else{
			p=NULL;
			q=tail->next;
			while((p!=tail) && (q->key!=element)){
				p=q;
				q=q->next;
			}
			if(p==tail) cout<<"Element is not in list\n";
			else{
				if(p==NULL) p=tail;
				if(q==tail) tail=tail->prev;
				
				p->next=q->next;
				q->next->prev=p;
				free(q);
			}
		}
	}
	return tail;
}



int main(int argc, char** argv) {
	struct node *tail;
	tail=NULL;
	int i;
	cin>>i;
	while(i!=0){
		if(i==1){
			int m;
			cin>>m;
			tail=insertincircularlist(tail,m);
		}
		if(i==2){
			printcircularlist(tail);
		}
		if(i==3){
			int m;
			cin>>m;
			deleteincircularlist(tail,m);
		}
		cout<<"Valor de operacion\n";
		cin>>i;
	}
	return 0;
}






