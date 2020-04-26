#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define RED 1
#define BLACK 0
#define NIL 2147483647

using namespace std;

struct  nodeTree{
    int key;
    int color;
    int frecuencia;
    struct nodeTree *parent;
    struct nodeTree *left;
    struct nodeTree *right;
};

struct nodeTree *Assing_Nil()
{
    struct nodeTree *z;
    z = (struct nodeTree *)malloc(sizeof(struct nodeTree));
    z->parent = NULL;
    z->right = NULL;
    z->left = NULL;
    z->key = NIL;
    z->color = BLACK;

    return z;
}
//------------------------------------------------PRINT------------------------------------------------------------------------
void RBInorderTreeWalk(struct nodeTree *root)
{
    if(root->key != NIL)
    {
        RBInorderTreeWalk(root->left);
        if(root->color == RED)
            printf("[%d | RED] ", root->key);
        else
            printf("[%d | BLACK] ", root->key);
        RBInorderTreeWalk(root->right);
    }
}
//---------------------------------------------------SEARCH--------------------------------------------------------------------
//-----------------------------------------------RECURSIVE TREE SEARCH---------------------------------------------------------
struct nodeTree *nodeTreeearch(struct nodeTree *root, int element)
{
    if(((root->key) == NIL) || (element == (root->key)))
        return root;
    if(element < (root->key))
        return nodeTreeearch((root->left), element);
    else
        return nodeTreeearch((root->right), element);
}
//----------------------------------------------ITERATIVE TREE SEARCH----------------------------------------------------------
struct nodeTree *RB_IterativeTreeSearch(struct nodeTree *root, int element)
{
    while(((root->key) != NIL) && (element != (root->key)))
    {
        if( element < (root->key))
            root = root->left;
        else
            root = root->right;
    }
    return root;
}
//-----------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------ROTATIONS--------------------------------------------------------------------
//----------------------------------------------LEFT ROTATION------------------------------------------------------------------
struct nodeTree *RB_LeftRotate(struct nodeTree *root, struct nodeTree *x)
{
    struct nodeTree *y;
    y = x->right;
    x->right = y->left;
    if((y->left->key) != NIL)
        y->left->parent =x;
    y->parent = x->parent;
    if((x->parent->key) == NIL)
        root = y;
    else if(x == (x->parent->left))
        x->parent->left = y;
    else
         x->parent->right = y;
    y->left = x;
    x->parent = y;
    return root;
}
//------------------------------------------------RIGHT ROTATION---------------------------------------------------------------
struct nodeTree *RB_RightRotate(struct nodeTree *root, struct nodeTree *node)
{
    struct nodeTree *y;
    y = node->left;
    node->left = y->right;
    if((y->right->key) != NIL)
        y->right->parent = node;
    y->parent = node->parent;
    if((node->parent->key) == NIL)
        root = y;
    else if( node == (node->parent->right))
        node->parent->right = y;
    else
        node->parent->left = y;

    y->right = node;
    node->parent = y;
    return root;
}
//-----------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------MINIMUN & MAXIMUN-----------------------------------------------------
//-------------------------------------------------------MINIMUN---------------------------------------------------------------
struct nodeTree *RB_Minimun(struct nodeTree *root)
{
    while((root->left->key) != NIL)
    {
        root = root->left;
    }
    return root;
}
//--------------------------------------------------------MAXIMUN--------------------------------------------------------------
struct nodeTree *RB_Maximun(struct nodeTree *root)
{
    while((root->right->key) != NIL)
    {
        root = root->right;
    }
    return root;
}

