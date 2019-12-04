//Alternate for Filter in C++ STL
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
int main(){
	vector<int> v{1,2,3,4,5,6,7};
	vector<int>::iterator end_r = remove_if(v.begin(),v.end(),[](int &value){//returns the end iterator such that even numbers are removed and the rest are in the vector 
		if(value%2 != 0)
			return true;
		return false;
	});
	//Vector becomes 2 4 6 4 5 6 7 and end_r points to index of 6
	// cout<<v.size()<<endl; - size does not change
	for(auto it = v.begin();it!=end_r;it++)
		cout<<*it<<endl;
	return 0;
}