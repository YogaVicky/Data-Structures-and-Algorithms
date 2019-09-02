#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector <int> a;
	int s , n , i , c=1;
	while(c){
		cout<<"Enter your choice\n1.Push\n2.Pop\n3.Print an element\n4.Print all elements\n5.Insert an element\n6.Erase an element\n";
		cin>>n;
		switch(n){
			case 1:
				cout<<"Enter the number ";
				cin>>s;
				a.push_back(s);
				break;
			case 2:
				a.pop_back();
				cout<<endl;
				break;
			case 3:
				cout<<"Ask any element from index 0 to "<<a.size() -1<<" ";
				cin>>s;
				cout<<a[s];
				cout<<endl;
				break;
			case 4:
				for(i = 0 ; i < a.size() ; i++)
					cout<<a[i]<<" ";
				cout<<endl;
				break;
			case 5:
				cout<<"Enter index and element to insert ";
				int pos;
				cin>>pos>>s;
				a.insert(a.begin() + pos,s);
				break;
			case 6:
				cout<<"Enter the index to be erased ";
				cin>>s;
				a.erase(a.begin() + s);
		}
		cout<<"Do u want to continue.?\n";
		cin>>c;
	}
	return 0;
}