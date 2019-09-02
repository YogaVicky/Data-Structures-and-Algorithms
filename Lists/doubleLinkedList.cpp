#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	node *next;
	node *prev;
};
node *head = NULL;
void insert(int pos,int data){
	node *thead = head;
	node *temp = (node*)malloc(sizeof(struct node));
	temp->data = data;
	if(thead == NULL){
		temp->prev = head;
		temp->next = head;
		head = temp;
	}
	else if(pos == 0){
		temp->next = thead;
		thead->prev = temp;
		temp->prev = NULL;
		head = temp;
	}
	else{
		pos = pos - 1;
		while(pos--){
			thead = thead->next;
		}
		temp->prev = thead;
		temp->next = thead->next;
		thead->next = temp;
	}
}
void printlist(){
	node *thead = head;
	if(thead == NULL){
		cout<<"List is empty\n";
	}
	else{
		while(thead!=NULL){
			cout<<thead->data<<" ";
			thead = thead->next;
		}
		cout<<endl;
	}
}
void remove(int pos){
	node *thead = head;
	if(thead == NULL)
		cout<<"List is empty\n";
	else if(pos == 0){
		head = head->next;
		head->prev = NULL;
	}
	else{
		pos = pos -1;
		while(pos--){
			thead = thead->next;
		}
		if((thead->next)->next!=NULL){
			((thead->next)->next)->prev = thead;
			thead->next = (thead->next)->next;
		}
		else{
			thead->next = (thead->next)->next;	
		}
	}
}
int main(){
	int data , pos , n , c = 1;
	while(c){
		cout<<"Enter your choice\n1.Insert\n2.Delete\n3.PrintList\n";
		cin>>n;
		switch(n){
			case 1:
				cout<<"Enter the position of insertion\n";
				cin>>pos;
				cout<<"Enter the data\n";
				cin>>data;
				insert(pos,data);
			break;
			case 2:
				cout<<"Enter position to be deleted\n";
				cin>>pos;
				remove(pos);
			break;
			case 3:
				printlist();
			break;
		}
		cout<<"Do u want to continue\n";
		cin>>c;
	}	
	return 0;
}

