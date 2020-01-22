#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main(){
	deque<int>q;
	q.push_back(10); 
    q.push_front(20); 
    q.push_back(30); 
    q.push_front(15);
    for(auto it = q.begin();it!=q.end();it++)
    	cout<<*it<<" ";
	cout<<endl;
    q.pop_front();
    q.pop_back();
    for(auto it = q.begin();it!=q.end();it++)
    	cout<<*it<<" ";
	cout<<endl; 	
	return 0;
}
//similar to vectors , more efficient in terms of insertion and deletion
