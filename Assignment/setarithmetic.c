#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *nptr;
};
void insert(struct node **S,int x);
void print(struct node *S);
int check(struct node *S, int x);
struct node* complement(struct node *S);
struct node* intersection(struct node *S1, struct node *S2);
struct node * union_(struct node *S1, struct node *S2);

int main()
{
	struct node *A=(struct node *)malloc(sizeof(struct node));
	struct node *B=(struct node *)malloc(sizeof(struct node));
	insert(&A,1);
	insert(&A,7);
	insert(&A,4);
	insert(&A,2);
	insert(&B,1);
	insert(&B,7);
	insert(&B,9);
	insert(&B,8);
	printf("A : ");
	print(A);
	printf("B : ");
	print(B);
	struct node *C=union_(A,B);
	printf("A ∪ B : ");
	print(C);
	struct node *D=intersection(A,B);
	printf("A ∩ B : ");
	print(D);
	struct node *E=complement(A);
	printf("A' : ");
	print(E);
	struct node *F=complement(B);
	printf("B' : ");
	print(F);
}

void insert(struct node **S,int x)
{
	if(check(*S,x)!=1 && x>=1 && x<=10)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->x=x;
		temp->nptr=*S;
		*S=temp;
	}
}

void print(struct node *S)
{
	struct node *tptr = S;
	while(tptr->nptr!=NULL)
	{
		printf("%d ",tptr->x);
		tptr=tptr->nptr;
	}
	printf("\n");
}

int check(struct node *S, int x)
{
	int flag=0;
	struct node *tptr = S;
	while(tptr!=NULL)
	{
		if(tptr->x==x) flag=1;
		tptr=tptr->nptr;
	}
	return flag;
}

struct node* complement(struct node *S)
{
	struct node *tptr = S;
	struct node *A=(struct node *)malloc(sizeof(struct node));
	for(int i=1;i<=10;i++)
		if(check(S,i)!=1) insert(&A, i);
	return A;
}

struct node* intersection(struct node *S1, struct node *S2)
{
	struct node *tptr = S1;
	struct node *A=(struct node *)malloc(sizeof(struct node));
	while(tptr!=NULL)
	{
		if(check(S2,tptr->x)) insert(&A, tptr->x);
		tptr=tptr->nptr;
	}
	return A;
}

struct node * union_(struct node *S1, struct node *S2)
{
	struct node *tptr = S1;
	struct node *A=(struct node *)malloc(sizeof(struct node));
	while(tptr!=NULL)
	{
		insert(&A, tptr->x);
		tptr=tptr->nptr;
	}
	tptr=S2;
	while(tptr!=NULL)
	{
		if(!check(A,tptr->x)) insert(&A, tptr->x);
		tptr=tptr->nptr;
	}
	return A;
}
