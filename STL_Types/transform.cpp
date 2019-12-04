//Alternate for Map in C++ STL
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int main(){
	vector<int> v {1,2,3,4,5,6,7};
	vector<int> vout(v.size());
	transform(v.begin() , v.end() , vout.begin() , [](int &value){ return value*3;});
	for(auto it = vout.begin();it!=vout.end();it++)
		cout<<*it<<endl;
	//or
	vector<int> vnew;
	transform(v.begin() , v.end() , back_inserter(vnew) , [](int &value){return value*4;});//back_insert does a push_back internally , cannot be used with forward list
	for(auto it = vnew.begin();it!=vnew.end();it++)
		cout<<*it<<endl;
	return 0;
}