//#include <bits/stdc++.h>

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <ctime>

using namespace std;
#define endl '\n'

struct nodeTree
{
    int frecuencia;
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
        printf("%d ",x->key);
        InOrderTreeWalk(x->right);
        }
}

struct nodeTree *TreeSearch(struct nodeTree *x,long long k)
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

struct nodeTree *TreeInsert(struct nodeTree *T, long long k)
{
    struct nodeTree *x,*y,*z;
    z=(struct nodeTree *)malloc(sizeof(struct nodeTree));
    z->key=k;
    z->frecuencia=1;
    z->right=NULL;
    z->left=NULL;
    y=NULL;
    x=T;

    while(x!=NULL)
    {
        y=x;
        if(z->key < x->key)
            x= x->left;
        else
            x=x->right;
    }
    z->p=y;
    if(y==NULL)
        T=z;
    else
    {
        if(z->key < y->key)
            y->left=z;
        else
            y->right=z;
    }
    return T;
}


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
        z->frecuencia=y->frecuencia;
        /*Copiar todo el resto de campos de informacion. */
    }
    free(y);
    return T;
}
















int main()
{
    //fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    struct nodeTree *numeros=NULL;
    struct nodeTree *busquedas=NULL;
    struct nodeTree *succ,*prec;
    int cant_operaciones;
    cin>>cant_operaciones;
    int valor;
    for(int a=0;a<cant_operaciones;a++){
            int largo;
            cin>>largo;
            for(int b=0;b<largo;b++){
                    cin>>valor;
                    busquedas=TreeSearch(numeros,valor);
                    if(busquedas==NULL){
                                        numeros=TreeInsert(numeros,valor);                 
                    }
                    else{
                         busquedas->frecuencia=busquedas->frecuencia + 1;     
                    }
            }
            int transacciones;
            cin>>transacciones;
            for(int c=0;c<transacciones;c++){
                    int realizar;
                    cin>>realizar;
                    int numero;
                    cin>>numero;
                    if(realizar==1){
                                    busquedas=TreeSearch(numeros,numero);
                                    if(busquedas==NULL){
                                         numeros=TreeInsert(numeros,numero);
                                         busquedas=TreeSearch(numeros,numero);
                                         prec=TreePredeccessor(busquedas);
                                         succ=TreeSuccessor(busquedas);
                                         if((prec==NULL) && (succ==NULL)) cout<<"-1 100001\n";
                                         if((prec==NULL) && (succ!=NULL)) cout<<"-1 "<<succ->key<<endl;
                                         if((prec!=NULL) && (succ==NULL)) cout<<prec->key<<" 100001\n";
                                         if((prec!=NULL) && (succ!=NULL)) cout<<prec->key<<" "<<succ->key<<endl;
                                         numeros=TreeDelete(numeros,busquedas);
                                    }
                                    else{
                                         prec=TreePredeccessor(busquedas);
                                         succ=TreeSuccessor(busquedas);
                                         if((prec==NULL) && (succ==NULL)) cout<<"-1 100001\n";
                                         if((prec==NULL) && (succ!=NULL)) cout<<"-1 "<<succ->key<<endl;
                                         if((prec!=NULL) && (succ==NULL)) cout<<prec->key<<" 100001\n";
                                         if((prec!=NULL) && (succ!=NULL)) cout<<prec->key<<" "<<succ->key<<endl;
                                    }
                    }
                    if(realizar==2){
                                    busquedas=TreeSearch(numeros,numero);
                                    if(busquedas==NULL){
                                                        numeros=TreeInsert(numeros,numero);                    
                                    }
                                    else{
                                         busquedas->frecuencia=busquedas->frecuencia + 1;     
                                    }
                    }
                    if(realizar==3){
                                    busquedas=TreeSearch(numeros,numero);
                                    if(busquedas!=NULL){
                                                        if(busquedas->frecuencia==1){
                                                                                    numeros=TreeDelete(numeros,busquedas);                            
                                                        }
                                                        else{
                                                             busquedas->frecuencia=busquedas->frecuencia - 1;     
                                                        }
                                    }                
                    }
            }
            numeros=NULL;
    }
    return 0;
}
