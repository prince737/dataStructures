#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *insert(struct node *root, int val){
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = val;
	if(root == NULL){
		newnode->left = NULL;
		newnode->right = NULL;
		root = newnode;
		return root;
	}	
	else if(val <= root->data)
		root->left = insert(root->left,val);
	else
		root->right = insert(root->right,val);
	return root;
}

int getMax(struct node *root){
	if(root->left == NULL && root->right == NULL){
		printf("Tree is empty.");
		return 0;
	}
	while(root->right != NULL){
		root = root->right;
	}
	return root->data;
}

int getMin(struct node *root){
	if(root->left == NULL && root->right == NULL){
		printf("Tree is empty.");
		return 0;
	}
	while(root->left != NULL){
		root = root->left;
	}
	return root->data;
}

int findHeight(struct node *root){
	if(root == NULL)
		return -1;
	int leftHeight, rightHeight;
	leftHeight = findHeight(root->left);
	rightHeight = findHeight(root->right);
	return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
}

void inorder(struct node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}

void preorder(struct node *root){
	if(root == NULL)
		return;
	printf("%d\t",root->data);
	inorder(root->left);
	inorder(root->right);
}

void postorder(struct node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	inorder(root->right);
	printf("%d\t",root->data);
}

struct node* FindMin(struct node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct node* Delete(struct node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			free(root);
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			free(temp);
		}
		// case 3: 2 children
		else { 
			struct node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

int main(){
	struct node *root = NULL;
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 5);
	root = insert(root, 25);
	int max = getMax(root);
	int min = getMin(root);
	printf("%d",max);
	printf("%d",min);
	printf("%d\n",findHeight(root));
	inorder(root);
	preorder(root);
	postorder(root);
	return 0;
}