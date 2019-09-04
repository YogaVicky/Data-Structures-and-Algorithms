#include<iostream>
#include<stdlib.h>
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