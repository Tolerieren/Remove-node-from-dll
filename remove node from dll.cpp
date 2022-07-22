
# include <stdlib.h>
# include <stdio.h>

# define FALSE 0
# define TRUE  1

typedef struct NODE {
	int value;
	struct NODE* fwd;
	struct NODE* bwd;
	
}Node;
int dll_remove(Node* rootp, Node* node);

int main()
{
	Node a, b, c, d,root;
	a = { 5,&b,NULL };
	b = { 10,&c,&a };
    c = { 15,&d,&b };
	d = { 20,NULL,&c};

	root = { 0,&a,&d };
	Node* rootp = &root;

	dll_remove(rootp, &b);

	while ((rootp=rootp->fwd)!=NULL)
	{
		printf("%d ", rootp->value);
	}

	return 0;
}

int dll_remove( Node* rootp, Node* node)
{
	register Node* current;
	register Node* next;

	if (rootp->fwd == NULL && rootp->bwd == NULL)
	{
		puts("Empty linklist.");
		return FALSE;
	}

	for (current = rootp; (next = current->fwd) != NULL; current = next)
	{
		if (next == node)
			break;
	}
	if (next == NULL)
	{
		printf("Not exist this node in the linklist.\n");
		return FALSE;
	}

     if ((next->fwd)!= NULL)
	{
		if (current != rootp)
		{
			next = next->fwd;
			current->fwd = next;
			next->bwd = current;
		}
		else
		{
			next = node->fwd;
			rootp->fwd = next;
			next->bwd = NULL;

		}
	}
	else
	{
		 current->fwd = NULL;
		 node->bwd = NULL;
		 rootp->bwd = current;
	}

	 return TRUE;

}