#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *right;
	struct node *left;
};
struct input{
	int data;
	int pos;
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
int identifyroot(int a[] , int b[] ,  int i , int j , int n){
	int max = 0 , k , l , pos = i;
	for(k=i;k<j;k++){
		for(l=0;l<n;l++){
			if(a[k] == b[l]){
				if(max<l){
					max = l;
					pos = k;
				}
			}
		}
	}
	return pos;
}
void insertpostin(int a[] , int b[] ,  int i , int j , int n){
	int pos;
	if(i!=j){
		pos = identifyroot(a,b,i,j,n);
		printf("%d\n",pos);
		root = insert(root,a[pos]);
		if(i!=pos)
			insertpostin(a,b,i,pos,n);
		if(j!=pos+1)
			insertpostin(a,b,pos+1,j,n);
	}
}
void preorder(struct node *root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
int main(){
	int a[100] , b[100] , n , i , j , pos;
	printf("Enter the number of inputs for inorder/postorder\n");
	scanf("%d",&n);
	printf("Enter the inorder\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the postorder\n");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	pos = identifyroot(a,b,0,n,n);
	printf("%d\n",pos);
	root = insert(root,a[pos]);
	insertpostin(a,b,0,pos,n);
	insertpostin(a,b,pos+1,n,n);
	printf("The preorder is ");
	preorder(root);
	printf("\n");
	return 0;
}