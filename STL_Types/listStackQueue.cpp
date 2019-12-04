#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int main(){
	cout<<"Stack"<<endl;
	stack<int>s;//Stack by default uses dequeue , can use vector and list instead
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	while(!s.empty()){//can use while(s.size()!=0)
		cout<<s.top()<<endl;
		s.pop();
	}
	cout<<"Queue"<<endl;
	queue<int>q;//by default uses dequeue , can use list , cannot use vector - no front() function
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while(!q.empty()){//can use while(s.size()!=0)
		cout<<q.front()<<endl;
		// cout<<q.back()<<endl;
		q.pop();
	}
	cout<<"Priority Queue"<<endl;
	priority_queue<int>p;//by default uses dequeue , cannot use list
	//by deault max heap
	// priority_queue<int,vector<int>,std::greater<int>>p; , for min heap
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);
	while(!p.empty()){//can use while(s.size()!=0)
		cout<<p.top()<<endl;//no front and back
		p.pop();
	}
	return 0;
}