#include <bits/stdc++.h>

#define infinite 2147483647
#define negativeinfinite -2147483647

using namespace std;

struct node{
	int key;
	struct node *next;
};

struct node *push(struct node *top,int element){ //pilas
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->key=element;
	newnode->next=top;
	top=newnode;
	return top;
}

int pop(struct node **top){ //pilas
	struct node *q;
	int element=negativeinfinite;
	if(*top==NULL) cout<<"The stack is empty\n";
	else{
		q=*top;
		element=q->key;
		*top=(*top)->next;
		free(q);
	}
	return element;
}




struct node *enqueue(struct node *tail,int element){ //insertar en colas
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

int dequeue(struct node **tail){
	struct node *q;
	int element=negativeinfinite;
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


int main(int argc, char** argv) {
	/*struct node *top; //parte de las pilas
	int operation,element;
	top=NULL;
	while(scanf("%d",&operation)!=EOF){
		if(operation==1){
			scanf("%d",&element);
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
	
	
	
	
	/*struct node *tail; //parte de las colas
	int operation, element;
	tail=NULL;
	while(scanf("%d",&operation)!=EOF){
		if(operation==1){
			scanf("%d",&element);
			tail=enqueue(tail,element);
		}
		else{
			if(operation==2){
				element=dequeue(&tail);
				if(element!=negativeinfinite) cout<<element<<endl;
			}
			else{
				cout<<"Bad operatio\n";
			}
		}
	}*/
	
	
	int n;
	cin>>n; //cantidad de torres que hay
	for(int a=0;a<n;a++){
		
	}
	return 0;
}














