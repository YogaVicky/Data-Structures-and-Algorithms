#include<iostream>
#include<stdlib.h>
using namespace std;
struct heap{
	int a[50];
	int last;
};
heap h;
h.last = 0;
void insert(int x){
	h.last++;
	h.a[h.last] = x;
	int t = h.last;
	while((t/2>=1) && h.a[t]>h.a[t/2]){
		h.a[t] = h.a[t] ^ h.a[t/2];
		h.a[t/2] = h.a[t] ^ h.a[t/2];
		h.a[t] = h.a[t] ^ h.a[t/2];
		t/=2;
	}
}
int deleteheap(){
	return 1;
}
void traverse(){
	int i;
	for(i=1;i<=h.last;i++)
		cout<<h.a[i]<<" ";
	cout<<endl;
}
int main(){
	int ch , k =1 , x;
	while(k){
		cout<<"1.Insert\n2.Delete\n3.Traverse\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter the element to be inserted\n";
				cin>>x;
				insert(x);
				break;
			case 2:
				cout<<"The element deleted is "<<deleteheap();
				break;
			case 3:
				cout<<"The heap is\n";
				traverse();
		}
		cout<<"Press any number to continue\n";
		cin>>k;
	}
	return 0;
}



