#include <bits/stdc++.h> 
using namespace std; 

int increment (int k) { return (k+1); }

int main() 
{ 
vector<int> a = {1, 2, 3}; 
vector<int> b = {4, 5, 6}; 
// int n = sizeof(a)/sizeof(a[0]); 
int n=a.size();
vector<int> k(n); 
vector<int> l(n); 
transform(a.begin(), a.end(), b.begin(), k.begin(), plus<int>()); 
transform(a.begin(), a.end(), l.begin() ,increment); 
for (int i=0; i<n; i++) 
	cout << k[i] << " "; 
cout << endl;

for (int i=0; i<n; i++) 
	cout << l[i] << " "; 
cout << endl;
    return 0;
} 
