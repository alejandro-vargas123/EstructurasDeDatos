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

    struct nodeTree *alturas=NULL, *z; //alturas de las chimpances(inicializadas en NULL)
    int n; //cantidad de alturas de las chimpances
    //scanf("%d", &n);
    cin>>n;
    int b;//varible para ingresar las alturas

    for(int a=0;a<n;a++){
        //scanf("%d", &b);
        cin>>b;
        z = TreeSearch(alturas, b);
        if(z == NULL)
            alturas=TreeInsert(alturas,b);
    }

    int k;//cantidad de alturas del chimpance macho
    //scanf("%d", &k);
    cin>>k;

    struct nodeTree *pred;
    struct nodeTree *succ;

    for(int a=0;a<k;a++)
    {
        //scanf("%d", &b);
        cin>>b;
        z = TreeSearch(alturas, b);
        if(z != NULL)
        {
            pred = TreePredeccessor(z);
            succ = TreeSuccessor(z);
            if(pred == NULL)
            {
                if(succ == NULL)
                    printf("X X\n");
                else
                    printf("X %d\n", succ->key);
            }
            else
            {
                if(succ == NULL)
                    printf("%d X\n", pred->key);
                else
                    printf("%d %d\n", pred->key, succ->key);
            }
        }
        else
        {
            alturas = TreeInsert(alturas, b);
            z = TreeSearch(alturas, b);
            pred = TreePredeccessor(z);
            succ = TreeSuccessor(z);
            if(pred == NULL)
            {
                if(succ == NULL)
                    printf("X X\n");
                else
                    printf("X %d\n", succ->key);
            }
            else
            {
                if(succ == NULL)
                    printf("%d X\n", pred->key);
                else
                    printf("%d %d\n", pred->key, succ->key);
            }
            alturas = TreeDelete(alturas, z);
        }
    }
    return 0;
}
