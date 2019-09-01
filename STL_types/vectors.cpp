#include<iostream>
using namespace std;
int main(){
	vector <int> a;
	cout<<"Enter your choice\n1.Push\n2.Pop\n3.Print an element\n4.Print all elements\n";
	cin>>n;
	switch(n){
		case 1:
			cout<<"Enter the number";
			cin>>s;
			a.push_back(s);
			cou<<endl;
		case 2:
			a.pop_back();
			cou<<endl;
		case 3:
			cout<<"Ask any element from index 0 to"<<a.size()-1;
			cin>>s;
			cout<<a[s];
			cou<<endl;
		case 4:
			for(i = 0 ; i < a.size() ; i++)
				cout<<a[i]<<" ";
			cout<<endl;
	}
	return 0;
}