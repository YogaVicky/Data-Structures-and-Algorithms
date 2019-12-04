#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
int main(){
	list<int> l;
	int n , i , a;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		l.push_back(a);
	}
	list<int>::iterator itr = l.begin();
	for(i=0;i<l.size();i++){
		cout<<*(itr)<<" ";
		itr++;
	}
	return 0;
}