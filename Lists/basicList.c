#include<stdio.h>
struct Node;
typedef struct Node* Ptr;
typedef Ptr list;
typedef Ptr pos;

void insert(int a , list l , pos p){
	pos tmp;
	temp = malloc(sizeof(struct Node));
	if(tmp == NULL)
		FatalError("Out of space");
	tmp->a = a;
	tmp->next = p->next;
	p->next = tmp;
}

struct Node{
	int a;
	pos next;
}

int main(){
	return 0;
}
