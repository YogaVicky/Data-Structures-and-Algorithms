#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int x;
	struct node *nptr;
};

void llinsert(struct node *hptr, int x);
void inputno(struct node *hptr);
void print(struct node *N);
void print1(struct node *hptr);
void remove_extra_zeroes(struct node *N);
int Compare(struct node *N1,struct node *N2);
int AbsCmp(struct node *N1,struct node *N2);
struct node* Addf(struct node *N1,struct node *N2,int sign);
struct node* Subf(struct node *N1,struct node *N2,int sign);
struct node* Add(struct node *N1,struct node *N2);
struct node* Sub(struct node *N1,struct node *N2);
struct node* Mul(struct node *N1,struct node *N2);
struct node* Divf(struct node *N1,struct node *N2);
void Negate(struct node *N);
struct node* createno(char n[]);

int main()
{
	struct node *A=(struct node*)malloc(sizeof(struct node));
	struct node *B=(struct node*)malloc(sizeof(struct node));
	inputno(A);
	inputno(B);
	struct node *C=Divf(A,B);
	print(C);
	return 1;
}

struct node* Mul(struct node *N1,struct node *N2)
{
	struct node *N3=createno("0");
	struct node *one=createno("1");
	for(struct node *i=createno("0");AbsCmp(i,N2)==-1;i=Addf(i,one,0))
		N3=Addf(N3,N1,0);
	if(N1->x!=N2->x) Negate(N3);
	return N3;
}

struct node* Divf(struct node *N1,struct node *N2)
{
	struct node *Num=createno("0");
	if(AbsCmp(N2,N1)==1) return Num;
	struct node *one=createno("1");
	struct node *i;
	for(i=createno("0");AbsCmp(Num,N1)==-1;i=Addf(i,one,0))
		Num=Addf(Num,N2,0);
	if(AbsCmp(Num,N1)!=0) i=Subf(i,one,0);
	if(N1->x!=N2->x) Negate(i);
	return i;
}

struct node* createno(char n[])
{
	struct node *N=(struct node*)malloc(sizeof(struct node));
	int s=0;
	int i=strlen(n)-1;
	if(n[0]=='-') s=1;
	N->x=s;
	N->nptr=NULL;
	while(i>=1)
	{
		llinsert(N,n[i]-48);
		i--;
	}
	if(s!=1) llinsert(N,n[i]-48);
	remove_extra_zeroes(N);
	return N;
}

struct node* Add(struct node *N1,struct node *N2)
{
	struct node *N3=(struct node*)malloc(sizeof(struct node));
	int x=AbsCmp(N1,N2);
	if(x==0 && N1->x!=N2->x)
	{
		N3->x=-0;
		struct node temp;
		temp.x=0;
		temp.nptr=NULL;
		N3->nptr=&temp;
	}
	else if(N1->x==N2->x) N3=Addf(N1,N2,N1->x);
	else	if(N1->x)
	{
		if(x==1) N3=Subf(N1,N2,1);
		else if(x==-1) N3=Subf(N2,N1,0);
	}
	else if(N2->x)
	{
		if(x==1) N3=Subf(N1,N2,0);
		else if(x==-1) N3=Subf(N2,N1,1);
	}
	return N3;
}

struct node* Sub(struct node *N1,struct node *N2)
{
	struct node *N3=(struct node*)malloc(sizeof(struct node));
	int x=AbsCmp(N1,N2);
	if(x==0 && N1->x==N2->x)
	{
		N3->x=-0;
		struct node temp;
		temp.x=0;
		temp.nptr=NULL;
		N3->nptr=&temp;
	}
	else if(N1->x!=N2->x) N3=Addf(N1,N2,N1->x);
	else	if(N1->x==1)
	{
		if(x==1) N3=Subf(N1,N2,1);
		else if(x==-1) N3=Subf(N2,N1,0);
	}
	else if(N1->x==0)
	{
		if(x==1) N3=Subf(N1,N2,0);
		else if(x==-1) N3=Subf(N2,N1,1);
	}
	return N3;
}

struct node* Addf(struct node *N1,struct node *N2,int sign)
{
	struct node *N3=(struct node*)malloc(sizeof(struct node));
	struct node *taptr=N1;
	struct node *tbptr=N2;
	taptr=taptr->nptr;
	tbptr=tbptr->nptr;
	N3->x=sign;
	N3->nptr=NULL;
	int s,r,c;
	c=0;
	while(taptr!=NULL && tbptr!=NULL)
	{
		s=c+taptr->x+tbptr->x;
		r=s%10;
		c=s/10;
		llinsert(N3,r);
		taptr=taptr->nptr;
		tbptr=tbptr->nptr;
	}
	while(taptr!=NULL && tbptr==NULL)
	{
		s=taptr->x+c;
		r=s%10;
		c=s/10;
		llinsert(N3,r);
		taptr=taptr->nptr;
	}
	while(taptr==NULL && tbptr!=NULL)
	{
		s=tbptr->x+c;
		r=s%10;
		c=s/10;
		llinsert(N3,r);
		tbptr=tbptr->nptr;
	}
	if(c) llinsert(N3,c);
	return N3;
}

