//#include <bits/stdc++.h>

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

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

struct nodeTree *TreeInsert(struct nodeTree *T, int k)
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







struct nodeTree *busqueda(struct nodeTree *x,int k)
{
    if((x->key==k) && (x->right==NULL)) return x;
    if( (x->key < k) && (k < x->right->key) ){
        return x;
    }
    if((x==NULL) || (k== x->key))
        return x;
    if (k< x->key)
        return TreeSearch(x->left, k);
    else
        return TreeSearch(x->right, k);
}








int main()
{
    /*int operation,element;
    struct nodeTree *T, *z;
    T=NULL;

    while(scanf("%d", &operation) !=EOF)
    {
        scanf("%d", &element);
        if (operation==1)
        {
            T=TreeInsert(T,element);
            InOrderTreeWalk(T);
            printf("\n");
        }
        else
        {
            if (operation==2)
            {
            z= TreeSearch(T, element);
            if(z!=NULL)
            {
                T=TreeDelete(T,z);
                InOrderTreeWalk(T);
                printf("\n");
            }
            else
                printf("The element %d is not in the tree.\n",element);
            }
        else
            printf("Invalid operation. \n Use \n 1.Insert \n 2. Delete");
        }
    }*/
    //Altura de las chimpance hembra con la variable (N)
    //Altura del chimpance con la varible (K)
    struct nodeTree *alturas=NULL; //alturas de las chimpances(inicializadas en NULL)
    struct nodeTree *chimpance=NULL; //alturas del chimpance (Inicializadas en NULL)
    int n; //cantidad de alturas de las chimpances
    cin>>n;
    int b;//varible para ingresar las alturas
    for(int a=0;a<n;a++){
        cin>>b;//Ingresar la altura de la chimpance
        alturas=TreeInsert(alturas,b);
    }
    int k;//cantidad de alturas del chimpance macho
    cin>>k;
    for(int a=0;a<k;a++){
        cin>>b;
        chimpance=TreeInsert(chimpance,b);
    }
    cout<<endl;
    struct nodeTree *tark;
    struct nodeTree *tmp;
    tmp=NULL;
    tark=NULL;
    for(int a=0;a<k;a++){ //ciclo principal para comparar todas las alturas(SE HACE CON LA VARIABLE K)
        tmp=TreeMinimum(chimpance);//Variable que tiene la altura actual mas pequeña del chimpance
        tark=busqueda(alturas,tmp->key);//falta por modificar bien la funcion para que parezca busqueda binaria
        struct nodeTree *m=TreeMaximum(alturas);
        //cout<<"tmp: "<<tmp->key<<endl;
        //cout<<"tark: "<<tark->key<<endl;
        if(tmp->key==tark->key){ //Se mira si la altura coincide con la del chimpance
            if(tark->p!=NULL){ //Si el predecesor es un numero y no "X"
                //cout<<"Entro cuando el izquierdo no es NULL\n";
                struct nodeTree *y,*z;
                y=tark->p; //predecesor
                z=tark->right;
                //cout<<"Y: "<<y<<endl;
                //cout<<"Z: "<<z<<endl;
                while((z->key == tark->key) && (z!=NULL)){
                    z=z->right;
                    if(z==NULL) break;
                    //cout<<"Z key: "<<z->key<<endl;
                }
                if(z!=NULL){ //si el sucesor no es "X"
                    cout<<y->key<<" "<<z->key<<endl;
                }
                if(z==NULL){//Si el sucesor es X y el predecesor no es "X"
                    if(z->right==NULL) cout<<"Z es null\n";
                    cout<<y->key<<" X\n";
                }
            }
            if(tark->p==NULL){
                struct nodeTree *z=tark->right;
                while((z->key==tark->key) && (z!=NULL)){
                    z=z->right;
                    if(z==NULL) break;
                }
                if(z!=NULL){
                    cout<<"X "<<z->key<<endl;
                }
                else{
                    cout<<"X X\n";
                }
            }
        }
        else{
            cout<<"NO\n"; //falta arreglar la funcion para cuando no de la coincidencia de encontrar la altura
        }
        chimpance=TreeDelete(chimpance,tmp);//ESTE BLOQUE VA AL FINAL(Libera tambien a tmp)
        tark=NULL;
        //free(tark); (Es liberada por la anterior solo si se encuentra la posicion)
    }
   return 0;
}
