#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct tnode
{
  int data;
  struct tnode *lchild;
  struct tnode *rchild;
}TNode;

typedef struct stack
{
	TNode *s[MAX];
	int top;
} STACK;

void push (STACK *st, TNode *root)
{
	st->s[++(st->top)] = root;
}

TNode *pop (STACK *st)
{
 	if(st->top==-1) 
    	return NULL;
	return st->s[(st->top)--];
}

TNode *getTNode()
{
  TNode *newnode = (TNode *) malloc (sizeof(TNode));
  newnode->rchild = newnode->lchild = NULL;
  return newnode;
}

void insertIterBT (TNode **rt, int item)
{
  int ch;
  TNode *t = *rt;
  TNode *present = NULL;
  TNode *newnode;
  if (*rt == NULL)
    {
      *rt = getTNode();
      (*rt)->data = item;
      return;
    }
  do
    {
      printf("1 to insert to left, 2 to insert to right\n");
      scanf("%d", &ch);
      present = t;
      if (ch == 1)
		t= t->lchild;
      else
		t = t->rchild;
      if (t == NULL)
		{
	  	newnode = getTNode();
	  	newnode->data = item;
	  	(ch == 1)?(present->lchild=newnode):(present->rchild=newnode);
	  	return;
		}
  	}while (1);
}

void insertRecurBT (TNode *root)
{
	int data;
	TNode *temp;
	printf("For no child, enter -1 when prompted for value\n");
	printf("Enter value of left child of %d\n", root->data);
	scanf("%d", &data);
	if (data != -1)
	{
		temp = getTNode();
		temp->data = data;
		root->lchild = temp;
		insertRecurBT (root->lchild);
	}
	printf("Enter value of right child of %d\n", root->rchild);
	scanf("%d", &data);
	if (data != -1)
	{
		temp = getTNode();
		temp->data = data;
		root->rchild = temp;
		insertRecurBT (root->rchild);
	}
}

void recurInorder (TNode *root)
{
  if (root != NULL)
    {
      recurInorder (root->lchild);
      printf("%d\n", root->data);
      recurInorder (root->rchild);
    }
}

void preorder (TNode *root)
{
  if (root != NULL)
    {
      printf("%d\n", root->data);
      preorder (root->lchild);
      preorder (root->rchild);
    }
}

void postorder (TNode *root)
{
  if (root != NULL)
    {
      postorder (root->lchild);
      postorder (root->rchild);
      printf("%d\n", root->data);
    }
}

void iterInorder (TNode *root)
{
	STACK s;
	s.top =-1;
	TNode *temp;
	temp = root;
	while (1)
	{
		while (temp != NULL)
		{
			push (&s, temp);
			temp = temp->lchild;
		}
		temp = pop(&s);
		if (!temp)
			break;
		printf(" %d\n", temp->data);
		temp = temp->rchild;
	}
}

int main()
{
  int n, ch, i, ele;
  TNode *root;
  root = NULL;
  while (1)
  {
  	printf("1. Iterative insertion\n2. Recursive insertion\n3. Iterative Inorder traversals\n4. Recursive inorder traversals\n5. Preorder traversals\n6. Postorder traversals\n7. Exit\n");
      scanf (" %d", &ch);
      switch (ch)
      {
      	case 1:
      		printf("Enter node\n"); 
      		scanf(" %d", &ele);
      		insertIterBT (&root, ele);
      		break;
      	case 2:
      		insertRecurBT (root);
      		break;
      	case 3:
      		iterInorder (root);
      		break;
      	case 4:
      		recurInorder (root);
      		break;
      	case 5:
      		preorder (root);
      		break;
      	case 6:
      		postorder (root);
      		break;
      	case 7: exit(0);
      }
  }
}
