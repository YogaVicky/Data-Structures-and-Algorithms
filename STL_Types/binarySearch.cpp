#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int>v {1,2,3,4,5};
	bool check = binary_search(v.begin() , v.end() , 2);
	cout<<check<<endl;
	check = binary_search(v.begin() , v.end() , 8);
	cout<<check<<endl;
	return 0;
}