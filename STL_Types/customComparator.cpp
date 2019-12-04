#include<iostream>
#include<map>
#include<set>
using namespace std;
//custom comparator
template<typename type>
struct comp{
	bool operator()(const type &first , const type &second) const{
		return first.second > second.second;
	}
};
int main(){
	set<pair<int,int>,greater<pair<int,int>>>s;
	s.insert({1,10});
	s.insert({2,20});
	s.insert({4,30});
	s.insert({3,40});
	for(auto it = s.begin();it!=s.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	set<pair<int,int>,comp<pair<int,int>>>sc;
	sc.insert({1,10});
	sc.insert({2,20});
	sc.insert({4,30});
	sc.insert({3,40});
	for(auto it = sc.begin();it!=sc.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	return 0;
}