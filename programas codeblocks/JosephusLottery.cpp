#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int key;
    struct node *next;
    struct node *prev;
};

struct node *InsertInCircularDoublyLinkedList(struct node *tail, int element)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->key = element;

    if(tail == NULL)
    {
        p->next = p;
        p->prev = p;
        tail = p;
    }
    else
    {
        p->next = tail->next;
        tail->next->prev = p;
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
    return tail;
}

int JosephusLottery(struct node *tail, int k)
{
    struct node *q;
    int index, result,clock=0;
    tail=tail->next;
    while (tail != tail->next)
    {
        if (clock%2==0)
        {
            for (index=1;index<k;index++)
                tail=tail->next;
            q=tail;
            tail = tail->next;
            q->prev->next=q->next;
            q->next->prev=q->prev;
            free(q);
            clock++;
    }
        else
        {
            for (index=1;index<k;index++)
                tail=tail->prev;
            q=tail;
            tail = tail->prev;
            q->prev->next=q->next;
            q->next->prev=q->prev;
            free(q);
            clock++;
            
            
            }
    }
    result=tail->key;
    free(tail);
    return result;
    }
       

struct node *CreateCircularDoublyLinkedList(int n)
{
    struct node *tail;
    int index;
    
    tail=NULL;
    for(int index=1;index<=n;index++) 
        tail=InsertInCircularDoublyLinkedList(tail,index);
    return tail;
    }
    
int main()
{
	struct node *tail;
	int n=1,k=1, result;
	while((scanf("%d %d",&n,&k)) && n!=0 && k!=0){
		tail=CreateCircularDoublyLinkedList(n);
		result=JosephusLottery(tail, k);
		printf("%d \n",result);
		}
	return 0;
}
