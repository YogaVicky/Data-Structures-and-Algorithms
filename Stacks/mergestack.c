#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *top1 = NULL;
struct node *top2 = NULL;
void push1(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	
	if(top1 == NULL){
		top1 = temp;
		top1->next = NULL;	
	}
	else{
		temp->next = top1;
		top1 = temp;
	}
	
}
void push2(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	
	if(top2 == NULL){
		top2 = temp;
		top2->next = NULL;	
	}
	else{
		temp->next = top2;
		top2 = temp;
	}
	
}
void sort(int a[1000] , int size){
	int i=0,j=0,n;
	int buff;
	n=size;
	for(i=0;i<n-1;i++){
	 	for(j=0;j<n-1-i;j++){
	   		if(a[j]>a[j+1]){
	   			buff=a[j];
	   			a[j]=a[j+1];
	   			a[j+1]=buff;
	   		}
	 	}
	}
	for(i = 0;i < size ; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void displayall(){
	int a[1000] , i = 0;
	while(top1!=NULL){
		a[i] = top1->data;
		top1 = top1->next;
		i++;
	}
	while(top2!=NULL){
		a[i] = top2->data;
		top2 = top2->next;
		i++;
	}
	sort(a , i);
}
int main(){
	int data , n = 1;
	printf("Insert in stack1 , press 0 to stop\n");
	while(n){
		printf("Enter the number\n");
		scanf("%d" , &data);
		push1(data);
		scanf("%d" , &n);
	}
	printf("Insert in stack2 , press 0 to stop\n");
	n=1;
	while(n){
		printf("Enter the number\n");
		scanf("%d" , &data);
		push2(data);
		scanf("%d" , &n);
	}
	displayall();
	return 0;
}

