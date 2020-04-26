#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#define RED 1
#define BLACK 0
#define NIL 2147483647

using namespace std;
//#define endl '\n'

//-----------------------------------------------------------------------------//
struct nodeTree {
  int cant;
  int frecuencia;
  int key;
  int color;
  struct nodeTree *Left;
  struct nodeTree *Right;
  struct nodeTree *p;
};
//-----------------------------------------------------------------------------//
struct nodeTree *AssignNIL() {
  struct nodeTree *z;
  z=(struct nodeTree *) malloc(sizeof(struct nodeTree));
  z->p=NULL;
  z->Right=NULL;
  z->Left=NULL;
  z->key=NIL;
  z->color = BLACK;
  return z;
}





struct nodeTree *RightRotate(struct nodeTree *root, struct nodeTree *node) //funcionales
{
    struct nodeTree *y;
    y = node->Left;
    node->Left = y->Right;
    if((y->Right->key) != NIL)
        y->Right->p = node;
    y->p = node->p;
    if((node->p->key) == NIL)
        root = y;
    else if( node == (node->p->Right))
        node->p->Right = y;
    else
        node->p->Left = y;

    y->Right = node;
    node->p = y;
    return root;
}




struct nodeTree *LeftRotate(struct nodeTree *root, struct nodeTree *x)
{
    struct nodeTree *y;
    y = x->Right;
    x->Right = y->Left;
    if((y->Left->key) != NIL)
        y->Left->p =x;
    y->p = x->p;
    if((x->p->key) == NIL)
        root = y;
    else if(x == (x->p->Left))
        x->p->Left = y;
    else
         x->p->Right = y;
    y->Left = x;
    x->p = y;
    return root;
}
















