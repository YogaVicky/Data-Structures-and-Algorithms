#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	ll n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=1;i<n;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}