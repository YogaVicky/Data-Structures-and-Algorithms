#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;	
}
node* insert(node *root , int data){
	node *temp = (node *)malloc(sizeof(node));
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
bool search(node *root , int data){
	if(root == NULL)
		return false;
	else if(root->data == data)
		return true;
	else if(root->data <= data)
		return search(root->left , data);
	else 
		return search(root->right , data);
}
int findMin(node *root){
	node *current = root;
	if(root == NULL){
		cout<<"Tree is empty\n";
		return -1;
	}
	while(current->left != NULL){
		current = current->left;
	}
	return current->data;
}
int findMax(node *root){
	node *current = root;
	if(root == NULL){
		cout<<"Tree is empty\n";
		return -1;
	}
	while(current->right != NULL){
		current = current->right;
	}
	return current->data;
}
node * findMinAddr(node *root){
	node *current = root;
	if(root == NULL){
		cout<<"Tree is empty\n";
		return -1;
	}
	while(current->left != NULL){
		current = current->left;
	}
	return current;
}
int findHeight(node *root){
	if(root == NULL)
		return -1;
	return max(findHeight(root->left) , findHeight(root->right)) + 1;	
}
node * deleteBST(node *root , int data){
	if(root = NULL)
		return root;
	else if(data < root->data)
		root->left = deleteBST(root->left , data);
	else if(data > root->data)
		root->right = deleteBST(root->right , data);
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
			return root;
		}
		else if(root->left == NULL){
			node *temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if(root->right == NULL){
			node *temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		else{
			node *temp = findMinAddr(root->right);
			root->data = temp->data;
			root->right = deleteBST(root->right , temp->data);
		}
	}
}
int main(){
	node *root = NULL;
	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,25);
	root = insert(root,8);
	root = insert(root,12);
	int num;
	cout<<"Enter a number to be searched\n";
	cin>>num;
	if(search(root , number) == true)
		cout<<"Found\n";
	else
		cout<<"Not Found\n";
}