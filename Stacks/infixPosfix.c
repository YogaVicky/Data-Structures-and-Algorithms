#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	node *next;
};
struct node *top = NULL;
void push(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if(top == NULL){
		top = temp;
		top->next = NULL;	
	}
	else{
		temp->next = top;
		top = temp;
	}
}

int main(){
	int i = 0;
	char b[100]; 
	string a;
	printf("Enter the expression\n");
	gets(a);
	while(s[i]!='\0'){
		if(a[i] > '64' && a[i] < '91'){
			b[j] = a[i];
			j++;
		}
		else{
			while(top!=NULL && prec[i]<)
		}
		i++;
	}
	return 0;
}