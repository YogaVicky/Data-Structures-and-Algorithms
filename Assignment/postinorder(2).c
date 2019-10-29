#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lc;
	struct node *rc;
};
struct node* search(int p,struct node* q)
{
	struct node* t=q;
	while(t->data!=p)
	{
      t=t->rc;
	}
	return t;
}
void preorder(struct node* ptr)
{
	if(ptr)
	{
		
		printf("%d ",ptr->data);
		preorder(ptr->lc);
		preorder(ptr->rc);

	}
}
int main()
{
	int i,n,l,h,tempe;
    struct node* temp;
	scanf("%d",&n);
	int post[n];
	int in[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&post[i]);
	}
	scanf("%d",&tempe);
	 struct node * q=(struct node *)malloc(sizeof(struct node));
    q->rc=NULL;
    q->lc=NULL;
    q->data=tempe;
    struct node *tptr=q;
	for(i=1;i<n;i++)
	{
		scanf("%d",&tempe);
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=tempe;
		temp->lc=NULL;
		tptr->rc=temp;
		tptr=temp;
		
	}

	
  struct node * rptr=(struct node*)malloc(sizeof(struct node));
  rptr->lc=rptr->rc=NULL;
  rptr->data=post[n-1];
  struct node* thptr=search(post[n-1],q);
  thptr->lc=rptr;

  i=n-2;
  struct node* p=rptr;
while(i>=0)
{
  if(post[i]>=p->data)
  {
  	temp=(struct node*)malloc(sizeof(struct node));
  	temp->lc=temp->rc=NULL;
  	temp->data=post[i];
   thptr=search(post[i],q);
   thptr->lc=temp;
   p->rc=temp;
   p=temp;
   i--;
  }
  else
  {
  	struct node* tptr;
    thptr=search(post[i],q);
    tptr=thptr;
    while(thptr->lc==NULL)
    {
    	thptr=thptr->rc;
    }
    p=thptr->lc;
    temp=(struct node*)malloc(sizeof(struct node));
  	temp->lc=temp->rc=NULL;
  	temp->data=post[i];
    p->lc=temp;
    p=temp;
    tptr->lc=temp;
i--;

  }

  }
  preorder(rptr);
  }