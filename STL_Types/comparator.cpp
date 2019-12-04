#include<iostream>
#include<map>
#include<set>
using namespace std;
//custom comparator
template<typename type>
struct comp{
	bool operator()(const type &first , const type &second) const{
		return first < second;
	}
};
int main(){
	set<int,greater<int>>s;//sorts the incoming elements in a sorted order
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	for(auto it = s.begin();it!=s.end();it++)
		cout<<*it<<endl;
	map<int,string,less<int>>m;//reverse sort//normal sort by default
	m[10] = "abc";
	m[30] = "def";
	m[20] = "xyz";
	for(auto it = m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}