//-----------------------------------------------------------------------------//
/*struct nodeTree *RBTreeLeftRotate(struct nodeTree *T, struct nodeTree *x) {
  struct nodeTree *y;
  y = x->Right;
  x->Right = y->Left;
  y->Left->p = x;
  y->p = x->p;
  if(x->p->key == NIL) {
    T = y;
  }
  else{
    if(x == x->p->Left) {
      x->p->Left = y;
    }
    else{
      x->p->Right = y;
    }
  }
  y->Left = x;
  x->p = y;
  return T;
}*/
//-----------------------------------------------------------------------------//
/*struct nodeTree *RBTreeRightRotate(struct nodeTree *T, struct nodeTree *x) {
  struct nodeTree *y;
  y = x->Left;
  x->Left = y->Right;
  y->Right->p = x;
  y->p = x->p;
  if(x->p->key == NIL) {
    T = y;
  }
  else{
    if(x == x->p->Right) {
      x->p->Right = y;
    }
    else{
      x->p->Left = y;
    }
  }
  y->Right = x;
  x->p = y;
  //printf("Rote a la derecha.\n");
  return T;
}*/
//-----------------------------------------------------------------------------//
void RBInorderTreeWalk(struct nodeTree *x) {
  if(x->key != NIL) {
    RBInorderTreeWalk(x->Left);
    if(x->color == RED)
      printf("[%d|R] ", x->key);
    else
      printf("[%d|B] ", x->key);
    RBInorderTreeWalk(x->Right);
  }
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreeSearch(struct nodeTree *x, int k) {
  if ((x->key == NIL) || (k == x->key)) {
    return x;
  }
  if(k < x->key) {
    return RBTreeSearch(x->Left,k);
  } else {
    return RBTreeSearch(x->Right,k);
  }
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreeMinimum(struct nodeTree *x) {
  while (x->Left->key != NIL) {
    x = x->Left;
  }
  return x;
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreeMaximun(struct nodeTree *x) {
  while (x->Right->key != NIL) {
    x = x->Right;
  }
  return x;
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreeSuccessor(struct nodeTree *x) {
  if (x->Right->key != NIL) {
    return RBTreeMinimum(x->Right);
  }
  struct nodeTree *y;
  y = x->p;
  while ((y->key != NIL) && (x == y->Right)) {
    x = y;
    y = y->p;
  }
  return y;
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreePredeccessor(struct nodeTree *x) {
  if (x->Left->key != NIL) {
    return RBTreeMaximun(x->Left);
  }
  struct nodeTree *y;
  y = x->p;
  while ((y->key != NIL) && (x == y->Left)) {
    x = y;
    y = y->p;
  }
  return y;
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreeInsertFIXUP(struct nodeTree *T, struct nodeTree *z) {
  struct nodeTree *y;
  while(z->p->color == RED) {
    if(z->p == z->p->p->Left) {
      y = z->p->p->Right;
      if(y->color == RED) {
        z->p->color = BLACK;
        y->color = BLACK;
        z->p->p->color = RED;
        z = z->p->p;
      }
      else{
        if(z == z->p->Right) {
          z = z->p;
          T = LeftRotate(T, z);
        }
        z->p->color = BLACK;
        z->p->p->color = RED;
        T = RightRotate(T, z->p->p);
      }
    }
    else{
        y = z->p->p->Left;
        if(y->color == RED) {
        z->p->color = BLACK;
        y->color = BLACK;
        z->p->p->color = RED;
        z = z->p->p;
        }
        else{
            if(z == z->p->Left) {
              z = z->p;
              T = RightRotate(T, z);
            }
            z->p->color = BLACK;
            z->p->p->color = RED;
            T = LeftRotate(T, z->p->p);
        }
    }
  }
  T->color = BLACK;
  return T;
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreeInsert(struct nodeTree *T, int element) {
    struct nodeTree *x, *y, *z;
    z = (struct nodeTree *) malloc(sizeof(struct nodeTree));
    z->key = element;
    z->frecuencia=1;
    z->color = RED;
    z->Left = AssignNIL();
    z->Right = AssignNIL();
    z->Right->p=z;
    z->Left->p=z;
    if(T->key != NIL) {
    y = T->p;
    }
    else{
    y = T;
    }
    x = T;
    while(x->key != NIL) {
        y = x;
        if(z->key < x->key) {
            x = x->Left;
    }
    else{
        x = x->Right;
    }
    }
	z->p = y;
	if(y->key == NIL) {
		T = z;
	}
	else{
        //free(x); ///////////////////
		if(z->key < y->key) {
			free(y->Left);
			y->Left = z;
		}
		else{
			free(y->Right);
			y->Right = z;
		}
	}
	return RBTreeInsertFIXUP(T, z);
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBDeleteFIXUP(struct nodeTree *T, struct nodeTree *x) {
  struct nodeTree *w;
  while ((x != T) && (x->color == BLACK)) {
    if (x == x->p->Left) {
      w = x->p->Right;
      if (w->color == RED) {
        w->color = BLACK;
        x->p->color = RED;
        T = LeftRotate(T, x->p);
        w = x->p->Right;
      }
      if ((w->Left->color == BLACK) && (w->Right->color == BLACK)) {
        w->color = RED;
        x = x->p;
      } else {
        if (w->Right->color == BLACK) {
          w->Left->color = BLACK;
          w->color = RED;
          T = RightRotate(T, w);
          w = x->p->Right;
        }
        w->color = x->p->color;
        x->p->color = BLACK;
        w->Right->color = BLACK;
        T = LeftRotate(T, x->p);
        x = T;
      }
    } else {
      w = x->p->Left;
      if (w->color == RED) {
        w->color = BLACK;
        x->p->color = RED;
        T = RightRotate(T, x->p);
        w = x->p->Left;
      }
      if ((w->Left->color == BLACK) && (w->Right->color == BLACK)) {
        w->color = RED;
        x = x->p;
      } else {
        if (w->Left->color == BLACK) {
          w->Right->color = BLACK;
          w->color = RED;
          T = LeftRotate(T, w);
          w = x->p->Left;
        }
        w->color = x->p->color;
        x->p->color = BLACK;
        w->Left->color = BLACK;
        T = RightRotate(T, x->p);
        x = T;
      }
    }
  }
  x->color = BLACK;
  return T;
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreeDelete(struct nodeTree *T, struct nodeTree *z) {
	struct nodeTree *x, *y;
	if((z->Left->key == NIL) || (z->Right->key == NIL)) {
		y = z;
	} else {
		y = RBTreeSuccessor(z);
  }
	if(y->Left->key != NIL) {
		x = y->Left;
	} else {
		x = y->Right;
  }
	x->p = y->p;
	if(y->p->key == NIL) {
		T = x;
	} else {
		if(y == y->p->Left) {
			y->p->Left = x;
		} else {
			y->p->Right = x;
    }
	}

	if(y != z) {
		z->key = y->key;
  }

	if(y->color == BLACK) {
		T = RBDeleteFIXUP(T, x);
  }

	if(y->Left->p == y) {
		free(y->Left);
  }

	if(y->Right->p == y) {
		free(y->Right);
  }
	free(y);
	return T;
}



//-----------------------------------------------------------------------------//
int main() {
  /*int operation, element;
  struct nodeTree *T;
  T = AssignNIL();
  while ((scanf("%d", &operation)) != EOF) {
    scanf("%d", &element);
    if (operation == 1) {
      T = RBTreeInsert(T, element);
      printf("[NIL] ");
      RBInorderTreeWalk(T);
      printf("\n");
    } else {
      if (operation == 2) {
        if (RBTreeSearch(T, element)->key != NIL) {
          T = RBTreeDelete(T,RBTreeSearch(T, element));
          printf("[NIL] ");
          RBInorderTreeWalk(T);
        } else {
          printf("Error: The value %d doesn't exist.", element);
        }
        printf("\n");
      } else {
        printf("Wrong operation, use: \n1: Insert.\n2: Delete\n");
      }
    }
  }*/


    //fast i/o
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    struct nodeTree *succ,*prec;
    int cant_operaciones;
    cin>>cant_operaciones;
    int valor;
    struct nodeTree *numeros = AssignNIL();
    for(int a=0;a<cant_operaciones;a++){
            struct nodeTree *busquedas;
            int largo;
            cin>>largo;
            for(int b=0;b<largo;b++){
                    cin>>valor;
                    busquedas=RBTreeSearch(numeros,valor);
                    if(busquedas->key==NIL){
                                        numeros=RBTreeInsert(numeros,valor);
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
                                    busquedas=RBTreeSearch(numeros,numero);
                                    if(busquedas->key==NIL){
                                         numeros=RBTreeInsert(numeros,numero);
                                         busquedas=RBTreeSearch(numeros,numero);
                                         prec=RBTreePredeccessor(busquedas);
                                         succ=RBTreeSuccessor(busquedas);
                                         //cout<<"predecesor: "<<prec->key<<endl;
                                         //cout<<"sucesor: "<<succ->key<<endl;
                                         //RBInorderTreeWalk(numeros);
                                         if((prec->key==NIL) && (succ->key==NIL)) cout<<"-1 100001\n";
                                         if((prec->key==NIL) && (succ->key!=NIL)) cout<<"-1 "<<succ->key<<endl;
                                         if((prec->key!=NIL) && (succ->key==NIL)) cout<<prec->key<<" 100001\n";
                                         if((prec->key!=NIL) && (succ->key!=NIL)) cout<<prec->key<<" "<<succ->key<<endl;
                                         numeros=RBTreeDelete(numeros,busquedas);
                                    }
                                    else{
                                         prec=RBTreePredeccessor(busquedas);
                                         succ=RBTreeSuccessor(busquedas);
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
                                    busquedas=RBTreeSearch(numeros,numero);
                                    if(busquedas->key==NIL){
                                                        numeros=RBTreeInsert(numeros,numero);
                                    }
                                    else{
                                         busquedas->frecuencia=busquedas->frecuencia + 1;
                                    }
                    }
                    if(realizar==3){
                                    busquedas=RBTreeSearch(numeros,numero);
                                    if(busquedas->key!=NIL){
                                                        if(busquedas->frecuencia==1){
                                                                                    numeros=RBTreeDelete(numeros,busquedas);
                                                        }
                                                        else{
                                                             busquedas->frecuencia=busquedas->frecuencia - 1;
                                                        }
                                    }
                    }
            }
            while(numeros->key != NIL){
                numeros = RBTreeDelete(numeros,numeros);
            }
    }
  return 0;
}
