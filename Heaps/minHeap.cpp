#include<iostream>
#include<stdlib.h>
using namespace std;
struct heap{
	int a[50];
	int last;
};
heap h;
void insert(int x){
	h.last++;
	int t = h.last;
	h.a[t] = x;
	while((t/2>=1) && h.a[t] < h.a[t/2]){
		h.a[t] = h.a[t] ^ h.a[t/2];
		h.a[t/2] = h.a[t] ^ h.a[t/2];
		h.a[t] = h.a[t] ^ h.a[t/2];
		t/=2;
	}
}
int deleteheap(){
	int i = 1 , temp = h.a[i] , min;
	h.a[i] = h.a[h.last];
	h.last--;
	while(2*i <= h.last){
		if(h.a[2*i] < h.a[2*i + 1])
			min = 2*i;
		else 
			min = 2*i + 1;
		if(h.a[i] > h.a[min]){
			h.a[i] = h.a[i] ^ h.a[min];
			h.a[min] = h.a[i] ^ h.a[min];
			h.a[i] = h.a[i] ^ h.a[min];
		}
		i = min;
	}
	return temp;
}
void traverse(){
	int i;
	for(i=1;i<=h.last;i++)
		cout<<h.a[i]<<" ";
	cout<<endl;
}
int main(){
	h.last = 0;
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
				cout<<"The heap is ";
				traverse();
		}
		cout<<"Press any number to continue\n";
		cin>>k;
	}
	return 0;
}



