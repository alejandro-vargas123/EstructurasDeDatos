//#include <bits/stdc++.h>

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <ctime>

using namespace std;

struct nodeTree
{
    int prior;
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
    return T;
}







struct nodeTree *TreeInsert2(struct nodeTree *T, int k,int m)
{
    struct nodeTree *x,*y,*z;
    z=(struct nodeTree *)malloc(sizeof(struct nodeTree));
    z->key=k;
    z->prior=m;
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







struct nodeTree *busqueda(struct nodeTree *x,int k)
{
    struct nodeTree *r1=TreePredeccessor(x);
    struct nodeTree *r2=TreeSuccessor(x);
    if((x->key < k) && (k < r2->key)){
        //cout<<"Entro\n";
        return x;
    }
    if(k < x->key){
        busqueda(r1,k);
    }
    if(k > x->key){
        busqueda(r2,k);
    }
}








int main()
{
    unsigned t0, t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;
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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //Altura de las chimpance hembra con la variable (N)
    //Altura del chimpance con la varible (K)

    t0=t1=t2=t3=t4=t5=t6=t7=t8=t9=t10=t11=t12=0;

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
        chimpance=TreeInsert2(chimpance,b,a);
    }
    //cout<<"mostrar los arboles"<<endl;
    //InOrderTreeWalk(alturas);
    //cout<<endl;
    //InOrderTreeWalk(chimpance);
    //cout<<endl;
    struct nodeTree *aa;
    struct nodeTree *cc;
    //tmp=NULL;
    //tark=NULL;

    /*for(int a=0;a<k;a++){
        int z;
        cout<<"Ingrese valor a buscar: ";
        cin>>z;
        struct nodeTree *y=TreeSearch(alturas,z);
        if(y==NULL) cout<<"NO\n"; //Estructura para hacer la busqueda
        if(y!=NULL){
            if(z==y->key) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }*/
    //cout<<endl<<endl;
    /*cout<<"Altura maxima de las chimpances en cada momento\n";
    for(int a=0;a<n;a++){
        aa=TreeMaximum(alturas);
        cout<<aa->key<<" ";
        alturas=TreeDelete(alturas,aa);
    }
    cout<<endl;
    cout<<"Alturas posibles del chimpance y que sea maxima en cada momento\n";
    for(int a=0;a<k;a++){
        cc=TreeMaximum(chimpance);
        cout<<cc->key<<" ";
        chimpance=TreeDelete(chimpance,cc);
    }
    cout<<endl;
    if(alturas==NULL) cout<<"El arbol de alturas esta vacio\n";
    if(chimpance==NULL) cout<<"El arbol de chimpance esta vacio\n";*/
    struct nodeTree *rr, *zz;
    for(int a=0;a<k;a++){
        if((n==0) || (k==0)) cout<<"X X\n"; //si se me dan dos li
        else{
            t0=clock();//////////////////////
            aa=TreeMinimum(chimpance); //altura actual del chimpance
            t1=clock();////////////////
            cc=TreeSearch(alturas,aa->key); //resultado de busqueda en alturas
            t2=clock();///////////////

            //cout<<"estamos saliendo\n";

            if(cc!=NULL){

                if(aa->key==cc->key){ //si se da que se encuetra en alturas
                    t3=clock();////////////////////////
                    rr=TreePredeccessor(cc);
                    t4=clock();//////////////////77777
                    zz=TreeSuccessor(cc);
                    t5=clock();
                    if((rr==NULL) && (zz==NULL)) cout<<"X X\n";
                    if((rr==NULL) && (zz!=NULL)){
                        //cout<<"*****\n";
                        t6=clock();////////////////////////
                        while(cc->key==zz->key){
                            //cout<<"__ ";
                            zz=TreeSuccessor(zz);
                            //zz=zz->right;
                            if(zz==NULL) break;
                        }
                        cout<<endl;
                        t7=clock();///////////////////////
                        if(zz==NULL) cout<<"X X\n";
                        else cout<<"X "<<zz->key<<endl; //aqui habia if(zz!=NULL)

                    }
                    //t12=clock();////////////////////////
                    if((rr!=NULL) && (zz==NULL))
                    //t8=clock();///////////////////////////
                    {
                        cout<<rr->key<<" X\n";
                    }
                    if((rr!=NULL) && (zz!=NULL)){

                        while(cc->key==zz->key){
                            zz=TreeSuccessor(zz);
                            if(zz==NULL) break;
                        }
                        t9=clock();//////////////////////////////
                        if(zz==NULL) cout<<rr->key<<" X\n";
                        t10=clock();///////////////////
                        if(zz!=NULL) cout<<rr->key<<" "<<zz->key<<endl;
                        t11=clock();////////////////////
                    }
                }
                /*else{
                    cout<<"YES\n";
                }*/
            }
            if(cc==NULL){

                struct nodeTree *s1=TreeMinimum(alturas);
                struct nodeTree *s2=TreeMaximum(alturas);

                //cout<<"Minimo alturas: "<<s1->key<<endl;
                //cout<<"Maximo alturas: "<<s2->key<<endl;
                if(s1->left==NULL && s1->right==NULL){
                    if(s1->key > aa->key) cout<<"X "<<s1->key<<endl;
                    else cout<<s1->key<<" X\n";
                }
                else{
                    if(aa->key < s1->key) cout<<"X "<<s1->key<<endl;
                    else{
                        if(aa->key > s2->key) cout<<s2->key<<" X\n";
                        else{
                            struct nodeTree *mas_cercano=busqueda(alturas,aa->key);
                            struct nodeTree *kr=TreeSuccessor(mas_cercano);
                            cout<<mas_cercano->key<<" "<<kr->key<<endl;
                        }
                    }
                }
            }
        }
        chimpance=TreeDelete(chimpance,aa);
    }

    double time1 = (double(t1-t0)/CLOCKS_PER_SEC);
    double time2 = (double(t2-t1)/CLOCKS_PER_SEC);
    double time3 = (double(t4-t3)/CLOCKS_PER_SEC);
    double time4 = (double(t5-t4)/CLOCKS_PER_SEC);
    double time5 = ((double(t7-t6)/CLOCKS_PER_SEC))/1000.;
    //double time6 = (double(t8-t12)/CLOCKS_PER_SEC);
    double time7 = (double(t10-t9)/CLOCKS_PER_SEC);
    double time8 = (double(t11-t10)/CLOCKS_PER_SEC);
    cout << "Execution Time1: " << time1 << endl;
    cout << "Execution Time2: " << time2 << endl;
    cout << "Execution Time3: " << time3 << endl;
    cout << "Execution Time4: " << time4 << endl;
    cout << "Execution Time5: " << time5 << endl;
    //cout << "Execution Time6: " << time6 << endl;
    cout << "Execution Time7: " << time7 << endl;
    cout << "Execution Time8: " << time8 << endl;
   return 0;
}
