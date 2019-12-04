#include<iostream>
using namespace std;
int visit[100] = {0} , n , check = 0 , recStack[100] = {0};
void dfs(int a[][100] , int v){
	int i , j;
	visit[v] = 1;
	recStack[v] = 1;
	cout<<v<<endl;
		for(i=1;i<=n;i++){
			if(a[v][i] == 1){
				if(visit[i]==0)
					dfs(a , i);
				else{
					for(j=1;j<=n;j++)
						if(a[i][j] == 1 && recStack[j] == 1)
							check++;
				}
			}
		}
	recStack[v] = 0;
}
int main(){
	int g[100][100] = {0},ch,i,j;
	cout<<"Enter the number of elements of the graph\n";
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>g[i][j];
	dfs(g , 1);
	if(check != 0)
		cout<<"Cyclic"<<endl;
	else
		cout<<"Not Cyclic"<<endl;
	return 0;
}