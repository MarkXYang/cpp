#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_tag {
	int data;
	struct node_tag *left;	/* less number */
	struct node_tag *right; 	/* Greater number */
} node;

void insert(node **rt, int num)
{
	node *newnode;
	if(*rt == NULL)
	{
		newnode = (node *)malloc(sizeof(mynode));
		if(newnode == NULL) {
			fprintf(stderr, "Unable to allocate node\n");
			exit(1);
		}
		newnode->data = num;
		*rt = newnode;
	}
	else {
		if(num > (*rt)->data) {
			insert(&(*rt)->right, num);
		}
		else
			insert(&(*rt)->left, num);
	}

}

void print_nodes(node *root)
{
	if(root == NULL)
		return;
	/* go to the left/less first */
	if(root->left != NULL) {
		print_nodes(root->left);
	}
	printf("data = %d\n", root->data);

	if(root->right != NULL)
		print_nodes(root->right);

}

bool bintree_search(node* root, int num)
{
    if (root == NULL) {
        return false;
    }
    
    if (root->data == num) {
        return true;
    }
    
    if (num < root->data) {
        return bintree_search(root->left, num);
    } else {
        return bintree_search(root->right, num);
    }
}

int main(int argc, char *argv[])
{

	int num[14] = {19, 6, 85, 2, 25, 90, 41, 23, 11, 7, 99, 82, 48, 32};
	

	int i;
	node *root = NULL;

	for(i=0; i<14; i++) {
		insert(&root, num[i]);
	}

	print_nodes(root);

	return 0;
}
