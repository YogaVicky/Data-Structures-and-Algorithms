#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<vector<int>> a;
	int n , s , i , j , m; 
	cout<<"Enter the number of rows\n";
	cin>>n;
	for(i=0;i<n;i++){
		a.push_back({});
		cout<<"Enter the number of elements for row "<<i<<endl;
		cin>>m;
		cout<<"Enter the elements\n";
		for(j=0;j<m;j++){
			cin>>s;
			a[i].push_back(s);
		}
	}
	cout<<"The 2D-Vector is\n";
	for(i=0;i<a.size();i++){
		for(j=0;j<a[i].size();j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}