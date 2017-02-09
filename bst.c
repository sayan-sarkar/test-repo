#include <stdio.h>
#include <malloc.h>

typedef struct bst_node {
	int data;
	struct bst_node *l_node;
	struct bst_node *r_node;
}node;

node * new_node(int val)
{
    	node* ptr = (node *)malloc(sizeof(node));
    	if(ptr) { printf("no memory\n"); return NULL;}
    	ptr->data = val; ptr->l_node = ptr->r_node = NULL; 
    	return ptr;
}

node * insert(node* head, int val)
{
	if(NULL == head) return new_node(val);
	
	if(val <= head->data) head->l_node = insert(head->l_node,val);
	else head->r_node = insert(head->r_node,val);

	return head;
}



int main()
{

}