//-----------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------SUCCESSOR & PREDECCESSOR---------------------------------------------------------
//-------------------------------------------------SUCCESSOR-------------------------------------------------------------------
struct nodeTree *nodeTreeuccessor(struct nodeTree *node)
{
    struct nodeTree *y;
    if((node->right->key) != NIL)
        return RB_Minimun(node->right);
    y = node->parent;
    while(((y->key) != NIL) && (node == (y->right)))
    {
        node = y;
        y = y->parent;
    }
    return y;
}
//-------------------------------------------------------PREDECCESSOR----------------------------------------------------------
struct nodeTree *RB_TreePredeccessor(struct nodeTree *node)
{
    struct nodeTree *y;
    if((node->left->key) != NIL)
        return RB_Maximun(node->left);
    y = node->parent;
    while(((y->key) != NIL) && (node == (y->left)))
    {
        node = y;
        y = y->parent;
    }
    return y;
}
//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------FIX UP FUCTIONS---------------------------------------------------------------------
//-----------------------------------------Insert Fix Up-----------------------------------------------------------------------
struct nodeTree *RB_InsertFixUp(struct nodeTree *root, struct nodeTree *node)
{
    struct nodeTree *y;
    while((node->parent->color) == RED)
    {
        if((node->parent) == (node->parent->parent->left))
        {
            y = node->parent->parent->right;
            if((y->color) == RED)//-------------------------------------CASE 1-------------------------------------------------
            {
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if(node == (node->parent->right))//-----------------------------------CASE 2----------------------------------
                {
                    node = node->parent;
                    root = RB_LeftRotate(root,node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                root = RB_RightRotate(root,(node->parent->parent));
            }
        }
        else
        {
            y = node->parent->parent->left;
            if((y->color) == RED)
            {
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if(node == (node->parent->left))
                {
                    node = node->parent;
                    root = RB_RightRotate(root,node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                root = RB_LeftRotate(root,(node->parent->parent));
            }
        }
    }
    root->color = BLACK;
    return root;
}
//--------------------------------------------------------Delete Fix Up--------------------------------------------------------
struct nodeTree *RB_DeleteFixUp(struct nodeTree *root, struct nodeTree *node)
{
    struct nodeTree *w;
    while((node != root) && ((node->color) == BLACK))
    {
        if(node == (node->parent->left))
        {
            w = node->parent->right;
            if((w->color) == RED)
            {
                w->color = BLACK;
                node->parent->color = RED;
                root = RB_LeftRotate(root,(node->parent));
                w = node->parent->right;
            }

            if(((w->left->color) == BLACK) && ((w->right->color) == BLACK))
            {
                w->color =  RED;
                node = node->parent;
            }
            else
            {
                if((w->right->color) == BLACK)
                {
                    w->left->color == BLACK;
                    w->color = RED;
                    root = RB_RightRotate(root, w);
                    w = node->parent->right;
                }
                w->color = node->parent->color;
                node->parent->color = BLACK;
                w->right->color = BLACK;
                root = RB_LeftRotate(root,(node->parent));
                node = root;
            }
        }
        else
        {
            w = node->parent->left;
            if((w->color) == RED)
            {
                w->color = BLACK;
                node->parent->color = RED;
                root = RB_RightRotate(root,(node->parent));
                w = node->parent->left;
            }

            if(((w->left->color) == BLACK) && ((w->right->color) == BLACK))
            {
                w->color = RED;
                node = node->parent;
            }
            else
            {
                if((w->left->color) == BLACK)
                {
                    w->right->color =BLACK;
                    w->color = RED;
                    root = RB_LeftRotate(root,w);
                    w = node->parent->left;
                }
                w->color = node->parent->color;
                node->parent->color = BLACK;
                w->left->color = BLACK;
                root = RB_RightRotate(root,(node->parent));
                node = root;
            }
        }
    }
    node->color = BLACK;
    return root;
}
//-----------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------RB INSERT & DELETE----------------------------------------------------------------
//----------------------------------------------RB INSERT----------------------------------------------------------------------
struct nodeTree *RB_Insert(struct nodeTree *root, int element)
{
    struct nodeTree *x, *y, *z;
    z = (struct nodeTree *) malloc(sizeof(struct nodeTree));
    z->key = element;
    z->frecuencia = 1;
    z->color = RED;
    z->left = Assing_Nil();
    z->left->parent = z;
    z->right = Assing_Nil();
    z->right->parent = z;

    if(root->key != NIL)
        y = root->parent;
    else
        y = root;

    x = root;
    while(x->key != NIL)
    {
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if(y->key == NIL)
        root = z;
    else
    {
        if(z->key < y->key)
        {
            free(y->left);
            y->left = z;

        }
        else
        {
            free(y->right);
            y->right = z;
        }
    }
    return RB_InsertFixUp(root, z);
}
//------------------------------------------------RB DELETE--------------------------------------------------------------------
struct nodeTree *RB_Delete(struct nodeTree *root, struct nodeTree *node)
{
    struct nodeTree *x, *y;
    if(((node->left->key) == NIL) || ((node->right->key) == NIL))
        y = node;
    else
        y = nodeTreeuccessor(node);

    if((y->left->key) != NIL)
        x = y->left;
    else
        x = y->right;

    x->parent = y->parent;
    if((y->parent->key) == NIL)
        root = x;
    else
    {
        if(y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    }

    if(y != node)
        node->key = y->key;
        node->frecuencia = y->frecuencia;
        //copy all information  camps

    if(y->color == BLACK) {
        root = RB_DeleteFixUp(root, x);
  }

    if(y->left->parent == y)
        free(y->left);

    if(y->right->parent == y)
        free(y->right);

    free(y);
    return root;
}



int main() {
    struct nodeTree *succ,*prec;
    int cant_operaciones;
    cin>>cant_operaciones;
    int valor;
    struct nodeTree *numeros = Assing_Nil();
    for(int a=0;a<cant_operaciones;a++){
            struct nodeTree *busquedas;
            int largo;
            cin>>largo;
            for(int b=0;b<largo;b++){
                    cin>>valor;
                    busquedas=nodeTreeearch(numeros,valor);
                    if(busquedas->key==NIL){
                                        numeros=RB_Insert(numeros,valor);
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
                                    busquedas=nodeTreeearch(numeros,numero);
                                    if(busquedas->key==NIL){
                                         numeros=RB_Insert(numeros,numero);
                                         busquedas=nodeTreeearch(numeros,numero);
                                         prec=RB_TreePredeccessor(busquedas);
                                         succ=nodeTreeuccessor(busquedas);
                                         //cout<<"predecesor: "<<prec->key<<endl;
                                         //cout<<"sucesor: "<<succ->key<<endl;
                                         //RBInorderTreeWalk(numeros);
                                         if((prec->key==NIL) && (succ->key==NIL)) cout<<"-1 100001\n";
                                         if((prec->key==NIL) && (succ->key!=NIL)) cout<<"-1 "<<succ->key<<endl;
                                         if((prec->key!=NIL) && (succ->key==NIL)) cout<<prec->key<<" 100001\n";
                                         if((prec->key!=NIL) && (succ->key!=NIL)) cout<<prec->key<<" "<<succ->key<<endl;
                                         numeros=RB_Delete(numeros,busquedas);
                                    }
                                    else{
                                         prec=RB_TreePredeccessor(busquedas);
                                         succ=nodeTreeuccessor(busquedas);
                                         //cout<<"predecesor: "<<prec->key<<endl;
                                         //cout<<"sucesor: "<<succ->key<<endl;
                                         //RBInorderTreeWalk(numeros);
                                         if((prec->key==NIL) && (succ->key==NIL)) cout<<"-1 100001\n";
                                         if((prec->key==NIL) && (succ->key!=NIL)) cout<<"-1 "<<succ->key<<endl;
                                         if((prec->key!=NIL) && (succ->key==NIL)) cout<<prec->key<<" 100001\n";
                                         if((prec->key!=NIL) && (succ->key!=NIL)) cout<<prec->key<<" "<<succ->key<<endl;
                                    }
                    }
                    if(realizar==2){
                                    busquedas=nodeTreeearch(numeros,numero);
                                    if(busquedas->key==NIL){
                                                        numeros=RB_Insert(numeros,numero);
                                    }
                                    else{
                                         busquedas->frecuencia=busquedas->frecuencia + 1;
                                    }
                    }
                    if(realizar==3){
                                    busquedas=nodeTreeearch(numeros,numero);
                                    if(busquedas->key!=NIL){
                                                        if(busquedas->frecuencia==1){
                                                                                    numeros=RB_Delete(numeros,busquedas);
                                                        }
                                                        else{
                                                             busquedas->frecuencia=busquedas->frecuencia - 1;
                                                        }
                                    }
                    }
            }
            while(numeros->key != NIL){
                numeros = RB_Delete(numeros,numeros);
            }
    }
  return 0;
}
