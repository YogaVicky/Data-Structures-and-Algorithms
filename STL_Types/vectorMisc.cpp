#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n , a , i;
	vector<int> v;
	cout<<"Enter the number of elements for vector"<<endl;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	//1 2 3 4 4 6 7
	//std::remove(v.begin() , v.end() , 4);
	//1 2 3 6 7 6 7
	v.erase(std::remove(v.begin(),v.end(),4),v.end());//1 2 3 6 7
	// vector<int>::iterator itr = v.begin(); crete an iterator
	// cout<<*itr<<endl;
	// sort(v.begin() , v.end()); 
	for(auto itr = v.begin();itr!=v.end();itr++){
		cout<<*itr<<" ";
	}
	// bool check = binary_search(v , 2);
	return 0;
}
//std::remove doesnt change the size of the vector
//std;;remove return an iterator pointing at the element that should have been removed after rearranging
//for_each(arr1.begin(), arr1.end(), printx2); 