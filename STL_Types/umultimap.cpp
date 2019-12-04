#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	unordered_multimap<int,int>m;
	// m[4] = 400; not allowerd
	// m[3] = 300;
	m.insert(make_pair(5,500));
	m.insert(make_pair(4,400));
	m.insert(make_pair(7,700));
	m.insert(make_pair(10,1000));
	m.insert(make_pair(10,900));
	// m[6] = 600;
	for(auto it = m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}