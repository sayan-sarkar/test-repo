#include <stdio.h>
#include <malloc.h>

typedef struct bst_node {
	int data;
	struct bst_node *l_node;
	struct bst_node *r_node;
}node;

node* new_node(int val)
{
    	node* ptr = (node *)malloc(sizeof(node));
    	if(NULL==ptr) { printf("no memory\n"); return NULL;}
    	ptr->data = val; ptr->l_node = ptr->r_node = NULL; 
    	return ptr;
}

node* insert(node* head, int val)
{
	if(NULL == head) return new_node(val);
	
	if(val <= head->data) head->l_node = insert(head->l_node,val);
	else head->r_node = insert(head->r_node,val);

	return head;
}


node* search(node *head, int val, node** head_ptr)
{
	if(NULL == head) return NULL;
	if(head->data == val) return head;
	*head_ptr = head;
	if(val < head->data) return search(head->l_node,val,head_ptr);
	return search(head->r_node,val,head_ptr);
}

node* successor(node* ptr)
{
	node* link_node = NULL;
	node* temp_ptr = NULL;
	if(ptr->l_node == NULL && ptr->r_node ==NULL)
		link_node == NULL;
	else if(ptr->l_node != NULL && ptr->r_node ==NULL) 
		link_node = ptr->l_node;
	else if(ptr->l_node == NULL && ptr->r_node !=NULL)
		link_node = ptr->r_node;
	else //if(ptr->l_node !=NULL && ptr->r_node != NULL)
	{
		link_node = ptr->l_node;
		temp_ptr = NULL;
		while(link_node->r_node) { temp_ptr = link_node; link_node  = link_node->r_node;}
		if(temp_ptr) temp_ptr->r_node =  NULL;
	}
	return link_node;
}

node* delete(node **head, int val)
{
	node *head_ptr = NULL;
	node *succ_node = NULL;
	node *ptr = search(*head,val,&head_ptr);
	//printf("\nptr:%p: head_ptr:%p l_ptr:%p r_ptr:%p",ptr,head_ptr,ptr->l_node,ptr->r_node);
	if(ptr)
	{
		succ_node = successor(ptr);
		if(succ_node) succ_node->r_node = ptr->r_node;
		if(succ_node &&  succ_node != ptr->l_node) succ_node->l_node = ptr->l_node;
		if(head_ptr->l_node == ptr)
			head_ptr->l_node = succ_node;
		else
			head_ptr->r_node = succ_node;

		//free(ptr);
		if(NULL == head_ptr) *head = NULL;
		printf("\nItem Deleted:%d",val);
	}
	else
	{
		printf("\nentry not present\n");
	}
}


void postorder(node* head)
{
  if(head==NULL) return;
  postorder(head->l_node);
  postorder(head->r_node);
  printf("%d, ",head->data);
}

void preorder(node* head)
{
  if(head==NULL) return;
  printf("%d, ",head->data);
  preorder(head->l_node);
  preorder(head->r_node);
}

void inorder(node* head)
{
  if(head==NULL) return;
  inorder(head->l_node);
  printf("%d, ",head->data);
  //printf("\nD:%d,H:%p,L:%p,R:%p ",head->data,head,head->l_node,head->r_node);
  inorder(head->r_node);
}

void tree_search(node* bst, int val)
{
	node *search_node = NULL;
	node *search_p_node = NULL;
	search_node = search(bst,val,&search_p_node);
	if(search_node) printf("\nSearch:: value:%d  node:%p parent:%p: ",val,search_node,search_p_node);
	else printf("\nSearch:: value:%d  not present ",val);
}

int main()
{
	node *bst=NULL;
	bst = insert(bst,15);
	bst = insert(bst,17);
	bst = insert(bst,13);
	bst = insert(bst,11);
	bst = insert(bst,14);
	bst = insert(bst,16);
	bst = insert(bst,18);

	printf("\nin-order: ");
	inorder(bst);
	printf("\npre-order: ");
	preorder(bst);
	printf("\npost-order: ");
	postorder(bst);

	tree_search(bst, 13);
	tree_search(bst, 18);
	tree_search(bst, 19);


	delete(&bst,13);
	delete(&bst,17);
	
	printf("\nin-order: ");
	inorder(bst);
	printf("\npre-order: ");
	preorder(bst);
	printf("\npost-order: ");
	postorder(bst);






	printf("\n");
}

