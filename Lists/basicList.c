#include<stdio.h>

struct node{
	int data;
	int key;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void insert(int data , int key){
	if(head == NULL){
		head = key;
		head->key = NULL
		current = key;
		current->key = NULL;
		current->data  = data;
		current->data  = data;
	}
	if(head ! NULL){
		current->key = key;
		current = key;
		current->data  = data;
		current->key = NULL;
	}
}

void printlist(){
	struct node *test = head;
	while(test!=NULL){
		printf("%d",test->data);
	}
}

int main(){
	int a;
	cout<<"Enter the number to be added/n";
	cin>>a;
	insert(a,&a);
	cout<<"Enter the number to be added/n";
	cin>>a;
	insert(a,&a);
	printf("\n");
	printlist();
	return 0;
}