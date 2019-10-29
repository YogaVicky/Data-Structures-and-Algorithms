#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node{
	int data;
	struct node *next;
};
struct node *head1 = NULL;
struct node *head2 = NULL;
void insert1(int pos,int data){
	struct node *thead = head1;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if(pos == 0){
		temp->next = head1;
		head1 = temp;
	}
	else{
		pos = pos - 1;
		while(pos--){
			thead = thead->next;
		}
		temp->next = thead->next;
		thead->next = temp;
	}
}
void insert2(int pos,int data){
	struct node *thead = head2;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if(pos == 0){
		temp->next = head2;
		head2 = temp;
	}
	else{
		pos = pos - 1;
		while(pos--){
			thead = thead->next;
		}
		temp->next = thead->next;
		thead->next = temp;
	}
}
void breakinsert1(char a[]){
	int i , j , k = 10;
	for(i=0;a[i]!='\0';i++);
	for(j=i-1;j>=0;j--){
		int n = a[j];
		// printf("%d\n",n-48);
		insert1(0,(a[j]-48)*pow(k,i-1-j));
	}
}
void breakinsert2(char a[]){
	int i , j , k = 10;
	for(i=0;a[i]!='\0';i++);
	for(j=i-1;j>=0;j--){
		int n = a[j];
		// printf("%d\n",n-48);
		insert2(0,(a[j]-48)*pow(k,i-1-j));
	}
}
void add(){
	long int sum = 0;
	struct node *thead = head1;
	while(thead!=NULL){
		sum = sum + thead->data;
		thead = thead->next;
	}
	thead = head2;
	while(thead!=NULL){
		sum = sum + thead->data;
		thead = thead->next;
	}
	printf("The sum is %ld\n", sum);
}
void sub(){
	long int sub = 0;
	struct node *thead = head1;
	while(thead!=NULL){
		sub = sub + thead->data;
		thead = thead->next;
	}
	thead = head2;
	while(thead!=NULL){
		sub = sub - thead->data;
		thead = thead->next;
	}
	printf("The difference is %ld\n", sub);
}
void mul(){
	long int sum1 = 0;
	long int sum2 = 0;
	struct node *thead = head1;
	while(thead!=NULL){
		sum1 = sum1 + thead->data;
		thead = thead->next;
	}
	thead = head2;
	while(thead!=NULL){
		sum2 = sum2 + thead->data;
		thead = thead->next;
	}
	printf("The product is %ld\n", sum1*sum2);
}
void divs(){
	long int sum1 = 0;
	long int sum2 = 0;
	struct node *thead = head1;
	while(thead!=NULL){
		sum1 = sum1 + thead->data;
		thead = thead->next;
	}
	thead = head2;
	while(thead!=NULL){
		sum2 = sum2 + thead->data;
		thead = thead->next;
	}
	long int div = sum1/sum2;
	printf("The quotient is %ld\n", div);
}
void mag(){
	long int sum1 = 0;
	long int sum2 = 0;
	struct node *thead = head1;
	while(thead!=NULL){
		sum1 = sum1 + thead->data;
		thead = thead->next;
	}
	thead = head2;
	while(thead!=NULL){
		sum2 = sum2 + thead->data;
		thead = thead->next;
	}
	if(sum1==sum2)
		printf("Equal\n");
	else 
		printf("Not Equal\n");
}
void neg(){
	long int sum1 = 0;
	struct node *thead = head1;
	while(thead!=NULL){
		sum1 = sum1 - thead->data;
		thead = thead->next;
	}
	printf("The negation is %ld\n" , sum1);
}
int main(){
	char a[50] , b[50];
	printf("Enter the first number\n");
	scanf("%s" , a);
	breakinsert1(a);
	printf("Enter the second number\n");
	scanf("%s" , b);
	breakinsert2(b);
	add();
	sub();
	mul();
	divs();
	mag();
	neg();
	return 0;
}