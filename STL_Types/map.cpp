#include<iostream>
#include<map>
using namespace std;
int main(){
	// pair<int , int> p = make_pair(10,20);
	// cout<<p.first<<" "<<p.second<<endl;
	map<int , int> m;
	m[4] = 400;
	m[3] = 300;
	m.insert(make_pair(5,500));
	m[6] = 600;
	for(auto it = m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
//map always makes order of the key
//map implements in a balanced tree
//map stores pairs in the nodes of trees