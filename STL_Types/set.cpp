#include<iostream>
#include<set>
#include<map>
using namespace std;
//Associative container
//only one value acts as the key and the value
int main(){
	map<int,string>m;
	set<int>s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	for(auto it = s.begin();it!=s.end();it++)
		cout<<*it<<endl;
	multiset<int>ms;
	ms.insert(1);
	ms.insert(2);
	ms.insert(3);
	ms.insert(4);
	ms.insert(4);
	for(auto it = ms.begin();it!=ms.end();it++)
		cout<<*it<<endl;
	s.erase(4);
	for(auto it = s.begin();it!=s.end();it++)
		cout<<*it<<endl;
	ms.erase(4);
	for(auto it = ms.begin();it!=ms.end();it++)
		cout<<*it<<endl;
	return 0;
}