struct node* Subf(struct node *N1,struct node *N2,int sign)
{
	struct node *N3=(struct node*)malloc(sizeof(struct node));
	struct node *taptr=N1;
	struct node *tbptr=N2;
	taptr=taptr->nptr;
	tbptr=tbptr->nptr;
	N3->x=sign;
	N3->nptr=NULL;
	int d,bor;
	bor=0;
	while(taptr!=NULL && tbptr!=NULL)
	{
		d=taptr->x-tbptr->x-bor;
		if(d>=0)
		{
			llinsert(N3,d);
			bor=0;
		}
		else
		{
			d+=10;
			llinsert(N3,d);
			bor=1;
		}
		taptr=taptr->nptr;
		tbptr=tbptr->nptr;
	}
	if(taptr!=NULL && tbptr==NULL)
	{
		d=taptr->x-bor;
		llinsert(N3,d);
		taptr=taptr->nptr;
	}
	while(taptr!=NULL && tbptr==NULL)
	{
		llinsert(N3,taptr->x);
		taptr=taptr->nptr;
	}
	remove_extra_zeroes(N3);
	return N3;
}

void llinsert(struct node *hptr, int x)
{
	struct node *thptr = hptr;
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp->x=x;
	temp->nptr=NULL;
	while(thptr->nptr!=NULL) thptr=thptr->nptr;
	thptr->nptr=temp;
}

void inputno(struct node *hptr)
{
	int s=0;
	char n[101];
	printf("Enter the number : ");
	gets(n);
	int i=strlen(n)-1;
	if(n[0]=='-') s=1;
	hptr->x=s;
	hptr->nptr=NULL;
	while(i>=1)
	{
		llinsert(hptr,n[i]-48);
		i--;
	}
	if(s!=1) llinsert(hptr,n[i]-48);
	remove_extra_zeroes(hptr);
}

void print1(struct node *hptr)
{
	struct node *thptr = hptr;
	while(thptr!=NULL)
	{
		printf("%d  ",thptr->x);
		thptr=thptr->nptr;
	}
	printf("\n");
}

void print(struct node *N)
{
  int a[100];
  struct node *tp=N;
  int i=0;
  if (tp==NULL) {printf("Null\n");return;}
  while(tp->nptr!=NULL)
  {
    a[i]=tp->x;
    tp=tp->nptr;
    i++;
  }
  a[i]=tp->x;
  a[i+1]=10;
  if(a[0]) printf("-");
  for(int j=i;j>0;j--)
  {
  	 if(a[j]==10) break;
  	 printf("%d",a[j]);
  }
  printf("\n");
}

void remove_extra_zeroes(struct node *N)
{
	struct node *tptr=N;
	int i=0;
	int pos=0;
	while(tptr!=NULL)
	{
		if(tptr->x==0 && pos==0) pos=i;
		else if(tptr->x!=0) pos=0;
		i++;
		tptr=tptr->nptr;
	}
	tptr=N;
	if(pos==1) pos=2;
	if(pos>=2)
	{
		for(int j=1;j<pos;j++) tptr=tptr->nptr;
		tptr->nptr=NULL;
	}
}

int Compare(struct node *N1,struct node *N2)
{
	int flag=0;
	if(N1->x==N2->x)
	{
		flag=AbsCmp(N1,N2);
		if(N1->x==1) flag*=-1;
	}
	else flag=(N1->x?-1:1);
	return(flag);
}

int AbsCmp(struct node *N1,struct node *N2)
{
	int j=0;
	int flag=0;
	struct node *taptr=N1;
	taptr=taptr->nptr;
	struct node *tbptr=N2;
	tbptr=tbptr->nptr;
	while(taptr->nptr!=NULL && tbptr->nptr!=NULL)
	{
		taptr=taptr->nptr;
		tbptr=tbptr->nptr;
		j++;
	}
	if(taptr->nptr!=NULL && tbptr->nptr==NULL) flag=1;
	else if(taptr->nptr==NULL && tbptr->nptr!=NULL) flag=-1;
	else
	{
		for(int i=j+1;i>=1;i--)
		{
			struct node *taptr=N1;
			struct node *tbptr=N2;
			//make i jumps
			for(int k=0;k<i;k++)
			{
				taptr=taptr->nptr;
				tbptr=tbptr->nptr;
			}
			if(taptr->x > tbptr->x)
			{
				flag=1;
				break;
			}
			else if(taptr->x < tbptr->x)
			{
				flag=-1;
				break;
			}
			else continue;
		}
	}
		return flag;
}

void Negate(struct node *N)
{
	N->x=(N->x?0:1);
}

