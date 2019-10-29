#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *right;
	struct node *left;
};
struct node *root = NULL;
struct node *insert(struct node *root , int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	if(root == NULL){
		root = temp;
		root->left = NULL;
		root->left = NULL;
	}
	else if(data <= root->data){
		root->left = insert(root->left,data);		
	}
	else{
		root->right = insert(root->right,data);			
	}
	return root;
}
void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
int main(){
	int a[100] , n , i;
	printf("Enter the number of inputs for postorder\n");
	scanf("%d",&n);
	printf("Enter the postorder\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=n-1;i>=0;i--)
		root = insert(root,a[i]);
	printf("The inorder is ");
	inorder(root);
	printf("\n");
}