#include<iostream>
using namespace std;
int main(){
	int *p = (int *)malloc(sizeof(int));
	*p = 5;
	cout<<*p;
	return 0;
}