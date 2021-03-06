#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodeTree
{
    int value;
    string key[20];// PROBLEMA
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

struct nodeTree *TreeSearch(struct nodeTree *x,string k)
{
    if((x==NULL) || (k==x->key)) //PROBLEMA
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

struct nodeTree *TreeInsert(struct nodeTree *T, string k,int g) //PROBLEMA
{
    struct nodeTree *x,*y,*z;
    z=(struct nodeTree *)malloc(sizeof(struct nodeTree));
    z->key=k;
    z->value=g;
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


/*int main()
{
    char word[20];
    int m, n, idParagraphs, idDictionary,  dollarValue;
    while(scanf("%d %d", &m, &n) != EOF)
    {
        for(idDictionary=1; idDictionary<=m; idDictionary++)
        {
            scanf("%s %d", word, &dollarValue);
        }

        for(idParagraphs=1; idParagraphs<=n; idParagraphs++)
        {
            do
            {
                scanf("%s", word);
                if(strcmp(word, ".") != 0)
                    printf(" %s", word);
            } while(strcmp(word, ".") != 0);

            printf("\n");
        }
    }

    return 0;
}*/





int main()
{
    char word[20];
    int m, n, idParagraphs, idDictionary,  dollarValue;
    struct nodeTree *diccionario=NULL, busqueda;
    int suma;
    //while(scanf("%d %d", &m, &n) != EOF)
    //{
        for(idDictionary=1; idDictionary<=m; idDictionary++)
        {
            scanf("%s %d", word, &dollarValue);
            diccionario=TreeInsert(diccionario,word,dollarValue); //PROBLEMA
        }
        suma=0;
        for(idParagraphs=1; idParagraphs<=n; idParagraphs++)
        {
            do
            {
                scanf("%s", word);
                if(strcmp(word, ".") != 0){
                    //printf(" %s", word);
                    busqueda=TreeSearch(diccionario,word); //se busca la palabra que esta en el momento en el diccionario
                    if(busqueda!=NULL){ //si la palabra actual esta presente en el diccionario
                        suma=suma + busqueda->value;
                    }
                    else{
                        suma=suma+0;
                    }
                }
            } while(strcmp(word, ".") != 0);

            printf("%d\n",&suma);
        }
    //}

    return 0;
}

