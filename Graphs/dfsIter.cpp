#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
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
int visit[100] = {0} , n;
void dfs(int a[][100]  , int v){
	int u , i = 1;
	visit[v] = 1;
	push(v);
	while(top!=NULL){
		u = pop();
		cout<<u<<endl;
		for(i=1;i<=n;i++){
			if(visit[i]==0 && a[u][i] == 1){
				visit[i] = 1;
				push(i);
			}
		}
	}
	for(i=1;i<=n;i++)
		cout<<visit[i]<<" ";
	cout<<endl;
}
int main(){
	int g[100][100] = {0},ch,i,j;
	cout<<"Enter the number of elements of the graph\n";
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			cout<<"Are "<<i<<" and "<<j<<" connected?\n";
			cin>>ch;
			if(ch)
				g[i][j] = 1;
		}
	dfs(g , 1);
	return 0;
}