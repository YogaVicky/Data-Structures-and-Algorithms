#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head = NULL;
void insert(int pos,int data){
	node *thead = head;
	node *temp = (node*)malloc(sizeof(struct node));
	temp->data = data;
	if(pos == 0){
		temp->next = head;
		head = temp;
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
	else if(pos==0){
		head = head->next;
	}
	else{
		pos = pos -1;
		while(pos--){
			thead = thead->next;
		}
		thead->next = (thead->next)->next;
	}
}
void reverse(){
	node *current , *next , *prev;
	current = head;
	prev = NULL;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}
int main(){
	int data , pos , n , c = 1;
	while(c){
		cout<<"Enter your choice\n1.Insert\n2.Delete\n3.PrintList\n4.Reverse\n";
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
			case 4:
				reverse();
			break;
		}
		cout<<"Do u want to continue\n";
		cin>>c;
	}	
	return 0;
}

