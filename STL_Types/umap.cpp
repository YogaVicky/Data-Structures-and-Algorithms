#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	unordered_map<int,int>m;
	m[4] = 400;
	m[3] = 300;
	m.insert(make_pair(5,500));
	m[6] = 600;
	for(auto it = m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
//stored as hash table
//more faster than regular map
//no overlap hashing