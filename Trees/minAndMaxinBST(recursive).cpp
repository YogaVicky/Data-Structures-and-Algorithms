int findMin(node *root){
	if(root == NULL){
		cout<<"Tree is empty";
		return -1;
	}
	else if(root->left == NULL){
		return root->data;
	}
	return findMin(root->left);
}
int findMax(node *root){
	if(root == NULL){
		cout<<"Tree is empty";
		return -1;
	}
	else if(root->right == NULL){
		return root->data;
	}
	return findMax(root->right);
}