#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include <sstream>
#include<vector>
#include <algorithm>

using namespace std;

struct nodeTree
{
    int prior;
    int cant;
    int key;
    struct nodeTree *p;
    struct nodeTree *left;
    struct nodeTree *right;
};


void InOrderTreeWalk(struct nodeTree *x)
{
    if(x !=NULL)
    {
        InOrderTreeWalk(x->left);
        //printf("%d %d\n",x->key,x->cant);
        printf("%d %d\n",x->key,x->cant);
        InOrderTreeWalk(x->right);
        }
}

struct nodeTree *TreeSearch(struct nodeTree *x,int k)
{
    if((x==NULL) || (k== x->key))
        return x;
    if (k< x->key)
        return TreeSearch(x->left, k);
    else
        return TreeSearch(x->right, k);
    }


struct nodeTree *TreeMinimum(struct nodeTree *x)
{
    while(x->left !=NULL)
        x=x->left;
    return x;
    }


struct nodeTree *TreeMaximum(struct nodeTree *x)
{
    while(x->right !=NULL)
        x=x->right;
    return x;
    }


struct nodeTree *TreeSuccessor(struct nodeTree *x)
{
    struct nodeTree *y;

    if(x->right != NULL)
        return TreeMinimum(x->right);

    y= x->p;
    while((y != NULL)&&(x==y->right))
    {
        x=y;
        y=y->p;
    }
    return y;
    }

struct nodeTree *TreePredeccessor(struct nodeTree *x)
{
    struct nodeTree *y;

    if(x->left != NULL)
        return TreeMaximum(x->left);

    y= x->p;
    while((y != NULL)&&(x==y->left))
    {
        x=y;
        y=y->p;
    }
    return y;
    }

struct nodeTree *TreeInsert(struct nodeTree *T, int k,int pri)
{
    struct nodeTree *x,*y,*z;
    z=(struct nodeTree *)malloc(sizeof(struct nodeTree));
    z->key=k;
    z->cant=1;
    z->prior=pri;
    z->right=NULL;
    z->left=NULL;
    y=NULL;
    x=T;

    while(x!=NULL)
    {
        y=x;
        if(z->prior < x->prior)
            x= x->left;
        else
            x=x->right;
    }
    z->p=y;
    if(y==NULL)
        T=z;
    else
    {
        if(z->prior < y->prior)
            y->left=z;
        else
            y->right=z;
    }
    return T;}

struct nodeTree *TreeDelete(struct nodeTree *T, struct nodeTree *z)
{
    struct nodeTree *x,*y;

    if((z->left== NULL)||(z->right==NULL))
        y=z;
    else
        y=TreeSuccessor(z);
    if(y->left != NULL)
        x=y->left;
    else
        x=y->right;

    if (x != NULL)
        x->p=y->p;
    if(y->p == NULL)
        T=x;
    else
    {
        if(y == y->p->left)
            y->p->left=x;
        else
            y->p->right=x;
    }

    if(y!=z)
    {
        z->key = y->key;
        /*Copiar todo el resto de campos de informacion. */
    }
    free(y);
    return T;
}

void Repetitions (struct nodeTree *T,int k)
{
	struct nodeTree *Q;
	Q=TreeSuccessor(T);
	int rep=1;

	while (T->key=Q->key)
	{
		rep+=1;
		T=Q;
		Q=TreeSuccessor(T);
	}

	printf("%d %d \n",k,rep);
	exit;
}


int main()
{
    string line;
	getline( cin, line );
	istringstream is(line);
	struct nodeTree *numeros=NULL;
	cout<<endl;
	int n;
	struct nodeTree *rr;
	int prior=1;
	while(is >> n){
        rr=TreeSearch(numeros,n);
        if(rr==NULL){ //no se encontro el numero en el arbol
            numeros=TreeInsert(numeros,n,prior);
            prior++;
        }
        else{
            rr->cant=rr->cant+1;
        }
	}
    InOrderTreeWalk(numeros);
    return 0;
}
