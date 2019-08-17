#include<stdio.h>

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;

void insert(int data , int key);

void printlist(){
	struct node *test = head;
	while(test!=NULL){
		printf("%d",test->data);
	}
}

int main(){
	int a;
	printf("What do you want to do?\n");
	printf("1.Print the list\n2.Insert\n3.Delete\n4.Check empty\n");
	scanf("%d",&a);
	switch(){
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
		case 5:
		break;
		default:
			printf("Enter the correct option\n");
	}
	return 0;
}

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