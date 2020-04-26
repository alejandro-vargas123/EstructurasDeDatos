#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NIL 2147483647

//-----------------------------------------------------------------------------//
struct nodeTree {
  int key;
  bool color;//Red=1, Black=0
  struct nodeTree *Left;
  struct nodeTree *Right;
  struct nodeTree *p;
};
//-----------------------------------------------------------------------------//
struct nodeTree *AssignNIL() {
  struct nodeTree *z;
  z = (struct nodeTree *) malloc(sizeof(struct nodeTree));
  z->key = NIL;
  z->color = false;
  z->p = NULL;
  z->Left = NULL;
  z->Right = NULL;
  return z;
}
//-----------------------------------------------------------------------------//
void RBInorderTreeWalk(struct nodeTree *x) {
  if(x->key != NIL) {
    RBInorderTreeWalk(x->Left);
    if(x->color == true)
      printf("[%d|R] ", x->key);
    else
      printf("[%d|B] ", x->key);
    RBInorderTreeWalk(x->Right);
  }
}
//-----------------------------------------------------------------------------//
struct nodeTree *TreeSearch(struct nodeTree *x, int k) {
  if ((x->key == NIL) || (k == x->key)) {
    return x;
  }
  if(k < x->key) {
    return TreeSearch(x->Left,k);
  } else {
    return TreeSearch(x->Right,k);
  }
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreeLeftRotate(struct nodeTree *T, struct nodeTree *x) {
  struct nodeTree *y;
  y = x->Right;
  x->Right = y->Left;
  if(x->Left->key != NIL) {
    y->Left->p = x;
  }
  y->p = x->p;
  if(x->p->key == NIL) {
    T = y;
  } else {
    if(x == x->p->Left) {
      x->p->Left = y;
    } else {
      x->p->Right = y;
    }
  }
  y->Left = x;
  x->p = y;
  return T;
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreeRightRotate(struct nodeTree *T, struct nodeTree *x) {
  struct nodeTree *y;
  y = x->Left;
  x->Left = y->Right;
  if(x->Right->key != NIL) {
    y->Right->p = x;
  }
  y->p = x->p;
  if(x->p->key == NIL) {
    T = y;
  } else {
    if(x == x->p->Right) {
      x->p->Right = y;
    } else {
      x->p->Left = y;
    }
  }
  y->Right = x;
  x->p = y;

  return T;
}
//-----------------------------------------------------------------------------//
struct nodeTree *TreeMinimum(struct nodeTree *x) {
  while (x->Left->key != NIL) {
    x = x->Left;
  }
  return x;
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBTreeMaximum(struct nodeTree *x) {
  while (x->Right->key != NIL) {
    x = x->Right;
  }
  return x;
}
//-----------------------------------------------------------------------------//
struct nodeTree *TreeSuccessor(struct nodeTree *x) {
  if (x->Right->key != NIL) {
    return TreeMinimum(x->Right);
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
struct nodeTree *TreePredeccessor(struct nodeTree *x) {
  if (x->Left->key != NIL) {
    return RBTreeMaximum(x->Left);
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
  while(z->p->color == true) {
    if(z->p == z->p->p->Left) {
      y = z->p->p->Right;
      if(y->color == true) {
        z->p->color = false;
        y->color = false;
        z->p->p->color = true;
        z = z->p->p;
      } else {
        if(z == z->p->Right) {
          z = z->p;
          T = RBTreeLeftRotate(T, z);
        }
        z->p->color = false;
        z->p->p->color = true;
        T = RBTreeRightRotate(T, z->p->p);
      }
    } else {
      y = z->p->p->Left;
      if(y->color == true) {
        z->p->color = false;
        y->color = false;
        z->p->p->color = true;
        z = z->p->p;
      } else {
        if(z == z->p->Left) {
          z = z->p;
          T = RBTreeRightRotate(T, z);
        }
        z->p->color = false;
        z->p->p->color = true;
        T = RBTreeLeftRotate(T, z->p->p);
      }
    }
  }
  T->color = false;
  return T;
}
//-----------------------------------------------------------------------------//
struct nodeTree *TreeInsert(struct nodeTree *T, int element) {
	struct nodeTree *x, *y, *z;
  z = (struct nodeTree *) malloc(sizeof(struct nodeTree));
  z->key = element;
  z->color = true;
  z->Left = AssignNIL();
  z->Left->p = z;
  z->Right = AssignNIL();
  z->Right->p = z;
	if(T->key != NIL) {
    y = T->p;
  } else {
    y = T;
  }
	x = T;
	while(x->key != NIL) {
		y = x;
		if(z->key < x->key) {
			x = x->Left;
    } else {
			x = x->Right;
    }
	}
	z->p = y;
	if(y->key == NIL) {
		T = z;
	} else {
    free(x);
		if(z->key < y->key) {
			y->Left = z;
		} else {
			y->Right = z;
		}
	}
	return RBTreeInsertFIXUP(T, z);
}
//-----------------------------------------------------------------------------//
struct nodeTree *RBDeleteFIXUP(struct nodeTree *T, struct nodeTree *x) {
  struct nodeTree *w;
  while ((x != T) && (x->color == false)) {
    if (x == x->p->Left) {
      w = x->p->Right;
      if (w->color == true) {
        w->color = false;
        x->p->color = true;
        T = RBTreeLeftRotate(T, x->p);
        w = x->p->Right;
      }
      if ((w->Left->color == false) && (w->Right->color == false)) {
        w->color = true;
        x = x->p;
      } else {
        if (w->Right->color == false) {
          w->Left->color = false;
          w->color = true;
          T = RBTreeRightRotate(T, w);
          w = x->p->Right;
        }
        w->color = x->p->color;
        x->p->color = false;
        w->Right->color = false;
        T = RBTreeLeftRotate(T, x->p);
        x = T;
      }
    } else {
      w = x->p->Left;
      if (w->color == true) {
        w->color = false;
        x->p->color = true;
        T = RBTreeRightRotate(T, x->p);
        w = x->p->Left;
      }
      if ((w->Left->color == false) && (w->Right->color == false)) {
        w->color = true;
        x = x->p;
      } else {
        if (w->Left->color == false) {
          w->Right->color = false;
          w->color = true;
          T = RBTreeLeftRotate(T, w);
          w = x->p->Left;
        }
        w->color = x->p->color;
        x->p->color = false;
        w->Left->color = false;
        T = RBTreeRightRotate(T, x->p);
        x = T;
      }
    }
  }
  x->color = false;
  return T;
}
//-----------------------------------------------------------------------------//
struct nodeTree *TreeDelete(struct nodeTree *T, struct nodeTree *z) {
	struct nodeTree *x, *y;
	if((z->Left->key == NIL) || (z->Right->key == NIL)) {
		y = z;
	} else {
		y = TreeSuccessor(z);
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

	if(y->color == false) {
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

/*
============================================================================================================
*/

int main()
{
    struct nodeTree *alturas, *z;//alturas de las chimpances(inicializadas en NIL)
    alturas=AssignNIL();
    int n; //cantidad de alturas de las chimpances
    scanf("%d", &n);
    int b;//varible para ingresar las alturas

    for(int a=0;a<n;a++){
        scanf("%d", &b);
        z = TreeSearch(alturas, b);
        if(z->key == NIL)
            alturas=TreeInsert(alturas,b);
    }

    int k;//cantidad de alturas del chimpance macho
    scanf("%d", &k);

    struct nodeTree *pred;
    struct nodeTree *succ;

    for(int a=0;a<k;a++)
    {
        scanf("%d", &b);
        z = TreeSearch(alturas, b);
        if(z->key != NIL)
        {
            pred = TreePredeccessor(z);
            succ = TreeSuccessor(z);
            if(pred->key == NIL)
            {
                if(succ->key == NIL)
                    printf("X X\n");
                else
                    printf("X %d\n", succ->key);
            }
            else
            {
                if(succ->key == NIL)
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
            if(pred->key == NIL)
            {
                if(succ->key == NIL)
                    printf("X X\n");
                else
                    printf("X %d\n", succ->key);
            }
            else
            {
                if(succ->key == NIL)
                    printf("%d X\n", pred->key);
                else
                    printf("%d %d\n", pred->key, succ->key);
            }
            alturas = TreeDelete(alturas, z);
        }
    }
    return 0;
}
