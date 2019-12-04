#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	node *next;
};
node *top = NULL;
void push(int data){
	node *temp = (node*)malloc(sizeof(struct node));
	temp->data = data;
	if(top == NULL){
		top = temp;
	}
	else{
		temp->next = top;
		top = temp;
	}
}
int pop(){
	node *temp = top;
	top = top->next;
	return temp->data;
}
int main(){
	int i = 0 , j = 0;
	char b[100]; 
	string a;
	printf("Enter the expression\n");
	gets(a);
	while(a[i]!='\0'){
		if(a[i] > '64' && a[i] < '91'){
			b[j] = a[i];
			j++;
		}
		else{
			while(top!=NULL && prec(a[i]) < prec(top->data)){
				b[j] = pop();
				j++;
			}
			push(a[i]);
		}
		i++;
	}
	printf("The postfix expression is ");
	printf("%s\n", b);
	return 0;
}

//infix to postfix - operator stack
//infix to prefix - operator stack - reverse - postfix - reverse
//evaluatng postfix - operand stack
//evaluating prefix - operand stack