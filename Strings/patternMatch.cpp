#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	string s,p;
	cin>>s>>p;
	ll l = p.length();
	ll ml = s.length();
	vector<ll>lps(l);
	vector<ll>check;
	lps[0]=0;
	ll len = 0,i=1,j;
	while(i<l){
		if(p[i]==p[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0)
				len=lps[len-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}
	for(auto it = lps.begin();it!=lps.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	i=0;
	j=0;
	while(i<ml){
		if(j==l){
			cout<<"Pattern found at "<<i-l+1<<endl;
			j=lps[j-1];
		}
		else if(s[i]==p[j]){
			i++;
			j++;
		}
		else{
			if(j==0)
				i++;
			else
				j=lps[j-1];
		}
	}
	return 0;
}