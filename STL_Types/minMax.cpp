#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int>v {1,2,3,4,5};
	auto it = max_element(v.begin() , v.end());
	cout<<*it<<endl;
	return 0;
}