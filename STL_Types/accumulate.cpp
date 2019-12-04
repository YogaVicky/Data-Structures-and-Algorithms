//Alternate for Reduce in C++ STL
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
int main(){
	vector<int> v{1,2,3};
	int final = accumulate(v.begin() , v.end() , 0 , [](int first , int second){ return first + second;});//sum
	cout<<final<<endl;
	return 0;
}